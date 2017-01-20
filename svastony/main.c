#include <gtk/gtk.h>

const char svaston_file[] = "svaston.png";
const char title[] = "СВАСТОНЫ";
const char title_sv[] = "СВАСТОН";
const char sieg[] = "SIEG HEIL!";
const char label_text[] = "Размер свастона в пикселях (от 40 до 2000):";
const int spin_min = 40;
const int spin_max = 2000;
const int spin_step = 2;
const int spin_start = 400;
const int border_width = 10;
const int button_width = 250;
const int button_height = 50;
const int spin_width = 100;
const int spin_height = 50;
GtkWidget *spin;

void drawSvaston (GtkButton *button, gpointer data)
{
	GtkWidget *dialog;
	unsigned int width = (unsigned int) gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin));
	GError *error;
	GtkWidget *svaston;
	svaston = gtk_image_new_from_pixbuf(gdk_pixbuf_new_from_file_at_scale(svaston_file, width, width,
				FALSE, &error));
	GtkWidget *content_area;

	dialog = gtk_dialog_new_with_buttons(title_sv,
			NULL,
			GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
			sieg,
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
	GtkWidget *grid;
	GtkWidget *label;

	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), title);
	gtk_container_set_border_width (GTK_CONTAINER(window), border_width);
	grid = gtk_grid_new();
	label = gtk_label_new(label_text);
	button = gtk_button_new_with_label("Нарисовать свастон!");
	spin = gtk_spin_button_new_with_range(spin_min, spin_max, spin_step);
	gtk_grid_attach(GTK_GRID(grid), button, 0, 0, button_width, button_height);
	gtk_grid_attach(GTK_GRID(grid), label, 0, button_height + 10, 400, 50);
	gtk_grid_attach(GTK_GRID(grid), GTK_WIDGET(spin), 0, button_height * 2 + 20, spin_width, spin_height);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin), spin_start);
	gtk_container_add(GTK_CONTAINER(window), grid);
	gtk_widget_show_all(window);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(GTK_BUTTON(button), "clicked", G_CALLBACK(drawSvaston), NULL);
	gtk_main();
	return 0;
}

