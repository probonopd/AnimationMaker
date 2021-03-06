/****************************************************************************
** Copyright (C) 2016 Olaf Japp
**
** This file is part of AnimationMaker.
**
**  AnimationMaker is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  AnimationMaker is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with AnimationMaker.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "animationscene.h"
#include "timeline.h"
#include "itempropertyeditor.h"
#include "scenepropertyeditor.h"

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

    void setTitle();
    
protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    void createMenus();
    void createActions();
    void createStatusBar();
    void createGui();
    void writeSettings();
    void readSettings();
    void writeFile(QString fileName);
    void reset();
    void fillTree();

    QSplitter *splitter;
    QToolBar *toolbar;
    QTreeWidget *elementTree;
    AnimationScene *scene;
    QGraphicsView *view;
    QFileInfo loadedFile;
    Timeline *timeline;
    ItemPropertyEditor *m_itemPropertyEditor;
    ScenePropertyEditor *m_scenePropertyEditor;
    QDockWidget *propertiesdock;
    QDockWidget *tooldock;
    QTreeWidgetItem *root;


    QAction *openAct;
    QAction *newAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *exportAct;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *selectAct;
    QAction *rectangleAct;
    QAction *ellipseAct;
    QAction *textAct;
    QAction *svgAct;
    QAction *bitmapAct;
    QAction *showPropertyPanelAct;
    QAction *showToolPanelAct;
    QAction *undoAct;
    QAction *redoAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *delAct;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QMenu *viewMenu;
    QUndoStack *undoStack;

public slots:
    void exportAnimation();
    void about();
    void save();
    void saveAs();
    void open();
    void newfile();
    void setSelectMode();
    void setRectangleMode();
    void setEllipseMode();
    void setTextMode();
    void setBitmapMode();
    void setSvgMode();
    void elementTreeItemChanged(QTreeWidgetItem*, QTreeWidgetItem*);
    void sceneItemAdded(QGraphicsItem *);
    void showPropertyPanel();
    void showToolPanel();
    void sceneSelectionChanged();
    void timelineSelectionChanged(ResizeableItem*);
    void copy();
    void paste();
    void del();
    void sceneSizeChanged(int width, int height);
    void sceneItemRemoved(ResizeableItem *item);
    void idChanged(ResizeableItem *, QString);
};

#endif // MAINWINDOW_H
