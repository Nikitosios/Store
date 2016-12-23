#include <gtk/gtk.h>
#include <stdio.h>

#define TITLE "СВАСТОНЫ"

int main (int argc, char ** argv) {
    GtkWidget *label;                                          // Метка
    GtkWidget *window;                                         // Главное окно

    gtk_init(&argc, &argv);                           // Инициализируем GTK+
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);            // Создаем главное окно
    gtk_window_set_title(GTK_WINDOW(window), TITLE);         // Устанавливаем заголовок окна 
    label = gtk_label_new("Здравствуй, мир!");        // Создаем метку с текстом
    gtk_container_add(GTK_CONTAINER(window), label);         // Вставляем метку в главное окно
    gtk_widget_show_all(window);                             // Показываем окно вместе с виджетами
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();                                              // Приложение переходит в цикл ожидания
    return 0; 
}
