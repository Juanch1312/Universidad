using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProductosTienda.mysql
{
    public class producto_venta
    {
        public string barcode { get; set; }
        public string nombre { get; set; }
        public int stock { get; set; }
        public double precio { get; set; }

        public producto_venta() { }

        public producto_venta(string bar, string nombre, int stock, double precio)
        {
            this.barcode = bar;
            this.nombre = nombre;
            this.stock = stock;
            this.precio = precio;
        }
    }
}
