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
    public partial class Login : Form
    {
        public Login()
        {
            InitializeComponent();
            label_sucessfull.Visible = false;
            label_error.Visible = false;
        }
        empleado emp = new empleado();

        //Mover ventana
        [DllImport("user32.DLL", EntryPoint = "ReleaseCapture")]
        private extern static void ReleaseCapture();
        [DllImport("user32.DLL", EntryPoint = "SendMessage")]
        private extern static void SendMessage(System.IntPtr hWnd, int wMsg, int wParam, int IParam);

        //Fin mover ventana

        private void btn_login_Click(object sender, EventArgs e)
        {
            string crypto = funciones.GetMD5(txt_password.Text);
            emp = funciones.BuscarSesion(txt_user.Text, crypto);
            if (txt_user.Text == emp.nombre && crypto == emp.contrasena && emp.tipo == 'S')
            {
                label_sucessfull.Visible = true;
                funciones.setEmpleado(emp);
                Index_admin form = new Index_admin();
                this.Hide();
                form.ShowDialog();
                this.Close();
            }
            if (txt_user.Text == emp.nombre && crypto == emp.contrasena && emp.tipo == 'E')
            {
                label_sucessfull.Visible = true;
                funciones.setEmpleado(emp);
                Index_usuario form = new Index_usuario();
                this.Hide();
                form.ShowDialog();
                this.Close();
            }
            txt_user.Clear();
            txt_password.Clear();
            label_error.Visible = true;
        }

        private void btn_cerrar_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void btn_minimizar_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized;
        }

        private void Login_Load(object sender, EventArgs e)
        {

        }

        private void barraTitulo_Paint(object sender, PaintEventArgs e)
        {

        }

        private void barraTitulo_MouseDown(object sender, MouseEventArgs e)
        {
            ReleaseCapture();
            SendMessage(this.Handle, 0x112, 0xf012, 0);
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
