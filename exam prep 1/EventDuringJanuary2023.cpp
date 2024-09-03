#include "EventDuringJanuary2023.h"

static const short MAX_DAY = 31;
static const short MAX_DAY_IN_WEEK = 7;

bool EventDuringJanuary2023::addDay(unsigned day)
{
	if (day==0||day>MAX_DAY)
	{
		return false;
	}

	m_days |= (1 << day);

	return true;
}

bool EventDuringJanuary2023::removeDay(unsigned day)
{
	if (day == 0||day>MAX_DAY)
	{
		return false;
	}

	m_days ^= (1 << day);
	return true;
}

bool EventDuringJanuary2023::containsDay(unsigned day) const
{
	if (day==0||day>MAX_DAY)
	{
		return false;
	}

	return m_days & (1 << day);
}

unsigned EventDuringJanuary2023::howManyOnDayOfWeek(unsigned dayOfWeek) const
{
	if (dayOfWeek == 0 || dayOfWeek>MAX_DAY_IN_WEEK)
	{
		return 0;
	}

	unsigned count = 0;
	int offset = (dayOfWeek == MAX_DAY_IN_WEEK) ? 0 : dayOfWeek;
	for (int i = 1+offset; i <= MAX_DAY ; i+=MAX_DAY_IN_WEEK)
	{
		if (containsDay(i))
		{
			count++;
		}
	}
	return count;
}

bool EventDuringJanuary2023::saveToFile(const char* fileName)
{
	std::ofstream ofs(fileName, std::ios::binary);
	if (!ofs.is_open())
	{
		throw std::exception("Cannot open file!");
	}

	ofs.write((const char*)&m_days, sizeof(m_days));
	ofs.close();
}

bool EventDuringJanuary2023::readFromFile(const char* fileName)
{
	std::ifstream ifs(fileName, std::ios::binary);

	if (!ifs.is_open())
	{
		throw std::exception("Cannot open file");
	}

	ifs.read((char*)&m_days, sizeof(m_days));
	ifs.close();
}

EventDuringJanuary2023 getUnion(const EventDuringJanuary2023& lhs, const EventDuringJanuary2023& rhs)
{
	EventDuringJanuary2023 result;

	result.m_days = lhs.m_days | rhs.m_days;
	return result;
}

EventDuringJanuary2023 getIntersection(const EventDuringJanuary2023& lhs, const EventDuringJanuary2023& rhs)
{
	EventDuringJanuary2023 result;
	
	result.m_days = lhs.m_days & rhs.m_days;
	return result;
}