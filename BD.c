/*
 * ventana.c
 * 
 * Copyright 2020 Esteban<esteban@Gigabyte>
 * 
 * This program is free software; you can redistribute it and/or modify
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
 *gcc -Wall -o "%e" "%f" `pkg-config --cflags --libs gtk+-3.0` $(mysql_config --cflags) $(mysql_config --libs)  `pkg-config --cflags --libs gtksourceview-4` -rdynamic -lm
 */


#include <gtk/gtk.h>
#include <mysql.h> 
#include <stdio.h>
#include <gtksourceview/gtksource.h>

GtkBuilder      	*builder; 
GtkWidget   	    *window_login;
GtkEntry 			*g_Entry_Usuario;
GtkEntry 			*g_Entry_Contraseña;
GtkEntry			*entry_buscar;
GtkWidget 			*g_Dialog_Error;
GtkWidget			*window_BD;
GtkWidget			*win_acercade;
GtkWidget			*source_code;
GtkLabel			*La_lbl_Titulo_BD;
GtkLabel			*La_Label_Error_ingreso;
GtkWidget			*lbl_no_datos;
GtkLabel			*lbl_añadir_advertencia;
GtkWidget			*menu_items;
GtkWidget			*tabla_items;
GtkWidget			*switchgtk;
GtkWidget			*stack_sql;
GtkWidget			*stack_historial;
GtkWidget			*stack_aceptar;
GtkWidget			*btn_sql_aceptar;
GtkWidget			*ocultar_btn;
GtkWidget       	*view;
GtkWidget       	*view2;
GtkWidget			*contenedor_historial;
GtkWidget			*historial_busqueda;
GtkWidget       	*debug;
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
GtkCellRenderer     *renderer;
GtkTreeModel        *model;
GtkTreeModel        *model2;
GtkListStore  		*store2;
GtkTreeViewColumn 	*column;
GtkTreeViewColumn 	*column2;
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
	COLfechant,
	COLnomnew,
	COLedadnew,
	COLapodonew,
	COLpoderesnew,
	COLsexonew,
	COLestaturanew,
	COLfechanew,
	COLusuario,
	COLmodificado,
	COLaccion,
	COLidheroe,
	NUM_COLS
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
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
	G_TYPE_STRING);
	
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,COLid, row[0],
	COLnomant, row[1],
	COLedadant, row[2],
	COLapodoant, row[3],
	COLpoderes, row[4],
	COLsexo, row[5],
	COLestatura, row[6],
	COLfechant, row[7],
	COLnomnew, row[8],
	COLedadnew, row[9],
	COLapodonew, row[10],
	COLpoderesnew, row[11],
	COLsexonew, row[12],
	COLestaturanew, row[13],
	COLfechanew, row[14],
	COLusuario, row[15],
	COLmodificado, row[16],
	COLaccion, row[17],
	COLidheroe, row[18],-1);
	while ((row = mysql_fetch_row(res)) != NULL){
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,COLid, row[0],
	COLnomant, row[1],
	COLedadant, row[2],
	COLapodoant, row[3],
	COLpoderes, row[4],
	COLsexo, row[5],
	COLestatura, row[6],
	COLfechant, row[7],
	COLnomnew, row[8],
	COLedadnew, row[9],
	COLapodonew, row[10],
	COLpoderesnew, row[11],
	COLsexonew, row[12],
	COLestaturanew, row[13],
	COLfechanew, row[14],
	COLusuario, row[15],
	COLmodificado, row[16],
	COLaccion, row[17],
	COLidheroe, row[18],-1);
}
	return GTK_TREE_MODEL (store);
}
 static GtkWidget *titulo_comic_auditoria (void)
{	
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"ID",renderer,"text", COLid,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Nombre Anterior",renderer,"text", COLnomant,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Edad Anterior",renderer,"text", COLedadant,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Apodo Anterior",renderer,"text", COLapodoant,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Poder Anterior",renderer,"text", COLpoderes,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Sexo Anterior",renderer,"text", COLsexo,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Estatura Anterior",renderer,"text", COLestatura,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Fecha Nac. Ant.",renderer,"text", COLfechant,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Nombre Nuevo",renderer,"text", COLnomnew,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Edad Nuevo",renderer,"text", COLedadnew,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Apodo Nuevo",renderer,"text", COLapodonew,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Poder Nuevo",renderer,"text", COLpoderesnew,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Sexo Nuevo",renderer,"text", COLsexonew,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Estatura Nuevo",renderer,"text", COLestaturanew,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Fecha Nac. Nuevo",renderer,"text", COLfechanew,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Usuario",renderer,"text", COLusuario,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"Modiicado",renderer,"text", COLmodificado,NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),-1,"IDHeroe",renderer,"text", COLidheroe,NULL);
	
	model = create_and_fill_model ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view), model);
	return view;
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
	column2 = gtk_tree_view_column_new_with_attributes ("ID",renderer,"text", idauditoria,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Cliente Anterior",renderer,"text", cliente,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Apellido Anterior",renderer,"text", apellidos,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Productos Anterior",renderer,"text", productos,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Monto Anterior",renderer,"text", monto,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Fecha Comp. Anterior",renderer,"text", fecha,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Formato Pago Anterior",renderer,"text", formato,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Cliente Nuevo.",renderer,"text", clientenew,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2= gtk_tree_view_column_new_with_attributes ("Apellido Nuevo",renderer,"text", apellidosnew,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Producto Nuevo",renderer,"text", productosnew,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Monto Nuevo",renderer,"text", montonew,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Fecha Comp. Nuevo",renderer,"text", fechanew,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Formato Pago Nuevo",renderer,"text", formatonew,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Usuario",renderer,"text", usuario,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Fecha Mod.",renderer,"text", modificado,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Accion",renderer,"text", accion,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	column2 = gtk_tree_view_column_new_with_attributes ("Id Factura",renderer,"text", idfactura,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW (view2),column2);
	renderer = gtk_cell_renderer_text_new ();
	g_object_unref(model);
	model2 = examen_auditoria ();
	gtk_tree_view_set_model (GTK_TREE_VIEW (view2), model2);
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
	g_print ("As Escogido la tabla %s\n", tabla);
	
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
					titulo_comic_auditoria();
					return ;	
			}
		}
		else
		{
			gtk_stack_set_visible_child (GTK_STACK(stackgtk),contenedor_view2);
				if (gtk_tree_model_get_iter_first(model2, &iter2) == FALSE) {
					titulo_examen_auditoria();
					return ;	
			}
			
			view2=NULL;
		}	
}
	char templabel[60];
	sprintf(templabel,"¿Desea añadir elementos ala tabla %s?",tabla);
	gtk_label_set_text(lbl_añadir_advertencia,templabel);
	
	/*char templabelmod[60];
	sprintf(templabelmod,"¿Desea modificar el elemento %s ala tabla %s?",tabla);
	gtk_label_set_text(lbl_añadir_advertencia,templabelmod);
	
	char templabelelimar[60];
	sprintf(templabelelimar,"¿Desea eliminar el elemento %s de la tabla %s?",tabla);
	gtk_label_set_text(lbl_añadir_advertencia,templabelelimar);
	*/
	gtk_text_buffer_set_text (textbuffer_main,debugtabla,-1);
	gtk_text_view_set_buffer (debug_textview, textbuffer_main);
	mysql_free_result(res);
	mysql_close(conn);
}
void on_Combo_Box_Mostrar_BD_changed(GtkComboBox *widget)
{
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
	gtk_combo_box_text_remove_all (GTK_COMBO_BOX_TEXT (tabla_items));
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
void on_Combo_Box_Mostrar_TD_changed(GtkComboBox *widget){
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
    gtk_init(&argc, &argv);
	
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "window_main.glade", NULL);

    window_login = GTK_WIDGET(gtk_builder_get_object(builder, "Login_main"));
    window_BD = GTK_WIDGET(gtk_builder_get_object(builder,"Window_BD"));
    gtk_builder_connect_signals(builder, NULL);

	g_Entry_Usuario = GTK_ENTRY(gtk_builder_get_object(builder,"Entry_Usuario"));
	g_Entry_Contraseña = GTK_ENTRY(gtk_builder_get_object(builder,"Entry_Contraseña"));
	g_Dialog_Error = GTK_WIDGET(gtk_builder_get_object(builder,"Dialog_Error"));
	La_lbl_Titulo_BD = GTK_LABEL(gtk_builder_get_object(builder,"lbl_Titulo_BD"));
	La_Label_Error_ingreso = GTK_LABEL(gtk_builder_get_object(builder,"Label_Error_ingreso"));
	menu_items = GTK_WIDGET(gtk_builder_get_object(builder,"Combo_Box_Mostrar_BD"));
	tabla_items = GTK_WIDGET(gtk_builder_get_object(builder,"Combo_Box_Mostrar_TD"));
	view = GTK_WIDGET(gtk_builder_get_object(builder,"view"));
	view2 = GTK_WIDGET(gtk_builder_get_object(builder,"view2"));
	contenedor_view2 = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view2"));
	contenedor_view = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_view"));
	contenedor_sql = GTK_WIDGET(gtk_builder_get_object(builder,"contenedor_sql"));
	stackgtk = GTK_WIDGET(gtk_builder_get_object(builder,"stack"));
	stack_sql = GTK_WIDGET(gtk_builder_get_object(builder,"stack_sql"));
	stack_aceptar = GTK_WIDGET(gtk_builder_get_object(builder,"stack_aceptar"));
	btn_sql_aceptar = GTK_WIDGET(gtk_builder_get_object(builder,"btn_sql_aceptar"));
	ocultar_btn = GTK_WIDGET(gtk_builder_get_object(builder,"ocultar_btn"));
	win_acercade = GTK_WIDGET(gtk_builder_get_object(builder,"acercade"));
	switchgtk = GTK_WIDGET(gtk_builder_get_object(builder,"activador_sql"));
	source_code = GTK_WIDGET(gtk_builder_get_object(builder,"Codigo_sql"));
	lbl_no_datos = GTK_WIDGET(gtk_builder_get_object(builder,"lbl_no_datos"));
	lbl_añadir_advertencia = GTK_LABEL(gtk_builder_get_object(builder,"lbl_añadir_advertencia"));
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
	
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(historial_busqueda));
    init_list(historial_busqueda);
    
    g_object_unref(builder);
    gtk_widget_show(window_login);  
    gtk_main();
}
//=========== Añadir datos =====================================
void on_btn_añadir_datos_clicked(){
	gtk_widget_show(dialog_advertencia_añadir);
	}
void on_btn_cancelar_adver_clicked(){
	gtk_widget_hide(dialog_advertencia_añadir);
	}
void on_btn_aceptar_añadir_clicked(){
		
	}
//================================================



//=========== Actualiza datos ====================================
void on_btn_actualizar_datos_clicked(){
	gtk_widget_show(dialog_advertencia_actualizar);
	}
void on_btn_cancelar_adver1_clicked(){
	gtk_widget_hide(dialog_advertencia_actualizar);
	}
//================================================
//=========== Elimina datos =====================================
void on_btn_eliminar_datos_clicked(){
	gtk_widget_show(dialog_advertencia_eliminar);
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
	gtk_widget_hide_on_delete(win_acercade);
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

  if (gtk_tree_model_get_iter_first(model_bus, &iter_bus) == FALSE) {
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
	gtk_entry_set_text(entry_buscar,"");
	gtk_stack_set_visible_child (GTK_STACK(stack_historial),contenedor_historial);
}
	

void on_entry_buscar_activate(){
	meter_historial();
	}
void on_remover_item_clicked(){
	remove_item();
	}
void on_remover_todos_items_clicked(){
	remove_all();
	}

void on_cerrar_acercade_clicked(){
	gtk_widget_hide_on_delete(win_acercade);
	}
	
void on_btn_aceptar_dial_advertencia_clicked(){
	
	} 
