using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LSystemGenerator
{
    public partial class LSystemRuleForm : Form
    {
        private bool Initialized = false;
        private bool Changed = false;

        public string Key { get { return KeyField.Text; } }
        public string Value { get { return ValueField.Text; } }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public LSystemRuleForm(string key = "", string value = "")
        {
            InitializeComponent();

            KeyField.Text = key;
            ValueField.Text = value;

            Initialized = true;

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void Control_Changed(object sender, EventArgs e)
        {
            if (!Initialized)
                return;

            Changed = true;

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void CloseButton_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;

            Close();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void OKButton_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;

            Close();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void UpdateControls()
        {
            OKButton.Enabled = Changed;
        }
    }
}
