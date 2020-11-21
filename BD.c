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


#include <gtk/gtk.h>
#include <mysql.h> 
#include <stdio.h>
#include <gtksourceview/gtksource.h>

GtkBuilder      	*builder; 
GtkWidget   	    *window_login;
GtkEntry 			*g_Entry_Usuario;
GtkToggleButton		*mostrar_calendario;
GtkEntry 			*g_Entry_Contraseña;
GtkEntry			*entry_buscar;
GtkEntry			*ety_clien;
GtkEntry			*ety_apelli;
GtkEntry			*ety_fcomp;
GtkEntry			*ety_monto;
GtkEntry			*ety_prod;
GtkEntry			*ety_clien_act;
GtkEntry			*ety_apelli_act;
GtkEntry			*ety_fcomp_act;
GtkEntry			*ety_monto_act;
GtkEntry			*ety_prod_act;
GtkEntry			*id_fac_act;
GtkEntry			*ety_id_fac_borrar;
GtkWidget 			*g_Dialog_Error;
GtkWidget			*window_BD;
GtkWidget			*inserta_factura;	
GtkWidget			*actualiza_factura;
GtkWidget 			*pop_delete_fac;
GtkWidget			*cb_anio_fac;
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
GtkToggleButton		*btn_eliminar_datos;
GtkWidget			*cb_anio_fac_actu;
GtkWidget			*cb_mes_fac_actu;
GtkWidget			*cb_dia_fac_actu;
GtkWidget			*menu_items;
GtkWidget			*tabla_items;
GtkWidget			*switchgtk;
GtkWidget			*stack_sql;
GtkWidget			*stack_historial;
GtkWidget			*stack_aceptar;
GtkWidget			*btn_sql_aceptar;
GtkWidget			*ocultar_btn;
GtkWidget       	*view;
GtkWidget			*dialog_error_datos;
GtkWidget       	*view2;
GtkWidget			*view_busc;
GtkWidget			*stack_busqueda;
GtkWidget			*contenedor_historial;
GtkWidget			*contenedor_busqueda;
GtkWidget			*historial_busqueda;
GtkWidget       	*debug;
GtkCalendar			*calendario_factura;
GtkTextBuffer 		*textbuffer_main;
GtkTextView			*debug_textview;
GtkWidget       	*dialog_advertencia_añadir;
GtkWidget       	*dialog_advertencia_actualizar;
GtkWidget       	*dialog_advertencia_eliminar;
GtkWidget			*contenedor_view2;
GtkWidget			*contenedor_view;
GtkWidget			*contenedor_sql;
GtkWidget       	*stackgtk;
MYSQL 				*conn;
MYSQL_RES 			*res;
MYSQL_ROW 			row;
GtkListStore  		*store;
GtkTreeIter    		iter;
GtkTreeIter    		iter2;
GtkTreeIter    		iter_busqueda;
GtkCellRenderer     *renderer;
GtkTreeModel        *model;
GtkTreeModel        *model2;
GtkTreeModel        *model_busc;
GtkListStore  		*store2;
GtkListStore  		*store_busqueda;
GtkTreeViewColumn 	*column;
GtkTreeViewColumn 	*column2;
GtkTreeViewColumn 	*column3;
GtkTreeViewColumn 	*column4;
GtkTreeViewColumn 	*column5;
GtkTreeViewColumn 	*column6;
GtkTreeViewColumn 	*column7;
GtkTreeViewColumn 	*column8;
GtkTreeViewColumn 	*column9;
GtkTreeViewColumn 	*column10;
GtkTreeViewColumn 	*column11;
GtkTreeViewColumn 	*column12;
GtkTreeViewColumn 	*column13;
GtkTreeViewColumn 	*column14;
GtkTreeViewColumn 	*column15;
GtkTreeViewColumn 	*column16;
GtkTreeViewColumn 	*column17;

GtkTreeViewColumn 	*column_fac;
GtkTreeViewColumn 	*column_fac2;
GtkTreeViewColumn 	*column_fac3;
GtkTreeViewColumn 	*column_fac4;
GtkTreeViewColumn 	*column_fac5;
GtkTreeViewColumn 	*column_fac6;
GtkTreeViewColumn 	*column_fac7;

GtkTreeViewColumn 	*column_fac_bus;
GtkTreeViewColumn 	*column_fac2_bus;
GtkTreeViewColumn 	*column_fac3_bus;
GtkTreeViewColumn 	*column_fac4_bus;
GtkTreeViewColumn 	*column_fac5_bus;
GtkTreeViewColumn 	*column_fac6_bus;
GtkTreeViewColumn 	*column_fac7_bus;

GtkTreeSelection 	*seleccion_view;
GtkTreeSelection 	*seleccion_view2;
GtkTreeSelection 	*selection; 



const char 		*user;
const char 		*password;

enum {
  LIST_ITEM = 0,
  N_COLUMNS_BUS
};
enum
{
	COLid,
	COLnomant,
	COLedadant,
	COLapodoant,
	COLpoderes,
	COLsexo,
	COLestatura,
	NUM_COLS
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
	NUM_COLS_bus
} ;


enum
{
	idauditoria,
	cliente,
	apellidos,
	productos,
	monto,
	fecha,
	formato,
	clientenew,
	apellidosnew,
	productosnew,
	montonew,
	fechanew,
	formatonew,
	usuario,
	modificado,
	accion,
	idfactura,
	NUM_COLS2
} ;

static GtkTreeModel * create_and_fill_model (void)
{
	store = gtk_list_store_new (NUM_COLS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,COLid, row[0],
	COLnomant, row[1],
	COLedadant, row[2],
	COLapodoant, row[3],
	COLpoderes, row[4],
	COLsexo, row[5],
	COLestatura, row[6],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,COLid, row[0],
	COLnomant, row[1],
	COLedadant, row[2],
	COLapodoant, row[3],
	COLpoderes, row[4],
	COLsexo, row[5],
	COLestatura, row[6],-1);
}
	return GTK_TREE_MODEL (store);
}
 static GtkWidget *titulo_factura_auditoria (void)
{	
	renderer = gtk_cell_renderer_text_new ();
	column_fac = gtk_tree_view_column_new_with_attributes  ("ID Factura",renderer,"text", COLid,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_fac);
	renderer = gtk_cell_renderer_text_new ();
	column_fac2 = gtk_tree_view_column_new_with_attributes ("Cliente",renderer,"text", COLnomant,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_fac2);
	renderer = gtk_cell_renderer_text_new ();
	column_fac3 = gtk_tree_view_column_new_with_attributes  ("Apellidos",renderer,"text", COLedadant,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_fac3);
	renderer = gtk_cell_renderer_text_new ();
	column_fac4 = gtk_tree_view_column_new_with_attributes  ("Productos",renderer,"text", COLapodoant,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_fac4);
	renderer = gtk_cell_renderer_text_new ();
	column_fac5 = gtk_tree_view_column_new_with_attributes  ("Monto",renderer,"text", COLpoderes,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_fac5);
	renderer = gtk_cell_renderer_text_new ();
	column_fac6 = gtk_tree_view_column_new_with_attributes ("Fecha Compra",renderer,"text", COLsexo,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_fac6);
	renderer = gtk_cell_renderer_text_new ();
	column_fac7 = gtk_tree_view_column_new_with_attributes ("Formato Compra",renderer,"text", COLestatura,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view),column_fac7);
	
	
	
	model = create_and_fill_model ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view), model);
	g_object_unref (model);
	return view;
}


static GtkTreeModel * create_and_fill_model_busqueda (void)
{
	store_busqueda = gtk_list_store_new (NUM_COLS_bus, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store_busqueda, &iter_busqueda);
	gtk_list_store_set (store_busqueda, &iter_busqueda,COLid_bus, row[0],
	COLnomant_bus, row[1],
	COLedadant_bus, row[2],
	COLapodoant_bus, row[3],
	COLpoderes_bus, row[4],
	COLsexo_bus, row[5],
	COLestatura_bus, row[6],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store_busqueda, &iter_busqueda);
	gtk_list_store_set (store_busqueda, &iter_busqueda,COLid_bus, row[0],
	COLnomant_bus, row[1],
	COLedadant_bus, row[2],
	COLapodoant_bus, row[3],
	COLpoderes_bus, row[4],
	COLsexo_bus, row[5],
	COLestatura_bus, row[6],-1);
}
	return GTK_TREE_MODEL (store_busqueda);
}
 static GtkWidget *titulo_factura_auditoria_busqueda (void)
{	
	renderer = gtk_cell_renderer_text_new ();
	column_fac_bus = gtk_tree_view_column_new_with_attributes  ("ID Factura",renderer,"text", COLid_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac2_bus = gtk_tree_view_column_new_with_attributes ("Cliente",renderer,"text", COLnomant_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac2_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac3_bus = gtk_tree_view_column_new_with_attributes  ("Apellidos",renderer,"text", COLedadant_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac3_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac4_bus = gtk_tree_view_column_new_with_attributes  ("Productos",renderer,"text", COLapodoant_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac4_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac5_bus = gtk_tree_view_column_new_with_attributes  ("Monto",renderer,"text", COLpoderes_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac5_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac6_bus = gtk_tree_view_column_new_with_attributes ("Fecha Compra",renderer,"text", COLsexo_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac6_bus);
	renderer = gtk_cell_renderer_text_new ();
	column_fac7_bus = gtk_tree_view_column_new_with_attributes ("Formato Compra",renderer,"text", COLestatura_bus,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view_busc),column_fac7_bus);
	
	
	
	model_busc = create_and_fill_model_busqueda ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view_busc), model_busc);
	g_object_unref (model_busc);
	return view_busc;
}


static GtkTreeModel *examen_auditoria (void)
{
	store2 = gtk_list_store_new (NUM_COLS2, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	gtk_list_store_append (store2, &iter2);
	gtk_list_store_set (store2, &iter2,idauditoria,row[0],
	cliente,row[1],
	apellidos,row[2],
	productos,row[3],
	monto,row[4],
	fecha,row[5],
	formato,row[6],
	clientenew,row[7],
	apellidosnew,row[8],
	productosnew,row[9],
	montonew,row[10],
	fechanew,row[11],
	formatonew,row[12],
	usuario,row[13],
	modificado,row[14],
	accion,row[15],
	idfactura,row[16],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store2, &iter);
	gtk_list_store_set (store2, &iter,idauditoria,row[0],
	cliente,row[1],
	apellidos,row[2],
	productos,row[3],
	monto,row[4],
	fecha,row[5],
	formato,row[6],
	clientenew,row[7],
	apellidosnew,row[8],
	productosnew,row[9],
	montonew,row[10],
	fechanew,row[11],
	formatonew,row[12],
	usuario,row[13],
	modificado,row[14],
	accion,row[15],
	idfactura,row[16],-1);
}
	return GTK_TREE_MODEL (store2);
}


 static GtkWidget *titulo_examen_auditoria (void)
{
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes ("ID",renderer,"text", idauditoria,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Cliente Anterior",renderer,"text", cliente,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column3 = gtk_tree_view_column_new_with_attributes ("Apellido Anterior",renderer,"text", apellidos,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column3);
	renderer = gtk_cell_renderer_text_new ();
	column4 = gtk_tree_view_column_new_with_attributes ("Productos Anterior",renderer,"text", productos,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column4);
	renderer = gtk_cell_renderer_text_new ();
	column5 = gtk_tree_view_column_new_with_attributes ("Monto Anterior",renderer,"text", monto,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column5);
	renderer = gtk_cell_renderer_text_new ();
	column6 = gtk_tree_view_column_new_with_attributes ("Fecha Comp. Anterior",renderer,"text", fecha,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column6);
	renderer = gtk_cell_renderer_text_new ();
	column7 = gtk_tree_view_column_new_with_attributes ("Formato Pago Anterior",renderer,"text", formato,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column7);
	renderer = gtk_cell_renderer_text_new ();
	column8 = gtk_tree_view_column_new_with_attributes ("Cliente Nuevo.",renderer,"text", clientenew,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column8);
	renderer = gtk_cell_renderer_text_new ();
	column9= gtk_tree_view_column_new_with_attributes ("Apellido Nuevo",renderer,"text", apellidosnew,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column9);
	renderer = gtk_cell_renderer_text_new ();
	column10 = gtk_tree_view_column_new_with_attributes ("Producto Nuevo",renderer,"text", productosnew,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column10);
	renderer = gtk_cell_renderer_text_new ();
	column11 = gtk_tree_view_column_new_with_attributes ("Monto Nuevo",renderer,"text", montonew,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column11);
	renderer = gtk_cell_renderer_text_new ();
	column12 = gtk_tree_view_column_new_with_attributes ("Fecha Comp. Nuevo",renderer,"text", fechanew,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column12);
	renderer = gtk_cell_renderer_text_new ();
	column13 = gtk_tree_view_column_new_with_attributes ("Formato Pago Nuevo",renderer,"text", formatonew,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column13);
	renderer = gtk_cell_renderer_text_new ();
	column14 = gtk_tree_view_column_new_with_attributes ("Usuario",renderer,"text", usuario,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column14);
	renderer = gtk_cell_renderer_text_new ();
	column15 = gtk_tree_view_column_new_with_attributes ("Fecha Mod.",renderer,"text", modificado,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column15);
	renderer = gtk_cell_renderer_text_new ();
	column16 = gtk_tree_view_column_new_with_attributes ("Accion",renderer,"text", accion,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column16);
	renderer = gtk_cell_renderer_text_new ();
	column17 = gtk_tree_view_column_new_with_attributes ("Id Factura",renderer,"text", idfactura,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column17);
	renderer = gtk_cell_renderer_text_new ();
	
	model2 = examen_auditoria ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view2), model2);
	g_object_unref (model2);
	return view2;
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
			if(strcmp(tabla,"auditoria_factura") != 0)
			{
			gtk_stack_set_visible_child (GTK_STACK(stackgtk),contenedor_view);	
			if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
					 titulo_factura_auditoria();
					return ;	
			}
		}
		else
		{
			gtk_stack_set_visible_child (GTK_STACK(stackgtk),contenedor_view2);
				if (gtk_tree_model_get_iter_first(model2, &iter2) == FALSE) {
					view2 = titulo_examen_auditoria();
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
void refresca_datos(){
	gtk_list_store_clear(store2);
	gtk_list_store_clear(store);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_fac);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_fac2);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_fac3);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_fac4);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_fac5);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_fac6);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view), column_fac7);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column2);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column3);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column4);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column5);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column6);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column7);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column8);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column9);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column10);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column11);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column12);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column13);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column14);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column15);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column16);
	gtk_tree_view_remove_column (GTK_TREE_VIEW(view2), column17);
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
		g_Entry_Usuario = GTK_ENTRY(gtk_builder_get_object(builder,"Entry_Usuario"));
		g_Entry_Contraseña = GTK_ENTRY(gtk_builder_get_object(builder,"Entry_Contraseña"));
		g_Dialog_Error = GTK_WIDGET(gtk_builder_get_object(builder,"Dialog_Error"));
		lbl_error = GTK_LABEL(gtk_builder_get_object(builder,"lbl_error"));
		inserta_factura = GTK_WIDGET(gtk_builder_get_object(builder,"inserta_factura"));
		pop_calendario = GTK_WIDGET(gtk_builder_get_object(builder,"pop_calendario"));
		pop_delete_fac = GTK_WIDGET(gtk_builder_get_object(builder,"pop_delete_fac"));
		La_lbl_Titulo_BD = GTK_LABEL(gtk_builder_get_object(builder,"lbl_Titulo_BD"));
		La_Label_Error_ingreso = GTK_LABEL(gtk_builder_get_object(builder,"Label_Error_ingreso"));
		menu_items = GTK_WIDGET(gtk_builder_get_object(builder,"Combo_Box_Mostrar_BD"));
		cb_anio_fac = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_fac"));
		tabla_items = GTK_WIDGET(gtk_builder_get_object(builder,"Combo_Box_Mostrar_TD"));
		dialog_error_datos = GTK_WIDGET(gtk_builder_get_object(builder,"dialog_error_datos"));
		view = GTK_WIDGET(gtk_builder_get_object(builder,"view"));
		view2 = GTK_WIDGET(gtk_builder_get_object(builder,"view2"));
		view_busc = GTK_WIDGET(gtk_builder_get_object(builder,"view_busc"));
		contenedor_view2 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view2"));
		contenedor_view = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view"));
		contenedor_busqueda = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_busqueda"));
		contenedor_sql = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_sql"));
		stackgtk = GTK_WIDGET(gtk_builder_get_object(builder,"stack"));
		stack_busqueda = GTK_WIDGET(gtk_builder_get_object(builder,"stack_busqueda"));
		stack_sql = GTK_WIDGET(gtk_builder_get_object(builder,"stack_sql"));
		stack_aceptar = GTK_WIDGET(gtk_builder_get_object(builder,"stack_aceptar"));
		btn_sql_aceptar = GTK_WIDGET(gtk_builder_get_object(builder,"btn_sql_aceptar"));
		mostrar_calendario = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"mostrar_calendario"));
		ocultar_btn = GTK_WIDGET(gtk_builder_get_object(builder,"ocultar_btn"));
		win_acercade = GTK_WIDGET(gtk_builder_get_object(builder,"acercade"));
		switchgtk = GTK_WIDGET(gtk_builder_get_object(builder,"activador_sql"));
		source_code = GTK_WIDGET(gtk_builder_get_object(builder,"Codigo_sql"));
		lbl_no_datos = GTK_WIDGET(gtk_builder_get_object(builder,"lbl_no_datos"));
		lbl_añadir_advertencia = GTK_LABEL(gtk_builder_get_object(builder,"lbl_añadir_advertencia"));
		lbl_eliminar_advertencia = GTK_LABEL(gtk_builder_get_object(builder,"lbl_eliminar_advertencia"));
		dialog_advertencia_añadir = GTK_WIDGET(gtk_builder_get_object(builder,"Dialog_advertencia_añadir"));
		dialog_advertencia_actualizar = GTK_WIDGET(gtk_builder_get_object(builder,"Dialog_advertencia_actualizar"));
		dialog_advertencia_eliminar = GTK_WIDGET(gtk_builder_get_object(builder,"Dialog_advertencia_eliminar"));
		seleccion_view = GTK_TREE_SELECTION(gtk_builder_get_object(builder,"seleccion_view"));
		seleccion_view2 = GTK_TREE_SELECTION(gtk_builder_get_object(builder,"seleccion_view2"));
		debug_textview = GTK_TEXT_VIEW(gtk_builder_get_object(builder,"debug_textview"));
		debug = GTK_WIDGET(gtk_builder_get_object(builder,"debug"));
		textbuffer_main = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "textbuffer_main"));
		entry_buscar = GTK_ENTRY(gtk_builder_get_object(builder,"entry_buscar"));
		historial_busqueda = GTK_WIDGET(gtk_builder_get_object(builder,"historial_busqueda"));
		stack_historial = GTK_WIDGET(gtk_builder_get_object(builder,"stack_historial"));
		contenedor_historial = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_historial"));
		ety_clien = GTK_ENTRY(gtk_builder_get_object(builder,"ety_clien"));
		ety_apelli = GTK_ENTRY(gtk_builder_get_object(builder,"ety_apelli"));
		ety_prod = GTK_ENTRY(gtk_builder_get_object(builder,"ety_prod"));
		ety_monto = GTK_ENTRY(gtk_builder_get_object(builder,"ety_monto"));
		ety_fcomp = GTK_ENTRY(gtk_builder_get_object(builder,"ety_fcomp"));
		id_fac_act = GTK_ENTRY(gtk_builder_get_object(builder,"id_fac_act"));
		ety_clien_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_clien_act"));
		ety_apelli_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_apelli_act"));
		ety_prod_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_prod_act"));
		ety_monto_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_monto_act"));
		ety_fcomp_act = GTK_ENTRY(gtk_builder_get_object(builder,"ety_fcomp_act"));
		ety_id_fac_borrar = GTK_ENTRY(gtk_builder_get_object(builder,"ety_id_fac_borrar"));
		cb_dia_fac = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_fac"));
		cb_mes_fac = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_fac"));
		cb_anio_fac = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_fac"));
		cb_dia_fac_actu = GTK_WIDGET(gtk_builder_get_object(builder,"cb_dia_fac_actu"));
		cb_mes_fac_actu = GTK_WIDGET(gtk_builder_get_object(builder,"cb_mes_fac_actu"));
		cb_anio_fac_actu = GTK_WIDGET(gtk_builder_get_object(builder,"cb_anio_fac_actu"));
		calendario_factura = GTK_CALENDAR(gtk_builder_get_object(builder,"calendario_factura"));
		btn_eliminar_datos = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"btn_eliminar_datos"));
		
		
		selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(historial_busqueda));
		
		init_list(historial_busqueda);
		
		for(i=2021;i>=1950;i--){ 
			sprintf(anio,"%d",i);
			gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_fac),anio);
			gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (cb_anio_fac_actu),anio);
			
		}

		gtk_builder_connect_signals(builder, NULL);
		g_object_unref(builder);
		gtk_widget_show(window_login);  
		gtk_main();
	}

//=========== Añadir datos =====================================
void on_btn_añadir_datos_clicked(){
	gtk_widget_show(inserta_factura);
	}
	
void on_btn_cancelar_adver_clicked(){
	gtk_widget_hide(dialog_advertencia_añadir);
	}
void on_cancela_and_factura_clicked(){
	gtk_widget_hide_on_delete(inserta_factura);
	}
	
void on_btn_aceptar_añadir_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "examen";
	char anadir_fac[512];
	char date[12];
	char *server = "localhost";

	
	const char 		*dia = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_dia_fac));
	const char 		*mes = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_mes_fac));
	const char 		*anio = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_anio_fac));
	const char 		*cliente = gtk_entry_get_text(ety_clien);
	const char 		*apellido = gtk_entry_get_text(ety_apelli);
	const char		*producto = gtk_entry_get_text(ety_prod);;
	const char		*monto = gtk_entry_get_text(ety_monto);
	const char		*compra = gtk_entry_get_text(ety_fcomp);
	
	
	sprintf(date,"%s-%s-%s",anio,mes,dia);
	sprintf(anadir_fac,"insert into Factura (idFactura,Cliente,Apellidos,Productos,Monto,FechaCompra,FormatoPago) values(null,'%s','%s','%s','%s','%s','%s')",cliente,apellido,producto,monto,date,compra);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, anadir_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(dialog_advertencia_añadir);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s",row[0]);
	}
	
	gtk_entry_set_text(ety_clien,"");
	gtk_entry_set_text(ety_apelli,"");
	gtk_entry_set_text(ety_fcomp,"");
	gtk_entry_set_text(ety_monto,"");
	gtk_entry_set_text(ety_prod,"");
	
	refresca_datos();
	contenido_tablas();

	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(dialog_advertencia_añadir);
	}
void on_inserta_datos_factura_clicked(){
		gtk_widget_show(dialog_advertencia_añadir);
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
	const char *database = "examen";
	char actualiza_fac[512];
	char date[13];
	char *server = "localhost";
	
	
	
	const char 		*id = gtk_entry_get_text(id_fac_act);
	const char 		*cliente = gtk_entry_get_text(ety_clien_act);
	const char 		*apellido = gtk_entry_get_text(ety_apelli_act);
	const char		*producto = gtk_entry_get_text(ety_prod_act);
	const char		*monto = gtk_entry_get_text(ety_monto_act);
	const char		*compra = gtk_entry_get_text(ety_fcomp_act);
	const char 		*dia = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_dia_fac_actu));
	const char 		*mes = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_mes_fac_actu));
	const char 		*anio2 = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(cb_anio_fac_actu));

	
	sprintf(date,"%s-%s-%s",anio2,mes,dia);
	sprintf(actualiza_fac,"update Factura set Cliente='%s', Apellidos='%s', Productos='%s', Monto=%s, FechaCompra='%s', FormatoPago='%s' where idFactura=%s",cliente,apellido,producto,monto,date,compra,id);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, actualiza_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(dialog_advertencia_actualizar);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s",row[0]);
	}
	/*
	if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), &model_bus, &iter_bus)) {
    gtk_list_store_remove(store, &iter);
    }
	store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(view)));
	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store, &iter, COLnomant, cliente,
	COLedadant, apellido,
	COLapodoant, producto,
	COLpoderes, monto,
	COLsexo,date,
	COLestatura, compra, -1);
	*/
	gtk_entry_set_text(id_fac_act,"");
	gtk_entry_set_text(ety_clien_act,"");
	gtk_entry_set_text(ety_apelli_act,"");
	gtk_entry_set_text(ety_fcomp_act,"");
	gtk_entry_set_text(ety_monto_act,"");
	gtk_entry_set_text(ety_prod_act,"");
	
	contenido_tablas();
	refresca_datos();
	
	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(dialog_advertencia_actualizar);
	}
void on_actualiza_datos_factura_clicked(){
		gtk_widget_show(dialog_advertencia_actualizar);
	}
void on_cancela_and_factura1_clicked(){
		gtk_widget_hide(actualiza_factura);
	}
void on_btn_actualizar_datos_clicked(){
	gtk_widget_show(actualiza_factura);
	
	}
void on_btn_cancelar_adver1_clicked(){
	gtk_widget_hide(dialog_advertencia_actualizar);
	}
//================================================
//=========== Elimina datos =====================================
void on_btn_eliminar_datos_toggled(){
	gboolean button_state;
	button_state = gtk_toggle_button_get_active(btn_eliminar_datos);
	if (button_state) {
		// button is active
		gtk_widget_set_visible (pop_delete_fac,gtk_toggle_button_get_active (btn_eliminar_datos));
	}
	else {
		// button is inactive
		gtk_widget_hide(pop_delete_fac);
	}
}
void on_btn_borrar_fac_clicked(){
	gtk_widget_show(dialog_advertencia_eliminar);
}
void on_ety_id_fac_borrar_activate(){
	gtk_widget_show(dialog_advertencia_eliminar);
}
void on_btn_aceptar_a_clicked(){
	user = gtk_entry_get_text(g_Entry_Usuario);
	password = gtk_entry_get_text(g_Entry_Contraseña);
	const char *database = "examen";
	char elimina_fac[50];
	char *server = "localhost";
	
	const char 	*id = gtk_entry_get_text(ety_id_fac_borrar);

	sprintf(elimina_fac,"delete from Factura where idFactura=%s",id);
	
	conn = mysql_init(NULL);

 if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{	 
	}

	if (mysql_query(conn, elimina_fac))
	{
		char tempErr[60];
		sprintf(tempErr,"%s", mysql_error(conn));
		gtk_label_set_text(lbl_error,tempErr);
		gtk_widget_hide(dialog_advertencia_eliminar);
		return gtk_widget_show(dialog_error_datos);
	}
	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL) {
		//printf("%s",row[0]);
	}
	
	gtk_entry_set_text(ety_id_fac_borrar,"");
	refresca_datos();
	contenido_tablas();
	mysql_free_result(res);
	mysql_close(conn);
	gtk_widget_hide(dialog_advertencia_eliminar);
}
void on_btn_cancelar_adver2_clicked(){
	gtk_widget_hide(dialog_advertencia_eliminar);
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
	const char *database = "examen";
	char busqueda_fac[50];
	char *server = "localhost";
	
	const char 	*busqueda = gtk_entry_get_text(entry_buscar);

	sprintf(busqueda_fac,"select * from Factura where Cliente = '%s'",busqueda);
	
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
