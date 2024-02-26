#pragma once

#include <QtWidgets/QMainWindow>
#include <QVector>
#include "ui_munchkinboard.h"
#include "player.hpp"

class munchkinboard : public QMainWindow
{
    Q_OBJECT

public:
    munchkinboard(QWidget *parent = nullptr);
    ~munchkinboard();
    QVector<player> _players;
    
public slots:
    void onCreatePlayerButtonClicked(QPushButton* button, QLineEdit* nameLine, QComboBox* genderBox);

private:
    Ui::munchkinboardClass ui;

};
