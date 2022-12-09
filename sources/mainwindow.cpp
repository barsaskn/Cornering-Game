#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
#include <QDebug>

#define LINE_A  0
#define LINE_B  116
#define LINE_C  230
#define LINE_D  345
#define LINE_E  459
#define LINE_F  574
#define LINE_G  688

#define LINE_1  0
#define LINE_2  114
#define LINE_3  229
#define LINE_4  343
#define LINE_5  457
#define LINE_6  572
#define LINE_7  687

#define RED     true
#define BLUE    false

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int k = 0;
    for(int i=1;i<8;i++){
        for(int j=1;j<8;j++){
            Coordinate* temp = new Coordinate(i,j);
            this->availableCoordinates[k]=temp;
            k++;
        }
    }
    for(Coordinate* i : availableCoordinates){
        this->ui->DeleteBox->addItem(QString::fromStdString(i->getString()));
    }
    this->turn = RED;
    findMoves(this->turn);

}

void MainWindow::moveUser(int x, int y, int User){
    if(User){
        this->ui->Red->setGeometry(x,y,112,112);
    }
    else{
        this->ui->Blue->setGeometry(x,y,112,112);
    }
}

void MainWindow::deleteTile(int x, int y){
    qDebug() << "Çalıştı";
    QLabel *label = new QLabel(this);
    label->setStyleSheet("border-image: url(:/other/cross.jpg);");
    label->raise();
    label->setGeometry(x,y,112,112);

};

bool MainWindow::playTurn(bool user){
    qDebug() << user;
    if(user){       //RED plays
        this->ui->Turn->setText(QString::fromStdString("Blue's Turn"));
        string deleteString=this->ui->DeleteBox->currentText().toStdString();

        this->turn = !user;
    }
    else{           //BLUE plays
        this->ui->Turn->setText(QString::fromStdString("Red's Turn"));
        this->deleteTile(LINE_A,LINE_1);
        this->turn = !user;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PlayButton_clicked()
{
    playTurn(this->turn);
    findMoves(this->turn);
}

void MainWindow::findMoves(bool user){
    this->ui->MoveBox->clear();
    int x;
    int y;
    if(user){       //find RED moves
        x = redUserCoordinate->getX();
        y = redUserCoordinate->getY();
    }
    else{
        x = blueUserCoordinate->getX();
        y = blueUserCoordinate->getY();

    }
    int right = x+1;
    int left = x-1;
    int up = y+1;
    int down = y-1;
    if(right < 8 && left > 0 && up < 8 && down > 0){
        Coordinate* up = new Coordinate(x,y+1);
        this->ui->MoveBox->addItem(QString::fromStdString(up->getString()));
        Coordinate* down = new Coordinate(x,y-1);
        this->ui->MoveBox->addItem(QString::fromStdString(down->getString()));
        Coordinate* right = new Coordinate(x+1,y);
        this->ui->MoveBox->addItem(QString::fromStdString(right->getString()));
        Coordinate* left = new Coordinate(x-1,y);
        this->ui->MoveBox->addItem(QString::fromStdString(left->getString()));
        Coordinate* upRight = new Coordinate(x+1,y+1);
        this->ui->MoveBox->addItem(QString::fromStdString(upRight->getString()));
        Coordinate* downRight = new Coordinate(x+1,y-1);
        this->ui->MoveBox->addItem(QString::fromStdString(downRight->getString()));
        Coordinate* upLeft = new Coordinate(x-1,y+1);
        this->ui->MoveBox->addItem(QString::fromStdString(upLeft->getString()));
        Coordinate* downLeft = new Coordinate(x-1,y-1);
        this->ui->MoveBox->addItem(QString::fromStdString(downLeft->getString()));
    }
    if(left == 0 && down > 0 && up < 8){
        Coordinate* up = new Coordinate(x,y+1);
        this->ui->MoveBox->addItem(QString::fromStdString(up->getString()));
        Coordinate* down = new Coordinate(x,y-1);
        this->ui->MoveBox->addItem(QString::fromStdString(down->getString()));
        Coordinate* right = new Coordinate(x+1,y);
        this->ui->MoveBox->addItem(QString::fromStdString(right->getString()));     //left
        Coordinate* upRight = new Coordinate(x+1,y+1);
        this->ui->MoveBox->addItem(QString::fromStdString(upRight->getString()));
        Coordinate* downRight = new Coordinate(x+1,y-1);
        this->ui->MoveBox->addItem(QString::fromStdString(downRight->getString()));
    }
    if(right == 8 && down > 0 && up < 8){
        Coordinate* up = new Coordinate(x,y+1);
        this->ui->MoveBox->addItem(QString::fromStdString(up->getString()));
        Coordinate* down = new Coordinate(x,y-1);
        this->ui->MoveBox->addItem(QString::fromStdString(down->getString()));
        Coordinate* left = new Coordinate(x-1,y);
        this->ui->MoveBox->addItem(QString::fromStdString(left->getString()));      //right
        Coordinate* upLeft = new Coordinate(x-1,y+1);
        this->ui->MoveBox->addItem(QString::fromStdString(upLeft->getString()));
        Coordinate* downLeft = new Coordinate(x-1,y-1);
        this->ui->MoveBox->addItem(QString::fromStdString(downLeft->getString()));
    }
    if(up == 8 && left > 0 && right < 8){
        Coordinate* down = new Coordinate(x,y-1);
        this->ui->MoveBox->addItem(QString::fromStdString(down->getString()));
        Coordinate* right = new Coordinate(x+1,y);
        this->ui->MoveBox->addItem(QString::fromStdString(right->getString()));
        Coordinate* left = new Coordinate(x-1,y);
        this->ui->MoveBox->addItem(QString::fromStdString(left->getString()));      //down
        Coordinate* downRight = new Coordinate(x+1,y-1);
        this->ui->MoveBox->addItem(QString::fromStdString(downRight->getString()));
        Coordinate* downLeft = new Coordinate(x-1,y-1);
        this->ui->MoveBox->addItem(QString::fromStdString(downLeft->getString()));
    }
    if(down == 0 && left > 0 && right < 8){
        Coordinate* up = new Coordinate(x,y+1);
        this->ui->MoveBox->addItem(QString::fromStdString(up->getString()));
        Coordinate* right = new Coordinate(x+1,y);
        this->ui->MoveBox->addItem(QString::fromStdString(right->getString()));
        Coordinate* left = new Coordinate(x-1,y);
        this->ui->MoveBox->addItem(QString::fromStdString(left->getString()));      //up
        Coordinate* upLeft = new Coordinate(x-1,y+1);
        this->ui->MoveBox->addItem(QString::fromStdString(upLeft->getString()));
        Coordinate* upRight = new Coordinate(x+1,y+1);
        this->ui->MoveBox->addItem(QString::fromStdString(upRight->getString()));
    }
    if(left == 0 && down == 0){
        Coordinate* right = new Coordinate(x+1,y);
        this->ui->MoveBox->addItem(QString::fromStdString(right->getString()));
        Coordinate* up = new Coordinate(x,y+1);
        this->ui->MoveBox->addItem(QString::fromStdString(up->getString()));        //upleft
        Coordinate* upRight = new Coordinate(x+1,y+1);
        this->ui->MoveBox->addItem(QString::fromStdString(upRight->getString()));
    }
    if(left == 0 && up==8){
        Coordinate* down = new Coordinate(x,y-1);
        this->ui->MoveBox->addItem(QString::fromStdString(down->getString()));
        Coordinate* right = new Coordinate(x+1,y);
        this->ui->MoveBox->addItem(QString::fromStdString(right->getString()));     //downleft
        Coordinate* downRight = new Coordinate(x+1,y-1);
        this->ui->MoveBox->addItem(QString::fromStdString(downRight->getString()));
    }
    if(right == 8 && down == 0){
        Coordinate* left = new Coordinate(x-1,y);
        this->ui->MoveBox->addItem(QString::fromStdString(left->getString()));
        Coordinate* up = new Coordinate(x,y+1);
        this->ui->MoveBox->addItem(QString::fromStdString(up->getString()));        //upright
        Coordinate* upLeft = new Coordinate(x-1,y+1);
        this->ui->MoveBox->addItem(QString::fromStdString(upLeft->getString()));
    }
    if(right == 8 && up == 8){
        Coordinate* left = new Coordinate(x-1,y);
        this->ui->MoveBox->addItem(QString::fromStdString(left->getString()));
        Coordinate* down = new Coordinate(x,y-1);
        this->ui->MoveBox->addItem(QString::fromStdString(down->getString()));
        Coordinate* downLeft = new Coordinate(x-1,y-1);
        this->ui->MoveBox->addItem(QString::fromStdString(downLeft->getString()));
    }
}

