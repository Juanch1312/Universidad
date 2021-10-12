using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySqlX.XDevAPI.Relational;
using ProductosTienda.mysql;

namespace ProductosTienda
{
    public partial class Ventas : Form
    {
        public static empleado empleado1 = new empleado();
        combobox cb = new combobox();
        public Ventas()
        {
            InitializeComponent();
            empleado1 = funciones.getEmpleado();
            cb.seleccionar_cliente(combobox_cliente);
            btn_vender.Visible = false;
        }
        public int contador = 0;
        producto producto_actual = new producto();

        private void Ventas_Load(object sender, EventArgs e)
        {

        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void btn_buscar_Click(object sender, EventArgs e)
        {
            if (String.IsNullOrEmpty(txt_nombre.Text))
            {
                dgv_productos.DataSource = funciones.MostrarVentas();
            }
            else
            {
                dgv_productos.DataSource = funciones.Buscar(txt_nombre.Text);
            }
        }

        private void btn_aceptar_Click(object sender, EventArgs e)
        {
                if (!String.IsNullOrEmpty(txt_cantidad.Text))
                {
                    if (dgv_productos.SelectedRows.Count == 1)
                    {
                        double total = 0, cantidad = 0;
                        cantidad += Convert.ToInt32(txt_cantidad.Text);
                        string id = Convert.ToString(dgv_productos.CurrentRow.Cells[1].Value);
                        producto_actual = funciones.ObtenerProducto(id);

                        if (producto_actual.id_sucursal == empleado1.num_suc)
                        {
                            if (cantidad > producto_actual.stock)
                            {
                                MessageBox.Show("La cantidad de venta rebasa el stock");
                            }
                            else
                            {
                                total = producto_actual.precio * cantidad;
                                dgv_venta.Rows.Add();
                                dgv_venta.Rows[contador].Cells[0].Value = producto_actual.barcode;
                                dgv_venta.Rows[contador].Cells[1].Value = producto_actual.nombre;
                                dgv_venta.Rows[contador].Cells[2].Value = cantidad;
                                dgv_venta.Rows[contador].Cells[3].Value = total;
                                contador++;
                                btn_vender.Visible = true;
                            }
                        }
                        else
                        {
                            MessageBox.Show("El producto seleccionado no se encuentra en tu sucursal");
                        }
                    }
                }
                else
                {
                    MessageBox.Show("Ingrese una cantidad a vender porfavor");
                }
        }
        //Aqui es zona de peligro
        private void btn_vender_Click(object sender, EventArgs e)
        {
            if(combobox_cliente.Text == "Seleccione")
            {
                MessageBox.Show("Seleccione un cliente para realizar la venta");
            }
            else
            {
                int contador = 0;
                double total = 0;
                ArrayList arr_bar = new ArrayList();
                ArrayList arr_cant = new ArrayList();
                ArrayList arr_subtotal = new ArrayList();
                //Paso 1: Obtener los de el DataGridView a una lista (de productos)
                while (true)
                {
                    if (dgv_venta.Rows[contador].Cells[1].Value == null) { break; }
                    else
                    {
                        arr_bar.Add(dgv_venta.Rows[contador].Cells[0].Value.ToString());
                        arr_cant.Add(Convert.ToInt32(dgv_venta.Rows[contador].Cells[2].Value.ToString()));
                        arr_subtotal.Add(Convert.ToDouble(dgv_venta.Rows[contador].Cells[3].Value.ToString()));
                        total += Convert.ToDouble(dgv_venta.Rows[contador].Cells[3].Value.ToString());
                    }
                    contador++;
                }
                //Paso 2: Leer el archivo que contiene el ultimo id de detalle,
                //Pasar los datos a la tabla detalle
                int id = funciones.ObtenerIdDetalle() + 1;
                producto producto = new producto();
                for (int i = 0; i < arr_bar.Count; i++)
                {
                    //Agregar todo lo del carrito a la tabla detalle y modificar el stock del producto vendido
                    funciones.agregar_detalle(id, arr_bar[i].ToString(), Convert.ToInt32(arr_cant[i]), Convert.ToDouble(arr_subtotal[i]));
                    producto = funciones.ObtenerProductoCod_bar(arr_bar[i].ToString());
                    funciones.modificar_productoStock(arr_bar[i].ToString(), (producto.stock - Convert.ToInt32(arr_cant[i])));
                }
                //Paso 3: Agregar registros a el resto de tablas
                //Agregar Factura
                int cliente = combobox_cliente.SelectedIndex + 1;
                total += (total * 0.16); //IVA
                funciones.agregar_factura(id, cliente, total, empleado1.codigo, empleado1.num_suc);

                //Agregar detalle_factura
                funciones.agregar_detalle_factura(id, id);

                //Agregar empleado_detalle
                funciones.agregar_empleado_detalle(empleado1.codigo, id);

                //Limpimpieza de memoria
                arr_bar.Clear();
                arr_cant.Clear();
                arr_subtotal.Clear();
                txt_cantidad.Clear();
                txt_nombre.Clear();
                dgv_venta.Rows.Clear();
                dgv_productos.Refresh();
                combobox_cliente.Text = "Seleccione";
                btn_vender.Visible = false;
            }
        }

        private void txt_nombre_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)Keys.Enter)
            {
                btn_buscar.Focus();
            }
        }

        private void txt_nombre_TextChanged(object sender, EventArgs e)
        {

        }
        //Termina zona de peligro
    }
}
