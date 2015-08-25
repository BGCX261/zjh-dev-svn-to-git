namespace PageDownloader
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.labelURL = new System.Windows.Forms.Label();
            this.textBoxURL = new System.Windows.Forms.TextBox();
            this.textBoxSaved = new System.Windows.Forms.TextBox();
            this.labelSaved = new System.Windows.Forms.Label();
            this.buttonDownload = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // labelURL
            // 
            this.labelURL.AutoSize = true;
            this.labelURL.Location = new System.Drawing.Point(26, 29);
            this.labelURL.Name = "labelURL";
            this.labelURL.Size = new System.Drawing.Size(23, 12);
            this.labelURL.TabIndex = 0;
            this.labelURL.Text = "URL";
            // 
            // textBoxURL
            // 
            this.textBoxURL.Location = new System.Drawing.Point(75, 26);
            this.textBoxURL.Name = "textBoxURL";
            this.textBoxURL.Size = new System.Drawing.Size(369, 21);
            this.textBoxURL.TabIndex = 1;
            this.textBoxURL.Text = "http://finance.sina.com.cn/money/globalindex/";
            // 
            // textBoxSaved
            // 
            this.textBoxSaved.Location = new System.Drawing.Point(74, 62);
            this.textBoxSaved.Name = "textBoxSaved";
            this.textBoxSaved.Size = new System.Drawing.Size(370, 21);
            this.textBoxSaved.TabIndex = 3;
            this.textBoxSaved.Text = "saved.html";
            // 
            // labelSaved
            // 
            this.labelSaved.AutoSize = true;
            this.labelSaved.Location = new System.Drawing.Point(25, 65);
            this.labelSaved.Name = "labelSaved";
            this.labelSaved.Size = new System.Drawing.Size(35, 12);
            this.labelSaved.TabIndex = 2;
            this.labelSaved.Text = "Saved";
            // 
            // buttonDownload
            // 
            this.buttonDownload.Location = new System.Drawing.Point(369, 150);
            this.buttonDownload.Name = "buttonDownload";
            this.buttonDownload.Size = new System.Drawing.Size(75, 23);
            this.buttonDownload.TabIndex = 4;
            this.buttonDownload.Text = "Download";
            this.buttonDownload.UseVisualStyleBackColor = true;
            this.buttonDownload.Click += new System.EventHandler(this.buttonDownload_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(456, 185);
            this.Controls.Add(this.buttonDownload);
            this.Controls.Add(this.textBoxSaved);
            this.Controls.Add(this.labelSaved);
            this.Controls.Add(this.textBoxURL);
            this.Controls.Add(this.labelURL);
            this.MaximizeBox = false;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Page Downloader";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelURL;
        private System.Windows.Forms.TextBox textBoxURL;
        private System.Windows.Forms.TextBox textBoxSaved;
        private System.Windows.Forms.Label labelSaved;
        private System.Windows.Forms.Button buttonDownload;
    }
}

