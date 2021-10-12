using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProductosTienda.mysql
{
    public class proveedor
    {
        public int id { get; set; }
        public string nombre { get; set; }

        public char estado { get; set; }


        public proveedor() { }

        public proveedor(int id, string nombre, char estado)
        {
            this.id = id;
            this.nombre = nombre;
            this.estado = estado;
        }



    }
}
