#include "headers/MainWindow.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QFileSystemModel>
#include "treemodel.h"
#include <iostream>
#include <QDebug>
#include <QMenuBar>
#include <QItemSelection>
using namespace std;

int MainWindow::initialize()
{
    
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    

    // QFileSystemModel *model = new QFileSystemModel;
    // model->setRootPath("/etc");
    QDir dir(Q_DIR);
    QString directories;

    for(QString q:dir.entryList())
    {
        if ( (q != ".") && (q != "..") )
        {   
            QDir d(Q_DIR + q);

            if (d.exists())
            {
                directories +=  "\n";
                directories += q+"\t"+QString::number(q.length()) ;
            }
            
            
        }
        
    }

    cout << directories.toUtf8().constData();

    TreeModel *model = new TreeModel(directories);
       

    tree = new QTreeView();
    tree->setModel(model);
    tree->setSortingEnabled(true);
    tree->sortByColumn(2);
    
    tree->show();

        
    QHBoxLayout *layout = new QHBoxLayout();
    
    layout->addWidget(tree);
    
    //QObject::connect(tree, SIGNAL(expanded(const QModelIndex &index)), this, SLOT(treeViewClicked()));
    connect(tree, SIGNAL(clicked(const QModelIndex &)), this, SLOT(treeViewClicked(const QModelIndex &)));

    centralWidget->setLayout(layout);
    centralWidget->show(); 

    //cria menu bar
    // QMenuBar *menu=new QMenuBar(centralWidget);

    // QMenu *file = new QMenu("&File");
    // file->addMenu("Novo");

    // menu->addMenu(file);
    menubar = menuBar();
    menubar->setNativeMenuBar(false);

    QAction *action = new QAction(tr("New"), this);

    QMenu *fileMenu = menubar->addMenu(tr("&File"));
    fileMenu->addAction(action);
    
}




void MainWindow::treeViewClicked(const QModelIndex &)
{
    qDebug() << "teste";

    TreeModel* model = (TreeModel*) tree->model();

    QModelIndex index = tree->currentIndex();

    QVariant texto = model->data(index, Qt::DisplayRole);

    qDebug() << texto.toString();

}

