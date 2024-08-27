#include <iostream>

class Time
{
private:
	unsigned hours = 0;
	unsigned mins = 0;
	unsigned sec = 0;

	bool isInInterval(unsigned upperBound, unsigned value) const
	{
		return upperBound >= value;
	}

	unsigned getUnixFromTime() const
	{
		return 3600 * hours + 60 * mins + sec;
	}

	void setTimeFromUnix(unsigned sec)
	{
		setSeconds(sec % 60);
		sec /= 60;
		setMins(sec % 60);
		sec /= 60;
		setHours(sec % 24);

	}

public:
	Time(unsigned h, unsigned m, unsigned s)
	{
		setHours(h);
		setMins(m);
		setSeconds(s);
	}

	Time() :Time(0, 0, 0)
	{

	}

	void setSeconds(int sec)
	{
		if (isInInterval(60,sec))
		{
			this->sec = sec;
		}
	}

	void setMins(int mins)
	{
		if (isInInterval(60,mins))
		{
			this->mins = mins;
		}
	}

	void setHours(int hours)
	{
		if (isInInterval(24,hours))
		{
			this->hours = hours;
		}
	}

	unsigned getHours() const
	{
		return hours;
	}

	unsigned getMins() const
	{
		return mins;
	}

	unsigned getSeconds() const
	{
		return sec;
	}

	void increment()
	{
		unsigned unixSec = getUnixFromTime();
		unixSec++;
		setTimeFromUnix(unixSec);
	}

	int compare(const Time& other)
	{
		unsigned unix = getUnixFromTime();
		unsigned otherUnix = other.getUnixFromTime();

		if (unix==otherUnix)
		{
			return 0;
		}

		return unix < otherUnix ? -1 : 1;
	}

	bool isDinnerTime()
	{
		Time begin(20, 30, 0);
		Time end(22, 0, 0);

		return compare(begin) > 0 || compare(end) < 0;
	}

	bool isPartyTime()
	{
		Time begin(23, 0, 0);
		Time end(6, 0, 0);
		return compare(begin) > 0 || compare(end) < 0;
	}

	Time getDiff(const Time& other) const
	{
		int diff = fabs(getUnixFromTime() - other.getUnixFromTime());
		Time t;
		t.setTimeFromUnix(diff);
		return t;
	}

	void print() const
	{
		if (hours<10)
		{
			std::cout << '0';
		}
		std::cout << hours << ':';
		if (mins<10)
		{
			std::cout << '0';
		}
		std::cout << mins << ':';
		if (sec<10)
		{
			std::cout << '0';
		}
		std::cout << sec<<std::endl;
	}
};

int main()
{
	Time t(6, 10, 8);
	t.print();
	t.increment();
	t.print();

	Time t2(2, 10, 23);
	std::cout << t.compare(t2)<<std::endl;
	std::cout << t2.isDinnerTime() << std::endl;
	std::cout << t2.isPartyTime() << std::endl;

	Time t3 = t.getDiff(t2);
	t3.print();
}