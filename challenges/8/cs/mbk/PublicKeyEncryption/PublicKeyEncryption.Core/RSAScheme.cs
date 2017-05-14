using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PublicKeyEncryption.Core
{
    public class RSAScheme : EncryptionScheme
    {
        private int PrivateD;

        public int PublicN;
        public int PublicE;

        public string PublicKey { get { return "(n = " + PublicN.ToString() + ", e = " + PublicE.ToString() + ")"; } }
        public string PrivateKey { get { return "(n = " + PublicN.ToString() + ", d = " + PrivateD.ToString() + ")"; } }

        ///////////////////////////////////////////////////////////////////////
        public static RSAScheme CreateEncryptor(int n, int e)
        {
            return new RSAScheme
            {
                PublicN = n,
                PublicE = e
            };
        }

        ///////////////////////////////////////////////////////////////////////
        public static RSAScheme CreateDecryptor(int p, int q, int d)
        {
            int lcm = p - 1;
            while ((lcm % (q - 1)) != 0)
                lcm += (p - 1);

            int e = 1;
            while (((e * d) % lcm) != 1)
                ++e;

            return new RSAScheme
            {
                PrivateD = d,
                PublicN = p * q,
                PublicE = e
            };
        }

        ///////////////////////////////////////////////////////////////////////
        public int Encrypt(int m)
        {
            return PowerMod(m, PublicE, PublicN);
        }

        ///////////////////////////////////////////////////////////////////////
        public int Decrypt(int c)
        {
            return PowerMod(c, PrivateD, PublicN);
        }

        ///////////////////////////////////////////////////////////////////////
        private int PowerMod(int b, int e, int n)
        {
            long r = 1;

            for (int i = 0; i < e; ++i)
                r = (r * b) % n;

            return (int)r;
        }
    }
}
