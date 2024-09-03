#pragma once
#include <iostream>
#include <fstream>

class EventDuringJanuary2023
{
private:
	const static unsigned firstDay = 7;

	uint32_t m_days = 0;

public:
	bool addDay(unsigned day);
	bool removeDay(unsigned day);
	bool containsDay(unsigned day) const;

	unsigned howManyOnDayOfWeek(unsigned dayOfWeek) const;

	bool saveToFile(const char* fileName);
	bool readFromFile(const char* fileName);

	friend EventDuringJanuary2023 getUnion(const EventDuringJanuary2023& lhs, const EventDuringJanuary2023& rhs);
	friend EventDuringJanuary2023 getIntersection(const EventDuringJanuary2023& lhs, const EventDuringJanuary2023& rhs);
};