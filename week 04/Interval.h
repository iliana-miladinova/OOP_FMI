#pragma once

class Interval
{
private:
	int _a;
	int _b;
public:
	Interval();
	Interval(int a, int b);

	void setA(int a);
	void setB(int b);

	int getA() const;
	int getB() const;

	int getIntervalLength() const;

	bool isInInterval(int x) const;

	unsigned getCountCondition(bool(*pred)(int)) const;

	unsigned getPrimesCount() const;
	unsigned getPalindromesCount() const;

	bool isSubinterval(const Interval& other) const;
};

Interval intersectInterval(const Interval& lhs, const Interval& rhs);