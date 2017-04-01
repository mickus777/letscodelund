using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LSystem
{
    public class Grammar
    {
        public string Value { get; private set; }
        private Dictionary<string, string> Rules;

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Grammar(string axiom, Dictionary<string, string> rules)
        {
            Value = axiom;
            Rules = new Dictionary<string, string>(rules);
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public void Iterate()
        {
            string value = Value;
            Value = "";

            while (value.Length > 0)
            {
                bool found = false;
                foreach (KeyValuePair<string, string> rule in Rules)
                {
                    if (value.StartsWith(rule.Key))
                    {
                        value = value.Substring(rule.Key.Length);
                        Value += rule.Value;
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    Value += value[0];
                    if (value.Length > 1)
                        value = value.Substring(1);
                    else
                        break;
                }
            }
        }
    }
}
