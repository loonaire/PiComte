#include "mainwindow.h"

//#include <QDesktopWidget>
#include <QGuiApplication>
#include <QScreen>

#include <QLayout>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // configuration de la fenêtre
    this->setWindowTitle("PiComte");
    this->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->setWindowIcon(QIcon(":/icon/icone.ico"));

    // taille de la fenetre
    int widthScreen = static_cast<int>(QGuiApplication::primaryScreen()->size().width() * 0.175); // la largeur = 17.5% de la taille de l'écran
    int heightScreen = static_cast<int> (QGuiApplication::primaryScreen()->size().height() * 0.25); // la hauteur = 25% de la hauteur de l'écran
    this->setFixedSize(widthScreen,heightScreen);
    this->setStyleSheet("background-color: grey");

    QString textCase1 = "<html><head/><body><p><span style=\" color:#cf0000;\">90°</span><br><span style=\" color:#005500;\">Pi/2<br>2Pi/4</span></p></body></html>";
    QString textCase2 = "<html><head/><body><p><span style=\" color:#cf0000;\">180°</span><br><span style=\" color:#005500;\">Pi<br>4Pi/4<br>2Pi/2</span></p></body></html>";
    QString textCase3 = "<html><head/><body><p><span style=\" color:#cf0000;\">270°</span><br><span style=\" color:#005500;\">3Pi/2<br>6Pi/4</span></p></body></html>";
    //mise en place des label
    this->nameCol1 = new QLabel("Horaire",this);
    this->nameCol1->setAlignment(Qt::AlignCenter);
    this->nameCol2 = new QLabel("Contrehoraire",this);
    this->nameCol2->setAlignment(Qt::AlignCenter);
    this->case11 = new QLabel(textCase1,this);
    this->case11->setAlignment(Qt::AlignCenter);
    this->case12 = new QLabel(textCase3,this);
    this->case12->setAlignment(Qt::AlignCenter);
    this->case21 = new QLabel(textCase3,this);
    this->case21->setAlignment(Qt::AlignCenter);
    this->case22 = new QLabel(textCase3,this);
    this->case22->setAlignment(Qt::AlignCenter);
    this->case31 = new QLabel(textCase2,this);
    this->case31->setAlignment(Qt::AlignCenter);
    this->case32 = new QLabel(textCase2,this);
    this->case32->setAlignment(Qt::AlignCenter);
    this->Col3Text1 = new QLabel("Taper à 9h\n(-90° horaire)",this);
    this->Col3Text1->setAlignment(Qt::AlignCenter);
    this->Col3Text2 = new QLabel("Taper à 6h\n(180° derrière)",this);
    this->Col3Text2->setAlignment(Qt::AlignCenter);
    this->Col3Text3 = new QLabel("Taper à 3h\n(+90° horaire)",this);
    this->Col3Text3->setAlignment(Qt::AlignCenter);

    this->mainWidget = new QWidget(this);
    //mise en place du Layout
    this->mainLayout = new QGridLayout(mainWidget);
    this->mainLayout->addWidget(nameCol1,0,0,1,1);
    this->mainLayout->addWidget(nameCol2,0,1,1,1);
    this->mainLayout->addWidget(case11,1,0,1,1);
    this->mainLayout->addWidget(case21,1,1,1,1);
    this->mainLayout->addWidget(Col3Text1,1,2,1,1);
    this->mainLayout->addWidget(case31,2,0,1,1);
    this->mainLayout->addWidget(case32,2,1,1,1);
    this->mainLayout->addWidget(Col3Text2,2,2,1,1);
    this->mainLayout->addWidget(case22,3,0,1,1);
    this->mainLayout->addWidget(case12,3,1,1,1);
    this->mainLayout->addWidget(Col3Text3,3,2,1,1);

    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);

}

MainWindow::~MainWindow()
{
}

