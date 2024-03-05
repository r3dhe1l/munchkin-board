#include "munchkinboard.h"

// This is the constructor of the class munchkinboard
munchkinboard::munchkinboard(QWidget* parent)
	: QMainWindow(parent),
	ui(Ui::munchkinboardClass()),
	_players(6)
{
	ui.setupUi(this);
	this->showFullScreen();


	// This will be removed when the project is finished because if defined hidden in the .ui file, the Qt Designer can't show the boxes.
	ui.groupBox_0->hide();
	ui.groupBox_1->hide();
	ui.groupBox_2->hide();
	ui.groupBox_3->hide();
	ui.groupBox_4->hide();
	ui.groupBox_5->hide();
	ui.battleBox->hide();

	createplayers* createPlayers = new createplayers(this); // Creates the dialog to create the players

	// Connects the playerCreated signal to the lambda function that replaces the player in the vector
	connect(createPlayers, &createplayers::playerCreated, this,
		[=](const player& player) { _players.push_back(player); });

	createPlayers->exec(); // Shows the dialog to create the players

	connect(ui.closeButton, &QPushButton::clicked, this, &QMainWindow::close); // Connects the close button to the close function

	connectButtons(); // Connects the buttons to the functions
}

// This is the destructor of the class munchkinboard
munchkinboard::~munchkinboard()
{}

void munchkinboard::connectButtons()
{
	// For each to rotate the vector of players and connect the buttons to the functions
	std::for_each(_players.begin(), _players.end(), [&](player& player) {

		// If to guarantee that the player is not empty
		if (player.getName() != "") {

			// Defines the labels, LCDs, buttons and line edits for each position
			QLabel* nameLabel = this->findChild<QLabel*>("name_" + QString::number(player.getChair()));
			QLabel* genderLabel = this->findChild<QLabel*>("gender_" + QString::number(player.getChair()));
			QLCDNumber* levelLCD = this->findChild<QLCDNumber*>("level_" + QString::number(player.getChair()));
			QLCDNumber* gearLCD = this->findChild<QLCDNumber*>("gear_" + QString::number(player.getChair()));
			QLCDNumber* bonusLCD = this->findChild<QLCDNumber*>("bonus_" + QString::number(player.getChair()));
			QLCDNumber* totalLCD = this->findChild<QLCDNumber*>("total_" + QString::number(player.getChair()));
			QPushButton* changeGenderButton = this->findChild<QPushButton*>("changeGender_" + QString::number(player.getChair()));
			QPushButton* addLevelButton = this->findChild<QPushButton*>("addLevel_" + QString::number(player.getChair()));
			QPushButton* subLevelButton = this->findChild<QPushButton*>("subLevel_" + QString::number(player.getChair()));
			QPushButton* addGearButton = this->findChild<QPushButton*>("addGear_" + QString::number(player.getChair()));
			QPushButton* subGearButton = this->findChild<QPushButton*>("subGear_" + QString::number(player.getChair()));
			QLineEdit* lineGear = this->findChild<QLineEdit*>("lineGear_" + QString::number(player.getChair()));
			QPushButton* addBonusButton = this->findChild<QPushButton*>("addBonus_" + QString::number(player.getChair()));
			QPushButton* subBonusButton = this->findChild<QPushButton*>("subBonus_" + QString::number(player.getChair()));
			QLineEdit* lineBonus = this->findChild<QLineEdit*>("lineBonus_" + QString::number(player.getChair()));

			// Gets the player's information and shows it in the board
			nameLabel->setText(player.getName());
			genderLabel->setText(player.getGender());
			levelLCD->display(player.getLevel());
			gearLCD->display(player.getGear());
			bonusLCD->display(player.getTemporaryBonus());
			totalLCD->display(player.getTotalPower());

			// Connects the buttons to the functions that change the each player's information
			connect(changeGenderButton, &QPushButton::clicked, this,
				[&, genderLabel]() {player.changeGender(); genderLabel->setText(player.getGender()); });

			connect(addLevelButton, &QPushButton::clicked, this,
				[&, levelLCD, totalLCD]() {player.addOneLevel(); levelLCD->display(player.getLevel()); totalLCD->display(player.getTotalPower()); });

			connect(subLevelButton, &QPushButton::clicked, this,
				[&, levelLCD, totalLCD]() {player.substractOneLevel(); levelLCD->display(player.getLevel()); totalLCD->display(player.getTotalPower()); });

			connect(addGearButton, &QPushButton::clicked, this,
				[&, lineGear, gearLCD, totalLCD]() {player.addGear(lineGear->text().toInt()); lineGear->clear();
			gearLCD->display(player.getGear()); totalLCD->display(player.getTotalPower()); });

			connect(subGearButton, &QPushButton::clicked, this,
				[&, lineGear, gearLCD, totalLCD]() {player.substractGear(lineGear->text().toInt()); lineGear->clear();
			gearLCD->display(player.getGear()); totalLCD->display(player.getTotalPower()); });

			connect(addBonusButton, &QPushButton::clicked, this,
				[&, lineBonus, bonusLCD, totalLCD]() {player.addTemporaryBonus(lineBonus->text().toInt()); lineBonus->clear();
			bonusLCD->display(player.getTemporaryBonus()); totalLCD->display(player.getTotalPower()); });

			connect(subBonusButton, &QPushButton::clicked, this,
				[&, lineBonus, bonusLCD, totalLCD]() {player.substractTemporaryBonus(lineBonus->text().toInt()); lineBonus->clear();
			bonusLCD->display(player.getTemporaryBonus()); totalLCD->display(player.getTotalPower()); });

			// Shows the group box with the player's information
			this->findChild<QGroupBox*>("groupBox_" + QString::number(player.getChair()))->show();
		}
		});
}