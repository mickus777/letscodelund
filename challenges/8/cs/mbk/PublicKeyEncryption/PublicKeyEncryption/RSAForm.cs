using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PublicKeyEncryption
{
    public partial class RSAForm : Form
    {
        public int P { get { return (int)PField.Value; } }
        public int Q { get { return (int)QField.Value; } }
        public int D { get { return (int)DField.Value; } }

        ///////////////////////////////////////////////////////////////////////
        public RSAForm()
        {
            InitializeComponent();

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////
        private void UpdateControls()
        {
            OKButton.Enabled = 
                PField.Value != QField.Value && 
                PField.Value != DField.Value &&
                QField.Value != DField.Value &&
                PField.Value != 0 &&
                QField.Value != 0 && 
                DField.Value != 0;
        }

        ///////////////////////////////////////////////////////////////////////
        private void Control_Changed(object sender, EventArgs e)
        {
            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////
        private void OKButton_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;

            Close();
        }

        ///////////////////////////////////////////////////////////////////////
        private void CloseButton_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;

            Close();
        }
    }
}
