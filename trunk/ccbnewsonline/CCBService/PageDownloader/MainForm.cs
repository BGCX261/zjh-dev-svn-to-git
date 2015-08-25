using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace PageDownloader
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void buttonDownload_Click(object sender, EventArgs e)
        {
            if (textBoxURL.Text == string.Empty)
            {
                MessageBox.Show("URL is empty !", "Error");
                return;
            }
            if (textBoxSaved.Text == string.Empty)
            {
                MessageBox.Show("Saved file name is empty !", "Error");
                return;
            }

            string pageContent = CCBService.Core.Utility.DownloadFromUrl(textBoxURL.Text);
            using (StreamWriter sw = new StreamWriter(textBoxSaved.Text, false, Encoding.UTF8))
            {
                sw.WriteLine(pageContent);
            }

            MessageBox.Show("Done !", "Message");
        }
    }
}
