using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DepthImage
{
    public class Class1
    {
        //public void DrawRectangleRectangle(PaintEventArgs e)
        public Graphics DrawRectangle(System.Windows.Forms.PaintEventArgs pe, int x,int y)
        {
         
                // Declares the Graphics object and sets it to the Graphics object  
                // supplied in the PaintEventArgs.  
                Graphics g = pe.Graphics;
                // Create pen.
                Pen blackPen = new Pen(Color.AliceBlue, 3);

            // Create rectangle.
            Rectangle rect = new Rectangle(0, 0, x, y);

            // Draw rectangle to screen.
            
            g.DrawRectangle(blackPen, rect);
            g.DrawRectangle(blackPen, rect);
            return g;
        }
    }
}

