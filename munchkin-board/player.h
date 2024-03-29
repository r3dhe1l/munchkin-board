#pragma once

#include <cstdint>
#include <QString>


class player {
public:
	player();
	player(const QString name, const QString gender, std::size_t chair);

	QString getName() const;
	QString getGender() const;
	std::uint8_t getLevel() const;
	std::int8_t getGear() const;
	std::int8_t getTemporaryBonus() const;
	std::int8_t getTotalPower() const;
	std::size_t getChair() const;

	void changeGender();
	void addOneLevel();
	void substractOneLevel();
	void addGear(const std::int8_t gear);
	void substractGear(const std::int8_t gear);
	void addTemporaryBonus(const std::int8_t bonus);
	void substractTemporaryBonus(const std::int8_t bonus);
	void clearTemporaryBonus();
	void calculateTotalPower();

private:
	QString _name;
	QString _gender;
	std::uint8_t _level;
	std::int8_t _gear;
	std::int8_t _temporaryBonus;
	std::int8_t _totalPower;
	std::size_t _chair;
};