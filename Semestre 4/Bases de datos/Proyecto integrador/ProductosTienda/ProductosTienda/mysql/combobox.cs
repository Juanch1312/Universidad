using ProductosTienda.mysql;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data.MySqlClient;
using System.Windows.Forms;
using System.Data.SqlClient;


namespace ProductosTienda.mysql
{
    class combobox
    {
        
        public void seleccionar_marcas (ComboBox cb)
        {
            cb.Items.Clear();
            MySqlCommand cmd = new MySqlCommand("SELECT * FROM marcas ORDER BY mar_id",conexion.obtenerConexion());
            MySqlDataReader dr = cmd.ExecuteReader();

            while(dr.Read())
            {
                cb.Items.Add(dr[1].ToString());
            }
        }

        public void seleccionar_sucursal(ComboBox cb)
        {
            cb.Items.Clear();
            MySqlCommand cmd = new MySqlCommand("SELECT * FROM sucursales ORDER BY id_sucursal", conexion.obtenerConexion());
            MySqlDataReader dr = cmd.ExecuteReader();
            while (dr.Read())
            {
                cb.Items.Add(dr[1].ToString());
            }
        }

        public void seleccionar_proveedor(ComboBox cb)
        {
            cb.Items.Clear();
            MySqlCommand cmd = new MySqlCommand("SELECT * FROM proveedores ORDER BY id_proveedor", conexion.obtenerConexion());
            MySqlDataReader dr = cmd.ExecuteReader();
            while (dr.Read())
            {
                cb.Items.Add(dr[1].ToString());
            }
        }

        public void seleccionar_cliente(ComboBox cb)
        {
            cb.Items.Clear();
            MySqlCommand cmd = new MySqlCommand("SELECT * FROM cliente ORDER BY Codigo", conexion.obtenerConexion());
            MySqlDataReader dr = cmd.ExecuteReader();
            while (dr.Read())
            {
                cb.Items.Add(dr[1].ToString());
            }
        }
    }
}
