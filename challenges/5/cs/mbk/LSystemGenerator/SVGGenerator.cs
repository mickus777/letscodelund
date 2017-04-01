using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LSystemGenerator
{
    public static class SVGGenerator
    {
        ///////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////
        private class State
        {
            public State() { }
            public State(State other)
            {
                Point = new MBK.Geometry.Point(other.Point);
                Direction = new MBK.Geometry.Vector(other.Direction);
            }

            public MBK.Geometry.Point Point { get; set; } 
            public MBK.Geometry.Vector Direction { get; set; }
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public static void Generate(string phrase, string filePath, double angleStep)
        {
            List<MBK.Geometry.Line> lines = GenerateGeometry(phrase, angleStep);

            MBK.Geometry.Rectangle boundingBox = GetBoundingBox(lines);

            AddVector(lines, boundingBox.BottomLeft.AsVector().MultiplyInPlace(-1));

            double scaleFactor = GetFitScale(boundingBox, 1000);

            Scale(lines, scaleFactor);

            string svg = "<svg version=\"1.1\" baseProfile=\"full\" width=\"1000\" height=\"1000\" xmlns=\"http://www.w3.org/2000/svg\">";

            foreach (MBK.Geometry.Line line in lines)
                svg += "\t<line x1=\"" + ToString(1000 - line.From.X) + "\" y1=\"" + ToString(1000 - line.From.Y) + "\" x2=\"" + ToString(1000 - line.To.X) + "\" y2=\"" + ToString(1000 - line.To.Y) + "\" style=\"stroke: rgb(255, 0, 0); stroke - width:2\" />" + Environment.NewLine;

            svg += "</svg>";

            if (File.Exists(filePath))
                File.Delete(filePath);

            File.WriteAllText(filePath, svg);
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static List<MBK.Geometry.Line> GenerateGeometry(string phrase, double angleStep)
        {
            State state = new State { Point = new MBK.Geometry.Point(0, 0), Direction = new MBK.Geometry.Vector(0, 1) };
            List<State> stack = new List<State>();

            List<MBK.Geometry.Line> lines = new List<MBK.Geometry.Line>();

            foreach (char letter in phrase)
            {
                switch (letter)
                {
                    case '[':
                        stack.Add(new State(state));
                        break;
                    case ']':
                        state = stack.Last();
                        stack.Remove(state);
                        break;
                    case '-':
                        state.Direction.RotateInPlace(-angleStep);
                        break;
                    case '+':
                        state.Direction.RotateInPlace(angleStep);
                        break;
                    default:
                        MBK.Geometry.Point nextPoint = state.Point.Add(state.Direction);
                        lines.Add(new MBK.Geometry.Line(state.Point, nextPoint));
                        state.Point = nextPoint;
                        break;
                }
            }

            return lines;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static MBK.Geometry.Rectangle GetBoundingBox(List<MBK.Geometry.Line> lines)
        {
            MBK.Geometry.Rectangle box = lines[0].BoundingBox();

            foreach (MBK.Geometry.Line line in lines)
            {
                box.ExpandToContainInPlace(line.From);
                box.ExpandToContainInPlace(line.To);
            }

            return box;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static double GetFitScale(MBK.Geometry.Rectangle box, double size)
        {
            double widthScale = size / box.Width;
            double heightScale = size / box.Height;

            return Math.Min(widthScale, heightScale);
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static void Scale(List<MBK.Geometry.Line> lines, double factor)
        {
            foreach (MBK.Geometry.Line line in lines)
            {
                line.From = line.From.AsVector().MultiplyInPlace(factor).AsPoint();
                line.To = line.To.AsVector().MultiplyInPlace(factor).AsPoint();
            }
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static void AddVector(List<MBK.Geometry.Line> lines, MBK.Geometry.Vector vector)
        {
            foreach (MBK.Geometry.Line line in lines)
            {
                line.From.AddInPlace(vector);
                line.To.AddInPlace(vector);
            }
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static string ToString(double value)
        {
            return value.ToString().Replace(',', '.');
        }
    }
}
