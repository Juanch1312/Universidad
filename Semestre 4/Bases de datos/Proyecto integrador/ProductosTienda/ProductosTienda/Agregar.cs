using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;
using ProductosTienda.mysql;

namespace ProductosTienda
{

    public partial class Agregar : Form
    {
        combobox cb = new combobox();
        public Agregar()
        {
            InitializeComponent();
            cb.seleccionar_marcas(combox_marcas);
            cb.seleccionar_sucursal(cb_sucursal);
            cb.seleccionar_proveedor(cb_proveedor);
        }




        private void combox_marcas_SelectedIndexChanged(object sender, EventArgs e)
        { 
        }

        private void btn_agregar_Click(object sender, EventArgs e)
        {
            if(combox_marcas.Text != "Seleccione" && cb_proveedor.Text != "Seleccione" && cb_sucursal.Text != "Seleccione")
            {
                proveedor proveedor1 = funciones.ObtenerProveedor(cb_proveedor.Text);
                empleado actual = funciones.getEmpleado();
                if(proveedor1.estado == 'A')
                {
                    if(actual.num_suc == cb_sucursal.SelectedIndex + 1)
                    {
                        if (String.IsNullOrEmpty(txt_codbar.Text) || String.IsNullOrEmpty(txt_nombre.Text) || String.IsNullOrEmpty(txt_precio.Text) || String.IsNullOrEmpty(txt_stock.Text))
                        {
                            MessageBox.Show("Asegurese de llenar todo el formulario");
                        }
                        else
                        {
                            int marca, proveedor, sucursal;
                            producto pro = new producto();
                            try
                            {
                                pro.barcode = txt_codbar.Text;
                                pro.nombre = txt_nombre.Text;
                                pro.stock = Convert.ToInt32(txt_stock.Text);
                                pro.precio = Convert.ToDouble(txt_precio.Text);

                                marca = combox_marcas.SelectedIndex + 1;
                                pro.id_marca = marca;
                                proveedor = cb_proveedor.SelectedIndex + 1;
                                pro.id_proveedor = proveedor;
                                sucursal = cb_sucursal.SelectedIndex + 1;
                                pro.id_sucursal = sucursal;

                                int retorno = funciones.agregar(pro);
                                if (retorno > 0)
                                {
                                    MessageBox.Show("Registro de producto exitoso!");
                                }
                                else
                                {
                                    MessageBox.Show("Hubo algun error :c");
                                }
                            }
                            catch(Exception ex) { MessageBox.Show("Ocurrio algun error"); }
                        }
                    }
                    else
                    {
                        MessageBox.Show("La sucursal seleccionada no concuerda con la del empleado");
                    }
                }
                else
                {
                    MessageBox.Show("El proveedor seleccionado esta Inactivo \n Porfavor seleccione otro");
                }
            }
            else
            {
                MessageBox.Show("Asegurese de llenar todo el formulario");
            }
            limpiar();
        }

        public void limpiar()
        {
            txt_codbar.Clear();
            txt_nombre.Clear();
            txt_precio.Clear();
            txt_stock.Clear();
            cb_proveedor.Text = "Seleccione";
            cb_sucursal.Text = "Seleccione";
            combox_marcas.Text = "Seleccione";
        }

        private void cb_proveedor_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void txt_codbar_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(e.KeyChar == (char)Keys.Enter)
            {
                empleado empleado = funciones.getEmpleado();
                MySqlCommand command = new MySqlCommand(String.Format("SELECT codigo_bar FROM productos WHERE codigo_bar = '{0}' AND id_sucursal = {1}", txt_codbar.Text, empleado.num_suc), conexion.obtenerConexion());
                MySqlDataReader reader = command.ExecuteReader();
                if (reader.Read())
                {
                    MessageBox.Show("Ya existe este producto");
                    txt_codbar.Clear();
                    txt_codbar.Focus();
                }
                else
                {
                    txt_nombre.Focus();
                }
                
            }
        }
    }
}
