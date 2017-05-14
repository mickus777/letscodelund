using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PublicKeyEncryption.Core
{
    public interface EncryptionScheme
    {
        string PublicKey { get; }
        string PrivateKey { get; }

        int Encrypt(int m);
        int Decrypt(int m);
    }
}
