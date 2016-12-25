#include <gtk/gtk.h>

#define TITLE "СВАСТОНЫ"
#define SVASTON "svaston.png"
#define SIEG "SIEG HEIL!"
 
void drawSvaston (GtkButton *button, gpointer data)
{
	GtkWidget *dialog;
	unsigned int width = 400;
	GError *error;
	GtkWidget *svaston = gtk_image_new_from_pixbuf(gdk_pixbuf_new_from_file_at_scale(SVASTON,
		width, width, TRUE, &error));
	GtkWidget *content_area;

	dialog = gtk_dialog_new_with_buttons(TITLE,
			NULL,
			GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
			SIEG,
			GTK_RESPONSE_ACCEPT,
			NULL);
	content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
	gtk_container_add(GTK_CONTAINER(content_area), svaston);
	gtk_widget_show(svaston);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

int main (int argc, char ** argv)
{
	GtkWidget *button;
	GtkWidget *window;

	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), TITLE);
	gtk_container_set_border_width (GTK_CONTAINER(window), 50);
	button = gtk_button_new_with_label("Нарисовать свастон!");
	gtk_container_add(GTK_CONTAINER(window), button);
	gtk_widget_show_all(window);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(GTK_BUTTON(button), "clicked", G_CALLBACK(drawSvaston), NULL);
	gtk_main();
	return 0;
}
                                                                                                             
