using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MapConverter
{
    class MapDataLayer
    {
        private string m_sName;
        private Int32 m_nWidth;
        private Int32 m_nHeight;
        private UInt16[] m_Gid;

        public string Name { get { return m_sName; } set { m_sName = value; } }
        public Int32 Width { get { return m_nWidth; } set { m_nWidth = value; } }
        public Int32 Height { get { return m_nHeight; } set { m_nHeight = value; } }

        //public UInt16 this[UInt16 index] { get { return m_Gid[index]; } set { m_Gid[index] = value; } }
        public void SetGid(UInt16 gid, UInt32 index) { m_Gid[index] = gid; }
        public UInt16 GetGid(UInt16 index) { return m_Gid[index]; }

        public MapDataLayer(string sName, Int32 nWidth, Int32 nHeight)
        {
            this.Name = sName;
            this.Width = nWidth;
            this.Height = nHeight;
            int nSize = this.Width * this.Height;

            m_Gid = new UInt16[nSize];

            for (int n = 0; n < nSize; n++)
            {
                m_Gid[n] = 0;
            }
        }
    }
}
