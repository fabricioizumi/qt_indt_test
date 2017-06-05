#include <QMainWindow>
#include <QItemSelection>
#include <QTreeView>

#define Q_DIR "/etc/"

class MainWindow: public QMainWindow
{
    Q_OBJECT

    public:
        int initialize();
        
        QTreeView *tree;

        QMenuBar *menubar;

        

    private slots:
        void treeViewClicked(const QModelIndex &);
};