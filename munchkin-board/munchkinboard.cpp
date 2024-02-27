#include "munchkinboard.h"

// This is the constructor of the class munchkinboard
munchkinboard::munchkinboard(QWidget* parent)
	: QMainWindow(parent),
	ui(Ui::munchkinboardClass()),
	_players(6)
{
	ui.setupUi(this);
	this->showFullScreen();

	createplayers* createPlayers = new createplayers(this); // Creates the dialog to create the players

	// Connects the playerCreated signal to the lambda function that replaces the player in the vector
	connect(createPlayers, &createplayers::playerCreated, this,
		[=](const player& player, std::size_t pos) { _players.replace(pos, player); });
	
	createPlayers->exec(); // Shows the dialog to create the players

	connect(ui.closeButton, &QPushButton::clicked, this, &QMainWindow::close); // Connects the close button to the close function
}

// This is the destructor of the class munchkinboard
munchkinboard::~munchkinboard()
{}
