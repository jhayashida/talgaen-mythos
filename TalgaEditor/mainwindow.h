#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QString>

namespace Ui {
class MainWindow;
}

class QListWidgetItem;
class QGraphicsScene;
class QPixmap;
class QGraphicsPixmapItem;

namespace talga
{
namespace editor
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    //void on_listWidget_itemClicked(QListWidgetItem *item);

    //void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_actionLoad_Assets_triggered();

protected:
    Ui::MainWindow *ui;

    int mTileWidth;
    int mTileHeight;

    QGraphicsScene* pmImageViewScene;
    QMap<QString, QPixmap* > mTextures;
};

}
}
#endif // MAINWINDOW_H
