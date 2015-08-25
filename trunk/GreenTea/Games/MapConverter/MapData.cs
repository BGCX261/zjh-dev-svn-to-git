using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Xml;

namespace MapConverter
{
    class MapData
    {
        private string m_sMapVersion;
        private string m_sOrientation;
        private Int32 m_nWidth;
        private Int32 m_nHeight;
        private Int32 m_nTileWidth;
        private Int32 m_nTileHeight;
        private Int16 m_nFirstGid;
        private string m_sName;
        private string m_sImageSource;
        private MapDataLayer[] m_MapLayer;

        public string MapVersion { get { return m_sMapVersion; } set { m_sMapVersion = value; } }
        private string Orientation { get { return m_sOrientation; } set { m_sOrientation = value; } }
        private Int32 Width { get { return m_nWidth; } set { m_nWidth = value; } }
        private Int32 Height { get { return m_nHeight; } set { m_nHeight = value; } }
        private Int32 TileWidth { get { return m_nTileWidth; } set { m_nTileWidth = value; } }
        private Int32 TileHeight { get { return m_nTileHeight; } set { m_nTileHeight = value; } }
        private Int16 FirstGid { get { return m_nFirstGid; } set { m_nFirstGid = value; } }
        private string Name { get { return m_sName; } set { m_sName = value; } }
        private string ImageSource { get { return m_sImageSource; } set { m_sImageSource = value; } }

        public MapData(string sXmlFileName)
        {
            try
            {
                Load(sXmlFileName);
            }
            catch (Exception e)
            {
                throw e;
            }
        }

        public bool Load(string sXmlFileName)
        {
            try
            {
                XmlDocument doc = new XmlDocument();
                doc.Load(sXmlFileName);

                XmlNode nodeMap = doc.SelectSingleNode("/map");
                XmlNode nodeTileSet = doc.SelectSingleNode("/map/tileset");
                XmlNode nodeImage = doc.SelectSingleNode("/map/tileset/image");
                XmlNodeList nodeLayerList = doc.SelectNodes("/map/layer");
                
                // Map node information
                this.MapVersion = nodeMap.Attributes["version"].InnerText;
                this.Orientation = nodeMap.Attributes["orientation"].InnerText;
                this.Width = Int32.Parse(nodeMap.Attributes["width"].InnerText);
                this.Height = Int32.Parse(nodeMap.Attributes["height"].InnerText);
                this.TileWidth = Int32.Parse(nodeMap.Attributes["tilewidth"].InnerText);
                this.TileHeight = Int32.Parse(nodeMap.Attributes["tileheight"].InnerText);
                // Tileset information
                this.FirstGid = Int16.Parse(nodeTileSet.Attributes["firstgid"].InnerText);
                this.Name = nodeTileSet.Attributes["name"].InnerText;
                this.ImageSource = nodeImage.Attributes["source"].InnerText;

                if (0 == nodeLayerList.Count)
                {
                    return false;
                }
                this.m_MapLayer = new MapDataLayer[nodeLayerList.Count];
                for (int i = 0; i < nodeLayerList.Count; ++i)
                {
                    XmlNode node = nodeLayerList[i];
                    // Read layer information
                    this.m_MapLayer[i] = new MapDataLayer(
                        node.Attributes["name"].InnerText,
                        Int32.Parse(node.Attributes["width"].InnerText),
                        Int32.Parse(node.Attributes["height"].InnerText)
                        );
                    // Read layer data information
                    XmlNodeList nodeLayerData = node.SelectNodes("data/tile");
                    for (UInt32 a = 0; a < nodeLayerData.Count; a++)
                    {
                        this.m_MapLayer[i].SetGid(UInt16.Parse(nodeLayerData[(int)a].Attributes["gid"].InnerText), a);
                    }
                }

                return true;
            }
            catch (Exception e)
            {
                throw e;
            }
        }

        public bool Save(string sFileName)
        {
            if (null == m_MapLayer)
            {
                return false;
            }

            using (BinaryWriter bw = new BinaryWriter(File.Open(sFileName, FileMode.Create)))
            {
                // Write map information
                BinaryWriteString("map", bw);
                BinaryWriteString(this.MapVersion, bw);
                BinaryWriteString(this.Orientation, bw);
                bw.Write(this.Width);
                bw.Write(this.Height);
                bw.Write(this.TileWidth);
                bw.Write(this.TileHeight);
                // Write tile set information
                bw.Write(this.FirstGid);
                BinaryWriteString(this.Name, bw);
                BinaryWriteString(this.ImageSource, bw);
                // Write the layer count
                bw.Write(this.m_MapLayer.Length);
                // Write each layer
                for (int i = 0; i < this.m_MapLayer.Length; i++)
                {
                    // Write layer information
                    BinaryWriteString(this.m_MapLayer[i].Name, bw);
                    bw.Write(this.m_MapLayer[i].Width);
                    bw.Write(this.m_MapLayer[i].Height);
                    // Write layer data - gid
                    for (UInt16 g = 0; g < this.m_MapLayer[i].Width * this.m_MapLayer[i].Height; g++)
                    {
                        bw.Write(this.m_MapLayer[i].GetGid(g));
                    }
                }
            }

            return true;
        }

        private bool BinaryWriteString(string str, BinaryWriter bw)
        {
            if (0 == str.Length)
            {
                return false;
            }
                        
            // Including the terminator '\0'
            /*
            byte[] array = new byte[str.Length + 1];
            for (int i = 0; i < str.Length; i++)
            {
                array[i] = byte.Parse(str.Substring(i, 1));
            }
            array[str.Length] = 0;

            bw.Write(array);

            array = null;
            */

            // FORMAT:
            // UINT32: String Length
            // CHAR: String Characters
            char[] cs = str.ToCharArray();
            // Including final terminator '\0'
            UInt32 nLength = (UInt32)str.Length + 1;
            bw.Write(nLength);
            bw.Write(cs);
            bw.Write((char)0);

            return true;
        }
    }
}
