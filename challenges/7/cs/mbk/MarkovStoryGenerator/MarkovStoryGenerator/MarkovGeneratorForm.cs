using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MarkovStoryGenerator
{
    public partial class MarkovGeneratorForm : Form
    {
        private MarkovChain.Chain<string> Chain = new MarkovChain.Chain<string>(7, "[[END]]");

        ///////////////////////////////////////////////////////////////////////////////////////////
        public MarkovGeneratorForm()
        {
            InitializeComponent();

            GenerateButton.Enabled = false;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void AddButton_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog dialog = new OpenFileDialog())
            {
                if (dialog.ShowDialog() != DialogResult.OK)
                    return;

                Chain.Read(new MarkovChain.TextParser(File.ReadAllLines(dialog.FileName)));
            }

            GenerateButton.Enabled = true;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void GenerateButton_Click(object sender, EventArgs e)
        {
            string text = "";

            foreach (string word in Chain.Generate())
            {
                if (word == "[[START]]" || word == "[[END]]")
                    text += word;
                else if (word == "[[PARAGRAPHBREAK]]")
                    text += Environment.NewLine;
                else if (word == "[[PERIOD]]")
                    text += ".";
                else if (word == "[[COMMA]]")
                    text += ",";
                else if (word == "[[SPACE]]")
                    text += " ";
                else
                    text += word;
            }

            int x = 0;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void QuitButton_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
