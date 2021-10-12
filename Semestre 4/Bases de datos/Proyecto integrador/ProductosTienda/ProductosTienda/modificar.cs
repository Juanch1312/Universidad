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
    public partial class modificar : Form
    {
        public modificar()
        {
            InitializeComponent();
        }

        private void btn_modproductos_Click(object sender, EventArgs e)
        {
            Productos productos = new Productos();
            this.Hide();
            productos.Show();
            this.Show();
        }

        private void btn_modprovedores_Click(object sender, EventArgs e)
        {
            Proveedores proveedores = new Proveedores();
            this.Hide();
            proveedores.Show();
            this.Show();
        }
    }
}
