#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "coordinate.h"
#include <list>

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void moveUser(int x, int y, bool User);

    void deleteTile(int x, int y);

    bool playTurn(bool user);

    void findMoves(bool user);

    void renderDeleteBox();

    ~MainWindow();

private slots:
    void on_PlayButton_clicked();

private:
    Ui::MainWindow *ui;

    list<Coordinate> bannedCoordinates;

    Coordinate* availableCoordinates[49];

    Coordinate* redUserCoordinate = new Coordinate(4, 1);

    Coordinate* blueUserCoordinate = new Coordinate(4, 7);

    bool turn;
};
#endif // MAINWINDOW_H
