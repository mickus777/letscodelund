using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MBK.Geometry
{
    public class Vector
    {
        public double X { get; set; }
        public double Y { get; set; }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Vector()
        {
            X = 0;
            Y = 0;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Vector(double x, double y)
        {
            X = x;
            Y = y;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Vector(Vector other)
        {
            X = other.X;
            Y = other.Y;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Vector MultiplyInPlace(double value)
        {
            X *= value;
            Y *= value;

            return this;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Vector Multiply(double value)
        {
            return new Vector(this).MultiplyInPlace(value);
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Vector RotateInPlace(double angle)
        {
            double nx = Math.Cos(angle) * X - Math.Sin(angle) * Y;
            double ny = Math.Sin(angle) * X + Math.Cos(angle) * Y;

            X = nx;
            Y = ny;

            return this;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Vector Rotate(double angle)
        {
            return new Vector(this).RotateInPlace(angle);
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Point AsPoint()
        {
            return new Point { X = X, Y = Y };
        }
    }
}
