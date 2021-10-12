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
    public partial class Reporte_Inventario : Form
    {
        public static empleado empleado1 = new empleado();
        public Reporte_Inventario()
        {
            InitializeComponent();
        }

        private void btn_buscar_Click(object sender, EventArgs e)
        {
            string resultante;
            empleado1 = funciones.getEmpleado();
            string mes = dtp_buscar.Value.Month.ToString();
            string year = dtp_buscar.Value.Year.ToString();
            if(Convert.ToInt32(mes) > 9)
            {
                resultante = year + "-" + mes;
            }
            else
            {
                resultante = year + "-0" + mes;
            }
            dgv_inventario.DataSource = funciones.MostrarInventario(resultante, empleado1.num_suc);
        }
    }
}
