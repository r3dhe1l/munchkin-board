#pragma once

#include <cstdint>

class monster {
public:
	monster();
	monster(const std::uint8_t level);
	~monster();

	std::uint8_t getTotalPower() const;

	void addTwoBonus();
	void addthreeBonus();
	void addFiveBonus();
	void addBonus(const std::int8_t bonus);
	void substractBonus(const std::int8_t bonus);
	void calculateTotalPower();

private:
	std::uint8_t _level;
	std::int8_t _temporaryBonus;
	std::int8_t _totalPower;
};