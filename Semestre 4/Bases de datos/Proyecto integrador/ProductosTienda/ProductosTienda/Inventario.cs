using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ProductosTienda.mysql;

namespace ProductosTienda
{
    public partial class Inventario : Form
    {
        combobox cb = new combobox();
        public empleado empleado1 = new empleado();
        public Inventario()
        {
            InitializeComponent();
        }

        private void btn_logout_Click(object sender, EventArgs e)
        {
            if (String.IsNullOrEmpty(txt_codigo.Text) || String.IsNullOrEmpty(txt_ecant.Text) || String.IsNullOrEmpty(txt_movimiento.Text) || String.IsNullOrEmpty(txt_precio.Text) || String.IsNullOrEmpty(txt_preciocli.Text) || String.IsNullOrEmpty(txt_producto.Text) || String.IsNullOrEmpty(txt_scant.Text) || String.IsNullOrEmpty(txt_stock.Text))
            {
                MessageBox.Show("Procure llenar todo el formulario");
            }
            else 
            {
                producto producto = new producto();
                empleado1 = funciones.getEmpleado();

                producto = funciones.ObtenerProducto(txt_producto.Text);
                producto.precio = Convert.ToDouble(txt_preciocli.Text);
                producto.stock = Convert.ToInt32(txt_stock.Text);

                proveedor proveedor = funciones.ObtenerProveedorID(producto.id_proveedor);
                if(proveedor.estado == 'A')
                {
                    if (producto.id_sucursal == empleado1.num_suc)
                    {
                        int codigo, suc, entrada, salida, stock;
                        double precio, precio_cli;
                        string name, Movimiento;
                        codigo = Convert.ToInt32(txt_codigo.Text);
                        suc = empleado1.num_suc;
                        entrada = Convert.ToInt32(txt_ecant.Text);
                        salida = Convert.ToInt32(txt_scant.Text);
                        stock = Convert.ToInt32(txt_stock.Text);
                        precio = Convert.ToDouble(txt_precio.Text);
                        precio_cli = Convert.ToDouble(txt_preciocli.Text);
                        name = txt_producto.Text;
                        Movimiento = txt_movimiento.Text;
                        int retorno = funciones.agregar_inventario(codigo, suc, name, entrada, salida, Movimiento, precio, precio_cli, stock);
                        funciones.modificar_producto(producto, producto.barcode);
                        if (retorno > 0)
                        {
                            MessageBox.Show("Registrado con exito!");
                        }
                        else
                        {
                            MessageBox.Show("Hubo algun error");
                        }
                    }
                    else
                    {
                        MessageBox.Show("El producto indicado no se encuentra disponible en tu sucursal.");
                    }
                }
                else
                {
                    MessageBox.Show("El proveedor esta inactivo no se pueden realizar movimientos");
                }
            }
            limpiar();
        }

        public void limpiar()
        {
            txt_codigo.Clear();
            txt_ecant.Clear();
            txt_movimiento.Clear();
            txt_precio.Clear();
            txt_preciocli.Clear();
            txt_producto.Clear();
            txt_scant.Clear();
            txt_stock.Clear();
        }

        private void groupBox1_Enter(object sender, EventArgs e){  }

        private void label9_Click(object sender, EventArgs e) { }

        private void label5_Click(object sender, EventArgs e) { }
    }
}
