using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data;
using MySql.Data.MySqlClient;

namespace ProductosTienda.mysql
{
    public class conexion
    {
        public static MySqlConnection obtenerConexion()
        {
            MySqlConnection conexion = new MySqlConnection("server=127.0.0.1;database=tienda_electronica;Uid=root;pwd=Ju@nch1312;");
            conexion.Open();
            return conexion;
        }
    }
}
