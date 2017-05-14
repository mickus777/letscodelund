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
    public partial class EncryptionForm : Form
    {
        private bool Initialized = false;

        private Core.EncryptionScheme Scheme = null;

        ///////////////////////////////////////////////////////////////////////
        public EncryptionForm()
        {
            InitializeComponent();

            SchemeCombo.Items.Add("RSA");

            Initialized = true;

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////
        private void Control_Changed(object sender, EventArgs e)
        {
            if (!Initialized)
                return;

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////
        private void UpdateControls()
        {
            GenerateButton.Enabled = SchemeCombo.SelectedItem != null;
            if (Scheme != null)
            {
                PublicKeyField.Text = Scheme.PublicKey;
                PrivateKeyField.Text = Scheme.PrivateKey;
            }
            else
            {
                PublicKeyField.Text = "";
                PrivateKeyField.Text = "";
            }
            EncodeButton.Enabled = Scheme != null && MessageField.Text.Length > 0;
            DecodeButton.Enabled = Scheme != null && CipherField.Text.Length > 0;
        }

        ///////////////////////////////////////////////////////////////////////
        private void EncodeButton_Click(object sender, EventArgs e)
        {
            Initialized = false;

            string cipher = "";

            for (int i = 0; i < MessageField.Text.Length; ++i)
                cipher += Char.ConvertFromUtf32(Scheme.Encrypt(Char.ConvertToUtf32(MessageField.Text, i)));

            CipherField.Text = cipher;

            Initialized = true;

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////
        private void DecodeButton_Click(object sender, EventArgs e)
        {
            Initialized = false;

            string message = "";

            for (int i = 0; i < CipherField.Text.Length; ++i)
                message += Char.ConvertFromUtf32(Scheme.Decrypt(Char.ConvertToUtf32(CipherField.Text, i)));

            DecodedMessageField.Text = message;

            Initialized = true;

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////
        private void GenerateButton_Click(object sender, EventArgs e)
        { 
            switch ((string)SchemeCombo.SelectedItem)
            {
                case "RSA":
                    using (RSAForm form = new RSAForm())
                        if (form.ShowDialog() == DialogResult.OK)
                            SetScheme(Core.RSAScheme.CreateDecryptor(form.P, form.Q, form.D));
                    break;
            }
        }

        ///////////////////////////////////////////////////////////////////////
        private void SetScheme(Core.EncryptionScheme scheme)
        {
            Initialized = false;

            Scheme = scheme;
            CipherField.Text = "";
            DecodedMessageField.Text = "";

            Initialized = true;

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////
        private void QuitButton_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
