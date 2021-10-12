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
    public partial class Index_usuario : Form
    {
        public Index_usuario()
        {
            InitializeComponent();
        }
        private void Index_usuario_Load(object sender, EventArgs e)
        {
            OpenForm(new Inicio());
        }

        //Mover ventana
        [DllImport("user32.DLL", EntryPoint = "ReleaseCapture")]
        private extern static void ReleaseCapture();
        [DllImport("user32.DLL", EntryPoint = "SendMessage")]
        private extern static void SendMessage(System.IntPtr hWnd, int wMsg, int wParam, int IParam);

        //Fin mover ventana

        private void btn_cerrar_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void btn_recortar_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Normal;
        }

        private void btn_maximizar_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Maximized;
        }

        private void btn_minimizar_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized;
        }

        private void barraTitulo_MouseDown(object sender, MouseEventArgs e)
        {
            ReleaseCapture();
            SendMessage(this.Handle, 0x112, 0xf012, 0);
        }

        private void btn_logout_Click(object sender, EventArgs e)
        {
            btn_logout.Visible = false;
            Login login = new Login();
            this.Hide();
            login.ShowDialog();
            this.Close();
        }

        private void OpenForm(object son)
        {
            if (panelContenedor.Controls.Count > 0)
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

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            OpenForm(new Inicio());
        }

        private void btn_venta_Click(object sender, EventArgs e)
        {
            OpenForm(new Ventas());
        }

        private void btn_costos_Click(object sender, EventArgs e)
        {
            OpenForm(new Costos());
        }
    }
}
