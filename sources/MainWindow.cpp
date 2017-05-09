#include "MainWindow.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QFileSystemModel>
#include <QTreeView>
#include "treemodel.h"
#include <iostream>
#include <QDebug>
#include <QMenuBar>
using namespace std;

int MainWindow::initialize()
{
    
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    

    // QFileSystemModel *model = new QFileSystemModel;
    // model->setRootPath("/etc");
    QDir dir("/etc");
    QString directories;

    for(QString q:dir.entryList())
    {
        if ( (q != ".") && (q != "..") )
        {
            directories +=  " \n ";
            directories += q.toUtf8().constData();
            
        }
        
    }

    cout << directories.toUtf8().constData();

    TreeModel *model = new TreeModel(directories);
       

    QTreeView *tree = new QTreeView();
    tree->setModel(model);

    // QModelIndex idx = model->index(location);
    // tree->setRootIndex(idx);

    tree->setColumnHidden(1,true);
    tree->setColumnHidden(2,true);
    tree->setColumnHidden(3,true);
    tree->setColumnHidden(4,true);

    tree->show();

    
    QHBoxLayout *layout = new QHBoxLayout();
    
    layout->addWidget(tree);
    
    connect(tree, SIGNAL(clicked(const QModelIndex &index)), this, SLOT(treeViewClicked()));

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




void MainWindow::treeViewClicked()
{
    qDebug() << "teste" <<"yt" ;
}

