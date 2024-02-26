#include "monster.hpp"

// Default constructor for the monster class
monster::monster()
	: _level(0), _temporaryBonus(0), _totalPower(0)
{}

// Constructor for the monster class with a level parameter
monster::monster(const std::uint8_t level)
	: _level(level), _temporaryBonus(0), _totalPower(level)
{}

// Destructor for the monster class
monster::~monster()
{}

// Returns the monster's total power
std::uint8_t monster::getTotalPower() const {
	return _totalPower;
}

// Adds a temporary bonus of 2 to the monster and refreshes its total power
void monster::addTwoBonus() {
	_temporaryBonus += 2;
	calculateTotalPower();
}

// Adds a temporary bonus of 3 to the monster and refreshes its total power
void monster::addthreeBonus() {
	_temporaryBonus += 3;
	calculateTotalPower();
}

// Adds a temporary bonus of 5 to the monster and refreshes its total power
void monster::addFiveBonus() {
	_temporaryBonus += 5;
	calculateTotalPower();
}

// Adds a temporary bonus to the monster and refreshes its total power
void monster::addBonus(const std::int8_t bonus) {
	_temporaryBonus += bonus;
	calculateTotalPower();
}

// Substracts a temporary bonus to the monster and refreshes its total power
void monster::substractBonus(const std::int8_t bonus) {
	_temporaryBonus -= bonus;
	calculateTotalPower();
}

// Calculates the monster's total power
void monster::calculateTotalPower() {
	_totalPower = _level + _temporaryBonus;
}