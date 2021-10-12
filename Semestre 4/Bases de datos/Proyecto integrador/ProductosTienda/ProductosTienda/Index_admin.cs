using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Windows.Forms.VisualStyles;
using ProductosTienda.mysql;

namespace ProductosTienda
{
    public partial class Index_admin : Form
    {
        public Index_admin()
        {
            InitializeComponent();
        }


        private void Form1_Load(object sender, EventArgs e)
        {
            OpenForm(new Inicio());
        }

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


        private void pictureBox1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void btn_maximizar_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Maximized;
            btn_maximizar.Visible = false;
            btn_recortar.Visible = true;
        }

        private void btn_recortar_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Normal;
            btn_maximizar.Visible = true;
            btn_recortar.Visible = false;
        }

        private void btn_minimizar_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized;
        }
        private void pictureBox1_Click_1(object sender, EventArgs e)
        {
            OpenForm(new Inicio());
        }

        private void btn_agregar_Click(object sender, EventArgs e)
        {
            panelSubmenu.Visible = false;
            OpenForm(new Agregar());
        }

        private void btn_reportes_Click(object sender, EventArgs e)
        {
            if(panelSubmenu.Visible == false){
                panelSubmenu.Visible = true;
            }
            else
            {
                panelSubmenu.Visible = false;
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            panelSubmenu.Visible = false;
            OpenForm(new Reporte_Ventas());
        }

        private void button1_Click(object sender, EventArgs e)
        {
            panelSubmenu.Visible = false;
            OpenForm(new Reporte_Inventario());
        }

        private void btn_venta_Click(object sender, EventArgs e)
        {
            panelSubmenu.Visible = false;
            OpenForm(new Ventas());
        }

        private void btn_costos_Click(object sender, EventArgs e)
        {
            panelSubmenu.Visible = false;
            OpenForm(new Costos());
        }

        private void btn_inventario_Click(object sender, EventArgs e)
        {
            panelSubmenu.Visible = false;
            OpenForm(new Inventario());
        }

        private void OpenForm(object son)
        {
            if(panelContenedor.Controls.Count > 0)
            {
                this.panelContenedor.Controls.RemoveAt(0);
            }
            Form form = son as Form;
            form.TopLevel = false;
            form.Dock = DockStyle.Fill;
            this.panelContenedor.Controls.Add(form);
            this.panelContenedor.Tag = form;
            form.Show();
        }

        //Activar y desactivar botones 

        //Logout
        private void btn_logout_Click(object sender, EventArgs e)
        {
            btn_logout.Visible = false;
            Login login = new Login();
            this.Hide();
            login.ShowDialog();
            this.Close();
        }

        private void btn_inventario_Click_1(object sender, EventArgs e)
        {
            panelSubmenu.Visible = false;
            OpenForm(new modificar());
        }
    }
}
