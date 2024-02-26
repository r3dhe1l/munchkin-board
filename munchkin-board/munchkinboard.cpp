#include "munchkinboard.h"
#include <QMessageBox>
#include <QStatusBar>

// This is the constructor of the class munchkinboard
munchkinboard::munchkinboard(QWidget* parent)
	: QMainWindow(parent),
	ui(Ui::munchkinboardClass())
{
	ui.setupUi(this);
	this->showFullScreen();

	statusBar(); // Creates the status bar
	connect(ui.closeButton, &QPushButton::clicked, this, &QMainWindow::close); // Connects the close button to the close function

	// Connects the createPlayer buttons to the onCreatePlayerButtonClicked function
	connect(ui.createPlayer1Button, &QPushButton::clicked, this,
		[=]() { onCreatePlayerButtonClicked(ui.createPlayer1Button, ui.player1NameLine, ui.player1GenderBox); });
	connect(ui.createPlayer2Button, &QPushButton::clicked, this,
		[=]() { onCreatePlayerButtonClicked(ui.createPlayer2Button, ui.player2NameLine, ui.player2GenderBox); });
	connect(ui.createPlayer3Button, &QPushButton::clicked, this,
		[=]() { onCreatePlayerButtonClicked(ui.createPlayer3Button, ui.player3NameLine, ui.player3GenderBox); });
	connect(ui.createPlayer4Button, &QPushButton::clicked, this,
		[=]() { onCreatePlayerButtonClicked(ui.createPlayer4Button, ui.player4NameLine, ui.player4GenderBox); });
	connect(ui.createPlayer5Button, &QPushButton::clicked, this,
		[=]() { onCreatePlayerButtonClicked(ui.createPlayer5Button, ui.player5NameLine, ui.player5GenderBox); });
	connect(ui.createPlayer6Button, &QPushButton::clicked, this,
		[=]() { onCreatePlayerButtonClicked(ui.createPlayer6Button, ui.player6NameLine, ui.player6GenderBox); });
}

// This is the destructor of the class munchkinboard
munchkinboard::~munchkinboard()
{}

// This function is called when a createPlayer button is clicked
void munchkinboard::onCreatePlayerButtonClicked(QPushButton* button, QLineEdit* nameLine, QComboBox* genderBox)
{
	// Checks if the name has at least 3 characters and doesn't contain spaces
	if (nameLine->text().length() < 3 || nameLine->text().contains(" ")) {
		QMessageBox::warning(this, "Erro", "O nome deve ter no mínimo 3 caracteres e não pode conter espaços em branco.");
		return;
	}

	// Checks if a gender was selected
	if (genderBox->currentText() != "Menino" && genderBox->currentText() != "Menina") {
		QMessageBox::warning(this, "Erro", "Selecione um gênero.");
		return;
	}

	// Creates a new player and adds it to the players vector
	player newPlayer(nameLine->text(), genderBox->currentText());
	_players.push_back(newPlayer);

	// Disables the button, name line, and gender box to avoid creating the same player twice
	button->setDisabled(true);
	nameLine->setDisabled(true);
	genderBox->setDisabled(true);

	// Shows a success message in the status bar
	statusBar()->showMessage(
		newPlayer.getGender() == "Menino" ? "O jogador " + newPlayer.getName() + " foi criado com sucesso!"
		: "A jogadora " + newPlayer.getName() + " foi criada com sucesso!", 2000);
}
