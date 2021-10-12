using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace ProductosTienda.mysql
{
    public class funciones
    {
        private static empleado empleadoActual = new empleado();

        public static void setEmpleado(empleado empleado) => empleadoActual = empleado;

        public static empleado getEmpleado()
        {
            return empleadoActual;
        }
        //Inicio funciones agregar
        public static int agregar(producto add)
        {
            int retorno = 0;
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("INSERT INTO productos(codigo_bar, nombre, stock, precio, id_marca, id_proveedor, id_sucursal) VALUES ('{0}','{1}',{2},{3},{4},{5},{6})", add.barcode, add.nombre, add.stock, add.precio, add.id_marca, add.id_proveedor, add.id_sucursal), conexion.obtenerConexion());
                retorno = comando.ExecuteNonQuery();
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return retorno;
        }

        public static int agregar_detalle(int id, string cod_bar, int cantidad, double sub_total)
        {
            int retorno = 0;
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("INSERT INTO detalle(ID_Detalle, Cod_Barras, Cantidad, Sub_Total) VALUES ({0},'{1}',{2},{3})", id, cod_bar, cantidad, sub_total), conexion.obtenerConexion());
                retorno = comando.ExecuteNonQuery();
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return retorno;
        }

        public static int agregar_factura(int folio, int id_cliente, double total, int id_empleado, int id_sucursal)
        {
            int retorno = 0;
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("INSERT INTO factura(Folio, ID_Cliente, Total, ID_Empleado, ID_Sucursal) VALUES({0}, {1}, {2}, {3}, {4})", folio, id_cliente, total, id_empleado, id_sucursal), conexion.obtenerConexion());
                retorno = comando.ExecuteNonQuery();
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return retorno;
        }

        public static int agregar_detalle_factura(int detalle, int factura)
        {
            int retorno = 0;
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("INSERT INTO detalle_factura(ID_detalle, Folio) VALUES({0},{1})", detalle, factura), conexion.obtenerConexion());
                retorno = comando.ExecuteNonQuery();
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return retorno;
        }

        public static int agregar_empleado_detalle(int id_empleado, int detalle)
        {
            int retorno = 0;
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("INSERT INTO empleado_detalle(Codigo_Empleado, Codigo_Venta) VALUES({0},{1})", id_empleado, detalle), conexion.obtenerConexion());
                retorno = comando.ExecuteNonQuery();
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return retorno;
        }

        public static int agregar_inventario(int codigo, int suc, string producto, int entrada, int salida, string movimiento, double precio, double precio_cli, int stock)
        {
            int retorno = 0;
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("INSERT INTO inventario(Codigo, Num_Sucursal, Producto, Entrada_Cantidad, Salida_Cantidad, Movimiento, Precio, Precio_Cliente, stock) VALUES ({0},{1},'{2}',{3},{4},'{5}',{6},{7},{8})", codigo, suc, producto, entrada, salida, movimiento, precio, precio_cli, stock), conexion.obtenerConexion());
                retorno = comando.ExecuteNonQuery();
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return retorno;
        }
        //Fin funciones agregar

        //Inicio Udates

        public static int modificar_producto(producto mod, string codigo)
        {
            int retorno = 0;
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("UPDATE productos SET codigo_bar = '{0}', nombre = '{1}', stock = {2}, precio = {3}, id_marca = {4}, id_proveedor = {5}, id_sucursal = {6} WHERE codigo_bar = '{7}'", mod.barcode, mod.nombre, mod.stock, mod.precio, mod.id_marca, mod.id_proveedor, mod.id_sucursal, codigo), conexion.obtenerConexion());
                retorno = comando.ExecuteNonQuery();
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return retorno;
        }

        public static int modificar_productoStock(string codigo, int newstock)
        {
            int retorno = 0;
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("UPDATE productos SET stock = {0} WHERE codigo_bar = '{1}'", newstock, codigo), conexion.obtenerConexion());
                retorno = comando.ExecuteNonQuery();
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return retorno;
        }

        public static int modificar_proveedor(proveedor mod, int codigo)
        {
            int retorno = 0;
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("UPDATE proveedores SET id_proveedor = {0}, nombre_proveedor = '{1}', estado_proveedor = '{2}' WHERE id_proveedor = {3}", mod.id, mod.nombre, mod.estado, codigo), conexion.obtenerConexion());
                retorno = comando.ExecuteNonQuery();
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return retorno;
        }

        //Fin Updates

        //Inicio Mostrar
        public static List<producto> Mostrar()
        {
            empleado empleado = getEmpleado();
            List<producto> productos = new List<producto>();
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("SELECT * FROM productos WHERE id_sucursal = {0}", empleado.num_suc), conexion.obtenerConexion());
                MySqlDataReader reader = comando.ExecuteReader();
                while (reader.Read())
                {
                    producto pro = new producto();
                    pro.barcode = reader.GetString(0);
                    pro.nombre = reader.GetString(1);
                    pro.stock = reader.GetInt32(2);
                    pro.precio = reader.GetDouble(3);
                    pro.id_marca = reader.GetInt32(4);
                    pro.id_proveedor = reader.GetInt32(5);
                    pro.id_sucursal = reader.GetInt32(6);
                    productos.Add(pro);
                }
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return productos;
        }

        public static List<proveedor> Mostrar_proveedores()
        {
            List<proveedor> proveedores = new List<proveedor>();
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("SELECT * FROM proveedores"), conexion.obtenerConexion());
                MySqlDataReader reader = comando.ExecuteReader();
                while (reader.Read())
                {
                    proveedor pro = new proveedor();
                    pro.id = reader.GetInt32(0);
                    pro.nombre = reader.GetString(1);
                    pro.estado = reader.GetChar(2);
                    proveedores.Add(pro);
                }
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return proveedores;
        }

        public static List<producto_venta> MostrarVentas()
        {
            empleado empleado = getEmpleado();
            List<producto_venta> productos = new List<producto_venta>();
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("SELECT codigo_bar, nombre, stock, precio FROM productos WHERE id_sucursal = {0}", empleado.num_suc), conexion.obtenerConexion());
                MySqlDataReader reader = comando.ExecuteReader();
                while (reader.Read())
                {
                    producto_venta pro = new producto_venta();
                    pro.barcode = reader.GetString(0);
                    pro.nombre = reader.GetString(1);
                    pro.stock = reader.GetInt32(2);
                    pro.precio = reader.GetDouble(3);
                    productos.Add(pro);
                }
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return productos;
        }

        public static List<inventario> MostrarInventario(string fecha, int suc)
        {
            List<inventario> inventarios = new List<inventario>();
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("SELECT * FROM inventario WHERE Fecha_Movimiento LIKE '{0}%' AND Num_Sucursal = {1}", fecha, suc), conexion.obtenerConexion());
                MySqlDataReader reader = comando.ExecuteReader();
                while (reader.Read())
                {
                    inventario inventario = new inventario();
                    inventario.codigo = reader.GetInt32(0);
                    inventario.num_suc = reader.GetInt32(1);
                    inventario.producto = reader.GetString(2);
                    inventario.entrada_cantidad = reader.GetInt32(3);
                    inventario.salida_cantidad = reader.GetInt32(4);
                    inventario.movimiento = reader.GetString(5);
                    inventario.precio = reader.GetDouble(6);
                    inventario.precio_cliente = reader.GetDouble(7);
                    inventario.stock = reader.GetInt32(8);
                    inventario.fecha = reader.GetString(9);
                    inventarios.Add(inventario);
                }
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return inventarios;
        }

        public static List<factura> MostrarFacturas(string fecha, int suc)
        {
            List<factura> facturas = new List<factura>();
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("SELECT * FROM factura WHERE fecha LIKE '{0}%' AND ID_Sucursal = {1}", fecha, suc), conexion.obtenerConexion());
                MySqlDataReader reader = comando.ExecuteReader();
                while (reader.Read())
                {
                    factura factura = new factura();
                    factura.folio = reader.GetInt32(0);
                    factura.ID_Cliente = reader.GetInt32(1);
                    factura.total = reader.GetDouble(2);
                    factura.ID_Empleado = reader.GetInt32(3);
                    factura.ID_Sucursal = reader.GetInt32(4);
                    factura.fecha = reader.GetString(5);
                    facturas.Add(factura);
                }
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return facturas;
        }

        //Fin mostrar
        public static List<producto> Buscar(string nombre)
        {
            empleado empleado = getEmpleado();
            List<producto> productos = new List<producto>();
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("SELECT * FROM productos WHERE codigo_bar = '{0}' AND id_sucursal = {1}", nombre, empleado.num_suc), conexion.obtenerConexion());
                MySqlDataReader reader = comando.ExecuteReader();
                while (reader.Read())
                {
                    producto pro = new producto();
                    pro.barcode = reader.GetString(0);
                    pro.nombre = reader.GetString(1);
                    pro.stock = reader.GetInt32(2);
                    pro.precio = reader.GetDouble(3);
                    pro.id_marca = reader.GetInt32(4);
                    pro.id_proveedor = reader.GetInt32(5);
                    pro.id_sucursal = reader.GetInt32(6);
                    productos.Add(pro);
                }
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return productos;

        }

        //Inicio obtener
        public static producto ObtenerProducto(string nombre)
        {
            producto pro = new producto();
            empleado empleado = getEmpleado();
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("SELECT * FROM productos WHERE nombre = '{0}' AND id_sucursal = {1}", nombre, empleado.num_suc), conexion.obtenerConexion());
                MySqlDataReader reader = comando.ExecuteReader();
                while (reader.Read())
                {
                    pro.barcode = reader.GetString(0);
                    pro.nombre = reader.GetString(1);
                    pro.stock = reader.GetInt32(2);
                    pro.precio = reader.GetDouble(3);
                    pro.id_marca = reader.GetInt32(4);
                    pro.id_proveedor = reader.GetInt32(5);
                    pro.id_sucursal = reader.GetInt32(6);
                }
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return pro;
        }

        public static producto ObtenerProductoCod_bar(string nombre)
        {
            producto pro = new producto();
            empleado empleado = getEmpleado();
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("SELECT * FROM productos WHERE codigo_bar = '{0}' AND id_sucursal = {1}", nombre, empleado.num_suc), conexion.obtenerConexion());
                MySqlDataReader reader = comando.ExecuteReader();
                while (reader.Read())
                {
                    pro.barcode = reader.GetString(0);
                    pro.nombre = reader.GetString(1);
                    pro.stock = reader.GetInt32(2);
                    pro.precio = reader.GetDouble(3);
                    pro.id_marca = reader.GetInt32(4);
                    pro.id_proveedor = reader.GetInt32(5);
                    pro.id_sucursal = reader.GetInt32(6);
                }
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return pro;
        }

        public static proveedor ObtenerProveedor(string nombre)
        {
            proveedor proveedor = new proveedor();
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("SELECT * FROM proveedores WHERE nombre_proveedor = '{0}'", nombre), conexion.obtenerConexion());
                MySqlDataReader reader = comando.ExecuteReader();
                while (reader.Read())
                {
                    proveedor.id = reader.GetInt32(0);
                    proveedor.nombre = reader.GetString(1);
                    proveedor.estado = reader.GetChar(2);
                }
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return proveedor;
        }

        public static proveedor ObtenerProveedorID(int id)
        {
            proveedor proveedor = new proveedor();
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("SELECT * FROM proveedores WHERE id_proveedor = {0}", id), conexion.obtenerConexion());
                MySqlDataReader reader = comando.ExecuteReader();
                while (reader.Read())
                {
                    proveedor.id = reader.GetInt32(0);
                    proveedor.nombre = reader.GetString(1);
                    proveedor.estado = reader.GetChar(2);
                }
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return proveedor;
        }

        public static int ObtenerIdDetalle()
        {
            int id = 0;
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("SELECT ID_Detalle FROM detalle ORDER BY ID_Detalle DESC"), conexion.obtenerConexion());
                MySqlDataReader reader = comando.ExecuteReader();
                if (reader.Read())
                {
                    id = reader.GetInt32(0);
                }
            }
            catch (Exception e) { MessageBox.Show("Ocurrio algo inesperado " + e); }
            return id;
        }

        //Fin obtener
        public static empleado BuscarSesion(string nombre, string contraseña)
        {
            empleado empleado = new empleado();
            try
            {
                MySqlCommand comando = new MySqlCommand(String.Format("SELECT * FROM empleados WHERE nombre = '{0}' AND contrasena = '{1}'", nombre, contraseña), conexion.obtenerConexion());
                MySqlDataReader reader = comando.ExecuteReader();
                while (reader.Read())
                {
                    empleado.codigo = reader.GetInt32(0);
                    empleado.nombre = reader.GetString(1);
                    empleado.edad = reader.GetInt32(2);
                    empleado.telefono = reader.GetString(3);
                    empleado.rfc = reader.GetString(4);
                    empleado.num_suc = reader.GetInt32(5);
                    empleado.contrasena = reader.GetString(6);
                    empleado.tipo = reader.GetChar(7);
                }
                return empleado;
            }
            catch(Exception ex)
            {
                System.Windows.Forms.MessageBox.Show("Ocurrio algo inesperado" + ex);
            }
            return empleado;
        }

        public static string GetMD5(string str)
        {
            MD5 md5 = MD5CryptoServiceProvider.Create();
            ASCIIEncoding encoding = new ASCIIEncoding();
            byte[] stream = null;
            StringBuilder sb = new StringBuilder();
            stream = md5.ComputeHash(encoding.GetBytes(str));
            for (int i = 0; i < stream.Length; i++) sb.AppendFormat("{0:x2}", stream[i]);
            return sb.ToString();
        }

    }
}
