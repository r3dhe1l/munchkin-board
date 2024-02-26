#include "player.hpp"

// Default constructor for the player class
player::player()
	: _name(""), _gender(""), _level(1), _gear(0), _temporaryBonus(0), _totalPower(1)
{}

// The constructor initializes the player with a name, gender and default level, gear and temporary bonus.
player::player(const QString name, const QString gender)
	: _name(name), _gender(gender), _level(1), _gear(0), _temporaryBonus(0), _totalPower(1)
{}

// Returns the player's name.
QString player::getName() const {
	return _name;
}

// Returns the player's gender
QString player::getGender() const {
	return _gender;
}

// Returns the player's level
std::uint8_t player::getLevel() const {
	return _level;
}

// Returns the player's total power
std::int8_t player::getTotalPower() const {
	return _totalPower;
}

// Changes player's gender
void player::changeGender() {
	_gender = _gender == "Menino" ? "Menina" : "Menino";
}

// Adds one level to the player and refreshes his total power
void player::addOneLevel() {
	_level++;
	calculateTotalPower();
}

// Substracts one level to the player and refreshes his total power
void player::substractOneLevel() {
	_level--;
	calculateTotalPower();
}

// Adds equipment power to the player and refreshes his total power
void player::addGear(const std::int8_t gear) {
	_gear += gear;
	calculateTotalPower();
}

// Substracts equipment power to the player and refreshes his total power
void player::substractGear(const std::int8_t gear) {
	_gear -= gear;
	calculateTotalPower();
}

// Adds a temporary bonus to the player and refreshes his total power
void player::addTemporaryBonus(const std::int8_t bonus) {
	_temporaryBonus += bonus;
	calculateTotalPower();
}

// Substracts a temporary bonus to the player and refreshes his total power
void player::substractTemporaryBonus(const std::int8_t bonus) {
	_temporaryBonus -= bonus;
	calculateTotalPower();
}

// Clears the temporary bonus and refreshes his total power
void player::clearTemporaryBonus() {
	_temporaryBonus = 0;
	calculateTotalPower();
}

// Calculates the player's total power
void player::calculateTotalPower() {
	_totalPower = _level + _gear + _temporaryBonus;
}