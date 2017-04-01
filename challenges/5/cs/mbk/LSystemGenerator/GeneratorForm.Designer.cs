namespace LSystemGenerator
{
    partial class GeneratorForm
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
            this.SeedField = new System.Windows.Forms.TextBox();
            this.IterateButton = new System.Windows.Forms.Button();
            this.RulesListBox = new System.Windows.Forms.ListBox();
            this.AddButton = new System.Windows.Forms.Button();
            this.EditButton = new System.Windows.Forms.Button();
            this.MoveUpButton = new System.Windows.Forms.Button();
            this.MoveDownButton = new System.Windows.Forms.Button();
            this.DeleteButton = new System.Windows.Forms.Button();
            this.ClearButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.QuitButton = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.AngleUpDown = new System.Windows.Forms.NumericUpDown();
            this.GenerateButton = new System.Windows.Forms.Button();
            this.OutputField = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.SelectOutputButton = new System.Windows.Forms.Button();
            this.ResultField = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.AngleUpDown)).BeginInit();
            this.SuspendLayout();
            // 
            // SeedField
            // 
            this.SeedField.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.SeedField.Location = new System.Drawing.Point(54, 10);
            this.SeedField.Name = "SeedField";
            this.SeedField.Size = new System.Drawing.Size(537, 20);
            this.SeedField.TabIndex = 0;
            this.SeedField.TextChanged += new System.EventHandler(this.SeedField_TextChanged);
            // 
            // IterateButton
            // 
            this.IterateButton.Location = new System.Drawing.Point(258, 297);
            this.IterateButton.Name = "IterateButton";
            this.IterateButton.Size = new System.Drawing.Size(75, 23);
            this.IterateButton.TabIndex = 1;
            this.IterateButton.Text = "Iterate";
            this.IterateButton.UseVisualStyleBackColor = true;
            this.IterateButton.Click += new System.EventHandler(this.IterateButton_Click);
            // 
            // RulesListBox
            // 
            this.RulesListBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.RulesListBox.FormattingEnabled = true;
            this.RulesListBox.Location = new System.Drawing.Point(6, 19);
            this.RulesListBox.Name = "RulesListBox";
            this.RulesListBox.Size = new System.Drawing.Size(482, 212);
            this.RulesListBox.TabIndex = 2;
            this.RulesListBox.SelectedIndexChanged += new System.EventHandler(this.RulesListBox_SelectedIndexChanged);
            // 
            // AddButton
            // 
            this.AddButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.AddButton.Location = new System.Drawing.Point(494, 19);
            this.AddButton.Name = "AddButton";
            this.AddButton.Size = new System.Drawing.Size(75, 23);
            this.AddButton.TabIndex = 3;
            this.AddButton.Text = "Add...";
            this.AddButton.UseVisualStyleBackColor = true;
            this.AddButton.Click += new System.EventHandler(this.AddButton_Click);
            // 
            // EditButton
            // 
            this.EditButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.EditButton.Location = new System.Drawing.Point(494, 48);
            this.EditButton.Name = "EditButton";
            this.EditButton.Size = new System.Drawing.Size(75, 23);
            this.EditButton.TabIndex = 4;
            this.EditButton.Text = "Edit...";
            this.EditButton.UseVisualStyleBackColor = true;
            this.EditButton.Click += new System.EventHandler(this.EditButton_Click);
            // 
            // MoveUpButton
            // 
            this.MoveUpButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.MoveUpButton.Location = new System.Drawing.Point(494, 77);
            this.MoveUpButton.Name = "MoveUpButton";
            this.MoveUpButton.Size = new System.Drawing.Size(75, 23);
            this.MoveUpButton.TabIndex = 5;
            this.MoveUpButton.Text = "Move up";
            this.MoveUpButton.UseVisualStyleBackColor = true;
            this.MoveUpButton.Click += new System.EventHandler(this.MoveUpButton_Click);
            // 
            // MoveDownButton
            // 
            this.MoveDownButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.MoveDownButton.Location = new System.Drawing.Point(494, 106);
            this.MoveDownButton.Name = "MoveDownButton";
            this.MoveDownButton.Size = new System.Drawing.Size(75, 23);
            this.MoveDownButton.TabIndex = 6;
            this.MoveDownButton.Text = "Move down";
            this.MoveDownButton.UseVisualStyleBackColor = true;
            this.MoveDownButton.Click += new System.EventHandler(this.MoveDownButton_Click);
            // 
            // DeleteButton
            // 
            this.DeleteButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.DeleteButton.Location = new System.Drawing.Point(494, 135);
            this.DeleteButton.Name = "DeleteButton";
            this.DeleteButton.Size = new System.Drawing.Size(75, 23);
            this.DeleteButton.TabIndex = 7;
            this.DeleteButton.Text = "Delete";
            this.DeleteButton.UseVisualStyleBackColor = true;
            this.DeleteButton.Click += new System.EventHandler(this.DeleteButton_Click);
            // 
            // ClearButton
            // 
            this.ClearButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.ClearButton.Location = new System.Drawing.Point(494, 164);
            this.ClearButton.Name = "ClearButton";
            this.ClearButton.Size = new System.Drawing.Size(75, 23);
            this.ClearButton.TabIndex = 8;
            this.ClearButton.Text = "Clear";
            this.ClearButton.UseVisualStyleBackColor = true;
            this.ClearButton.Click += new System.EventHandler(this.ClearButton_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 10;
            this.label1.Text = "Seed:";
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.Controls.Add(this.RulesListBox);
            this.groupBox1.Controls.Add(this.AddButton);
            this.groupBox1.Controls.Add(this.EditButton);
            this.groupBox1.Controls.Add(this.ClearButton);
            this.groupBox1.Controls.Add(this.MoveUpButton);
            this.groupBox1.Controls.Add(this.DeleteButton);
            this.groupBox1.Controls.Add(this.MoveDownButton);
            this.groupBox1.Location = new System.Drawing.Point(16, 36);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(575, 255);
            this.groupBox1.TabIndex = 11;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Rules";
            // 
            // groupBox2
            // 
            this.groupBox2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox2.Controls.Add(this.ResultField);
            this.groupBox2.Location = new System.Drawing.Point(16, 326);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(575, 399);
            this.groupBox2.TabIndex = 12;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Result";
            // 
            // QuitButton
            // 
            this.QuitButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.QuitButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.QuitButton.Location = new System.Drawing.Point(516, 815);
            this.QuitButton.Name = "QuitButton";
            this.QuitButton.Size = new System.Drawing.Size(75, 23);
            this.QuitButton.TabIndex = 13;
            this.QuitButton.Text = "Quit";
            this.QuitButton.UseVisualStyleBackColor = true;
            this.QuitButton.Click += new System.EventHandler(this.QuitButton_Click);
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 762);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(37, 13);
            this.label2.TabIndex = 14;
            this.label2.Text = "Angle:";
            // 
            // AngleUpDown
            // 
            this.AngleUpDown.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.AngleUpDown.Location = new System.Drawing.Point(62, 760);
            this.AngleUpDown.Maximum = new decimal(new int[] {
            180,
            0,
            0,
            0});
            this.AngleUpDown.Minimum = new decimal(new int[] {
            180,
            0,
            0,
            -2147483648});
            this.AngleUpDown.Name = "AngleUpDown";
            this.AngleUpDown.Size = new System.Drawing.Size(529, 20);
            this.AngleUpDown.TabIndex = 15;
            this.AngleUpDown.Value = new decimal(new int[] {
            25,
            0,
            0,
            0});
            this.AngleUpDown.ValueChanged += new System.EventHandler(this.Control_Changed);
            // 
            // GenerateButton
            // 
            this.GenerateButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.GenerateButton.Location = new System.Drawing.Point(258, 786);
            this.GenerateButton.Name = "GenerateButton";
            this.GenerateButton.Size = new System.Drawing.Size(75, 23);
            this.GenerateButton.TabIndex = 16;
            this.GenerateButton.Text = "Generate";
            this.GenerateButton.UseVisualStyleBackColor = true;
            this.GenerateButton.Click += new System.EventHandler(this.GenerateButton_Click);
            // 
            // OutputField
            // 
            this.OutputField.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.OutputField.Location = new System.Drawing.Point(62, 733);
            this.OutputField.Name = "OutputField";
            this.OutputField.Size = new System.Drawing.Size(499, 20);
            this.OutputField.TabIndex = 17;
            this.OutputField.TextChanged += new System.EventHandler(this.Control_Changed);
            // 
            // label3
            // 
            this.label3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(13, 736);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(42, 13);
            this.label3.TabIndex = 18;
            this.label3.Text = "Output:";
            // 
            // SelectOutputButton
            // 
            this.SelectOutputButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.SelectOutputButton.Location = new System.Drawing.Point(567, 731);
            this.SelectOutputButton.Name = "SelectOutputButton";
            this.SelectOutputButton.Size = new System.Drawing.Size(24, 23);
            this.SelectOutputButton.TabIndex = 19;
            this.SelectOutputButton.Text = "...";
            this.SelectOutputButton.UseVisualStyleBackColor = true;
            this.SelectOutputButton.Click += new System.EventHandler(this.SelectOutputButton_Click);
            // 
            // ResultField
            // 
            this.ResultField.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.ResultField.Location = new System.Drawing.Point(6, 19);
            this.ResultField.Multiline = true;
            this.ResultField.Name = "ResultField";
            this.ResultField.ReadOnly = true;
            this.ResultField.Size = new System.Drawing.Size(563, 374);
            this.ResultField.TabIndex = 0;
            // 
            // GeneratorForm
            // 
            this.AcceptButton = this.IterateButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.QuitButton;
            this.ClientSize = new System.Drawing.Size(603, 850);
            this.Controls.Add(this.SelectOutputButton);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.OutputField);
            this.Controls.Add(this.GenerateButton);
            this.Controls.Add(this.AngleUpDown);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.QuitButton);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.IterateButton);
            this.Controls.Add(this.SeedField);
            this.Name = "GeneratorForm";
            this.ShowIcon = false;
            this.Text = "L-System Generator";
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.AngleUpDown)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox SeedField;
        private System.Windows.Forms.Button IterateButton;
        private System.Windows.Forms.ListBox RulesListBox;
        private System.Windows.Forms.Button AddButton;
        private System.Windows.Forms.Button EditButton;
        private System.Windows.Forms.Button MoveUpButton;
        private System.Windows.Forms.Button MoveDownButton;
        private System.Windows.Forms.Button DeleteButton;
        private System.Windows.Forms.Button ClearButton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button QuitButton;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown AngleUpDown;
        private System.Windows.Forms.Button GenerateButton;
        private System.Windows.Forms.TextBox OutputField;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button SelectOutputButton;
        private System.Windows.Forms.TextBox ResultField;
    }
}

