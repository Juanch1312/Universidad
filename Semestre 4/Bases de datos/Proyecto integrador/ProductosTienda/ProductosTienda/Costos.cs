using MySql.Data.MySqlClient;
using ProductosTienda.mysql;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProductosTienda
{
    public partial class Costos : Form
    {
        public Costos()
        {
            InitializeComponent();
            txt_buscar.Focus();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            empleado empleado = funciones.getEmpleado();
            if (String.IsNullOrEmpty(txt_buscar.Text))
            {
                dvg_costos.DataSource = funciones.Mostrar();
            }
            else
            {
                dvg_costos.DataSource = funciones.Buscar(txt_buscar.Text);
            }
        }

        private void txt_buscar_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)Keys.Enter)
            {
                button2.Focus();
            }
        }
    }
}
