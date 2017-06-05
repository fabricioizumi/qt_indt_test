#include <MainWindow.h>
#include <QApplication>
 
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow telaPrincipal;
    telaPrincipal.initialize();
    
    telaPrincipal.showNormal();

    return app.exec();

}