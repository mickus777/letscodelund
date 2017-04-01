using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MBK.Geometry
{
    public class Point
    {
        public double X { get; set; }
        public double Y { get; set; }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Point()
        {
            X = 0;
            Y = 0;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Point(double x, double y)
        {
            X = x;
            Y = y;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Point(Point other)
        {
            X = other.X;
            Y = other.Y;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Point Add(Vector vector)
        {
            return new Point(this).AddInPlace(vector);
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Point AddInPlace(Vector vector)
        {
            X += vector.X;
            Y += vector.Y;

            return this;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Vector AsVector()
        {
            return new Vector { X = X, Y = Y };
        }
    }
}
