namespace PublicKeyEncryption
{
    partial class EncryptionForm
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
            this.SchemeCombo = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.GenerateButton = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.PublicKeyField = new System.Windows.Forms.TextBox();
            this.PrivateKeyField = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.MessageField = new System.Windows.Forms.TextBox();
            this.EncodeButton = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.CipherField = new System.Windows.Forms.TextBox();
            this.DecodeButton = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.DecodedMessageField = new System.Windows.Forms.TextBox();
            this.QuitButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // SchemeCombo
            // 
            this.SchemeCombo.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.SchemeCombo.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.SchemeCombo.FormattingEnabled = true;
            this.SchemeCombo.Location = new System.Drawing.Point(117, 14);
            this.SchemeCombo.Name = "SchemeCombo";
            this.SchemeCombo.Size = new System.Drawing.Size(355, 21);
            this.SchemeCombo.TabIndex = 0;
            this.SchemeCombo.SelectedIndexChanged += new System.EventHandler(this.Control_Changed);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 17);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Scheme:";
            // 
            // GenerateButton
            // 
            this.GenerateButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.GenerateButton.Location = new System.Drawing.Point(478, 12);
            this.GenerateButton.Name = "GenerateButton";
            this.GenerateButton.Size = new System.Drawing.Size(75, 23);
            this.GenerateButton.TabIndex = 1;
            this.GenerateButton.Text = "Generate...";
            this.GenerateButton.UseVisualStyleBackColor = true;
            this.GenerateButton.Click += new System.EventHandler(this.GenerateButton_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 44);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(59, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Public key:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 70);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(63, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Private key:";
            // 
            // PublicKeyField
            // 
            this.PublicKeyField.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.PublicKeyField.Location = new System.Drawing.Point(117, 41);
            this.PublicKeyField.Name = "PublicKeyField";
            this.PublicKeyField.ReadOnly = true;
            this.PublicKeyField.Size = new System.Drawing.Size(436, 20);
            this.PublicKeyField.TabIndex = 2;
            // 
            // PrivateKeyField
            // 
            this.PrivateKeyField.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.PrivateKeyField.Location = new System.Drawing.Point(117, 67);
            this.PrivateKeyField.Name = "PrivateKeyField";
            this.PrivateKeyField.ReadOnly = true;
            this.PrivateKeyField.Size = new System.Drawing.Size(436, 20);
            this.PrivateKeyField.TabIndex = 3;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 96);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(53, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Message:";
            // 
            // MessageField
            // 
            this.MessageField.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.MessageField.Location = new System.Drawing.Point(117, 93);
            this.MessageField.Name = "MessageField";
            this.MessageField.Size = new System.Drawing.Size(436, 20);
            this.MessageField.TabIndex = 4;
            this.MessageField.TextChanged += new System.EventHandler(this.Control_Changed);
            // 
            // EncodeButton
            // 
            this.EncodeButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.EncodeButton.Location = new System.Drawing.Point(478, 119);
            this.EncodeButton.Name = "EncodeButton";
            this.EncodeButton.Size = new System.Drawing.Size(75, 23);
            this.EncodeButton.TabIndex = 5;
            this.EncodeButton.Text = "Encode";
            this.EncodeButton.UseVisualStyleBackColor = true;
            this.EncodeButton.Click += new System.EventHandler(this.EncodeButton_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(12, 151);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(40, 13);
            this.label5.TabIndex = 10;
            this.label5.Text = "Cipher:";
            // 
            // CipherField
            // 
            this.CipherField.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.CipherField.Location = new System.Drawing.Point(117, 148);
            this.CipherField.Name = "CipherField";
            this.CipherField.Size = new System.Drawing.Size(436, 20);
            this.CipherField.TabIndex = 6;
            this.CipherField.TextChanged += new System.EventHandler(this.Control_Changed);
            // 
            // DecodeButton
            // 
            this.DecodeButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.DecodeButton.Location = new System.Drawing.Point(478, 174);
            this.DecodeButton.Name = "DecodeButton";
            this.DecodeButton.Size = new System.Drawing.Size(75, 23);
            this.DecodeButton.TabIndex = 7;
            this.DecodeButton.Text = "Decode";
            this.DecodeButton.UseVisualStyleBackColor = true;
            this.DecodeButton.Click += new System.EventHandler(this.DecodeButton_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(12, 206);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(99, 13);
            this.label6.TabIndex = 13;
            this.label6.Text = "Decoded message:";
            // 
            // DecodedMessageField
            // 
            this.DecodedMessageField.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.DecodedMessageField.Location = new System.Drawing.Point(117, 203);
            this.DecodedMessageField.Name = "DecodedMessageField";
            this.DecodedMessageField.ReadOnly = true;
            this.DecodedMessageField.Size = new System.Drawing.Size(436, 20);
            this.DecodedMessageField.TabIndex = 8;
            // 
            // QuitButton
            // 
            this.QuitButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.QuitButton.Location = new System.Drawing.Point(478, 231);
            this.QuitButton.Name = "QuitButton";
            this.QuitButton.Size = new System.Drawing.Size(75, 23);
            this.QuitButton.TabIndex = 9;
            this.QuitButton.Text = "Quit";
            this.QuitButton.UseVisualStyleBackColor = true;
            this.QuitButton.Click += new System.EventHandler(this.QuitButton_Click);
            // 
            // EncryptionForm
            // 
            this.AcceptButton = this.EncodeButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.QuitButton;
            this.ClientSize = new System.Drawing.Size(565, 266);
            this.Controls.Add(this.QuitButton);
            this.Controls.Add(this.DecodedMessageField);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.DecodeButton);
            this.Controls.Add(this.CipherField);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.EncodeButton);
            this.Controls.Add(this.MessageField);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.PrivateKeyField);
            this.Controls.Add(this.PublicKeyField);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.GenerateButton);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.SchemeCombo);
            this.MinimumSize = new System.Drawing.Size(287, 305);
            this.Name = "EncryptionForm";
            this.ShowIcon = false;
            this.Text = "Encryption";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox SchemeCombo;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button GenerateButton;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox PublicKeyField;
        private System.Windows.Forms.TextBox PrivateKeyField;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox MessageField;
        private System.Windows.Forms.Button EncodeButton;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox CipherField;
        private System.Windows.Forms.Button DecodeButton;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox DecodedMessageField;
        private System.Windows.Forms.Button QuitButton;
    }
}

