using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace compiler
{
public class Interpreter
    {
        List<Dictionary<string, string>> vars = new List<Dictionary<string, string>>();
        public void PrintString(string arg)
        {
            string[] lines = arg.Split(new Char[] { '<', '<' });
            bool coutOK = false;
            foreach (string line in lines)
            {
                string com = line.Trim();
                if (com != "")
                {
                    if (!coutOK)
                    {
                        if (com == "cout")
                        {
                            coutOK = true;
                        }
                    }
                    else
                    {
                        if (com.StartsWith("\""))
                        {
                            string[] fix = com.Split('"');
                            foreach (string mt in fix)
                            {
                                if (mt.Trim() == "endl")
                                {
                                    Console.Write("\n");
                                }
                                else
                                {
                                    string fix_op = mt.Replace("\\n", "\n");
                                    Console.Write(fix_op);
                                }
                            }
                        }
                        else if (com.Trim() == "endl")
                        {
                            Console.Write("\n");
                        }
                        else
                        {
                            foreach (Dictionary<string, string> single in vars)
                            {
                                foreach (var key in single)
                                {
                                    if (key.Key == com)
                                    {
                                        Console.Write(key.Value);
                                    }
                                }
                            }
                        }
                        
                    }
                }
            }
        }

        public int EvaluateExpression(string math)
        {
            return Convert.ToInt32(math);
        }
        public void saveVariable(string arg)
        {
            bool initiated = false;
            string type = "";
            if (arg.StartsWith("int"))
            {
                initiated = true;
                type = "int";
            }
            else if (arg.StartsWith("string"))
            {
                initiated = true;
                type = "string";
            }
            else if (arg.StartsWith("bool"))
            {
                initiated = true;
                type = "bool";
            }
            else if (arg.StartsWith("double"))
            {
                initiated = true;
                type = "double";
            }
            else if (arg.StartsWith("float"))
            {
                initiated = true;
                type = "float";
            }
            else if (arg.StartsWith("char"))
            {
                initiated = true;
                type = "char";
            }

            if (initiated)
            {
                string[] lines = arg.Split(',');
                foreach (string line in lines)
                {
                    string com = line.Trim();
                    if (com != "")
                    {
                        com = com.Replace(type, "");
                        com = com.Trim();
                        string[] fix = com.Split('=');

                        string key = fix[0].Trim();
                        string value = fix[1].Trim();
                        if (type == "int")
                        {
                            value = new DataTable().Compute(value, null).ToString();
                        } else if (type == "string")
                        {
                            if (value.StartsWith("\""))
                            {
                                value = value.Replace("\"", "");
                            } else if (value.StartsWith("'"))
                            {
                                value = value.Replace("'", "");
                            }
                        }
                        
                        Dictionary<string, string> variable = new Dictionary<string, string>();
                        variable.Add(key, value);
                        vars.Add(variable);
                    }
                }
            }
        }
    }
    
    class Program
    { 
        static void Main(string[] args)
        {
            Interpreter interpreter = new Interpreter();
            Console.WriteLine("C++ Interpreter");
            string cpp = System.IO.File.ReadAllText("<enter your cpp file here>.cpp");
            string[] blocks = cpp.Split('{', '}');
            bool mainFunction = false;
            foreach (string command in blocks)
            {
                if (!mainFunction)
                {
                    if (command.Trim().ToLower().Contains("int main()"))
                    {
                        mainFunction = true;
                    }
                } else
                {
                    string block = command.Trim();
                    string[] lines = block.Split(';');
                    foreach(string line in lines)
                    {
                        string com = line.Trim();
                        if (com != "")
                        {
                            if (com.StartsWith("cout"))
                            {
                                interpreter.PrintString(com);
                            } else if (com.StartsWith("int") || com.StartsWith("string"))
                            {
                                interpreter.saveVariable(com);
                            }
                        }
                    }
                }
            }
            Console.ReadLine();
        }
    }
}
