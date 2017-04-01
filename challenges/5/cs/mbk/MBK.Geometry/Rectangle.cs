using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MBK.Geometry
{
    public class Rectangle
    {
        public Point TopRight { get; set; }
        public Point BottomLeft { get; set; }

        public double Width { get { return TopRight.X - BottomLeft.X; } }
        public double Height { get { return TopRight.Y - BottomLeft.X; } }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Rectangle(Rectangle other)
        {
            TopRight = new Point(other.TopRight);
            BottomLeft = new Point(other.BottomLeft);
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Rectangle(Point topRight, Point bottomLeft)
        {
            TopRight = new Point(topRight);
            BottomLeft = new Point(bottomLeft);
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Rectangle ExpandToContainInPlace(Point point)
        {
            if (point.X < BottomLeft.X)
                BottomLeft.X = point.X;
            if (point.Y < BottomLeft.Y)
                BottomLeft.Y = point.Y;

            if (point.X > TopRight.X)
                TopRight.X = point.X;
            if (point.Y > TopRight.Y)
                TopRight.Y = point.Y;

            return this;
        }
    }
}
