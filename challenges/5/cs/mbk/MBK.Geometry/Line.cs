using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MBK.Geometry
{
    public class Line
    {
        public Point From { get; set; }
        public Point To { get; set; }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Line(Line other)
        {
            From = new Point(other.From);
            To = new Point(other.To);
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Line(Point from, Point to)
        {
            From = new Point(from);
            To = new Point(to);
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Rectangle BoundingBox()
        {
            Point bottomLeft = new Point(Math.Min(From.X, To.X), Math.Min(From.Y, To.Y));
            Point topRight = new Point(Math.Max(From.X, To.X), Math.Max(From.Y, To.Y));

            return new Rectangle(topRight, bottomLeft);
        }
    }
}
