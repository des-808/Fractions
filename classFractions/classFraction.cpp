#include"classFraction.h"

	int Fraction::get_integer()const { return integer; }
	int Fraction::get_numerator()const { return numerator; }
	int Fraction::get_denominator()const { return denominator; }

	void Fraction::set_integer(int integer) { this->integer = integer; }
	void Fraction::set_numerator(int numerator) { this->numerator = numerator; }
	void Fraction::set_denominator(int denominator) {
		if (denominator == 0) { denominator = 1; }
		this->denominator = denominator;
	}

	unsigned int Fraction::maxKrChislo(unsigned int numerator, unsigned int denominator) {
		if (numerator == denominator)
			return numerator;
		if (numerator > denominator)
			return maxKrChislo(numerator - denominator, denominator);
		return maxKrChislo(numerator, denominator - numerator);
	}
	int Fraction::minKrChislo(int denominator_left, int denominator_right) {
		return denominator_left * (denominator_right / gcd(denominator_left, denominator_right));
	}
	//////////////////////////////////////////////////////
	int Fraction::gcd(int denominator_left, int denominator_right) {
		while (denominator_right > 0) {
			int tmp = denominator_right;
			denominator_right = denominator_left % denominator_right; // % is remainder
			denominator_left = tmp;
		}
		return denominator_left;
	}

	Fraction& Fraction::to_improper() {
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& Fraction::to_proper() {
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction Fraction::inverted()const {
		Fraction inverted = *this;
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;
		return inverted;

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
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "copyAssigment  " << this << endl;
		reduce();
		return *this;
	}
	Fraction& Fraction::operator*= (Fraction other) {//
		/*other.to_improper();
		this->set_numerator(this->get_numerator() * other.get_numerator());
		this->set_denominator(this->get_denominator() * other.get_denominator());
		return *this;*/
		return *this = *this * other;
	}
	Fraction& Fraction::operator/= (Fraction other) {//
		return *this = *this / other;
	}
	Fraction& Fraction::operator+= (Fraction other) {//
		return *this = *this + other;
	}
	Fraction& Fraction::operator-= (Fraction other) {//
		return *this = *this - other;
	}

	Fraction& Fraction::operator++() {
		integer++;
		return *this;
	}
	Fraction  Fraction::operator++(int) {
		Fraction vspom = *this;
		this->integer++;
		return vspom;
	}
	Fraction& Fraction::operator--() {
		this->integer--;
		return *this;
	}
	Fraction  Fraction::operator--(int) {
		Fraction vspom = *this;
		this->integer--;
		return vspom;
	}

	Fraction::Fraction(int integer) {//	явный
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
	}
	//explicit Fraction(int integer) {//	явный
	//	this->integer = integer;
	//	this->numerator = 0;
	//	this->denominator = 1;
	//}

	Fraction::Fraction(double xz) {
		xz += 1e-10;
		integer = xz;//преобразовываем дробь в целое число при этом дробь отбрасывается
		xz = xz - integer;//получаем дробную часть
		numerator = xz * 1e9;// дробную часть в целую
		denominator = 1e9;//в делитель пишем такой же множитель на который и умножили числитель для правильного преобразования дроби
		xz = maxKrChislo(numerator, denominator);//ищем максимальное кратное число
		set_numerator(numerator / xz);//сокращаем дробь если это получится
		set_denominator(denominator / xz);//сокращаем дробь если это получится

	}
	Fraction& Fraction::reduce()
	{
		int x = maxKrChislo(numerator, denominator);//ищем максимальное кратное число
		set_numerator(numerator / x);//сокращаем дробь если это получится
		set_denominator(denominator / x);//сокращаем дробь если это получится 
		return *this;
	}

	Fraction::operator int()const
	{
		return integer;
	}
	/*explicit Fraction::operator int()const
	{
		return integer;
	}*/
	Fraction::operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	Fraction& Fraction::operator()(int integer, int numerator, int denominator) {
		this->set_integer(integer);
		this->set_numerator(numerator);
		this->set_denominator(denominator);
		return *this;
	}
	Fraction& Fraction::operator()(int numerator, int denominator) {
		this->set_integer(0);
		this->set_numerator(numerator);
		this->set_denominator(denominator);
		//cout << "operator() 2 " << this << endl;
		return *this;
	}

	Fraction::Fraction() {//конструктор класса 
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
	}
	Fraction::Fraction(int numerator, int denominator) {//конструктор класса 
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
	}
	Fraction::Fraction(int integer, int numerator, int denominator) {//конструктор класса с инициализацией
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
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

//1. Арифметические операторы : +, -, *, / ;
//2. Составные присваивания : +=, -=, *=, /=;
//3. Incremento / Decremento;
//4. Операторы сравнения : == , != , > , < , >= , <= ;

bool operator==(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	/*if ((left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }*/
	return (left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator());
}
bool operator!=(const Fraction& left, const Fraction& right) {
	return !(left == right);
}
//bool operator!=( Fraction left, Fraction right) {
//	left.to_improper();
//	right.to_improper();
//	/*if ((left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator())) { return true; }
//	else { return false; }*/
//	return (left.get_numerator() * right.get_denominator()) != (left.get_denominator() * right.get_numerator());
//}
bool operator> (Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	/*if ((left.get_numerator() * right.get_denominator()) > (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }*/
	return (left.get_numerator() * right.get_denominator()) > (left.get_denominator() * right.get_numerator());
}
bool operator< (Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	/*if ((left.get_numerator() * right.get_denominator()) < (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }*/
	return (left.get_numerator() * right.get_denominator()) < (left.get_denominator() * right.get_numerator());
}
bool operator>=(const Fraction& left, const  Fraction& right) {
	//return left >right|| left == right;
	return !(left < right);
}
//bool operator>=(Fraction left, Fraction right) {
//	left.to_improper();
//	right.to_improper();
//	/*if ((left.get_numerator() * right.get_denominator()) >= (left.get_denominator() * right.get_numerator())) { return true; }
//	else { return false; }*/
//	//return !(left == right);
//	return (left.get_numerator() * right.get_denominator()) >= (left.get_denominator() * right.get_numerator());
//}
bool operator<=(const Fraction& left, const  Fraction& right) {
	//return left < right || left == right;
	return !(left > right);
}
//bool operator<=( Fraction left, Fraction right) {
//	left.to_improper();
//	right.to_improper();
//	/*if ((left.get_numerator() * right.get_denominator()) <= (left.get_denominator() * right.get_numerator())) { return true; }
//	else { return false; }*/
//	return (left.get_numerator() * right.get_denominator()) <= (left.get_denominator() * right.get_numerator());
//}

std::ostream& operator<<(std::ostream& os, const Fraction& obj) {
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator()) {
		if (obj.get_integer())os << "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	if (!obj.get_integer() && !obj.get_numerator())os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj) {
	const int SIZE = 256;
	char sz_buffer[SIZE] = {};
	//is >> sz_buffer;
	is.getline(sz_buffer, SIZE);
	char* sz_numbers[3] = {};
	char sz_delimetrs[] = "() /";
	int n = 0;
	for (char* pch = strtok(sz_buffer, sz_delimetrs); pch != 0; pch = strtok(NULL, sz_delimetrs))
	{
		sz_numbers[n++] = pch;
	}
	obj = Fraction();
	//for (int i = 0; i < n; i++)cout << sz_numbers[i] << "\t"; cout << endl;
	switch (n) {
	case 1: obj.set_integer(atoi(sz_numbers[0])); break;
	case 2:
		obj.set_numerator(atoi(sz_numbers[0]));
		obj.set_denominator(atoi(sz_numbers[1])); break;
	case 3:obj(atoi(sz_numbers[0]), atoi(sz_numbers[1]), atoi(sz_numbers[2]));

	}

	/*int integer,numerator,denominator;
	cin >> integer >> numerator >> denominator;
	obj(integer,numerator,denominator);*/


	/*int a;
	is >> a; obj.set_integer(a);
	is >> a; obj.set_numerator(a);
	is >> a; obj.set_denominator(a);*/
	return is;
}



Fraction operator+(Fraction left, Fraction right) {
	Fraction result;
	left.to_improper();
	right.to_improper();
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
	return result.to_proper();
}
Fraction operator-(Fraction left, Fraction right) {
	Fraction result;
	left.to_improper();
	right.to_improper();
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
	return result.to_proper();
}
Fraction operator*(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	//Fraction result;
	//result.set_numerator(left.get_numerator() * right.get_numerator());
	//result.set_denominator(left.get_denominator() * right.get_denominator());
	//result.to_proper();
	return Fraction(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/(const Fraction& left, const Fraction& right) {

	return left * right.inverted();
}
