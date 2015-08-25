using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Xml;

namespace CodeTemplateGenerator
{
    public partial class CodeTemplateGenerator : Form
    {
        private string m_sConfigPath = "config";

        private List<Label> m_Labels = new List<Label>();
        private List<TextBox> m_TextBoxes = new List<TextBox>();
                
        public CodeTemplateGenerator()
        {
            InitializeComponent();
        }

        private void InitializeLabel(Label label, TextBox textBox, XmlNode node)
        {
            label.Text = node.ChildNodes[0].InnerText;
        }

        private void InitializeControllers(string file)
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(Path.Combine(m_sConfigPath, file));
            XmlNodeList nodeList = doc.SelectNodes("/Template/Parameter");

            for (int i = 0; i < nodeList.Count; i++)
            {
                InitializeLabel(m_Labels[i], m_TextBoxes[i], nodeList[i]);
                /*
                if (0 == i)
                    InitializeLabel(ref m_LabelParamter1, ref m_TextBoxParameter1, nodeList[i]);
                else if (1 == i)
                    InitializeLabel(ref m_LabelParamter1, ref m_TextBoxParameter2, nodeList[i]);
                else if (2 == i)
                    InitializeLabel(ref m_LabelParamter1, ref m_TextBoxParameter3, nodeList[i]);
                else if (3 == i)
                    InitializeLabel(ref m_LabelParamter1, ref m_TextBoxParameter4, nodeList[i]);
                else if (4 == i)
                    InitializeLabel(ref m_LabelParamter1, ref m_TextBoxParameter5, nodeList[i]);
                else if (5 == i)
                    InitializeLabel(ref m_LabelParamter1, ref m_TextBoxParameter6, nodeList[i]);
                else if (6 == i)
                    InitializeLabel(ref m_LabelParamter1, ref m_TextBoxParameter7, nodeList[i]);
                 * */
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            m_Labels.Add(m_LabelParamter1);
            m_Labels.Add(m_LabelParamter2);
            m_Labels.Add(m_LabelParamter3);
            m_Labels.Add(m_LabelParamter4);
            m_Labels.Add(m_LabelParamter5);
            m_Labels.Add(m_LabelParamter6);

            m_TextBoxes.Add(m_TextBoxParameter1);
            m_TextBoxes.Add(m_TextBoxParameter2);
            m_TextBoxes.Add(m_TextBoxParameter3);
            m_TextBoxes.Add(m_TextBoxParameter4);
            m_TextBoxes.Add(m_TextBoxParameter5);
            m_TextBoxes.Add(m_TextBoxParameter6);

            string[] files = Directory.GetFiles(m_sConfigPath, "*.config.xml");
            foreach (string file in files)
            {
                m_ComboBoxConfig.Items.Add(Path.GetFileName(file));
            }
            if (m_ComboBoxConfig.Items.Count != 0)
            {
                m_ComboBoxConfig.SelectedIndex = 0;
            }
        }
        
        private void m_ComboBoxConfig_SelectedIndexChanged(object sender, EventArgs e)
        {
            InitializeControllers(m_ComboBoxConfig.Items[m_ComboBoxConfig.SelectedIndex] as string);
        }

        private void m_ButtonGenerate_Click(object sender, EventArgs e)
        {
            string fileName = m_ComboBoxConfig.Items[m_ComboBoxConfig.SelectedIndex] as string;
            string fileNameFull = Path.Combine(m_sConfigPath, fileName);

            XmlDocument doc = new XmlDocument();
            doc.Load(fileNameFull);
            XmlNodeList nodeListFile = doc.SelectNodes("/Template/FileList/File");
            XmlNodeList nodeListParameter = doc.SelectNodes("/Template/Parameter");

            // Read template files
            StringBuilder[] sbList = null;
            if(nodeListFile.Count!=0)
            {
                sbList = new StringBuilder[nodeListFile.Count];
                for (int i = 0; i < nodeListFile.Count; i++)
                {
                    using (StreamReader sr = new StreamReader(Path.Combine(m_sConfigPath, nodeListFile[i].ChildNodes[0].InnerText)))
                    {
                        sbList[i] = new StringBuilder(sr.ReadToEnd());
                    }
                }
            }

            // Do replacements
            for (int i = 0; i < nodeListParameter.Count; i++)
            {
                string sReplacement = nodeListParameter[i].ChildNodes[1].InnerText;
                for(int m=0;m<sbList.Length;m++)
                {
                    sbList[m].Replace(sReplacement, m_TextBoxes[i].Text);
                }
            }

            // Save
            for (int i = 0; i < nodeListFile.Count; i++)
            {
                string timeStamp = DateTime.Now.ToString("MM-dd-HH-mm-ss");
                using (StreamWriter sw = new StreamWriter(Path.Combine(m_sConfigPath, nodeListFile[i].ChildNodes[0].InnerText + "_" + timeStamp)))
                {
                    sw.Write(sbList[i].ToString());
                }
            }
        }
    }
}
