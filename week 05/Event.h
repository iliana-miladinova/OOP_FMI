#pragma once
#include "Time.h"
#include "BulgarianDate.h"

typedef BulgarianDate Date;

class Event
{
private:
	char _name[21];
	Date _date;
	Time _startTime;
	Time _endTime;

	void setName(const char* name);
	void validateTimes();

public:
	Event();
	Event(const char* name, const Date& date, const Time& startTime, const Time& endTime);
	Event(const char* name, unsigned day, unsigned month, unsigned year,
		unsigned startHour, unsigned startMin, unsigned startSec,
		unsigned endHour, unsigned endMin, unsigned endSec);

	const char* getName() const;
	const Date& getDate() const;
	const Time& getStartTime() const;
	const Time& getEndTime() const;
};