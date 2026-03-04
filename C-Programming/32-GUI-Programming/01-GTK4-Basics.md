# GTK4 Basics

GTK (GIMP Toolkit) is a popular cross-platform widget toolkit for creating graphical user interfaces.

## 📦 Installation
-   **Linux**: `sudo apt install libgtk-4-dev`
-   **Windows**: Use MSYS2.

## 🖼️ Hello World

```c
#include <gtk/gtk.h>

static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hello GTK");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *label = gtk_label_new("Welcome to C GUI!");
    gtk_window_set_child(GTK_WINDOW(window), label);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("com.example.GtkApp", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
```

## 📡 Signals
GTK uses a signal system. You connect a function (callback) to an event (signal).
`g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);`

---
[[00-Index|Back to GUI Index]]
