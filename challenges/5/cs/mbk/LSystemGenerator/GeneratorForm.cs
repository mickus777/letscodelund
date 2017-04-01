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
    public partial class GeneratorForm : Form
    {
        private bool Initialized = false;

        ///////////////////////////////////////////////////////////////////////////////////////////
        public GeneratorForm()
        {
            InitializeComponent();

            Initialized = true;

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void SeedField_TextChanged(object sender, EventArgs e)
        {
            if (!Initialized)
                return;

            ResultField.Text = SeedField.Text;

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void RulesListBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void AddButton_Click(object sender, EventArgs e)
        {
            using (LSystemRuleForm form = new LSystemRuleForm())
            {
                if (form.ShowDialog() != DialogResult.OK)
                    return;

                RulesListBox.Items.Add(new LSystemRule { Key = form.Key, Value = form.Value });
            }

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void EditButton_Click(object sender, EventArgs e)
        {
            LSystemRule rule = (LSystemRule)RulesListBox.SelectedItem;

            using (LSystemRuleForm form = new LSystemRuleForm(rule.Key, rule.Value))
            {
                if (form.ShowDialog() != DialogResult.OK)
                    return;

                rule.Key = form.Key;
                rule.Value = form.Value;
            }

            RulesListBox.Items[RulesListBox.SelectedIndex] = RulesListBox.SelectedItem;

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void MoveUpButton_Click(object sender, EventArgs e)
        {
            int index = RulesListBox.SelectedIndex;

            object item = RulesListBox.Items[index];
            RulesListBox.Items.Remove(item);
            RulesListBox.Items.Insert(index - 1, item);

            RulesListBox.SelectedIndex = index - 1;

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void MoveDownButton_Click(object sender, EventArgs e)
        {
            int index = RulesListBox.SelectedIndex;

            object item = RulesListBox.Items[index];
            RulesListBox.Items.Remove(item);
            RulesListBox.Items.Insert(index + 1, item);

            RulesListBox.SelectedIndex = index + 1;

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void DeleteButton_Click(object sender, EventArgs e)
        {
            int index = RulesListBox.SelectedIndex;

            RulesListBox.Items.Remove(RulesListBox.SelectedItem);

            if (RulesListBox.Items.Count > index)
                RulesListBox.SelectedIndex = index;
            else if (RulesListBox.Items.Count > 0)
                RulesListBox.SelectedIndex = index - 1;

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void ClearButton_Click(object sender, EventArgs e)
        {
            RulesListBox.Items.Clear();

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void IterateButton_Click(object sender, EventArgs e)
        {
            Dictionary<string, string> rules = new Dictionary<string, string>();
            foreach (LSystemRule rule in RulesListBox.Items)
                rules.Add(rule.Key, rule.Value);

            LSystem.Grammar grammar = new LSystem.Grammar(ResultField.Text, rules);

            grammar.Iterate();

            ResultField.Text = grammar.Value;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void Control_Changed(object sender, EventArgs e)
        {
            if (!Initialized)
                return;

            UpdateControls();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void SelectOutputButton_Click(object sender, EventArgs e)
        {
            using (SaveFileDialog dialog = new SaveFileDialog { Filter = "svg-file (*.svg)|.svg" })
            {
                if (dialog.ShowDialog() != DialogResult.OK)
                    return;

                OutputField.Text = dialog.FileName;
            }
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void GenerateButton_Click(object sender, EventArgs e)
        {
            SVGGenerator.Generate(ResultField.Text, OutputField.Text, (double)AngleUpDown.Value * Math.PI / 180.0);
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void QuitButton_Click(object sender, EventArgs e)
        {
            Close();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void UpdateControls()
        {
            EditButton.Enabled = RulesListBox.SelectedItem != null;
            MoveUpButton.Enabled = RulesListBox.SelectedItem != null && RulesListBox.SelectedIndex > 0;
            MoveDownButton.Enabled = RulesListBox.SelectedItem != null && RulesListBox.SelectedIndex < (RulesListBox.Items.Count - 1);
            DeleteButton.Enabled = RulesListBox.SelectedItem != null;
            ClearButton.Enabled = RulesListBox.Items.Count > 0;
            IterateButton.Enabled = RulesListBox.Items.Count > 0 && ResultField.Text.Length > 0;
            GenerateButton.Enabled = ResultField.Text.Length > 0 && OutputField.Text.Length > 0;
        }
    }
}
