namespace ProductosTienda
{
    partial class modificar
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(modificar));
            this.label1 = new System.Windows.Forms.Label();
            this.btn_modproductos = new System.Windows.Forms.Button();
            this.btn_modprovedores = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft YaHei UI", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(313, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(173, 42);
            this.label1.TabIndex = 4;
            this.label1.Text = "Modificar";
            // 
            // btn_modproductos
            // 
            this.btn_modproductos.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(134)))), ((int)(((byte)(14)))), ((int)(((byte)(152)))));
            this.btn_modproductos.FlatAppearance.BorderSize = 0;
            this.btn_modproductos.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btn_modproductos.Font = new System.Drawing.Font("Microsoft YaHei UI", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_modproductos.ForeColor = System.Drawing.Color.White;
            this.btn_modproductos.Location = new System.Drawing.Point(94, 209);
            this.btn_modproductos.Name = "btn_modproductos";
            this.btn_modproductos.Size = new System.Drawing.Size(202, 68);
            this.btn_modproductos.TabIndex = 11;
            this.btn_modproductos.Text = "Productos";
            this.btn_modproductos.UseVisualStyleBackColor = false;
            this.btn_modproductos.Click += new System.EventHandler(this.btn_modproductos_Click);
            // 
            // btn_modprovedores
            // 
            this.btn_modprovedores.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(134)))), ((int)(((byte)(14)))), ((int)(((byte)(152)))));
            this.btn_modprovedores.FlatAppearance.BorderSize = 0;
            this.btn_modprovedores.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btn_modprovedores.Font = new System.Drawing.Font("Microsoft YaHei UI", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_modprovedores.ForeColor = System.Drawing.Color.White;
            this.btn_modprovedores.Location = new System.Drawing.Point(502, 209);
            this.btn_modprovedores.Name = "btn_modprovedores";
            this.btn_modprovedores.Size = new System.Drawing.Size(202, 68);
            this.btn_modprovedores.TabIndex = 12;
            this.btn_modprovedores.Text = "Provedores";
            this.btn_modprovedores.UseVisualStyleBackColor = false;
            this.btn_modprovedores.Click += new System.EventHandler(this.btn_modprovedores_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft YaHei UI", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(202, 130);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(401, 36);
            this.label2.TabIndex = 13;
            this.label2.Text = "Seleccione dato a modificar:";
            // 
            // modificar
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(3)))), ((int)(((byte)(50)))));
            this.ClientSize = new System.Drawing.Size(800, 470);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.btn_modprovedores);
            this.Controls.Add(this.btn_modproductos);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "modificar";
            this.Text = "modificar";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btn_modproductos;
        private System.Windows.Forms.Button btn_modprovedores;
        private System.Windows.Forms.Label label2;
    }
}