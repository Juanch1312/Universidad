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
    public partial class Proveedores : Form
    {
        public Proveedores()
        {
            InitializeComponent();
            dgv_mostrar.DataSource = funciones.Mostrar_proveedores();
        }

        public static int codigo;

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

        private void btn_minimizar_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized;
        }

        private void btn_cerrar_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btn_seleccionar_Click(object sender, EventArgs e)
        {
            lb_modsuss.Visible = false;
            lb_moderr.Visible = false;
            if (dgv_mostrar.SelectedRows.Count == 1)
            {
                int columna = 0;
                columna = dgv_mostrar.CurrentRow.Index;
                codigo = Convert.ToInt32(dgv_mostrar.Rows[columna].Cells[0].Value.ToString());
                txt_nombre.Text = dgv_mostrar.Rows[columna].Cells[1].Value.ToString();
                txt_estado.Text = dgv_mostrar.Rows[columna].Cells[2].Value.ToString();
            }
            else
            {
                MessageBox.Show("Seleccione una columna");
            }
        }

        private void btn_aceptar_Click(object sender, EventArgs e)
        {
            if (String.IsNullOrEmpty(txt_nombre.Text) || String.IsNullOrEmpty(txt_estado.Text))
            {
                MessageBox.Show("Asegurese de llenar todo el formulario");
                limpiar();
            }
            else
            {
                proveedor proveedor = new proveedor(codigo, txt_nombre.Text, txt_estado.Text[0]);
                int retorno = funciones.modificar_proveedor(proveedor, codigo);
                if (retorno > 0)
                {
                    lb_modsuss.Visible = true;
                }
                else
                {
                    lb_moderr.Visible = true;
                }
                limpiar();
            }
        }
        public void limpiar()
        {
            txt_estado.Clear();
            txt_nombre.Clear();
        }
    }
}
