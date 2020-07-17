#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLayout>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel *nameCol1;
    QLabel *nameCol2;
    QLabel *case11;
    QLabel *case12;
    QLabel *case21;
    QLabel *case22;
    QLabel *case31;
    QLabel *case32;
    QLabel *Col3Text1;
    QLabel *Col3Text2;
    QLabel *Col3Text3;
    QGridLayout *mainLayout;
    QWidget *mainWidget;

};
#endif // MAINWINDOW_H
