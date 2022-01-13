using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.IO;

namespace CSpixmap
{
    class StreamPixmap
    {
        public Image stringToImage(string inputString)
        {
            byte[] imageBytes = Encoding.Unicode.GetBytes(inputString);
            MemoryStream ms = new MemoryStream(imageBytes, 0, imageBytes.Length);

            ms.Write(imageBytes, 0, imageBytes.Length);
            Image image = Image.FromStream(ms, true, true);

            return image;
        }
    }
}
