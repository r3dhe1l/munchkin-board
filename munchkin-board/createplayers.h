#pragma once

#include <cstdint>
#include <QDialog>
#include <QMessageBox>

#include "ui_createplayers.h"
#include "player.h"

class createplayers : public QDialog
{
	Q_OBJECT

public:
	createplayers(QWidget* parent = nullptr);
	~createplayers();

public slots:
	void onCreateButtonClicked();
	void onAcceptButtonClicked();

signals:
	void playerCreated(const player& player);

private:
	Ui::createplayersClass ui;
};
