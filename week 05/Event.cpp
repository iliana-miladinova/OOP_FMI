#include "Event.h"
#pragma warning(disable:4996)

Event::Event(const char* name, const Date& date, const Time& startTime, const Time& endTime)
{
	setName(name);
	validateTimes();
}

Event::Event(const char* name, unsigned day, unsigned month, unsigned year,
	unsigned startHour, unsigned startMin, unsigned startSec,
	unsigned endHour, unsigned endMin, unsigned endSec):_date(day,month,year),
														_startTime(startHour,startMin,startSec),
														_endTime(endHour,endMin,endSec)
{
	setName(name);
	validateTimes();
}

const char* Event::getName() const
{
	return _name;
}

const Date& Event::getDate() const
{
	return _date;
}

const Time& Event::getStartTime() const
{
	return _startTime;
}

const Time& Event::getEndTime() const
{
	return _endTime;
}

void Event::setName(const char* name)
{
	if (strlen(name)>20)
	{
		return;
	}
	else
	{
		strcpy(this->_name, name);
	}
}

void Event::validateTimes()
{
	if (compareTimes(_startTime,_endTime)<=-1)
	{
		std::swap(_startTime, _endTime);
	}
}

Event::Event() :Event("", 1, 1, 1, 0, 0, 0, 0, 0, 0)
{

}