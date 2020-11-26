/*
 * BD.c
 * 
 * Copyright 2020 Esteban<esteban@Gigabyte>
 * 
 * This program is free software; you can redistribute it and /or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * gcc -Wall -o "%e" "%f" `pkg-config --cflags --libs gtk+-3.0` $(mysql_config --cflags) $(mysql_config --libs)  `pkg-config --cflags --libs gtksourceview-4` -rdynamic -lm
 */

#include <stdio.h>
#include <gtk/gtk.h>
#include <mysql.h> 
#include <stdlib.h>
#include <gtksourceview/gtksource.h>

GtkBuilder      	*builder; 
GtkWidget   	    *window_login;
GtkEntry 			*g_Entry_Usuario;
GtkEntry 			*g_Entry_Contraseña;
GtkToggleButton		*mostrar_calendario;
GtkEntry			*entry_buscar;
GtkEntry			*ety_idpro;
GtkEntry			*ety_idemp;
GtkEntry			*ety_catidad;
GtkEntry			*ety_precio;
GtkEntry			*ety_mpago;
GtkEntry			*ety_desc;
GtkEntry			*ety_total;

GtkEntry			*id_fac_act;
GtkEntry			*ety_profac_act;
GtkEntry			*ety_empfact_act;
GtkEntry			*ety_cantidafac_act;
GtkEntry			*ety_preci_act;
GtkEntry			*ety_mpago_act;
GtkEntry			*ety_descfac_act1;
GtkEntry			*ety_totalfac_act;

GtkEntry			*ety_produ_emp;
GtkEntry			*ety_nombreemp;
GtkEntry			*ety_direccion;
GtkEntry			*ety_telefono;
GtkEntry			*ety_region;
GtkEntry			*ety_pais;
GtkEntry			*ety_rfc;
GtkEntry			*ety_correoemp;

GtkEntry			*ety_nombrepro;
GtkEntry			*ety_marcapro;
GtkEntry			*ety_nlote;
GtkEntry			*ety_des;
GtkEntry			*ety_cbarra;
GtkEntry			*ety_cneto;

GtkEntry			*ety_id_empresa;
GtkEntry			*ety_id_producto;
GtkEntry			*ety_nombre_act;
GtkEntry			*ety_direccion_act;
GtkEntry			*ety_telefono_act;
GtkEntry			*ety_region_act;
GtkEntry			*ety_pais_act;
GtkEntry			*ety_rfc_act;
GtkEntry			*ety_correo_act;

GtkEntry			*ety_idpro_act;
GtkEntry			*ety_nombrepro_act;
GtkEntry		 	*ety_marcapro_act;
GtkEntry			*ety_nlotepro_act;
GtkEntry			*ety_descpro_act;
GtkEntry			*ety_cbarrapro_act;
GtkEntry			*ety_cnetopro_act;

GtkEntry			*ety_id_fac_borrar;
GtkEntry			*ety_id_emp_borrar;
GtkEntry			*ety_id_pro_borrar;
GtkWidget 			*g_Dialog_Error;
GtkWidget			*window_BD;
GtkWidget			*inserta_factura;
GtkWidget			*inserta_producto;
GtkWidget			*inserta_empresa;	
GtkWidget			*actualiza_factura;
GtkWidget			*actualiza_producto;
GtkWidget			*actualiza_empresa;
GtkWidget 			*pop_delete_fac;
GtkWidget 			*pop_delete_emp;
GtkWidget 			*pop_delete_pro;

GtkWidget 			*info_eliminado;
GtkWidget 			*info_ananido;
GtkWidget 			*info_actualizar;

GtkWidget			*win_acercade;
GtkWidget			*source_code;
GtkWidget			*pop_calendario;
GtkLabel			*La_lbl_Titulo_BD;
GtkLabel			*La_Label_Error_ingreso;
GtkWidget			*lbl_no_datos;
GtkLabel			*lbl_añadir_advertencia;
GtkLabel			*lbl_eliminar_advertencia;
GtkLabel			*lbl_error;
GtkWidget			*cb_anio_fac;
GtkWidget			*cb_mes_fac;
GtkWidget			*cb_dia_fac;
GtkWidget			*cb_anio_pro;
GtkWidget			*cb_mes_pro;
GtkWidget			*cb_dia_pro;
GtkWidget			*cb_anio_propro;
GtkWidget			*cb_mes_propro;
GtkWidget			*cb_dia_propro;
GtkToggleButton		*btn_eliminar_datos;
GtkWidget			*cb_anio_fac_actu;
GtkWidget			*cb_mes_fac_actu;
GtkWidget			*cb_dia_fac_actu;

GtkWidget			*cb_dia_proact;
GtkWidget			*cb_mes_proact;
GtkWidget			*cb_anio_proact;

GtkWidget			*cb_dia_proact2;
GtkWidget			*cb_mes_proact2;
GtkWidget			*cb_anio_proact2;

GtkWidget			*menu_items;
GtkWidget			*tabla_items;
GtkWidget			*muestra_func;
GtkWidget			*switchgtk;
GtkWidget			*stack_sql;
GtkWidget			*stack_historial;
GtkWidget			*stack_aceptar;
GtkWidget	 		*exportar_pdf;
GtkWidget			*btn_sql_aceptar;
GtkWidget			*ocultar_btn;
GtkWidget       	*view;
GtkWidget       	*view2;
GtkWidget       	*view3;
GtkWidget       	*view4;
GtkWidget       	*view5;
GtkWidget       	*view6;
GtkWidget			*dialog_error_datos;
GtkWidget			*view_busc;
GtkWidget			*stack_busqueda;
GtkWidget			*stack_pdf;
GtkWidget			*stack_func;
GtkWidget			*oculta_funcion;
GtkWidget			*oculta_pdf;
GtkWidget			*contenedor_historial;
GtkWidget			*contenedor_busqueda;
GtkWidget			*historial_busqueda;
GtkWidget       	*debug;
GtkCalendar			*calendario_factura;
GtkTextBuffer 		*textbuffer_main;
GtkTextView			*debug_textview;
GtkWidget       	*advertencia_añadir_fac;
GtkWidget       	*advertencia_añadir_pro;
GtkWidget       	*advertencia_añadir_emp;
GtkWidget 			*advertencia_actualizar_emp;
GtkWidget       	*advertencia_actualizar_fac;
GtkWidget       	*advertencia_actualizar_pro;
GtkWidget       	*advertencia_eliminar_fac;
GtkWidget       	*advertencia_eliminar_emp;
GtkWidget       	*advertencia_eliminar_pro;
GtkWidget			*contenedor_view;
GtkWidget			*contenedor_view2;
GtkWidget			*contenedor_view3;
GtkWidget			*contenedor_view4;
GtkWidget			*contenedor_view5;
GtkWidget			*contenedor_view6;
GtkWidget			*contenedor_sql;
GtkWidget       	*stackgtk;
MYSQL 				*conn;
MYSQL_RES 			*res;
MYSQL_ROW 			row;
GtkListStore  		*store;
GtkTreeIter    		iter;
GtkTreeIter    		iter2;
GtkTreeIter    		iter3;
GtkTreeIter    		iter4;
GtkTreeIter    		iter5;
GtkTreeIter    		iter6;
GtkTreeIter    		iter_busqueda;
GtkCellRenderer     *renderer;
GtkCellRenderer     *renderer2;
GtkCellRenderer     *renderer3;
GtkCellRenderer     *renderer4;
GtkCellRenderer     *renderer5;
GtkCellRenderer     *renderer6;
GtkTreeModel        *model;
GtkTreeModel        *model2;
GtkTreeModel        *model3;
GtkTreeModel        *model4;
GtkTreeModel        *model5;
GtkTreeModel        *model6;
GtkTreeModel        *model_busc;
GtkListStore  		*store2;
GtkListStore  		*store3;
GtkListStore  		*store4;
GtkListStore  		*store5;
GtkListStore  		*store6;
GtkListStore  		*store_busqueda;

GtkTreeViewColumn 	*column_emp;
GtkTreeViewColumn 	*column_emp2;
GtkTreeViewColumn 	*column_emp3;
GtkTreeViewColumn 	*column_emp4;
GtkTreeViewColumn 	*column_emp5;
GtkTreeViewColumn 	*column_emp6;
GtkTreeViewColumn 	*column_emp7;
GtkTreeViewColumn 	*column_emp8;
GtkTreeViewColumn 	*column_emp9;

GtkTreeViewColumn 	*column_fac;
GtkTreeViewColumn 	*column_fac2;
GtkTreeViewColumn 	*column_fac3;
GtkTreeViewColumn 	*column_fac4;
GtkTreeViewColumn 	*column_fac5;
GtkTreeViewColumn 	*column_fac6;
GtkTreeViewColumn 	*column_fac7;
GtkTreeViewColumn 	*column_fac8;
GtkTreeViewColumn 	*column_fac9;

GtkTreeViewColumn 	*column_pro;
GtkTreeViewColumn 	*column_pro2;
GtkTreeViewColumn 	*column_pro3;
GtkTreeViewColumn 	*column_pro4;
GtkTreeViewColumn 	*column_pro5;
GtkTreeViewColumn 	*column_pro6;
GtkTreeViewColumn 	*column_pro7;
GtkTreeViewColumn 	*column_pro8;
GtkTreeViewColumn 	*column_pro9;

GtkTreeViewColumn 	*column_aud_emp;
GtkTreeViewColumn 	*column_aud_emp2;
GtkTreeViewColumn 	*column_aud_emp3;
GtkTreeViewColumn 	*column_aud_emp4;
GtkTreeViewColumn 	*column_aud_emp5;
GtkTreeViewColumn 	*column_aud_emp6;
GtkTreeViewColumn 	*column_aud_emp7;
GtkTreeViewColumn 	*column_aud_emp8;
GtkTreeViewColumn 	*column_aud_emp9;
GtkTreeViewColumn 	*column_aud_emp10;
GtkTreeViewColumn 	*column_aud_emp11;
GtkTreeViewColumn 	*column_aud_emp12;
GtkTreeViewColumn 	*column_aud_emp13;
GtkTreeViewColumn 	*column_aud_emp14;
GtkTreeViewColumn 	*column_aud_emp15;
GtkTreeViewColumn 	*column_aud_emp16;
GtkTreeViewColumn 	*column_aud_emp17;
GtkTreeViewColumn 	*column_aud_emp18;
GtkTreeViewColumn 	*column_aud_emp19;
GtkTreeViewColumn 	*column_aud_emp20;
GtkTreeViewColumn 	*column_aud_emp21;

GtkTreeViewColumn 	*column_aud_pro;
GtkTreeViewColumn 	*column_aud_pro2;
GtkTreeViewColumn 	*column_aud_pro3;
GtkTreeViewColumn 	*column_aud_pro4;
GtkTreeViewColumn 	*column_aud_pro5;
GtkTreeViewColumn 	*column_aud_pro6;
GtkTreeViewColumn 	*column_aud_pro7;
GtkTreeViewColumn 	*column_aud_pro8;
GtkTreeViewColumn 	*column_aud_pro9;
GtkTreeViewColumn 	*column_aud_pro10;
GtkTreeViewColumn 	*column_aud_pro11;
GtkTreeViewColumn 	*column_aud_pro12;
GtkTreeViewColumn 	*column_aud_pro13;
GtkTreeViewColumn 	*column_aud_pro14;
GtkTreeViewColumn 	*column_aud_pro15;
GtkTreeViewColumn 	*column_aud_pro16;
GtkTreeViewColumn 	*column_aud_pro17;
GtkTreeViewColumn 	*column_aud_pro18;
GtkTreeViewColumn 	*column_aud_pro19;
GtkTreeViewColumn 	*column_aud_pro20;
GtkTreeViewColumn 	*column_aud_pro21;

GtkTreeViewColumn 	*column_aud_fac;
GtkTreeViewColumn 	*column_aud_fac2;
GtkTreeViewColumn 	*column_aud_fac3;
GtkTreeViewColumn 	*column_aud_fac4;
GtkTreeViewColumn 	*column_aud_fac5;
GtkTreeViewColumn 	*column_aud_fac6;
GtkTreeViewColumn 	*column_aud_fac7;
GtkTreeViewColumn 	*column_aud_fac8;
GtkTreeViewColumn 	*column_aud_fac9;
GtkTreeViewColumn 	*column_aud_fac10;
GtkTreeViewColumn 	*column_aud_fac11;
GtkTreeViewColumn 	*column_aud_fac12;
GtkTreeViewColumn 	*column_aud_fac13;
GtkTreeViewColumn 	*column_aud_fac14;
GtkTreeViewColumn 	*column_aud_fac15;
GtkTreeViewColumn 	*column_aud_fac16;
GtkTreeViewColumn 	*column_aud_fac17;
GtkTreeViewColumn 	*column_aud_fac18;
GtkTreeViewColumn 	*column_aud_fac19;
GtkTreeViewColumn 	*column_aud_fac20;
GtkTreeViewColumn 	*column_aud_fac21;

GtkTreeViewColumn 	*column_fac_bus;
GtkTreeViewColumn 	*column_fac2_bus;
GtkTreeViewColumn 	*column_fac3_bus;
GtkTreeViewColumn 	*column_fac4_bus;
GtkTreeViewColumn 	*column_fac5_bus;
GtkTreeViewColumn 	*column_fac6_bus;
GtkTreeViewColumn 	*column_fac7_bus;
GtkTreeViewColumn 	*column_fac8_bus;
GtkTreeViewColumn 	*column_fac9_bus;

GtkTreeSelection 	*seleccion_view;
GtkTreeSelection 	*seleccion_view2;
GtkTreeSelection 	*selection; 


	
FILE* 			fichero;
FILE* 			fichero2;
FILE* 			fichero3;
const char 		*user;
const char 		*password;

enum {
  LIST_ITEM = 0,
  N_COLUMNS_BUS
};
enum
{
	COLid,
	COLidproc,
	COLnombre,
	COLdireccion,
	COLtelefono,
	COLregion,
	COLpais,
	COLrfc,
	COLcorreo,
	NUM_COLS
} ;
enum
{
	COLidfac,
	COLidproduc,
	COLidempresa,
	COLfechaventa,
	COLcantidad,
	COLprecio,
	COLmodopago,
	COLdescuento,
	COLtotal,
	NUM_COLS_fac
} ;
enum
{
	COLidproducto,
	COLnomprod,
	COLmarca,
	COLfechacaducidad,
	COLfechaproduccion,
	COLnumlote,
	COLdescripcion,
	COLcodigobarra,
	COLcontenidoneto,
	NUM_COLS_pro
} ;
enum
{
	id_aud_emp,
	id_pro_ant_emp,
	nom_ant_emp,
	dir_ant_emp,
	tel_ant_emp,
	reg_ant_emp,
	pais_ant_emp,
	rfc_ant_emp,
	corr_ant_emp,
	id_pro_new_emp,
	nom_new_emp,
	dir_new_emp,
	tel_new_emp,
	reg_new_emp,
	pais_new_emp,
	rfc_new_emp,
	corr_new_emp,
	user_emp_emp,
	modifi_emp_emp,
	accion_emp_emp,
	id_emp_au_emp,
	NUM_COLS_au_emp
} ;

enum
{
	idaud_fac,
	idpro_ant_fac,
	idemp_ant_fac,
	fechaven_ant_fac,
	cantidad_ant_fac,
	precio_ant_fac,
	modopago_ant_fac,
	descue_ant_fac,
	total_ant_fac,
	idpro_new_fac,
	idemp_new_fac,
	fechaven_new_fac,
	cantidad_new_fac,
	precio_new_fac,
	modopago_new_fac,
	descue_new_fac,
	total_new_fac,
	user_fac,
	mod_fac,
	accion_fac,
	idfac_au_fac,
	NUM_COLS_au_fac
} ;

enum
{
	idaud_pro,
	nom_ant_pro,
	marca_ant_pro,
	fechacad_ant_pro,
	fechapro_ant_pro,
	numlote_ant_pro,
	desc_ant_pro,
	codbarra_ant_pro,
	conneto_ant_pro,
	nom_new_pro,
	marca_new_pro,
	fechacad_new_pro,
	fechapro_new_pro,
	numlote_new_pro,
	desc_new_pro,
	codbarra_new_pro,
	conneto_new_pro,
	user_pro,
	mod_pro,
	accion_pro,
	idpro_au_pro,
	NUM_COLS_au_pro
} ;
enum
{
	COLid_bus,
	COLnomant_bus,
	COLedadant_bus,
	COLapodoant_bus,
	COLpoderes_bus,
	COLsexo_bus,
	COLestatura_bus,
	Colbarra,
	conneto,
	NUM_COLS_bus
} ;

static GtkTreeModel * create_empresa (void)
{
	store = gtk_list_store_new (NUM_COLS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,COLid, row[0],
	COLidproc, row[1],
	COLnombre, row[2],
	COLdireccion, row[3],
	COLtelefono, row[4],
	COLregion, row[5],
	COLpais, row[6],
	COLrfc, row[7],
	COLcorreo, row[8],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,COLid, row[0],
	COLidproc, row[1],
	COLnombre, row[2],
	COLdireccion, row[3],
	COLtelefono, row[4],
	COLregion, row[5],
	COLpais, row[6],
	COLrfc, row[7],
	COLcorreo, row[8],-1);
}
	return GTK_TREE_MODEL (store);
}


 static GtkWidget *titulo_empresa(void)
{	
	renderer = gtk_cell_renderer_text_new ();
	column_emp = gtk_tree_view_column_new_with_attributes  ("ID Empresa",renderer,"text", COLid,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp);
	renderer = gtk_cell_renderer_text_new ();
	column_emp2 = gtk_tree_view_column_new_with_attributes ("ID Producto",renderer,"text", COLidproc,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp2);
	renderer = gtk_cell_renderer_text_new ();
	column_emp3 = gtk_tree_view_column_new_with_attributes  ("Nombre",renderer,"text", COLnombre,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp3);
	renderer = gtk_cell_renderer_text_new ();
	column_emp4 = gtk_tree_view_column_new_with_attributes  ("Direccion",renderer,"text", COLdireccion,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp4);
	renderer = gtk_cell_renderer_text_new ();
	column_emp5 = gtk_tree_view_column_new_with_attributes  ("Telefono",renderer,"text", COLtelefono,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp5);
	renderer = gtk_cell_renderer_text_new ();
	column_emp6 = gtk_tree_view_column_new_with_attributes ("Region",renderer,"text", COLregion,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp6);
	renderer = gtk_cell_renderer_text_new ();
	column_emp7 = gtk_tree_view_column_new_with_attributes ("Pais",renderer,"text", COLpais,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp7);
	renderer = gtk_cell_renderer_text_new ();
	column_emp8 = gtk_tree_view_column_new_with_attributes ("RFC",renderer,"text", COLrfc,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp8);
	renderer = gtk_cell_renderer_text_new ();
	column_emp9 = gtk_tree_view_column_new_with_attributes ("Correo",renderer,"text", COLcorreo,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_emp9);
	
	model = create_empresa ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view), model);
	g_object_unref (model);
	return view;
}


static GtkTreeModel * create_factura (void)
{
	store2 = gtk_list_store_new (NUM_COLS_fac, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store2, &iter2);
	gtk_list_store_set (store2, &iter2,
	COLidfac, row[0],
	COLidproduc, row[1],
	COLidempresa, row[2],
	COLfechaventa, row[3],
	COLcantidad, row[4],
	COLprecio, row[5],
	COLmodopago, row[6],
	COLdescuento, row[7],
	COLtotal, row[8],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store2, &iter2);
	gtk_list_store_set (store2, &iter2,
	COLidfac, row[0],
	COLidproduc, row[1],
	COLidempresa, row[2],
	COLfechaventa, row[3],
	COLcantidad, row[4],
	COLprecio, row[5],
	COLmodopago, row[6],
	COLdescuento, row[7],
	COLtotal, row[8],-1);
}
	return GTK_TREE_MODEL (store2);
}

 static GtkWidget *titulo_factura(void)
{	
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac = gtk_tree_view_column_new_with_attributes  ("ID Factura",renderer2,"text", COLidfac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac2 = gtk_tree_view_column_new_with_attributes ("ID Producto",renderer2,"text", COLidproduc,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac2);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac3 = gtk_tree_view_column_new_with_attributes  ("ID Empresa",renderer2,"text", COLidempresa,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac3);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac4 = gtk_tree_view_column_new_with_attributes  ("Fecha de Venta",renderer2,"text", COLfechaventa,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac4);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac5 = gtk_tree_view_column_new_with_attributes  ("Cantidad",renderer2,"text", COLcantidad,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac5);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac6 = gtk_tree_view_column_new_with_attributes ("Precio",renderer2,"text", COLprecio,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac6);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac7 = gtk_tree_view_column_new_with_attributes ("Modo Pago",renderer2,"text", COLmodopago,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac7);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac8 = gtk_tree_view_column_new_with_attributes ("Descuento",renderer2,"text", COLdescuento,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac8);
	renderer2 = gtk_cell_renderer_text_new ();
	column_fac9 = gtk_tree_view_column_new_with_attributes ("Total",renderer2,"text", COLtotal,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column_fac9);
	
	model2 = create_factura ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view2), model2);
	g_object_unref (model2);
	return view2;
}

static GtkTreeModel * create_producto (void)
{
	store3 = gtk_list_store_new (NUM_COLS_pro, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store3, &iter3);
	gtk_list_store_set (store3, &iter3,COLidproducto, row[0],
	COLnomprod, row[1],
	COLmarca, row[2],
	COLfechacaducidad, row[3],
	COLfechaproduccion, row[4],
	COLnumlote, row[5],
	COLdescripcion, row[6],
	COLcodigobarra, row[7],
	COLcontenidoneto, row[8],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store3, &iter3);
	gtk_list_store_set (store3, &iter3,COLidproducto, row[0],
	COLnomprod, row[1],
	COLmarca, row[2],
	COLfechacaducidad, row[3],
	COLfechaproduccion, row[4],
	COLnumlote, row[5],
	COLdescripcion, row[6],
	COLcodigobarra, row[7],
	COLcontenidoneto, row[8],-1);
}
	return GTK_TREE_MODEL (store3);
}

 static GtkWidget *titulo_producto(void)
{	
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro = gtk_tree_view_column_new_with_attributes  ("ID Producto",renderer3,"text", COLidproducto,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro2 = gtk_tree_view_column_new_with_attributes ("Nombre",renderer3,"text", COLnomprod,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro2);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro3 = gtk_tree_view_column_new_with_attributes  ("Marca",renderer3,"text", COLmarca,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro3);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro4 = gtk_tree_view_column_new_with_attributes  ("Fecha Cad.",renderer3,"text", COLfechacaducidad,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro4);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro5 = gtk_tree_view_column_new_with_attributes  ("Fecha Producción",renderer3,"text", COLfechaproduccion,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro5);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro6 = gtk_tree_view_column_new_with_attributes ("Numero Lote",renderer3,"text", COLnumlote,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro6);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro7 = gtk_tree_view_column_new_with_attributes ("Descripción",renderer3,"text", COLdescripcion,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro7);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro8 = gtk_tree_view_column_new_with_attributes ("Codigo Barras",renderer3,"text", COLcodigobarra,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro8);
	renderer3 = gtk_cell_renderer_text_new ();
	column_pro9 = gtk_tree_view_column_new_with_attributes ("Contenido Neto",renderer3,"text", COLcontenidoneto,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view3),column_pro9);
	
	model3 = create_producto ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view3), model3);
	g_object_unref (model3);
	return view3;
}

static GtkTreeModel *create_empresa_auditoria (void)
{
	store4 = gtk_list_store_new (NUM_COLS_au_emp, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store4, &iter4);
	gtk_list_store_set (store4, &iter4,id_aud_emp,row[0],
	id_pro_ant_emp,row[1],
	nom_ant_emp,row[2],
	dir_ant_emp,row[3],
	tel_ant_emp,row[4],
	reg_ant_emp,row[5],
	pais_ant_emp,row[6],
	rfc_ant_emp,row[7],
	corr_ant_emp,row[8],
	id_pro_new_emp,row[9],
	nom_new_emp,row[10],
	dir_new_emp,row[11],
	tel_new_emp,row[12],
	reg_new_emp,row[13],
	pais_new_emp,row[14],
	rfc_new_emp,row[15],
	corr_new_emp,row[16],
	user_emp_emp,row[17],
	modifi_emp_emp,row[18],
	accion_emp_emp,row[19],
	id_emp_au_emp,row[20],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store4, &iter4);
	gtk_list_store_set (store4, &iter4,id_aud_emp,row[0],
	id_pro_ant_emp,row[1],
	nom_ant_emp,row[2],
	dir_ant_emp,row[3],
	tel_ant_emp,row[4],
	reg_ant_emp,row[5],
	pais_ant_emp,row[6],
	rfc_ant_emp,row[7],
	corr_ant_emp,row[8],
	id_pro_new_emp,row[9],
	nom_new_emp,row[10],
	dir_new_emp,row[11],
	tel_new_emp,row[12],
	reg_new_emp,row[13],
	pais_new_emp,row[14],
	rfc_new_emp,row[15],
	corr_new_emp,row[16],
	user_emp_emp,row[17],
	modifi_emp_emp,row[18],
	accion_emp_emp,row[19],
	id_emp_au_emp,row[20],-1);
}
	return GTK_TREE_MODEL (store4);
}

 static GtkWidget *titulo_empresa_auditoria (void)
{
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp = gtk_tree_view_column_new_with_attributes ("ID",renderer4,"text", id_aud_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp2 = gtk_tree_view_column_new_with_attributes ("ID Producto Ant.",renderer4,"text", id_pro_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp2);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp3= gtk_tree_view_column_new_with_attributes ("Nombre Anterior",renderer4,"text", nom_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp3);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp4= gtk_tree_view_column_new_with_attributes ("Direccion Anterior",renderer4,"text", dir_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp4);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp5 = gtk_tree_view_column_new_with_attributes ("Telefono Anterior",renderer4,"text", tel_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp5);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp6 = gtk_tree_view_column_new_with_attributes ("Region Anterior",renderer4,"text", reg_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp6);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp7 = gtk_tree_view_column_new_with_attributes ("Pais Anterior",renderer4,"text", pais_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp7);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp8 = gtk_tree_view_column_new_with_attributes ("RFC Anterior",renderer4,"text", rfc_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp8);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp9 = gtk_tree_view_column_new_with_attributes ("Correo Anterior",renderer4,"text", corr_ant_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp9);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp10 = gtk_tree_view_column_new_with_attributes ("ID Producto Nuevo",renderer4,"text", id_pro_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp10);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp11 = gtk_tree_view_column_new_with_attributes ("Nombre Nuevo",renderer4,"text", nom_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp11);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp12 = gtk_tree_view_column_new_with_attributes ("Direccion Nuevo",renderer4,"text", dir_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp12);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp13 = gtk_tree_view_column_new_with_attributes ("Telefono Nuevo",renderer4,"text",tel_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp13);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp14 = gtk_tree_view_column_new_with_attributes ("Region Nuevo",renderer4,"text", reg_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp14);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp15 = gtk_tree_view_column_new_with_attributes ("Pais Nuevo",renderer4,"text", pais_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp15);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp16 = gtk_tree_view_column_new_with_attributes ("RFC Nuevo",renderer4,"text", rfc_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp16);
	renderer = gtk_cell_renderer_text_new ();
	column_aud_emp17 = gtk_tree_view_column_new_with_attributes ("Correo Nuevo",renderer4,"text", corr_new_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp17);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp18 = gtk_tree_view_column_new_with_attributes ("Usuario",renderer4,"text", user_emp_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp18);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp19 = gtk_tree_view_column_new_with_attributes ("Modificado",renderer4,"text", modifi_emp_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp19);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp20 = gtk_tree_view_column_new_with_attributes ("Accion",renderer4,"text", accion_emp_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp20);
	renderer4 = gtk_cell_renderer_text_new ();
	column_aud_emp21 = gtk_tree_view_column_new_with_attributes ("ID Empresa",renderer4,"text", id_emp_au_emp,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view4),column_aud_emp21);
	
	model4 = create_empresa_auditoria();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view4), model4);
	g_object_unref (model4);
	return view4;
}

static GtkTreeModel *create_factura_auditoria (void)
{
	store5 = gtk_list_store_new (NUM_COLS_au_fac, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store5, &iter5);
	gtk_list_store_set (store5, &iter5,idaud_fac,row[0],
	idpro_ant_fac,row[1],
	idemp_ant_fac,row[2],
	fechaven_ant_fac,row[3],
	cantidad_ant_fac,row[4],
	precio_ant_fac,row[5],
	modopago_ant_fac,row[6],
	descue_ant_fac,row[7],
	total_ant_fac,row[8],
	idpro_new_fac,row[9],
	idemp_new_fac,row[10],
	fechaven_new_fac,row[11],
	cantidad_new_fac,row[12],
	precio_new_fac,row[13],
	modopago_new_fac,row[14],
	descue_new_fac,row[15],
	total_new_fac,row[16],
	user_fac,row[17],
	mod_fac,row[18],
	accion_fac,row[19],
	idfac_au_fac,row[20],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store5, &iter5);
	gtk_list_store_set (store5, &iter5,idaud_fac,row[0],
	idpro_ant_fac,row[1],
	idemp_ant_fac,row[2],
	fechaven_ant_fac,row[3],
	cantidad_ant_fac,row[4],
	precio_ant_fac,row[5],
	modopago_ant_fac,row[6],
	descue_ant_fac,row[7],
	total_ant_fac,row[8],
	idpro_new_fac,row[9],
	idemp_new_fac,row[10],
	fechaven_new_fac,row[11],
	cantidad_new_fac,row[12],
	precio_new_fac,row[13],
	modopago_new_fac,row[14],
	descue_new_fac,row[15],
	total_new_fac,row[16],
	user_fac,row[17],
	mod_fac,row[18],
	accion_fac,row[19],
	idfac_au_fac,row[20],-1);
}
	return GTK_TREE_MODEL (store5);
}

 static GtkWidget *titulo_factura_auditoria (void)
{
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac = gtk_tree_view_column_new_with_attributes ("ID",renderer5,"text", idaud_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac2 = gtk_tree_view_column_new_with_attributes ("ID Pro. Ant.",renderer5,"text", idpro_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac2);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac3= gtk_tree_view_column_new_with_attributes ("ID Empresa Ant.",renderer5,"text", idemp_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac3);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac4= gtk_tree_view_column_new_with_attributes ("Fecha Venta Ant.",renderer5,"text", fechaven_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac4);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac5= gtk_tree_view_column_new_with_attributes ("Cantidad Ant.",renderer5,"text", cantidad_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac5);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac6 = gtk_tree_view_column_new_with_attributes ("Precio Ant.",renderer5,"text", precio_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac6);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac7 = gtk_tree_view_column_new_with_attributes ("Modo Pago Ant.",renderer5,"text", modopago_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac7);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac8 = gtk_tree_view_column_new_with_attributes ("Descuento Ant.",renderer5,"text", descue_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac8);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac9 = gtk_tree_view_column_new_with_attributes ("Total Ant.",renderer5,"text", total_ant_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac9);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac10 = gtk_tree_view_column_new_with_attributes ("ID Pro. Nuevo",renderer5,"text", idpro_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac10);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac11 = gtk_tree_view_column_new_with_attributes ("ID Empresa Nuevo",renderer5,"text", idemp_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac11);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac12 = gtk_tree_view_column_new_with_attributes ("Fecha Venta Nuevo",renderer5,"text", fechaven_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac12);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac13= gtk_tree_view_column_new_with_attributes ("Cantidad Nuevo.",renderer5,"text", cantidad_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac13);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac14 = gtk_tree_view_column_new_with_attributes ("Precio Nuevo",renderer5,"text", precio_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac14);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac15 = gtk_tree_view_column_new_with_attributes ("Modo Pago Nuevo",renderer5,"text", modopago_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac15);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac16 = gtk_tree_view_column_new_with_attributes ("Descuento Nuevo",renderer5,"text", descue_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac16);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac17 = gtk_tree_view_column_new_with_attributes ("Total Nuevo",renderer5,"text", total_new_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac17);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac18 = gtk_tree_view_column_new_with_attributes ("Usuario",renderer5,"text", user_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac18);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac19 = gtk_tree_view_column_new_with_attributes ("Modificado",renderer5,"text", mod_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac19);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac20 = gtk_tree_view_column_new_with_attributes ("Accion",renderer5,"text", accion_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac20);
	renderer5 = gtk_cell_renderer_text_new ();
	column_aud_fac21 = gtk_tree_view_column_new_with_attributes ("ID Factura",renderer5,"text", idfac_au_fac,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view5),column_aud_fac21);
	
	model5 = create_factura_auditoria();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view5), model5);
	g_object_unref (model5);
	return view5;
}

static GtkTreeModel *create_producto_auditoria (void)
{
	store6 = gtk_list_store_new (NUM_COLS_au_pro, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store6, &iter6);
	gtk_list_store_set (store6, &iter6,idaud_pro,row[0],
	nom_ant_pro,row[1],
	marca_ant_pro,row[2],
	fechacad_ant_pro,row[3],
	fechapro_ant_pro,row[4],
	numlote_ant_pro,row[5],
	desc_ant_pro,row[6],
	codbarra_ant_pro,row[7],
	conneto_ant_pro,row[8],
	nom_new_pro,row[9],
	marca_new_pro,row[10],
	fechacad_new_pro,row[11],
	fechapro_new_pro,row[12],
	numlote_new_pro,row[13],
	desc_new_pro,row[14],
	codbarra_new_pro,row[15],
	conneto_new_pro,row[16],
	user_pro,row[17],
	mod_pro,row[18],
	accion_pro,row[19],
	idpro_au_pro,row[20],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store6, &iter6);
	gtk_list_store_set (store6, &iter6,idaud_pro,row[0],
	nom_ant_pro,row[1],
	marca_ant_pro,row[2],
	fechacad_ant_pro,row[3],
	fechapro_ant_pro,row[4],
	numlote_ant_pro,row[5],
	desc_ant_pro,row[6],
	codbarra_ant_pro,row[7],
	conneto_ant_pro,row[8],
	nom_new_pro,row[9],
	marca_new_pro,row[10],
	fechacad_new_pro,row[11],
	fechapro_new_pro,row[12],
	numlote_new_pro,row[13],
	desc_new_pro,row[14],
	codbarra_new_pro,row[15],
	conneto_new_pro,row[16],
	user_pro,row[17],
	mod_pro,row[18],
	accion_pro,row[19],
	idpro_au_pro,row[20],-1);
}
	return GTK_TREE_MODEL (store6);
}
 
static GtkWidget *titulo_producto_auditoria (void)
{
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro = gtk_tree_view_column_new_with_attributes ("ID",renderer6,"text", idaud_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro2 = gtk_tree_view_column_new_with_attributes ("Nombre Ant.",renderer6,"text", nom_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro2);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro3= gtk_tree_view_column_new_with_attributes ("Marca Ant.",renderer6,"text", marca_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro3);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro4= gtk_tree_view_column_new_with_attributes ("Fecha Cad. Ant.",renderer6,"text", fechacad_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro4);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro5= gtk_tree_view_column_new_with_attributes ("Fecha Prod. Ant.",renderer6,"text", fechapro_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro5);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro6= gtk_tree_view_column_new_with_attributes ("Num. Lote Ant.",renderer6,"text", numlote_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro6);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro7 = gtk_tree_view_column_new_with_attributes ("Descripcion Ant.",renderer6,"text", desc_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro7);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro8 = gtk_tree_view_column_new_with_attributes ("Cod. Barras Ant.",renderer6,"text", codbarra_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro8);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro9 = gtk_tree_view_column_new_with_attributes ("Cont. Neto Ant.",renderer6,"text", conneto_ant_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro9);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro10 = gtk_tree_view_column_new_with_attributes ("Nombre Nuevo",renderer6,"text", nom_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro10);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro11= gtk_tree_view_column_new_with_attributes ("Marca Nuevo",renderer6,"text", marca_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro11);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro12= gtk_tree_view_column_new_with_attributes ("Fecha Cad. Nuevo",renderer6,"text", fechacad_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro12);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro13 = gtk_tree_view_column_new_with_attributes ("Fecha Prod. Nuevo",renderer6,"text", fechapro_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro13);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro14= gtk_tree_view_column_new_with_attributes ("Num. Lote Nuevo",renderer6,"text", numlote_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro14);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro15 = gtk_tree_view_column_new_with_attributes ("Descripcion Ant.",renderer6,"text", desc_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro15);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro16 = gtk_tree_view_column_new_with_attributes ("Cod. Barras Nuevo",renderer6,"text", codbarra_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro16);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro17 = gtk_tree_view_column_new_with_attributes ("Cont. Neto Nuevo",renderer6,"text", conneto_new_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro17);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro18 = gtk_tree_view_column_new_with_attributes ("Usuario",renderer6,"text", user_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro18);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro19 = gtk_tree_view_column_new_with_attributes ("Modificado",renderer6,"text", mod_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro19);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro20 = gtk_tree_view_column_new_with_attributes ("Accion",renderer6,"text", accion_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro20);
	renderer6 = gtk_cell_renderer_text_new ();
	column_aud_pro21 = gtk_tree_view_column_new_with_attributes ("ID Producto",renderer6,"text", idpro_au_pro,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view6),column_aud_pro21);
	
	model6 = create_producto_auditoria();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view6), model6);
	g_object_unref (model6);
	return view6;
}
static GtkTreeModel * create_and_fill_model_busqueda (void)
{
	store_busqueda = gtk_list_store_new (NUM_COLS_bus, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store_busqueda, &iter_busqueda);
	gtk_list_store_set (store_busqueda, &iter_busqueda,COLid_bus, row[0],
	COLnomant_bus, row[1],
	COLedadant_bus, row[2],
	COLapodoant_bus, row[3],
	COLpoderes_bus, row[4],
	COLsexo_bus, row[5],
	COLestatura_bus, row[6],
	Colbarra, row[7],
	conneto, row[8],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store_busqueda, &iter_busqueda);
	gtk_list_store_set (store_busqueda, &iter_busqueda,COLid_bus, row[0],
	COLnomant_bus, row[1],
	COLedadant_bus, row[2],
	COLapodoant_bus, row[3],
	COLpoderes_bus, row[4],
	COLsexo_bus, row[5],
	COLestatura_bus, row[6],
	Colbarra, row[7],
	conneto, row[8],-1);
}
	return GTK_TREE_MODEL (store_busqueda);
}


 static GtkWidget *titulo_factura_auditoria_busqueda (void)
{	
	renderer = gtk_cell_renderer_text_new ();
	column_fac_bus = gtk_tree_view_column_new_with_attributes  ("ID Pro",renderer,"text", COLid_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac2_bus = gtk_tree_view_column_new_with_attributes ("Nombre",renderer,"text", COLnomant_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac2_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac3_bus = gtk_tree_view_column_new_with_attributes  ("Marca",renderer,"text", COLedadant_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac3_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac4_bus = gtk_tree_view_column_new_with_attributes  ("F. Caducidad",renderer,"text", COLapodoant_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac4_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac5_bus = gtk_tree_view_column_new_with_attributes  ("F. Produccion",renderer,"text", COLpoderes_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac5_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac6_bus = gtk_tree_view_column_new_with_attributes ("N. Lote",renderer,"text", COLsexo_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac6_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac7_bus = gtk_tree_view_column_new_with_attributes ("Descripcion",renderer,"text", COLestatura_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac7_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac8_bus = gtk_tree_view_column_new_with_attributes ("Codigo Barra",renderer,"text", Colbarra,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac8_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac9_bus = gtk_tree_view_column_new_with_attributes ("Con. Neto",renderer,"text", conneto,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac9_bus);
	
	model_busc = create_and_fill_model_busqueda ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view_busc), model_busc);
	g_object_unref (model_busc);
	return view_busc;
}


void conectar(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	char *server = "localhost";
	char *database = "mysql";
	conn = mysql_init(NULL);
 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) 
 {
     char tempErr[60];
	 sprintf(tempErr,"%s", mysql_error(conn));
	 gtk_label_set_text(La_Label_Error_ingreso,tempErr);
     return gtk_widget_show(g_Dialog_Error);
 }else
 {
	 char temp[60];
	 sprintf(temp,"Bases de Datos Sobre %s",user);
	 gtk_label_set_text(La_lbl_Titulo_BD,temp);
	 gtk_widget_hide_on_delete (window_login);
	 gtk_widget_show(window_BD);
	 
}
	 
 if (mysql_query(conn, "show databases")) 
 {
     char tempErr[60];
	 sprintf(tempErr,"%s", mysql_error(conn));
	 gtk_label_set_text(La_Label_Error_ingreso,tempErr);
     return gtk_widget_show(g_Dialog_Error);

 }
 res = mysql_use_result(conn); 

 while ((row = mysql_fetch_row(res)) != NULL) gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (menu_items), row[0]);
 mysql_free_result(res);
 mysql_close(conn);
 
}

void mostrar_tablas()
{
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(menu_items));
	char *server = "localhost";
	conn = mysql_init(NULL);
	/* Conectarse a la base de datos */

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
     char tempErr[60];
	 sprintf(tempErr,"%s", mysql_error(conn));
	 gtk_label_set_text(La_Label_Error_ingreso,tempErr);
     return gtk_widget_show(g_Dialog_Error);

 }
	 
 if (mysql_query(conn, "show tables")) {
     char tempErr[60];
	 sprintf(tempErr,"%s", mysql_error(conn));
	 gtk_label_set_text(La_Label_Error_ingreso,tempErr);
     return gtk_widget_show(g_Dialog_Error);

 }
 res = mysql_use_result(conn); 
 

 while ((row = mysql_fetch_row(res)) != NULL){ gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (tabla_items), row[0]);

}
 mysql_free_result(res);
 mysql_close(conn);
	
}


void contenido_tablas(){
	const char *database = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(menu_items));
	const char *tabla = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(tabla_items));
	
	char debugtabla[50];
	sprintf(debugtabla,"As Escogido la Tabla %s\n", tabla);
	char mostrarContenido[50];
	char *server = "localhost";
	sprintf(mostrarContenido,"select * from %s",tabla);
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	
	conn = mysql_init(NULL);


 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, mostrarContenido))
	{ 
	}
	res = mysql_use_result(conn);
//==================================================================================================================
while ((row = mysql_fetch_row(res)) != NULL)
{
			if(tabla[0]== 'E')
				{
				gtk_stack_set_visible_child (GTK_STACK(stackgtk),contenedor_view);
				gtk_stack_set_visible_child (GTK_STACK(stack_pdf),oculta_pdf);	
				gtk_stack_set_visible_child (GTK_STACK(stack_func),muestra_func);
				if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
						 titulo_empresa();
						 return ;
					}
				}else if(tabla[0]== 'F')
					{
						gtk_stack_set_visible_child (GTK_STACK(stackgtk),contenedor_view2);
						gtk_stack_set_visible_child (GTK_STACK(stack_pdf),oculta_pdf);	
						gtk_stack_set_visible_child (GTK_STACK(stack_func),muestra_func);
							if (gtk_tree_model_get_iter_first(model2, &iter2) == FALSE) {
								titulo_factura();	
								return ;
						}
					}else if(tabla[0]== 'P')
						{
							gtk_stack_set_visible_child (GTK_STACK(stackgtk),contenedor_view3);
							gtk_stack_set_visible_child (GTK_STACK(stack_pdf),oculta_pdf);	
							gtk_stack_set_visible_child (GTK_STACK(stack_func),muestra_func);
								if (gtk_tree_model_get_iter_first(model3, &iter3) == FALSE) {
									titulo_producto();
									return ;
							}
						}else if(tabla[10]== 'e')
							{
								gtk_stack_set_visible_child (GTK_STACK(stackgtk),contenedor_view4);
								gtk_stack_set_visible_child (GTK_STACK(stack_pdf),exportar_pdf);	
								gtk_stack_set_visible_child (GTK_STACK(stack_func),oculta_funcion);
									if (gtk_tree_model_get_iter_first(model4, &iter4) == FALSE) {
										 titulo_empresa_auditoria();
										 return ;
								}
							}else if(tabla[10]== 'f')
								{
									gtk_stack_set_visible_child (GTK_STACK(stackgtk),contenedor_view5);
									gtk_stack_set_visible_child (GTK_STACK(stack_pdf),exportar_pdf);	
									gtk_stack_set_visible_child (GTK_STACK(stack_func),oculta_funcion);
										if (gtk_tree_model_get_iter_first(model5, &iter5) == FALSE) {
											titulo_factura_auditoria();
											return ;
									}
								}else if(tabla[10]== 'p')
									{
										gtk_stack_set_visible_child (GTK_STACK(stackgtk),contenedor_view6);
										gtk_stack_set_visible_child (GTK_STACK(stack_pdf),exportar_pdf);	
										gtk_stack_set_visible_child (GTK_STACK(stack_func),oculta_funcion);
											if (gtk_tree_model_get_iter_first(model6, &iter6) == FALSE) {
												titulo_producto_auditoria();
												return ;	
										}
									}	
}
	gtk_text_buffer_set_text (textbuffer_main,debugtabla,-1);
	gtk_text_view_set_buffer (debug_textview, textbuffer_main);
	mysql_free_result(res);
	mysql_close(conn);
}


void on_Combo_Box_Mostrar_BD_changed(GtkComboBox *widget)
{
	gtk_combo_box_text_remove_all (GTK_COMBO_BOX_TEXT (tabla_items));
	GtkComboBox *menu_items = widget;
	const char *database = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(menu_items));
	char debugbd[50];
	sprintf(debugbd,"As Escogido la Bases de Datos %s\n", database);
    g_print ("As Escogido la BD %s\n", database);
    char temp[60];
	sprintf(temp,"%s Sobre BD %s",user,database);
	gtk_label_set_text(La_lbl_Titulo_BD,temp);

	char temp2[30];
	sprintf(temp2,"use %s",database);
	gtk_text_buffer_set_text (textbuffer_main,debugbd,-1);
	gtk_text_view_set_buffer (debug_textview, textbuffer_main);
	mostrar_tablas();
}	

void on_btn_cambiar_usuario_clicked()
{
	gtk_entry_set_text(g_Entry_Usuario,"");
	gtk_entry_set_text(g_Entry_Contraseña,"");
	gtk_combo_box_text_remove_all (GTK_COMBO_BOX_TEXT (menu_items));
	gtk_combo_box_text_remove_all (GTK_COMBO_BOX_TEXT (tabla_items));
	gtk_widget_hide_on_delete(window_BD);
	gtk_widget_show(window_login);
	gtk_widget_hide_on_delete (g_Dialog_Error);
	gtk_stack_set_visible_child (GTK_STACK(stackgtk),lbl_no_datos);
}

void on_acercade_clicked(){
	gtk_widget_show (win_acercade); 
	}
	
void on_acercade_response(){
	gtk_widget_hide_on_delete(win_acercade);
	}
void on_btn_Sesion_clicked ( gpointer  user_data)
{
	conectar();
}

void on_Entry_Contraseña_activate(gpointer  user_data)
{	
	conectar();
}
	
void on_btn_cancelar_adver3_clicked()
{
	gtk_widget_hide(g_Dialog_Error);
}
	
void on_btn_Rein_Dial_clicked()
	{
		gtk_entry_set_text(g_Entry_Usuario,"");
		gtk_entry_set_text(g_Entry_Contraseña,"");
		gtk_widget_hide_on_delete (g_Dialog_Error);
	}
void refresca_datos_fac(){
	
	if (gtk_tree_model_get_iter_first(model2, &iter2) == TRUE) {
		gtk_list_store_clear(store2);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac2);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac3);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac4);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac5);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac6);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac7);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac8);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column_fac9);
}
	if (gtk_tree_model_get_iter_first(model5, &iter5) == TRUE) {
		gtk_list_store_clear(store5);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac2);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac3);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac4);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac5);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac6);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac7);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac8);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac9);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac10);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac11);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac12);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac13);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac14);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac15);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac16);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac17);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac18);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac19);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac20);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view5), column_aud_fac21);
}
	
}
void refresca_datos_emp(){
	
	if (gtk_tree_model_get_iter_first(model, &iter) == TRUE) {
		gtk_list_store_clear(store);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp2);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp3);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp4);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp5);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp6);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp7);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp8);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_emp9);
}
	if (gtk_tree_model_get_iter_first(model4, &iter4) == TRUE) {
		gtk_list_store_clear(store4);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp2);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp3);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp4);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp5);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp6);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp7);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp8);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp9);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp10);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp11);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp12);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp13);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp14);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp15);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp16);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp17);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp18);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp19);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp20);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view4), column_aud_emp21);
}
}
void refresca_datos_pro(){
	
	if (gtk_tree_model_get_iter_first(model3, &iter3) == TRUE) {
		gtk_list_store_clear(store3);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro2);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro3);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro4);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro5);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro6);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro7);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro8);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view3), column_pro9);
}
	if (gtk_tree_model_get_iter_first(model6, &iter6) == TRUE) {
		gtk_list_store_clear(store6);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro2);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro3);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro4);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro5);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro6);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro7);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro8);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro9);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro10);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro11);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro12);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro13);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro14);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro15);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro16);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro17);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro18);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro19);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro20);
		gtk_tree_view_remove_column (GTK_TREE_VIEW(view6), column_aud_pro21);
}
}
void refresca_busqueda(){
	gtk_list_store_clear(store_busqueda);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac2_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac3_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac4_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac5_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac6_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac7_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac8_bus);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view_busc), column_fac9_bus);
	}
void on_Combo_Box_Mostrar_TD_changed(GtkComboBox *widget)
	{
		contenido_tablas();
	}
void init_list(GtkWidget *historial_busqueda) {

		GtkCellRenderer    *renderer_bus;
		GtkTreeViewColumn  *column_bus;
		GtkListStore 		*store_bus;

		renderer_bus = gtk_cell_renderer_text_new();
		column_bus = gtk_tree_view_column_new_with_attributes("Historial de Busqueda",renderer_bus, "text", LIST_ITEM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(historial_busqueda), column_bus);

		store_bus = gtk_list_store_new(N_COLUMNS_BUS, G_TYPE_STRING);

		gtk_tree_view_set_model(GTK_TREE_VIEW(historial_busqueda), GTK_TREE_MODEL(store_bus));

		g_object_unref(store_bus);
	}

int main(int argc, char *argv[])
	{
		char anio[256];
		int i;
		gtk_init(&argc, &argv);
		
		builder = gtk_builder_new();
		gtk_builder_add_from_file (builder, "window_main.glade", NULL);

		window_login = GTK_WIDGET(gtk_builder_get_object(builder, "Login_main"));
		window_BD = GTK_WIDGET(gtk_builder_get_object(builder,"Window_BD"));
		actualiza_factura = GTK_WIDGET(gtk_builder_get_object(builder,"actualiza_factura"));
		actualiza_empresa = GTK_WIDGET(gtk_builder_get_object(builder,"actualiza_empresa"));
		actualiza_producto = GTK_WIDGET(gtk_builder_get_object(builder,"actualiza_producto"));
		g_Entry_Usuario = GTK_ENTRY(gtk_builder_get_object(builder,"Entry_Usuario"));
		g_Entry_Contraseña = GTK_ENTRY(gtk_builder_get_object(builder,"Entry_Contraseña"));
		g_Dialog_Error = GTK_WIDGET(gtk_builder_get_object(builder,"Dialog_Error"));
		lbl_error = GTK_LABEL(gtk_builder_get_object(builder,"lbl_error"));
		inserta_factura = GTK_WIDGET(gtk_builder_get_object(builder,"inserta_factura"));
		inserta_producto = GTK_WIDGET(gtk_builder_get_object(builder,"inserta_producto"));
		inserta_empresa = GTK_WIDGET(gtk_builder_get_object(builder,"inserta_empresa"));
		info_actualizar = GTK_WIDGET(gtk_builder_get_object(builder,"info_actualizar"));
		info_ananido = GTK_WIDGET(gtk_builder_get_object(builder,"info_ananido"));
		info_eliminado = GTK_WIDGET(gtk_builder_get_object(builder,"info_eliminado"));
		pop_calendario = GTK_WIDGET(gtk_builder_get_object(builder,"pop_calendario"));
		pop_delete_fac = GTK_WIDGET(gtk_builder_get_object(builder,"pop_delete_fac"));
		pop_delete_pro = GTK_WIDGET(gtk_builder_get_object(builder,"pop_delete_pro"));
		pop_delete_emp = GTK_WIDGET(gtk_builder_get_object(builder,"pop_delete_emp"));
		La_lbl_Titulo_BD = GTK_LABEL(gtk_builder_get_object(builder,"lbl_Titulo_BD"));
		La_Label_Error_ingreso = GTK_LABEL(gtk_builder_get_object(builder,"Label_Error_ingreso"));
		menu_items = GTK_WIDGET(gtk_builder_get_object(builder,"Combo_Box_Mostrar_BD"));
		cb_anio_fac = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_fac"));
		tabla_items = GTK_WIDGET(gtk_builder_get_object(builder,"Combo_Box_Mostrar_TD"));
		dialog_error_datos = GTK_WIDGET(gtk_builder_get_object(builder,"dialog_error_datos"));
		view = GTK_WIDGET(gtk_builder_get_object(builder,"view"));
		view2 = GTK_WIDGET(gtk_builder_get_object(builder,"view2"));
		view3 = GTK_WIDGET(gtk_builder_get_object(builder,"view3"));
		view4 = GTK_WIDGET(gtk_builder_get_object(builder,"view4"));
		view5 = GTK_WIDGET(gtk_builder_get_object(builder,"view5"));
		view6 = GTK_WIDGET(gtk_builder_get_object(builder,"view6"));
		view_busc = GTK_WIDGET(gtk_builder_get_object(builder,"view_busc"));
		contenedor_view = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view"));
		contenedor_view2 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view2"));
		contenedor_view3 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view3"));
		contenedor_view4 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view4"));
		contenedor_view5 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view5"));
		contenedor_view6 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view6"));
		contenedor_busqueda = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_busqueda"));
		contenedor_sql = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_sql"));
		stackgtk = GTK_WIDGET(gtk_builder_get_object(builder,"stack"));
		stack_busqueda = GTK_WIDGET(gtk_builder_get_object(builder,"stack_busqueda"));
		stack_sql = GTK_WIDGET(gtk_builder_get_object(builder,"stack_sql"));
		stack_aceptar = GTK_WIDGET(gtk_builder_get_object(builder,"stack_aceptar"));
		stack_pdf = GTK_WIDGET(gtk_builder_get_object(builder,"stack_pdf"));
		stack_func = GTK_WIDGET(gtk_builder_get_object(builder,"stack_func"));
		oculta_pdf = GTK_WIDGET(gtk_builder_get_object(builder,"oculta_pdf"));
		exportar_pdf = GTK_WIDGET(gtk_builder_get_object(builder,"exportar_pdf"));
		oculta_funcion = GTK_WIDGET(gtk_builder_get_object(builder,"oculta_funcion"));
		muestra_func = GTK_WIDGET(gtk_builder_get_object(builder,"muestra_func"));
		btn_sql_aceptar = GTK_WIDGET(gtk_builder_get_object(builder,"btn_sql_aceptar"));
		mostrar_calendario = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"mostrar_calendario"));
		ocultar_btn = GTK_WIDGET(gtk_builder_get_object(builder,"ocultar_btn"));
		win_acercade = GTK_WIDGET(gtk_builder_get_object(builder,"acercade"));
		switchgtk = GTK_WIDGET(gtk_builder_get_object(builder,"activador_sql"));
		source_code = GTK_WIDGET(gtk_builder_get_object(builder,"Codigo_sql"));
		lbl_no_datos = GTK_WIDGET(gtk_builder_get_object(builder,"lbl_no_datos"));
		lbl_añadir_advertencia = GTK_LABEL(gtk_builder_get_object(builder,"lbl_añadir_advertencia"));
		lbl_eliminar_advertencia = GTK_LABEL(gtk_builder_get_object(builder,"lbl_eliminar_advertencia"));
		advertencia_añadir_fac = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_añadir_fac"));
		advertencia_añadir_emp = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_añadir_emp"));
		advertencia_añadir_pro = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_añadir_pro"));
		advertencia_actualizar_emp = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_actualizar_emp"));
		advertencia_actualizar_fac = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_actualizar_fac"));
		advertencia_actualizar_pro = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_actualizar_pro"));
		advertencia_eliminar_fac = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_eliminar_fac"));
		advertencia_eliminar_pro = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_eliminar_pro"));
		advertencia_eliminar_emp = GTK_WIDGET(gtk_builder_get_object(builder,"advertencia_eliminar_emp"));
		seleccion_view = GTK_TREE_SELECTION(gtk_builder_get_object(builder,"seleccion_view"));
		seleccion_view2 = GTK_TREE_SELECTION(gtk_builder_get_object(builder,"seleccion_view2"));
		debug_textview = GTK_TEXT_VIEW(gtk_builder_get_object(builder,"debug_textview"));
		debug = GTK_WIDGET(gtk_builder_get_object(builder,"debug"));
		textbuffer_main = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "textbuffer_main"));
		entry_buscar = GTK_ENTRY(gtk_builder_get_object(builder,"entry_buscar"));
		historial_busqueda = GTK_WIDGET(gtk_builder_get_object(builder,"historial_busqueda"));
		stack_historial = GTK_WIDGET(gtk_builder_get_object(builder,"stack_historial"));
		contenedor_historial = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_historial"));
		
		ety_idpro = GTK_ENTRY(gtk_builder_get_object(builder,"ety_idpro"));
		ety_idemp = GTK_ENTRY(gtk_builder_get_object(builder,"ety_idemp"));
		ety_catidad = GTK_ENTRY(gtk_builder_get_object(builder,"ety_catidad"));
		ety_precio = GTK_ENTRY(gtk_builder_get_object(builder,"ety_precio"));
		ety_mpago = GTK_ENTRY(gtk_builder_get_object(builder,"ety_mpago"));
		ety_desc = GTK_ENTRY(gtk_builder_get_object(builder,"ety_desc"));
		ety_total = GTK_ENTRY(gtk_builder_get_object(builder,"ety_total"));
		
		ety_produ_emp = GTK_ENTRY(gtk_builder_get_object(builder,"ety_produ_emp"));
		ety_nombreemp = GTK_ENTRY(gtk_builder_get_object(builder,"ety_nombreemp"));
		ety_direccion = GTK_ENTRY(gtk_builder_get_object(builder,"ety_direccion"));
		ety_telefono = GTK_ENTRY(gtk_builder_get_object(builder,"ety_telefono"));
		ety_region = GTK_ENTRY(gtk_builder_get_object(builder,"ety_region"));
		ety_pais = GTK_ENTRY(gtk_builder_get_object(builder,"ety_pais"));
		ety_rfc = GTK_ENTRY(gtk_builder_get_object(builder,"ety_rfc"));
		ety_correoemp = GTK_ENTRY(gtk_builder_get_object(builder,"ety_correoemp"));
		
		ety_nombrepro = GTK_ENTRY(gtk_builder_get_object(builder,"ety_nombrepro"));
		ety_marcapro = GTK_ENTRY(gtk_builder_get_object(builder,"ety_marcapro"));
		ety_nlote = GTK_ENTRY(gtk_builder_get_object(builder,"ety_nlote"));
		ety_des = GTK_ENTRY(gtk_builder_get_object(builder,"ety_des"));
		ety_cbarra = GTK_ENTRY(gtk_builder_get_object(builder,"ety_cbarra"));
		ety_cneto = GTK_ENTRY(gtk_builder_get_object(builder,"ety_cneto"));
		
		ety_id_empresa = GTK_ENTRY(gtk_builder_get_object(builder,"ety_id_empresa"));
		ety_id_producto = GTK_ENTRY(gtk_builder_get_object(builder,"ety_id_producto"));
		ety_nombre_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_nombre_act"));
		ety_direccion_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_direccion_act"));
		ety_telefono_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_telefono_act"));
		ety_region_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_region_act"));
		ety_pais_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_pais_act"));
		ety_rfc_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_rfc_act"));
		ety_correo_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_correo_act"));
		
		id_fac_act = GTK_ENTRY(gtk_builder_get_object(builder,"id_fac_act"));
		ety_profac_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_profac_act"));
		ety_empfact_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_empfact_act"));
		ety_cantidafac_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_cantidafac_act"));
		ety_preci_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_preci_act"));
		ety_mpago_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_mpago_act"));
		ety_descfac_act1 = GTK_ENTRY(gtk_builder_get_object(builder,"ety_descfac_act1"));
		ety_totalfac_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_totalfac_act"));
		
		ety_idpro_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_idpro_act"));
		ety_nombrepro_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_nombrepro_act"));
		ety_marcapro_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_marcapro_act"));
		ety_nlotepro_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_nlotepro_act"));
		ety_descpro_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_descpro_act"));
		ety_cbarrapro_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_cbarrapro_act"));
		ety_cnetopro_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_cnetopro_act"));
		
		ety_id_fac_borrar = GTK_ENTRY(gtk_builder_get_object(builder,"ety_id_fac_borrar"));
		ety_id_emp_borrar = GTK_ENTRY(gtk_builder_get_object(builder,"ety_id_emp_borrar"));
		ety_id_pro_borrar = GTK_ENTRY(gtk_builder_get_object(builder,"ety_id_pro_borrar"));
		cb_dia_fac = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_fac"));
		cb_mes_fac = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_fac"));
		cb_anio_fac = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_fac"));
		cb_dia_pro = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_pro"));
		cb_mes_pro = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_pro"));
		cb_anio_pro = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_pro"));
		cb_dia_propro = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_propro"));
		cb_mes_propro = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_propro"));
		cb_anio_propro = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_propro"));
		cb_dia_fac_actu = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_fac_actu"));
		cb_mes_fac_actu = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_fac_actu"));
		cb_anio_fac_actu = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_fac_actu"));
		
		cb_dia_proact = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_proact"));
		cb_mes_proact = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_proact"));
		cb_anio_proact = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_proact"));
		
		cb_dia_proact2 = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_proact2"));
		cb_mes_proact2 = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_proact2"));
		cb_anio_proact2 = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_proact2"));
		
		calendario_factura = GTK_CALENDAR(gtk_builder_get_object(builder,"calendario_factura"));
		btn_eliminar_datos = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"btn_eliminar_datos"));
		
		
		selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(historial_busqueda));
		
		init_list(historial_busqueda);
		
		for(i=2021;i>=1950;i--){ 
			sprintf(anio,"%d",i);
			gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_fac),anio);
			gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_fac_actu),anio);
			gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_pro),anio);
			gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_propro),anio);
			gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_proact),anio);
			gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_proact2),anio);
		}

		gtk_builder_connect_signals(builder, NULL);
		g_object_unref(builder);
		gtk_widget_show(window_login);  
		gtk_main();
	}

//=========== Añadir datos =====================================
void on_btn_añadir_datos_clicked(){
const char *tabla = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(tabla_items));
	if(tabla[0]== 'E'){
		gtk_widget_show(inserta_empresa);
	}else if(tabla[0]== 'F'){
			gtk_widget_show(inserta_factura);
		}else if(tabla[0]== 'P'){
				gtk_widget_show(inserta_producto);
			}
}
void on_cancela_and_factura4_clicked(){
		gtk_widget_hide(inserta_producto);
	}
void on_cancela_and_factura2_clicked(){
		gtk_widget_hide(inserta_empresa);
	}
void on_btn_cancelar_adver_clicked(){
	gtk_widget_hide(advertencia_añadir_fac);
	}
void on_cancela_and_factura_clicked(){
	gtk_widget_hide_on_delete(inserta_factura);
	}
	
void on_fac_aceptar_añadir_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "Tienda";
	char anadir_fac[512];
	char date[12];
	char *server = "localhost";

	
	const char 		*dia = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_dia_fac));
	const char 		*mes = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_mes_fac));
	const char 		*anio = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_anio_fac));
	const char 		*id_pro = gtk_entry_get_text(ety_idpro);
	const char 		*id_emp = gtk_entry_get_text(ety_idemp);
	const char		*cantidad = gtk_entry_get_text(ety_catidad);
	const char		*precio = gtk_entry_get_text(ety_precio);
	const char		*mpago = gtk_entry_get_text(ety_mpago);
	const char		*descuento = gtk_entry_get_text(ety_desc);
	const char		*total = gtk_entry_get_text(ety_total);
	
	
	sprintf(date,"%s-%s-%s",anio,mes,dia);
	sprintf(anadir_fac,"insert into Factura (Idfactura,Idproducto,Idempresa,Fechadeventa,cantidad,precio,ModoPago,Descuento,Total) values(null,%s,%s,'%s',%s,%s,'%s',%s,%s)",id_pro,id_emp,date,cantidad,precio,mpago,descuento,total);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, anadir_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_añadir_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s",row[0]);
	}
	
	gtk_entry_set_text(ety_idpro,"");
	gtk_entry_set_text(ety_idemp,"");
	gtk_entry_set_text(ety_catidad,"");
	gtk_entry_set_text(ety_precio,"");
	gtk_entry_set_text(ety_mpago,"");
	gtk_entry_set_text(ety_desc,"");
	gtk_entry_set_text(ety_total,"");
	
	refresca_datos_fac();
	contenido_tablas();

	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_añadir_fac);
	gtk_widget_show(info_ananido);
	}
void on_inserta_datos_factura_clicked(){
		gtk_widget_show(advertencia_añadir_fac);
	}
void on_inserta_datos_empresa_clicked(){
		gtk_widget_show(advertencia_añadir_emp);
	}
void on_emp_aceptar_añadir_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "Tienda";
	char anadir_fac[512];
	char *server = "localhost";

	
	const char 		*id_prodi = gtk_entry_get_text(ety_produ_emp);
	const char 		*id_nom_emp = gtk_entry_get_text(ety_nombreemp);
	const char		*direccion = gtk_entry_get_text(ety_direccion);
	const char		*telefono = gtk_entry_get_text(ety_telefono);
	const char		*region = gtk_entry_get_text(ety_region);
	const char		*pais = gtk_entry_get_text(ety_pais);
	const char		*rfc_emp = gtk_entry_get_text(ety_rfc);
	const char		*correo = gtk_entry_get_text(ety_correoemp);
	
	
	sprintf(anadir_fac,"insert into Empresa values(null,%s, '%s' , '%s', %s , '%s' , '%s' , '%s' , '%s' )",id_prodi,id_nom_emp,direccion,telefono,region,pais,rfc_emp,correo);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, anadir_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_añadir_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s",row[0]);
	}
	
	gtk_entry_set_text(ety_produ_emp,"");
	gtk_entry_set_text(ety_nombreemp,"");
	gtk_entry_set_text(ety_direccion,"");
	gtk_entry_set_text(ety_telefono,"");
	gtk_entry_set_text(ety_region,"");
	gtk_entry_set_text(ety_pais,"");
	gtk_entry_set_text(ety_rfc,"");
	gtk_entry_set_text(ety_correoemp,"");
	
	refresca_datos_emp();
	contenido_tablas();

	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_añadir_emp);
	gtk_widget_show(info_ananido);
	}
void on_btn_cancelar_adver6_clicked(){
		gtk_widget_hide(advertencia_añadir_emp);
	}
void on_btn_cancelar_adver7_clicked(){
		gtk_widget_hide(advertencia_añadir_pro);
	}
void on_inserta_datos_empres_clicked(){
		gtk_widget_show(advertencia_añadir_pro);
	}
void on_pro_aceptar_añadir_clicked (){
user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "Tienda";
	char anadir_fac[512];
	char date[12];
	char date2[12];
	char *server = "localhost";

	
	const char 		*dia = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_dia_pro));
	const char 		*mes = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_mes_pro));
	const char 		*anio = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_anio_pro));
	
	const char 		*dia2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_dia_propro));
	const char 		*mes2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_mes_propro));
	const char 		*anio2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_anio_propro));
	
	const char 		*nombre = gtk_entry_get_text(ety_nombrepro);
	const char 		*marca = gtk_entry_get_text(ety_marcapro);
	const char		*nlote = gtk_entry_get_text(ety_nlote);
	const char		*desc = gtk_entry_get_text(ety_des);
	const char		*cbarra = gtk_entry_get_text(ety_cbarra);
	const char		*cneto = gtk_entry_get_text(ety_cneto);
	
	
	sprintf(date,"%s-%s-%s",anio,mes,dia);
	sprintf(date2,"%s-%s-%s",anio2,mes2,dia2);
	sprintf(anadir_fac,"insert into Producto (Idproducto,Nombre,Marca,Fechacaducidad,Fechaproduccion,Numerolote,Descripcion,Codigobarras,Contenidoneto) values(null,'%s','%s','%s','%s',%s,'%s',%s,'%s')",nombre,marca,date,date2,nlote,desc,cbarra,cneto);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, anadir_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_añadir_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s",row[0]);
	}
	
	gtk_entry_set_text(ety_nombrepro,"");
	gtk_entry_set_text(ety_marcapro,"");
	gtk_entry_set_text(ety_nlote,"");
	gtk_entry_set_text(ety_des,"");
	gtk_entry_set_text(ety_cbarra,"");
	gtk_entry_set_text(ety_cneto,"");
	
	refresca_datos_pro();
	contenido_tablas();

	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_añadir_pro);
	gtk_widget_show(info_ananido);
	}
//================================================
void on_mostrar_calendario_toggled(){
	gboolean button_state;
	button_state = gtk_toggle_button_get_active(mostrar_calendario);
	if (button_state) {
		// button is active
		gtk_widget_set_visible (pop_calendario,gtk_toggle_button_get_active (mostrar_calendario));
	}
	else {
		// button is inactive
		gtk_widget_hide(pop_calendario);
	}
	
}
void on_btn_aceptar_1_clicked(){
	gtk_widget_hide(dialog_error_datos);
	}
//=========== Actualiza datos ====================================
void on_btn_aceptar__clicked(){

	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "Tienda";
	char date[13];
	char actualiza_fac[512];
	char *server = "localhost";
	
	const char 		*id = gtk_entry_get_text(id_fac_act);
	const char 		*idpro = gtk_entry_get_text(ety_profac_act);
	const char 		*idemp = gtk_entry_get_text(ety_empfact_act);
	const char		*cantidad = gtk_entry_get_text(ety_cantidafac_act);
	const char		*precio = gtk_entry_get_text(ety_preci_act);
	const char		*mpago = gtk_entry_get_text(ety_mpago_act);
	const char		*descuento = gtk_entry_get_text(ety_descfac_act1);
	const char		*total = gtk_entry_get_text(ety_totalfac_act);
	
	const char 		*dia = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_dia_fac_actu));
	const char 		*mes = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_mes_fac_actu));
	const char 		*anio2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_anio_fac_actu));

	sprintf(date,"'%s-%s-%s'",anio2,mes,dia);
	sprintf(actualiza_fac,"update Factura set Idproducto=%s, Idempresa=%s, Fechadeventa=%s, cantidad=%s, precio='%s', ModoPago='%s',Descuento=%s,Total=%s where idfactura=%s",idpro,idemp,date,cantidad,precio,mpago,descuento,total,id);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, actualiza_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_actualizar_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s",row[0]);
	}
	
	gtk_entry_set_text(id_fac_act,"");
	gtk_entry_set_text(ety_profac_act,"");
	gtk_entry_set_text(ety_empfact_act,"");
	gtk_entry_set_text(ety_cantidafac_act,"");
	gtk_entry_set_text(ety_preci_act,"");
	gtk_entry_set_text(ety_mpago_act,"");
	gtk_entry_set_text(ety_descfac_act1,"");
	gtk_entry_set_text(ety_totalfac_act,"");
	
	refresca_datos_fac();
	contenido_tablas();
	
	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_actualizar_fac);
	gtk_widget_show(info_actualizar);
	}
void on_actualiza_datos_factura_clicked(){
		gtk_widget_show(advertencia_actualizar_fac);
	}
void on_cancela_and_factura1_clicked(){
		gtk_widget_hide(actualiza_factura);
	}
void on_btn_actualizar_datos_clicked(){
	const char *tabla = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(tabla_items));
	if(tabla[0]== 'E'){
		gtk_widget_show(actualiza_empresa);
	}else if(tabla[0]== 'F'){
			gtk_widget_show(actualiza_factura);
		}else if(tabla[0]== 'P'){
				gtk_widget_show(actualiza_producto);
}
	}
void on_btn_cancelar_adver1_clicked(){
	gtk_widget_hide(advertencia_actualizar_fac);
	}
void on_cancela_and_factura5_clicked(){
	gtk_widget_hide(actualiza_producto);
	}
void on_cancela_and_factura3_clicked(){
	gtk_widget_hide(actualiza_empresa);
	}
void on_actualiza_datos_empresa_clicked(){
	gtk_widget_show(advertencia_actualizar_emp);
	}
void on_btn_cancelar_adver4_clicked(){
	gtk_widget_hide(advertencia_actualizar_emp);
	}
void on_btn_actualiza_emp_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "Tienda";
	char anadir_fac[512];
	char *server = "localhost";

	
	const char 		*id_emp = gtk_entry_get_text(ety_id_empresa);
	const char 		*id_pro = gtk_entry_get_text(ety_id_producto);
	const char		*nombre = gtk_entry_get_text(ety_nombre_act);
	const char		*direccion = gtk_entry_get_text(ety_direccion_act);
	const char		*telefono = gtk_entry_get_text(ety_telefono_act);
	const char		*region = gtk_entry_get_text(ety_region_act);
	const char		*pais = gtk_entry_get_text(ety_pais_act);
	const char		*rfc = gtk_entry_get_text(ety_rfc_act);
	const char		*correo = gtk_entry_get_text(ety_correo_act);
	
	
	sprintf(anadir_fac,"update Empresa set Idproducto= %s, Nombre='%s', Direccion='%s', Telefono=%s, Region='%s', Pais='%s' ,Rfc='%s',Correo='%s' where Idempresa =  %s",id_pro,nombre,direccion,telefono,region,pais,rfc,correo,id_emp);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, anadir_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_añadir_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s",row[0]);
	}
	
	gtk_entry_set_text(ety_id_empresa,"");
	gtk_entry_set_text(ety_id_producto,"");
	gtk_entry_set_text(ety_nombre_act,"");
	gtk_entry_set_text(ety_direccion_act,"");
	gtk_entry_set_text(ety_telefono_act,"");
	gtk_entry_set_text(ety_region_act,"");
	gtk_entry_set_text(ety_pais_act,"");
	gtk_entry_set_text(ety_rfc_act,"");
	gtk_entry_set_text(ety_correo_act,"");
	
	refresca_datos_emp();
	contenido_tablas();

	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_actualizar_emp);	
	gtk_widget_show(info_actualizar);
	}
	
void on_actualiza_datos_producto_clicked(){
	gtk_widget_show(advertencia_actualizar_pro);
	}
void on_btn_cancelar_adver5_clicked(){
	gtk_widget_hide(advertencia_actualizar_pro);
	}
void on_btn_actualiza_pro_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "Tienda";
	char date[12];
	char date2[13];
	char anadir_fac[512];
	char *server = "localhost";

	
	const char 		*id_pro = gtk_entry_get_text(ety_idpro_act);
	const char		*nombre = gtk_entry_get_text(ety_nombrepro_act);
	const char		*marca = gtk_entry_get_text(ety_marcapro_act);
	const char		*nlote = gtk_entry_get_text(ety_nlotepro_act);
	const char		*desc = gtk_entry_get_text(ety_descpro_act);
	const char		*cbarra = gtk_entry_get_text(ety_cbarrapro_act);
	const char		*cneto = gtk_entry_get_text(ety_cnetopro_act);
	
	const char 		*dia = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_dia_proact));
	const char 		*mes = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_mes_proact));
	const char 		*anio = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_anio_proact));
	
	const char 		*dia2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_dia_proact2));
	const char 		*mes2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_mes_proact2));
	const char 		*anio2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_anio_proact2));
	
	sprintf(date,"%s-%s-%s",anio,mes,dia);
	sprintf(date2,"%s-%s-%s",anio2,mes2,dia2);
	sprintf(anadir_fac,"update Producto set Nombre= '%s' , Marca='%s' , Fechacaducidad='%s' , Fechaproduccion= '%s' , Numerolote= %s , Descripcion= '%s' ,Codigobarras= %s ,Contenidoneto= '%s' where Idproducto = %s",nombre,marca,date,date2,nlote,desc,cbarra,cneto,id_pro);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, anadir_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_añadir_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s",row[0]);
	}
	gtk_entry_set_text(ety_idpro_act,"");
	gtk_entry_set_text(ety_nombrepro_act,"");
	gtk_entry_set_text(ety_marcapro_act,"");
	gtk_entry_set_text(ety_nlotepro_act,"");
	gtk_entry_set_text(ety_descpro_act,"");
	gtk_entry_set_text(ety_cbarrapro_act,"");
	gtk_entry_set_text(ety_cnetopro_act,"");

	refresca_datos_pro();
	contenido_tablas();

	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_actualizar_pro);		
	gtk_widget_show(info_actualizar);
	
}
//================================================
//=========== Elimina datos =====================================
void on_btn_eliminar_datos_toggled(){
	const char *tabla = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(tabla_items));
	gboolean button_state;
	button_state = gtk_toggle_button_get_active(btn_eliminar_datos);

	if(tabla[0]== 'E'){
		if (button_state) {
		// button is active
		gtk_widget_set_visible (pop_delete_emp,gtk_toggle_button_get_active (btn_eliminar_datos));
	}
	else {
		// button is inactive
		gtk_widget_hide(pop_delete_emp);
	}
	}else if(tabla[0]== 'F'){
			if (button_state) {
		// button is active
		gtk_widget_set_visible (pop_delete_fac,gtk_toggle_button_get_active (btn_eliminar_datos));
	}
	else {
		// button is inactive
		gtk_widget_hide(pop_delete_fac);
	}
		}else if(tabla[0]== 'P'){
				if (button_state) {
		// button is active
		gtk_widget_set_visible (pop_delete_pro,gtk_toggle_button_get_active (btn_eliminar_datos));
	}
	else {
		// button is inactive
		gtk_widget_hide(pop_delete_pro);
	}
		}
}
void on_btn_borrar_fac_clicked(){
	gtk_widget_show(advertencia_eliminar_fac);
}
void on_ety_id_fac_borrar_activate(){
	gtk_widget_show(advertencia_eliminar_fac);
}
void on_btn_aceptar_a_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "Tienda";
	char elimina_fac[50];
	char *server = "localhost";
	
	const char 	*id = gtk_entry_get_text(ety_id_fac_borrar);

	sprintf(elimina_fac,"delete from Factura where idfactura=%s",id);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, elimina_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_eliminar_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		//printf("%s",row[0]);
	}
	
	gtk_entry_set_text(ety_id_fac_borrar,"");
	
	if (gtk_tree_model_get_iter_first(model2, &iter2) == TRUE) {
		refresca_datos_fac();
		if (gtk_tree_model_get_iter_first(model2, &iter2) == FALSE) {
		gtk_stack_set_visible_child (GTK_STACK(stackgtk),lbl_no_datos);	
		}else{
	contenido_tablas();
}
}
	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_eliminar_fac);
	gtk_widget_show(info_eliminado);
}
void on_btn_cancelar_adver2_clicked(){
	gtk_widget_hide(advertencia_eliminar_fac);
	}
void on_btn_borrar_emp_clicked(){
	gtk_widget_show(advertencia_eliminar_emp);
	}
void on_btn_cancelar_adver8_clicked(){
	gtk_widget_hide(advertencia_actualizar_emp);
	}
void on_btn_aceptar_a1_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "Tienda";
	char elimina_fac[50];
	char *server = "localhost";
	
	const char 	*id = gtk_entry_get_text(ety_id_emp_borrar);

	sprintf(elimina_fac,"delete from Empresa where Idempresa=%s",id);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, elimina_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_eliminar_fac);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		//printf("%s",row[0]);
	}
	
	gtk_entry_set_text(ety_id_emp_borrar,"");
	
	refresca_datos_emp();
	contenido_tablas();

	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_eliminar_emp);
	gtk_widget_show(info_eliminado);
}
void on_btn_borrar_pro_clicked(){
	gtk_widget_show(advertencia_eliminar_pro);
	}
void on_btn_aceptar_a2_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "Tienda";
	char elimina_fac[50];
	char *server = "localhost";
	
	const char 	*id = gtk_entry_get_text(ety_id_pro_borrar);

	sprintf(elimina_fac,"delete from Producto where Idproducto=%s",id);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, elimina_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(advertencia_eliminar_pro);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		//printf("%s",row[0]);
	}
	
	gtk_entry_set_text(ety_id_pro_borrar,"");
	
	refresca_datos_pro();
	contenido_tablas();

	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(advertencia_eliminar_pro);
	gtk_widget_show(info_eliminado);
}
	
//================================================
void on_Window_BD_destroy()
{
	gtk_main_quit();
	}
void on_window_main_destroy()
{
    gtk_main_quit();
}
void on_btn_cerrar_acd_clicked (){
	gtk_widget_hide (win_acercade);
	}
void on_activador_sql_state_set(){
	if (gtk_switch_get_active (GTK_SWITCH (switchgtk))){
		gtk_stack_set_visible_child (GTK_STACK(stack_aceptar),btn_sql_aceptar);
		gtk_stack_set_visible_child (GTK_STACK(stack_sql),contenedor_sql);
	}else{
		gtk_stack_set_visible_child (GTK_STACK(stack_aceptar),ocultar_btn);
		gtk_stack_set_visible_child (GTK_STACK(stack_sql),debug);
	}
}
void remove_item() {
    
  GtkListStore *store_bus;
  GtkTreeIter iter_bus;
  GtkTreeModel *model_bus;

  store_bus = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(historial_busqueda)));
  model_bus = gtk_tree_view_get_model(GTK_TREE_VIEW(historial_busqueda));

  if (gtk_tree_model_get_iter_first(model_bus, &iter_bus) == FALSE) {
      return;
  }

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), &model_bus, &iter_bus)) {
    gtk_list_store_remove(store_bus, &iter_bus);
  }
}
void remove_all() {
    
  GtkListStore *store_bus;
  GtkTreeModel *model_bus;
  GtkTreeIter  iter_bus;

  store_bus = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(historial_busqueda)));
  model_bus = gtk_tree_view_get_model(GTK_TREE_VIEW(historial_busqueda));

  if (gtk_tree_model_get_iter_first(model_bus, &iter_bus) == TRUE) {
	  gtk_list_store_clear(store_bus);
      return;
  }
  gtk_list_store_clear(store_bus);
  
}

void meter_historial(){
	GtkListStore 	*store_bus;
	GtkTreeIter 	iter_bus;

	const gchar *str = gtk_entry_get_text(entry_buscar); 

	store_bus = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(historial_busqueda)));

	gtk_list_store_append(store_bus, &iter_bus);
	gtk_list_store_set(store_bus, &iter_bus, LIST_ITEM, str, -1);
	
	gtk_stack_set_visible_child (GTK_STACK(stack_historial),contenedor_historial);
	gtk_entry_set_text(entry_buscar,"");
}
	

void on_entry_buscar_activate(){
	refresca_busqueda();
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "Tienda";
	char busqueda_fac[50];
	char *server = "localhost";
	
	const char 	*busqueda = gtk_entry_get_text(entry_buscar);

	sprintf(busqueda_fac,"select * from Producto where Nombre = '%s'",busqueda);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, busqueda_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {

			
			gtk_stack_set_visible_child (GTK_STACK(stack_busqueda),contenedor_busqueda);	
			if (gtk_tree_model_get_iter_first(model_busc, &iter_busqueda) == FALSE) {
					 titulo_factura_auditoria_busqueda();
					 meter_historial();
					return ;	
			}
}
	mysql_free_result(res);
	mysql_close(conn);
	
	
}
void on_btn_consulta_emp_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "Tienda";
	char busqueda_fac[50];
	char *server = "localhost";
	
	const char 	*consulta = gtk_entry_get_text(ety_id_empresa);

	sprintf(busqueda_fac,"select * from Empresa where Idempresa = %s",consulta);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, busqueda_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		
		
			gtk_entry_set_text(ety_id_producto,row[1]);
			gtk_entry_set_text(ety_nombre_act,row[2]);
			gtk_entry_set_text(ety_direccion_act,row[3]);
			gtk_entry_set_text(ety_telefono_act,row[4]);
			gtk_entry_set_text(ety_region_act,row[5]);
			gtk_entry_set_text(ety_pais_act,row[6]);
			gtk_entry_set_text(ety_rfc_act,row[7]);
			gtk_entry_set_text(ety_correo_act,row[8]);
		}
	
	mysql_free_result(res);
	mysql_close(conn);
}
void on_btn_consulta_fac_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "Tienda";
	char busqueda_fac[50];
	char *server = "localhost";
	
	const char 	*consulta = gtk_entry_get_text(id_fac_act);

	sprintf(busqueda_fac,"select * from Factura where Idfactura = %s",consulta);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, busqueda_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		
			gtk_entry_set_text(ety_profac_act,row[1]);
			gtk_entry_set_text(ety_empfact_act,row[2]);
			gtk_entry_set_text(ety_cantidafac_act,row[4]);
			gtk_entry_set_text(ety_preci_act,row[5]);
			gtk_entry_set_text(ety_mpago_act,row[6]);
			gtk_entry_set_text(ety_descfac_act1,row[7]);
			gtk_entry_set_text(ety_totalfac_act,row[8]);
		}
	
	mysql_free_result(res);
	mysql_close(conn);
	
}
void on_btn_consulta_pro_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "Tienda";
	char busqueda_fac[50];
	char *server = "localhost";
	
	const char 	*consulta = gtk_entry_get_text(ety_idpro_act);

	sprintf(busqueda_fac,"select * from Producto where Idproducto = %s",consulta);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, busqueda_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		
			gtk_entry_set_text(ety_nombrepro_act,row[1]);
			gtk_entry_set_text(ety_marcapro_act,row[2]);
			gtk_entry_set_text(ety_nlotepro_act,row[5]);
			gtk_entry_set_text(ety_descpro_act,row[6]);
			gtk_entry_set_text(ety_cbarrapro_act,row[7]);
			gtk_entry_set_text(ety_cnetopro_act,row[8]);
		}
	
	mysql_free_result(res);
	mysql_close(conn);
}
void on_exportar_pdf_clicked(){
	const char *tabla = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(tabla_items));
	char exporta [40];
	sprintf(exporta,"select * from %s",tabla);
	
	const char cabeceras []="\\documentclass[a4paper,6pt]{report}\n\\usepackage[T1]{fontenc}\n \\usepackage[utf8]{inputenc}\n\\usepackage{lmodern}\n\\usepackage[spanish]{babel}\n\\usepackage{pdflscape}\n";
	char init_document [] = "\\begin{document}\n\\begin{landscape}\n \\setlength{\\textwidth}{10mm}\n\\setlength{\\textheight}{10mm}\n \\setlength{\\oddsidemargin}{-70mm} \n\\setlength{\\evensidemargin}{100mm}\n\\setlength{\\topmargin}{35mm}\n";
	char campos [] = "ID & ID Pro. Ant. & Nombre Ant. & Direccion Ant. & Tel. Ant. & Region Ant. & Pais Ant. & RFC Ant. & Correo Ant. & ID Pro. New & Nombre New & Direcc. New & Telefono New & Region New & Pais New & RFC New & Correo New & User & Modificado & Accion & Id Empresa\\\\ \\hline \\hline\n";
	char campos2 [] = "ID & ID Pro. Ant. & ID Emp. Ant. & Fecha Ven. Ant. & Can. Ant. & Precio Ant. & M.Pago Ant. & Desc. Ant. & Total Ant. & ID Pro. New & ID Emp New & F. Ven. New & Cant. New & Precio New & MPago New & Desc. New & Total New & User & Modificado & Accion & Id Fac.\\\\ \\hline \\hline\n";
	char campos3 [] = "ID & Nombre Ant. & Marca Ant. & FCaducidad Ant. & FProduccion Ant. & Num. Lote Ant. & Desc. Ant. & CBarra Ant. & Con. Neto Ant. & Nombre New & Marca New & FCaducidad New & FProd. New & Num. Lote New & Desc. New & CBarra New & Con. Neto & User & Modificado & Accion & Id Pro.\\\\ \\hline \\hline\n";

	char inicia_tabla [] = "\\begin{table}\n\\label{tab:}\n\\begin{center}\n \\resizebox{27cm}{!} { \n\\begin{tabular}{| c | c | c | c | c | c | c | c | c | c | c | c | c | c | c | c | c | c | c | c | c | }\n";
	char fin_tabla [] = "\\end{tabular}\n }\\end{center}\n\\end{table}\n";
	char fin_documento [] = "\n\\end{landscape}\n\\end{document}";
	char hline[]= "\\hline\n";

	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "Tienda";
	char *server = "localhost";
	
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, exporta))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	
//==========================================================================================================================================================		
	if(tabla[10]== 'e'){
		fichero = fopen("Empresa.tex", "wt");
	fputs(cabeceras, fichero);
	fputs(init_document, fichero);
	fputs(inicia_tabla, fichero);
	fputs(hline,fichero);
	fputs(campos, fichero);
	while ((row = mysql_fetch_row(res)) != NULL) {
		fprintf(fichero,"%s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s \\\\ \\hline\n",row[0],row[1],row[2],row[3],row[4],row[5],row[6],row[7],row[8],row[9],row[10],row[11],row[12],row[13],row[14],row[15],row[16],row[17],row[18],row[19],row[20]);
	}
	fputs(hline,fichero);
	fputs(fin_tabla,fichero);
	fputs(fin_documento, fichero);
	fclose(fichero); 
	system("latexmk -pdf -synctex=1 Empresa.tex ");
    system("evince Empresa.pdf &");
    //return ;
//==========================================================================================================================================================    
	}else if(tabla[10]== 'f'){
	fichero2 = fopen("Factura.tex", "wt");
	fputs(cabeceras, fichero2);
	fputs(init_document, fichero2);
	fputs(inicia_tabla, fichero2);
	fputs(hline,fichero2);
	fputs(campos2, fichero2);
	while ((row = mysql_fetch_row(res)) != NULL) {
		fprintf(fichero2,"%s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s \\\\ \\hline\n",row[0],row[1],row[2],row[3],row[4],row[5],row[6],row[7],row[8],row[9],row[10],row[11],row[12],row[13],row[14],row[15],row[16],row[17],row[18],row[19],row[20]);
	}
	fputs(hline,fichero2);
	fputs(fin_tabla,fichero2);
	fputs(fin_documento, fichero2);
	fclose(fichero2); 
	system("latexmk -pdf -synctex=1 Factura.tex ");
    system("evince Factura.pdf &");
   // return ;
//==========================================================================================================================================================   
		}else if(tabla[10]== 'p'){
	fichero3 = fopen("Producto.tex", "wt");
	fputs(cabeceras, fichero3);
	fputs(init_document, fichero3);
	fputs(inicia_tabla, fichero3);
	fputs(hline,fichero3);
	fputs(campos3, fichero3);
	while ((row = mysql_fetch_row(res)) != NULL) {
		fprintf(fichero3,"%s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s & %s \\\\ \\hline\n",row[0],row[1],row[2],row[3],row[4],row[5],row[6],row[7],row[8],row[9],row[10],row[11],row[12],row[13],row[14],row[15],row[16],row[17],row[18],row[19],row[20]);
	}
	fputs(hline,fichero3);
	fputs(fin_tabla,fichero3);
	fputs(fin_documento, fichero3);
	fclose(fichero3); 
	system("latexmk -pdf -synctex=1 Producto.tex ");
    system("evince Producto.pdf &");
    //return ;
}
//==========================================================================================================================================================
	mysql_free_result(res);
	mysql_close(conn);
  

    printf("Proceso completado");
	}
void on_remover_item_clicked(){
	remove_item();
	}
void on_remover_todos_items_clicked(){
	remove_all();
	}
void on_acercade_close (){
	gtk_dialog_run (GTK_DIALOG (win_acercade));
	gtk_widget_hide_on_delete(win_acercade);
	}
void on_cerrar_acercade_clicked(){
	gtk_widget_hide_on_delete(win_acercade);
	}
void on_acercade_destroy(){
	gtk_widget_hide(win_acercade);
		}	
void on_btn_aceptar_dial_advertencia_clicked(){
	
	} 
void on_btn_aceptar_2_clicked(){
	gtk_widget_hide(info_actualizar);
	}
void on_btn_aceptar_3_clicked(){
	gtk_widget_hide(info_ananido);
	}
void on_btn_aceptar_4_clicked(){
	gtk_widget_hide(info_eliminado);
	}
