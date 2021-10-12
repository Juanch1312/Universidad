using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProductosTienda.mysql
{
    public class producto
    {
        public string barcode { get; set; }
        public string nombre { get; set; }
        public int stock { get; set; }
        public double precio { get; set; }
        public int id_marca { get; set; }
        public int id_proveedor { get; set; }
        public int id_sucursal { get; set; }

        public producto() { }

        public producto(string bar, string nombre, int stock, double precio ,int marca, int provee, int sucursal)
        {
            this.barcode = bar;
            this.nombre = nombre;
            this.stock = stock;
            this.precio = precio;
            this.id_marca = marca;
            this.id_proveedor = provee;
            this.id_sucursal = sucursal;
        }
        
    }
}
