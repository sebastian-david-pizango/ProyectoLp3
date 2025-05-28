#include <QApplication>
#include <QInputDialog>
#include "mainwindow.h"
#include "horsesec2.h"
#include <vector>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    std::vector<HorseSec2*> todosLosCaballos;
    todosLosCaballos.push_back(new HorseSec2("Billy"));
    todosLosCaballos.push_back(new HorseSec2("Bad Billy >:c"));
    todosLosCaballos.push_back(new HorseSec2("Centella"));
    todosLosCaballos.push_back(new HorseSec2("Tornado"));
    todosLosCaballos.push_back(new HorseSec2("Eclipse"));
    todosLosCaballos.push_back(new HorseSec2("Furia"));

    bool ok;
    int cantidad = QInputDialog::getInt(
        nullptr,
        "Caballos en la carrera",
        "¿Cuántos caballos competirán? (1 - 6)",
        3, 1, 6, 1, &ok
        );

    if (!ok || cantidad < 1 || cantidad > 6)
        return 0;

    std::vector<HorseSec2*> caballosSeleccionados(
        todosLosCaballos.begin(),
        todosLosCaballos.begin() + cantidad
        );

    MainWindow w(caballosSeleccionados);
    w.show();

    return a.exec();
}


