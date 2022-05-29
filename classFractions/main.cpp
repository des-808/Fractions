#include"Header.h"

class Fraction {
	int integer;// celoe;
	int numerator;// chislitel;
	int denominator;// znamenatel;
public:

	int get_integer()const { return integer; }
	int get_numerator()const { return numerator; }
	int get_denominator()const { return denominator; }

	void set_integer(int integer) { this->integer = integer; }
	void set_numerator(int numerator) { this->numerator = numerator; }
	void set_denominator(int denominator) { 
		if (denominator == 0) { denominator = 1; } 
		this->denominator = denominator; 
	}
	


	//int maxKrChislo(int numerator, int denominator) {
	//	int max = 0;
	//	int xz = (numerator > denominator) ? denominator : numerator;
	//	for (int i = 2; i < xz / 2; i += 2) {
	//		if (numerator % i == 0 && denominator % i == 0) {
	//			max = ((numerator > denominator) ? denominator / i : numerator / i);
	//		}
	//	}
	//	return max;
	//}
	//int minKrChislo(int denominator_left, int denominator_right) {
	//	return denominator_left * (denominator_right / gcd(denominator_left, denominator_right));
	//}
	//////////////////////////////////////////////////////
	//int gcd(int denominator_left, int denominator_right) {
	//	while (denominator_right > 0) {
	//		int tmp = denominator_right;
	//		denominator_right = denominator_left % denominator_right; // % is remainder
	//		denominator_left = tmp;
	//	}
	//	return denominator_left;
	//}

	//int gcd(int input[]) {
	//	int result = input[0];
	//	for (int i = 1; i < input.length; i++) {
	//		result = gcd(result, input[i]);
	//	}
	//	return result;
	//}

	/*int lcm(int a, int b) {
		return a * (b / gcd(a, b));
	}*/

	//int lcm(int input[]) {
	//	int result = input[0];
	//	for (int i = 1; i < input.length; i++) {
	//		result = lcm(result, input[i]);
	//	}
	//	return result;
	//}
	////////////////////////////////////////////////////
	//void print() { cout << "Целое = " << this->integer << "\t" << "Числитель = " << this->numerator << "\t" << "Знаменатель = " << this->denominator << endl; }
	void print() {
		if (integer)cout << integer;
		if (numerator) {
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		if (!integer && !numerator)cout << 0;
		cout << endl;
	}
	Fraction& operator= (const Fraction& other) {// оператор присвоения
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "copyAssigment  " << this << endl;
		return *this;
	}
	/*Fraction& operator++() {
		numerator++;
		denominator++;
		return *this;
	}
	Fraction& operator++(int) {
		Fraction vspom = *this;
		this->numerator++;
		this->denominator++;
		return vspom;
	}
	Fraction& operator--() {
		this->numerator--;
		this->denominator--;
		return *this;
	}
	Fraction& operator--(int) {
		Fraction vspom = *this;
		this->numerator--;
		this->denominator--;
		return vspom;
	}*/
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_numerator(integer * denominator + numerator);
		set_denominator(denominator);
		//cout << "operator() 1 " << this << endl;
		return *this;
	}
	Fraction& operator()(int numerator, int denominator)
	{
		set_integer(0);
		set_numerator(numerator);
		set_denominator(denominator);
		//cout << "operator() 2 " << this << endl;
		return *this;
	}


	Fraction() {//конструктор класса 
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;

	}
	Fraction(int numerator,int denominator) {//конструктор класса 
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);

	}
	Fraction(int integer) {//конструктор класса 
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;

	}
	Fraction(int integer, int numerator, int denominator) {//конструктор класса с инициализацией
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);

	}
	Fraction(const Fraction& other) {//копирующий конструктор
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "copyconstructor" << this << endl;
	}
	~Fraction() {//деструктор класса
		//cout << "destructor "<< this<< endl;
	}
};

//bool operator==(const Fraction& left, const Fraction& right) {
//	/*if ((left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator())) { return true; }
//	else { return false; }*/
//	return (left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator());
//}
//bool operator>=(const Fraction& left, const Fraction& right) {
//	/*if ((left.get_numerator() * right.get_denominator()) >= (left.get_denominator() * right.get_numerator())) { return true; }
//	else { return false; }*/
//	return !(left == right);
//}
//bool operator<=(const Fraction& left, const Fraction& right) {
//	if ((left.get_numerator() * right.get_denominator()) <= (left.get_denominator() * right.get_numerator())) { return true; }
//	else { return false; }
//}
//bool operator> (const Fraction& left, const Fraction& right) {
//	if ((left.get_numerator() * right.get_denominator()) > (left.get_denominator() * right.get_numerator())) { return true; }
//	else { return false; }
//}
//bool operator< (const Fraction& left, const Fraction& right) {
//	if ((left.get_numerator() * right.get_denominator()) < (left.get_denominator() * right.get_numerator())) { return true; }
//	else { return false; }
//}
//
//Fraction& operator+(const Fraction& left, const Fraction& right) {
//	Fraction result;
//	if (left.get_denominator() == right.get_denominator()) {
//		result.set_numerator(left.get_numerator() + right.get_numerator());
//		result.set_denominator(left.get_denominator());
//	}
//	else {
//		int nok = result.minKrChislo(left.get_denominator(), right.get_denominator());
//		int mn1 = nok / left.get_denominator();
//		int mn2 = nok / right.get_denominator();
//		result.set_numerator(left.get_numerator() * mn1 + right.get_numerator() * mn2);
//		result.set_denominator(left.get_denominator() * mn1);// + right.get_denominator() * mn2
//	}
//	return result;
//}
//Fraction& operator-(const Fraction& left, const Fraction& right) {
//	Fraction result;
//	if (left.get_denominator() == right.get_denominator()) {
//		result.set_numerator((left.get_numerator() > right.get_numerator()) ? left.get_numerator() - right.get_numerator() : right.get_numerator() - left.get_numerator());
//		result.set_denominator(left.get_denominator());
//	}
//	else {
//		int nok = result.minKrChislo(left.get_denominator(), right.get_denominator());
//		int mn1 = nok / left.get_denominator();
//		int mn2 = nok / right.get_denominator();
//		result.set_numerator(left.get_numerator() * mn1 - right.get_numerator() * mn2);
//		result.set_denominator(left.get_denominator() * mn1);//- right.get_denominator() * mn2
//	}
//	return result;
//}
//Fraction& operator*(const Fraction& left, const Fraction& right) {
//	Fraction result;
//	result.set_numerator(left.get_numerator() * right.get_numerator());
//	result.set_denominator(left.get_denominator() * right.get_denominator());
//	return result;
//}
//
//Fraction& operator/(const Fraction& left, const int right) {
//	Fraction result;
//	result.set_numerator(left.get_numerator() / right);
//	result.set_denominator(left.get_denominator() / right);
//	return result;
//}

int main() {
	setlocale(LC_ALL, "Russian");

	Fraction A;
	A.print();
	Fraction B = 5;
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3,4);
	D.print();
	Fraction E;
	E = D;
	D.print();
	//if (D >= E) { cout << "rabotaet" << endl; }
	//cout << "E =       "; E.print();
	//cout << "D =       "; D.print();
	//Fraction C(2, 36);
	//int xz = C.minKrChislo(9, 17); cout << "xz = " << xz << endl;

	//C = E + D; cout << "C = E+D   "; C.print();
	//C = E - D; cout << "C = E-D   "; C.print();
	//C = E * D; cout << "C = E*D   "; C.print();
	//D(2, 14, 17);
	//cout << "D =       "; D.print();
	////C = A + B;
	////C.print();
	////C = A - B;
	////C.print();
	////C = A * B;
	////C.print();
	////C = A / B;


	return 0;
}