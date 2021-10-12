using ProductosTienda.mysql;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProductosTienda
{
    public partial class Productos : Form
    {
        public static empleado empleado1 = new empleado();
        public Productos()
        {
            InitializeComponent();
        }

        public static string codigo;

        //Mover ventana
        [DllImport("user32.DLL", EntryPoint = "ReleaseCapture")]
        private extern static void ReleaseCapture();
        [DllImport("user32.DLL", EntryPoint = "SendMessage")]
        private extern static void SendMessage(System.IntPtr hWnd, int wMsg, int wParam, int IParam);

        //Fin mover ventana

        private void barraTitulo_MouseDown(object sender, MouseEventArgs e)
        {
            ReleaseCapture();
            SendMessage(this.Handle, 0x112, 0xf012, 0);
        }

        private void barraTitulo_Paint(object sender, PaintEventArgs e)
        {

        }

        private void btn_minimizar_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized;
        }

        private void btn_recortar_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Normal;
            btn_maximizar.Visible = true;
            btn_recortar.Visible = false;
        }

        private void btn_maximizar_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Maximized;
            btn_maximizar.Visible = false;
            btn_recortar.Visible = true;
        }

        private void btn_cerrar_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(String.IsNullOrEmpty(txt_buscar.Text))
            {
                dgv_editar.DataSource = funciones.Mostrar();
            }
            else
            {
                dgv_editar.DataSource = funciones.Buscar(txt_buscar.Text);
            }
        }

        private void btn_seleccionar_Click(object sender, EventArgs e)
        {
            if(dgv_editar.SelectedRows.Count == 1)
            {
                int columna;
                columna = dgv_editar.CurrentRow.Index;
                txt_cod.Text = dgv_editar.Rows[columna].Cells[0].Value.ToString();
                txt_nombre.Text = dgv_editar.Rows[columna].Cells[1].Value.ToString();
                txt_stock.Text = dgv_editar.Rows[columna].Cells[2].Value.ToString();
                txt_precio.Text = dgv_editar.Rows[columna].Cells[3].Value.ToString();
                txt_marca.Text = dgv_editar.Rows[columna].Cells[4].Value.ToString();
                txt_proveedor.Text = dgv_editar.Rows[columna].Cells[5].Value.ToString();
                txt_sucursal.Text = dgv_editar.Rows[columna].Cells[6].Value.ToString();
                codigo = txt_cod.Text;
            }
        }

        private void btn_login_Click(object sender, EventArgs e)
        {
            empleado1 = funciones.getEmpleado();
            if (String.IsNullOrEmpty(txt_sucursal.Text) || String.IsNullOrEmpty(txt_cod.Text) || String.IsNullOrEmpty(txt_marca.Text) || String.IsNullOrEmpty(txt_nombre.Text) || String.IsNullOrEmpty(txt_precio.Text) || String.IsNullOrEmpty(txt_proveedor.Text) || String.IsNullOrEmpty(txt_stock.Text))
            {
                MessageBox.Show("Asegurese de llenar todo el formulario");
            }
            else
            {
                producto producto = new producto(txt_cod.Text, txt_nombre.Text, Convert.ToInt32(txt_stock.Text), Convert.ToDouble(txt_precio.Text), Convert.ToInt32(txt_marca.Text), Convert.ToInt32(txt_proveedor.Text), Convert.ToInt32(txt_sucursal.Text));
                if(empleado1.num_suc == producto.id_sucursal)
                {
                    int retorno = funciones.modificar_producto(producto, codigo);
                    if (retorno > 0)
                    {
                        lb_modsuss.Visible = true;
                    }
                    else
                    {
                        lb_moderr.Visible = true;
                    }
                }
                else
                {
                    MessageBox.Show("No puedes modificar el producto, ya que la sucursal (MODIFICADA O ACTUAL) no pertenece a la tuya");
                }
            }
        }
    }
}
