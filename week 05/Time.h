#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>

constexpr unsigned SECONDS_IN_HOUR = 3600;
constexpr unsigned SECONDS_IN_MINUTE = 60;
constexpr unsigned SECONDS_IN_DAY = 24 * SECONDS_IN_HOUR;

class Time
{
private:
	unsigned secondsFromMidnight = 0;
	bool validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldValue, unsigned multiplier);

public:
	Time() = default;
	Time(unsigned hours, unsigned mins, unsigned sec);

	unsigned getHours() const;
	unsigned getMins() const;
	unsigned getSec() const;

	bool setHours(unsigned hours);
	bool setMins(unsigned mins);
	bool setSec(unsigned sec);

	void tick();
	void serialize(std::ostream& os)const;
};

int compareTimes(const Time& lhs, const Time& rhs);