#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtQuick>
#include <QtWidgets>
#include "treemodel.h"
#include "animationscene.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    void createMenus();
    void createActions();
    void createStatusBar();
    void createGui();
    void writeSettings();
    void readSettings();

    QSplitter *splitter;
    QLabel *timeline;
    QToolBar *toolbar;
    QTreeView *tree;
    TreeModel *model;
    AnimationScene *scene;
    QGraphicsView *view;

    QAction *openAct;
    QAction *saveAct;
    QAction *playAct;
    QAction *saveAsAct;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *selectAct;
    QAction *rectangleAct;
    QAction *ellipseAct;
    QMenu *fileMenu;
    QMenu *helpMenu;

public slots:
    void exportAnimation();
    void playAnimation();
    void about();
    void save();
    void open();
    void setSelectMode();
    void setRectangleMode();
    void setEllipseMode();
};

#endif // MAINWINDOW_H
