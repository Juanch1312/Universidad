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
    public partial class Inicio : Form
    {
        public static empleado empleado1 = new empleado();
        public Inicio()
        {
            empleado1 = funciones.getEmpleado();
            string nombre = empleado1.nombre;
            InitializeComponent();
            label1.Text = String.Format("Bienvenido {0}",nombre);
        }

        
    }
}
