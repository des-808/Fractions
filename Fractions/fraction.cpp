#include"fraction.h"

	int Fraction::get_integer()const { return integer; }
	int Fraction::get_numerator()const { return numerator; }
	int Fraction::get_denominator()const { return denominator; }

	void Fraction::set_integer(int integer) { this->integer = integer; }
	void Fraction::set_numerator(int numerator) { this->numerator = numerator; }
	void Fraction::set_denominator(int denominator) {
		if (denominator == 0) { denominator = 1; }
		this->denominator = denominator;
	}

	
	int Fraction::minKrChislo(int denominator_left, int denominator_right) {
		return denominator_left * (denominator_right / gcd(denominator_left, denominator_right));
	}
	////////////////////////////////////////////////////
	int Fraction::gcd(int denominator_left, int denominator_right) {
		while (denominator_right > 0) {
			int tmp = denominator_right;
			denominator_right = denominator_left % denominator_right; // % is remainder
			denominator_left = tmp;
		}
		return denominator_left;
	}

	
	void Fraction::print() {
		if (integer)cout << integer;
		if (numerator) {
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		if (!integer && !numerator)cout << 0;
		cout << endl;
	}
	Fraction& Fraction::operator= (const Fraction& other) {// оператор присвоения
		if (other.numerator > other.denominator) {
			this->integer = other.numerator / other.denominator; this->numerator = other.numerator % other.denominator;
		}
		else {
			this->integer = other.integer;
			this->numerator = other.numerator;
		}
		this->denominator = other.denominator;
		return *this;
	}
	Fraction& Fraction::operator++() {
		this->integer++;
		return *this;
	}
	Fraction Fraction::operator++(int) {
		Fraction vspom = *this;
		this->integer++;
		return vspom;
	}
	Fraction& Fraction::operator--() {
		this->integer--;
		return *this;
	}
	Fraction Fraction::operator--(int) {
		Fraction vspom = *this;
		this->integer--;
		return vspom;
	}
	Fraction& Fraction::operator()(int integer, int numerator, int denominator)
	{
		this->set_integer(integer);
		this->set_numerator(numerator);
		this->set_denominator(denominator);
		//cout << "operator() 1 " << this << endl;
		return *this;
	}
	Fraction& Fraction::operator()(int numerator, int denominator)
	{
		this->set_integer(0);
		this->set_numerator(numerator);
		this->set_denominator(denominator);
		//cout << "operator() 2 " << this << endl;
		return *this;
	}
	Fraction::Fraction(int integer , int numerator , int denominator ) {//конструктор класса с инициализацией//Fraction::Fraction(int integer = 0, int numerator = 1, int denominator = 0) {
		if (!denominator) { denominator = numerator; numerator = integer; integer = 0; }
		this->integer = 0;
		if (integer) { this->numerator = integer * denominator + numerator; }
		else { this->numerator = numerator; }
		this->denominator = denominator;
		//cout << "constructor " << this << endl;
	}
	Fraction::Fraction(const Fraction& other) {//копирующий конструктор
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "copyconstructor" << this << endl;
	}
	Fraction::~Fraction() {//деструктор класса
		//cout << "destructor "<< this<< endl;
	}


bool operator==(const Fraction& left, const Fraction& right) {
	/*if ((left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }*/
	return (left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator());
}
bool operator>=(const Fraction& left, const Fraction& right) {
	/*if ((left.get_numerator() * right.get_denominator()) >= (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }*/
	return !(left == right);
}
bool operator<=(const Fraction& left, const Fraction& right) {
	if ((left.get_numerator() * right.get_denominator()) <= (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}
bool operator> (const Fraction& left, const Fraction& right) {
	if ((left.get_numerator() * right.get_denominator()) > (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}
bool operator< (const Fraction& left, const Fraction& right) {
	if ((left.get_numerator() * right.get_denominator()) < (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}

Fraction& operator+(const Fraction& left, const Fraction& right) {
	Fraction result;
	if (left.get_denominator() == right.get_denominator()) {
		result.set_numerator(left.get_numerator() + right.get_numerator());
		result.set_denominator(left.get_denominator());
	}
	else {
		int nok = result.minKrChislo(left.get_denominator(), right.get_denominator());
		int mn1 = nok / left.get_denominator();
		int mn2 = nok / right.get_denominator();
		result.set_numerator(left.get_numerator() * mn1 + right.get_numerator() * mn2);
		result.set_denominator(left.get_denominator() * mn1);// + right.get_denominator() * mn2
	}
	return result;
}
Fraction& operator-(const Fraction& left, const Fraction& right) {
	Fraction result;
	if (left.get_denominator() == right.get_denominator()) {
		result.set_numerator((left.get_numerator() > right.get_numerator()) ? left.get_numerator() - right.get_numerator() : right.get_numerator() - left.get_numerator());
		result.set_denominator(left.get_denominator());
	}
	else {
		int nok = result.minKrChislo(left.get_denominator(), right.get_denominator());
		int mn1 = nok / left.get_denominator();
		int mn2 = nok / right.get_denominator();
		result.set_numerator(left.get_numerator() * mn1 - right.get_numerator() * mn2);
		result.set_denominator(left.get_denominator() * mn1);//- right.get_denominator() * mn2
	}
	return result;
}
Fraction& operator*(const Fraction& left, const Fraction& right) {
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}

Fraction& operator/(const Fraction& left, const Fraction& right) {
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_numerator());
	return result;
}