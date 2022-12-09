#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
#include <QDebug>

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

void MainWindow::moveUser(int x, int y, bool User){
    int xArr[7] = {0,116,230,345,459,574,688};
    int yArr[7] = {0,114,229,343,457,572,687};
    if(User){
        this->ui->Red->setGeometry(xArr[x-1],yArr[y-1],112,112);
    }
    else{
        this->ui->Blue->setGeometry(xArr[x-1],yArr[y-1],112,112);
    }
    if(User){
        this->redUserCoordinate = new Coordinate(x,y);
    }
    else{
        this->blueUserCoordinate = new Coordinate(x,y);
    }
}

void MainWindow::deleteTile(int x, int y){

    int xArr[7] = {0,116,230,345,459,574,688};
    int yArr[7] = {0,114,229,343,457,572,687};
    QLabel *label = new QLabel(this);
    label->setStyleSheet("border-image: url(:/other/cross.jpg);");
    label->setGeometry(xArr[x-1],yArr[y-1],112,112);
    label->show();
};

bool MainWindow::playTurn(bool user){
        string deleteString=this->ui->DeleteBox->currentText().toStdString();
        switch (deleteString.at(0)) {
            case 'A':
                deleteTile(1,deleteString.at(2)-'0');
            break;
            case 'B':
                deleteTile(2,deleteString.at(2)-'0');
            break;
            case 'C':
                deleteTile(3,deleteString.at(2)-'0');
            break;
            case 'D':
                deleteTile(4,deleteString.at(2)-'0');
            break;
            case 'E':
                deleteTile(5,deleteString.at(2)-'0');
            break;
            case 'F':
                deleteTile(6,deleteString.at(2)-'0');
            break;
            case 'G':
                deleteTile(7,deleteString.at(2)-'0');
            break;
        }
        string moveString=this->ui->MoveBox->currentText().toStdString();
        switch (moveString.at(0)) {
            case 'A':
                moveUser(1,moveString.at(2)-'0',user);
            break;
            case 'B':
                moveUser(2,moveString.at(2)-'0',user);
            break;
            case 'C':
                moveUser(3,moveString.at(2)-'0',user);
            break;
            case 'D':
                moveUser(4,moveString.at(2)-'0',user);
            break;
            case 'E':
                moveUser(5,moveString.at(2)-'0',user);
            break;
            case 'F':
                moveUser(6,moveString.at(2)-'0',user);
            break;
            case 'G':
                moveUser(7,moveString.at(2)-'0', user);
            break;
        }

    if(user){       //RED plays
        this->ui->Turn->setText(QString::fromStdString("Blue's Turn"));
    }
    else{           //BLUE plays
        this->ui->Turn->setText(QString::fromStdString("Red's Turn"));
    }
    this->turn = !this->turn;
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

