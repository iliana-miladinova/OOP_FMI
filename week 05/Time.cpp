#include "Time.h"
Time::Time(unsigned hours, unsigned mins, unsigned sec)
{
	setHours(hours);
	setMins(mins);
	setSec(sec);
}

unsigned Time::getHours() const
{
	return secondsFromMidnight / SECONDS_IN_HOUR;
}

unsigned Time::getMins() const
{
	return (secondsFromMidnight / SECONDS_IN_MINUTE) % 60;
}

unsigned Time::getSec() const
{
	return (secondsFromMidnight) & 60;
}
bool Time::setHours(unsigned hours)
{
	return validateAndSet(0, 23, hours, getHours(), SECONDS_IN_HOUR);
}

bool Time::setMins(unsigned mins)
{
	return validateAndSet(0, 59, mins, getMins(), SECONDS_IN_MINUTE);
}

bool Time::setSec(unsigned sec)
{
	return validateAndSet(0, 59, sec, getSec(), 1);
}

bool Time::validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldValue, unsigned multiplier)
{
	if (newValue >= lowerBound && newValue <= upperBound)
	{
		secondsFromMidnight = secondsFromMidnight - (oldValue * multiplier) + (newValue * multiplier);
		return true;
	}
	return false;
}

void Time::tick()
{
	secondsFromMidnight = (secondsFromMidnight + 1) % SECONDS_IN_DAY;
}

void Time::serialize(std::ostream& os) const
{
	os << std::setfill('0') << getHours() << ":" <<
		std::setfill('0') << getMins() << ":" <<
		std::setfill('0') << getSec() << std::endl;
}

int compareTimes(const Time& lhs, const Time& rhs)
{
	//we don't have access to the secondsFromMidnight
	// and we don't know what 'static' and 'friend' is at this point of the course, yet.

	if (lhs.getHours()==rhs.getHours())
	{
		if (lhs.getMins()==rhs.getMins())
		{
			return lhs.getSec() - rhs.getSec();
		}
		else
		{
			return lhs.getMins() - rhs.getMins();
		}
	}
	else
	{
		return lhs.getHours() - rhs.getHours();
	}
}