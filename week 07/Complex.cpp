#include "Complex.h"

Complex::Complex()
{
	real = 0;
	im = 0;
}

Complex::Complex(double real, double im)
{
	this->real = real;
	this->im = im;
}

Complex& Complex::operator+=(const Complex& other)
{
	real += other.real;
	im += other.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
	real -= other.real;
	im -= other.im;
	return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
	double oldReal = real;
	real = real * other.real - im * other.im;
	im = oldReal * other.im + im * other.real;
	return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
	Complex conjugeted = other.getConjugated();
	Complex otherCopy(other);

	*this *= conjugeted;
	otherCopy *= conjugeted;

	if (otherCopy.real!=0)
	{
		real /= otherCopy.real;
		im /= otherCopy.real;
	}
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	result += rhs;
	return result;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	result -= rhs;
	return result;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	result *= rhs;
	return result;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	result /= rhs;
	return result;
}

Complex Complex::getConjugated() const
{
	Complex result(*this);
	result.im *= -1;
	return result;
}

double Complex::getReal() const
{
	return real;
}

double Complex::getIm() const
{
	return im;
}

void Complex::setReal(double newReal)
{
	real = newReal;
}

void Complex::setIm(double newIm)
{
	im = newIm;
}

// за да можем да правим  cout<<c1 или да запазваме във файл и др.
std::ostream& operator<<(std::ostream& os, const Complex& r)
{
	return os << r.real << ' ' << r.im << 'i';
}

std::istream& operator>>(std::istream& is, Complex& r)
{
	return is >> r.real >> r.im;
}

bool operator==(const Complex& lhs, const Complex& rhs)
{
	return lhs.getReal() == rhs.getReal() && lhs.getIm() == rhs.getIm();
}

bool operator!=(const Complex& lhs, const Complex& rhs)
{
	return !(lhs == rhs);
}