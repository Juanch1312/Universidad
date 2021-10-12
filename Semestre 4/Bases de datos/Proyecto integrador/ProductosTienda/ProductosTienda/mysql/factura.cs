using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProductosTienda.mysql
{
    public class factura
    {
        public int folio { get; set; }
        public int ID_Cliente { get; set; }
        public double total { get; set; }
        public int ID_Empleado { get; set; }
        public int ID_Sucursal { get; set; }
        public string fecha { get; set; }

        public factura() { }
    }
}
