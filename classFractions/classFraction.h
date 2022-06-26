#pragma once
#include"Header.h"

class Fraction;
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
class Fraction {
	int integer;// celoe;
	int numerator;// chislitel;
	int denominator;// znamenatel;
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;

	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	unsigned int maxKrChislo(unsigned int numerator, unsigned int denominator);
	int minKrChislo(int denominator_left, int denominator_right);
	//////////////////////////////////////////////////////
	int gcd(int denominator_left, int denominator_right);

	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;
	void print();
	Fraction& operator= (const Fraction& other);
	Fraction& operator*= (Fraction other);
	Fraction& operator/= (Fraction other);
	Fraction& operator+= (Fraction other);
	Fraction& operator-= (Fraction other);

	Fraction& operator++();
	Fraction  operator++(int);
	Fraction& operator--();
	Fraction  operator--(int);

	explicit Fraction(int integer);

	Fraction(double xz);
	Fraction& reduce();

	explicit operator int()const;
	operator double()const;

	Fraction& operator()(int integer, int numerator, int denominator);
	Fraction& operator()(int numerator, int denominator);

	Fraction();
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();
};

bool operator==(Fraction left, Fraction right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator> (Fraction left, Fraction right);
bool operator< (Fraction left, Fraction right);
bool operator>=(const Fraction& left, const  Fraction& right);
bool operator<=(const Fraction& left, const  Fraction& right);

std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);


Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);