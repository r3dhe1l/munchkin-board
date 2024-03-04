#pragma once

#include <algorithm>
#include <QtWidgets/QMainWindow>
#include <QVector>

#include "ui_munchkinboard.h"
#include "createplayers.h"

class munchkinboard : public QMainWindow
{
	Q_OBJECT

public:
	munchkinboard(QWidget* parent = nullptr);
	~munchkinboard();

private:
	QVector<player> _players;
	Ui::munchkinboardClass ui;

	void connectButtons();
};
