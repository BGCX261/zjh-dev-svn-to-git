using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MapConverter
{
    class MapConverter
    {
        //const string sSourceTest = "blocks_40x40.tmx.xml";
        //const string sDestTest = "blocks_40x40.tmx.xml.map";

        static void ConvertMap(string source, string dest)
        {
            try
            {
                // Open the source file
                MapData md = new MapData(source);
                // Save the result
                md.Save(dest);
            }
            catch (Exception e)
            {
                throw e;
            }
        }

        static void Main(string[] args)
        {
            try
            {
                if (2 == args.Length)
                {
                    MapConverter.ConvertMap(args[0], args[1]);
                }
                else
                {
                    Console.WriteLine("Usage Guide:");
                    Console.WriteLine("MapConverter.exe SourceMapName TargetMapFileName");
                    Console.WriteLine("Sample: MapConverter.exe sample.tmx.xml sample.tmx.map");
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(string.Format("EXCEPTION: {0}", e.Message));
            }
        }
    }
}
