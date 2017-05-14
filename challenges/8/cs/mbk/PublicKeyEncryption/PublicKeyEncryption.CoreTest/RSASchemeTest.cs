using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace PublicKeyEncryption.CoreTest
{
    [TestClass]
    public class RSASchemeTest
    {
        ///////////////////////////////////////////////////////////////////////
        [TestMethod]
        public void RSAScheme_Encrypt()
        {
            int m = 65;
            int result = 2790;

            Core.RSAScheme scheme = Core.RSAScheme.CreateEncryptor(3233, 17);

            int cipher = scheme.Encrypt(m);

            Assert.AreEqual(result, cipher);
        }

        ///////////////////////////////////////////////////////////////////////
        [TestMethod]
        public void RSAScheme_Decrypt()
        {
            int m = 65;

            Core.RSAScheme decryptor = Core.RSAScheme.CreateDecryptor(61, 53, 413);
            Core.RSAScheme encryptor = Core.RSAScheme.CreateEncryptor(decryptor.PublicN, decryptor.PublicE);

            int cipher = encryptor.Encrypt(m);
            int result = decryptor.Decrypt(cipher);

            Assert.AreEqual(m, result);
        }

        ///////////////////////////////////////////////////////////////////////
        [TestMethod]
        public void RSAScheme_Decrypt_Simple()
        {
            int m = 42;

            Core.RSAScheme decryptor = Core.RSAScheme.CreateDecryptor(11, 13, 7);
            Core.RSAScheme encryptor = Core.RSAScheme.CreateEncryptor(decryptor.PublicN, decryptor.PublicE);

            int cipher = encryptor.Encrypt(m);
            int result = decryptor.Decrypt(cipher);

            Assert.AreEqual(m, result);
        }
    }
}
