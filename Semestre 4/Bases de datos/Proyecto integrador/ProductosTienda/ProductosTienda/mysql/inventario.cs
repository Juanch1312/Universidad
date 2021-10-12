using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace ProductosTienda.mysql
{
    public class inventario
    {
        public int codigo { get; set; }
        public int num_suc { get; set; }
        public string producto { get; set; }
        public int entrada_cantidad { get; set; }
        public int salida_cantidad { get; set; }
        public string movimiento { get; set; }
        public double precio { get; set; }
        public double precio_cliente { get; set; }
        public int stock { get; set; }
        public string fecha { get; set; }

        public inventario() { }
    }
}
