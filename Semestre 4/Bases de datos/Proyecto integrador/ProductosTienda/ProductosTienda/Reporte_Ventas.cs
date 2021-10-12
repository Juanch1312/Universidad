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
    public partial class Reporte_Ventas : Form
    {
        public static empleado empleado1 = new empleado();
        public Reporte_Ventas()
        {
            InitializeComponent();
        }

        private void btn_buscar_Click(object sender, EventArgs e)
        {
            empleado1 = funciones.getEmpleado();
            string mes = dtp_buscar.Value.Month.ToString();
            string year = dtp_buscar.Value.Year.ToString();
            string resultado = year + "-" + mes;
            dgv_ventas.DataSource = funciones.MostrarFacturas(resultado, empleado1.num_suc);
        }
    }
}
