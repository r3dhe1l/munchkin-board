#include "createplayers.h"

// This is the constructor of the class createplayers
createplayers::createplayers(QWidget* parent)
	: QDialog(parent),
	ui(Ui::createplayersClass())
{
	ui.setupUi(this);

	// Connects the button to the function that creates the player
	connect(ui.createButton, &QPushButton::clicked, this, &createplayers::onCreateButtonClicked);

	// Connects the start game button to the accept function
	connect(ui.startGameButton, &QPushButton::clicked, this, &createplayers::onAcceptButtonClicked);
}

// This is the destructor of the class createplayers
createplayers::~createplayers()
{}

void createplayers::onCreateButtonClicked()
{
	// Checks if the name has at least 3 characters and doesn't contain spaces
	if (ui.nameLine->text().length() < 3 || ui.nameLine->text().contains(" ")) {
		QMessageBox::warning(this, "Erro", "O nome deve ter no mínimo 3 caracteres e não pode conter espaços em branco.");
		return;
	}

	// Checks if a gender was selected
	if (ui.genderBox->currentText() != "Menino" && ui.genderBox->currentText() != "Menina") {
		QMessageBox::warning(this, "Erro", "Selecione um gênero.");
		return;
	}

	// Checks if a position was selected
	if (ui.positionBox->currentText().isEmpty()) {
		QMessageBox::warning(this, "Erro", "Selecione uma cadeira.");
		return;
	}

	player newPlayer(ui.nameLine->text(), ui.genderBox->currentText(), ui.positionBox->currentText().toInt()); // Creates the player
	emit playerCreated(newPlayer); // Emits the signal to replace the player in the vector

	ui.nameLine->clear(); // Clears the name line
	ui.genderBox->setCurrentIndex(-1); // Resets the gender box
	ui.positionBox->removeItem(ui.positionBox->currentIndex()); // Removes the selected position
	ui.positionBox->setCurrentIndex(-1); // Resets the position box

	ui.label->setText(newPlayer.getGender() == "Menino" ? "O jogador " + newPlayer.getName() + " foi criado com sucesso!"
		: "A jogadora " + newPlayer.getName() + " foi criada com sucesso!"); // Shows a message of creation player
}

void createplayers::onAcceptButtonClicked()
{
	// Checks if there are at least 3 players
	if (ui.positionBox->count() > 3) {
		QMessageBox::warning(this, "Erro", "São necessários pelo menos 3 jogadores.");
		return;
	}
	accept(); // Accepts the dialog
}