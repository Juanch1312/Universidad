using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProductosTienda.mysql
{
    public class empleado
    {
        public int codigo { set; get; }
        public string nombre { set; get; }
        public int edad { set; get; }
        public string telefono { set; get; }
        public string rfc { set; get; }
        public int num_suc { set; get; }
        public string contrasena { set; get; }
        public char tipo { set; get; }


        public empleado() { }

        public empleado(int codigo, string nombre, int edad, string telefono, string rfc, int num_suc, string contrasena, char tipo)
        {
            this.codigo = codigo;
            this.nombre = nombre;
            this.edad = edad;
            this.telefono = telefono;
            this.rfc = rfc;
            this.num_suc = num_suc;
            this.contrasena = contrasena;
            this.tipo = tipo;
        }
    }
}
