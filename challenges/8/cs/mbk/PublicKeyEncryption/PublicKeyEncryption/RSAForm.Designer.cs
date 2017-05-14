namespace PublicKeyEncryption
{
    partial class RSAForm
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.CloseButton = new System.Windows.Forms.Button();
            this.OKButton = new System.Windows.Forms.Button();
            this.PField = new System.Windows.Forms.NumericUpDown();
            this.QField = new System.Windows.Forms.NumericUpDown();
            this.DField = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.PField)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.QField)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.DField)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 14);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(17, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "P:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 40);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(18, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Q:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 66);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(18, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "D:";
            // 
            // CloseButton
            // 
            this.CloseButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.CloseButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.CloseButton.Location = new System.Drawing.Point(197, 226);
            this.CloseButton.Name = "CloseButton";
            this.CloseButton.Size = new System.Drawing.Size(75, 23);
            this.CloseButton.TabIndex = 4;
            this.CloseButton.Text = "Cancel";
            this.CloseButton.UseVisualStyleBackColor = true;
            this.CloseButton.Click += new System.EventHandler(this.CloseButton_Click);
            // 
            // OKButton
            // 
            this.OKButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.OKButton.Location = new System.Drawing.Point(116, 226);
            this.OKButton.Name = "OKButton";
            this.OKButton.Size = new System.Drawing.Size(75, 23);
            this.OKButton.TabIndex = 3;
            this.OKButton.Text = "OK";
            this.OKButton.UseVisualStyleBackColor = true;
            this.OKButton.Click += new System.EventHandler(this.OKButton_Click);
            // 
            // PField
            // 
            this.PField.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.PField.Location = new System.Drawing.Point(35, 12);
            this.PField.Name = "PField";
            this.PField.Size = new System.Drawing.Size(237, 20);
            this.PField.TabIndex = 0;
            this.PField.ValueChanged += new System.EventHandler(this.Control_Changed);
            // 
            // QField
            // 
            this.QField.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.QField.Location = new System.Drawing.Point(35, 38);
            this.QField.Name = "QField";
            this.QField.Size = new System.Drawing.Size(237, 20);
            this.QField.TabIndex = 1;
            this.QField.ValueChanged += new System.EventHandler(this.Control_Changed);
            // 
            // DField
            // 
            this.DField.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.DField.Location = new System.Drawing.Point(35, 64);
            this.DField.Name = "DField";
            this.DField.Size = new System.Drawing.Size(237, 20);
            this.DField.TabIndex = 2;
            this.DField.ValueChanged += new System.EventHandler(this.Control_Changed);
            // 
            // RSAForm
            // 
            this.AcceptButton = this.OKButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.CloseButton;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.DField);
            this.Controls.Add(this.QField);
            this.Controls.Add(this.PField);
            this.Controls.Add(this.OKButton);
            this.Controls.Add(this.CloseButton);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "RSAForm";
            this.ShowIcon = false;
            this.Text = "RSAForm";
            ((System.ComponentModel.ISupportInitialize)(this.PField)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.QField)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.DField)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button CloseButton;
        private System.Windows.Forms.Button OKButton;
        private System.Windows.Forms.NumericUpDown PField;
        private System.Windows.Forms.NumericUpDown QField;
        private System.Windows.Forms.NumericUpDown DField;
    }
}