#include"Header.h"

class Fraction;
Fraction operator+( Fraction left, Fraction right);
Fraction operator-( Fraction left, Fraction right);
Fraction operator*( Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
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
	int minKrChislo(int denominator_left, int denominator_right) {
		return denominator_left * (denominator_right / gcd(denominator_left, denominator_right));
	}
	//////////////////////////////////////////////////////
	int gcd(int denominator_left, int denominator_right) {
		while (denominator_right > 0) {
			int tmp = denominator_right;
			denominator_right = denominator_left % denominator_right; // % is remainder
			denominator_left = tmp;
		}
		return denominator_left;
	}

	Fraction& to_improper() {
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper() {
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const{
		Fraction inverted = *this;
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;
		return inverted;
	
	}
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
	Fraction& operator= (const Fraction& other) {// оператор присвоени€
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "copyAssigment  " << this << endl;
		return *this;
	}
	Fraction& operator*= (Fraction other) {//
		/*other.to_improper();
		this->set_numerator(this->get_numerator() * other.get_numerator());
		this->set_denominator(this->get_denominator() * other.get_denominator());
		return *this;*/
		return *this = *this * other;
	}
	Fraction& operator/= (Fraction other) {//
		return *this = *this / other;
	}
	Fraction& operator+= (Fraction other) {//
		return *this = *this + other;
	}
	Fraction& operator-= (Fraction other) {//
		return *this = *this - other;
	}

	Fraction& operator++() {
		integer++;
		return *this;
	}
	Fraction  operator++(int) {
		Fraction vspom = *this;
		this->integer++;
		return vspom;
	}
	Fraction& operator--() {
		this->integer--;
		return *this;
	}
	Fraction  operator--(int) {
		Fraction vspom = *this;
		this->integer--;
		return vspom;
	}

	Fraction& operator()(int integer, int numerator, int denominator){
		this->set_integer(integer);
		this->set_numerator(numerator);
		this->set_denominator(denominator);
		return *this;
	}
	Fraction& operator()(int numerator, int denominator){
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

//1. јрифметические операторы : +, -, *, / ;
//2. —оставные присваивани€ : +=, -=, *=, /=;
//3. Incremento / Decremento;
//4. ќператоры сравнени€ : == , != , > , < , >= , <= ;

bool operator==( Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	/*if ((left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }*/
	return (left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator());
}
bool operator!=( Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	/*if ((left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }*/
	return (left.get_numerator() * right.get_denominator()) != (left.get_denominator() * right.get_numerator());
}
bool operator>=( Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	if ((left.get_numerator() * right.get_denominator()) >= (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
	//return !(left == right);
}
bool operator<=( Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	if ((left.get_numerator() * right.get_denominator()) <= (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}
bool operator> ( Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	if ((left.get_numerator() * right.get_denominator()) > (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}
bool operator< ( Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	if ((left.get_numerator() * right.get_denominator()) < (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}

Fraction operator+( Fraction left, Fraction right) {
	Fraction result;
	left.to_improper();
	right.to_improper();
	/*if (left.get_denominator() == right.get_denominator()) {
		result.set_numerator(left.get_numerator() + right.get_numerator());
		result.set_denominator(left.get_denominator());
	}
	else {*/
		int nok = result.minKrChislo(left.get_denominator(), right.get_denominator());
		int mn1 = nok / left.get_denominator();
		int mn2 = nok / right.get_denominator();
		result.set_numerator(left.get_numerator() * mn1 + right.get_numerator() * mn2);
		result.set_denominator(left.get_denominator() * mn1);// + right.get_denominator() * mn2
	//}
	return result.to_proper();
}
Fraction operator-( Fraction left, Fraction right) {
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
Fraction operator*( Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	//Fraction result;
	//result.set_numerator(left.get_numerator() * right.get_numerator());
	//result.set_denominator(left.get_denominator() * right.get_denominator());
	//result.to_proper();
	return Fraction(
		left.get_numerator() * right.get_numerator(),
	    left.get_denominator()* right.get_denominator()
	).to_proper();
}
Fraction operator/(const Fraction& left,const Fraction& right) {

	return left * right.inverted();
}

//#define CONSTRUCTORS_CHECK

//#define CONSTRUCTORS_CHECK
int main() {
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
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
#endif // CONSTRUCTORS_CHECK

	Fraction A( 2, 3, 4);  A.print();
	//Fraction B( 2, 3, 4);  B.print();
	Fraction B( 3, 4, 5);  B.print();
	Fraction C = A * B;    C.print();
	
			   cout << "A+B  = "; (A + B). print();
			   cout << "A-B  = "; (A - B). print();
			   cout << "A*B  = "; (A * B). print();
			   cout << "A/B  = "; (A / B). print();
	A(2, 3, 4);cout << "A+=B = "; (A += B).print();
	A(2, 3, 4);cout << "A-=B = "; (A -= B).print();
	A(2, 3, 4);cout << "A*=B = "; (A *= B).print();
	A(2, 3, 4);cout << "A/=B = "; (A /= B).print();
	A(2, 3, 4);
	cout <<"C == B ? " << ((C == B) ? " TRUE " : " FALSE ") << endl;
	cout <<"C != B ? " << ((C != B) ? " TRUE " : " FALSE ") << endl;
	cout <<"C >  B ? " << ((C >  B) ? " TRUE " : " FALSE ") << endl;
	cout <<"C <  B ? " << ((C <  B) ? " TRUE " : " FALSE ") << endl;
	cout <<"C >= B ? " << ((C >= B) ? " TRUE " : " FALSE ") << endl;
	cout <<"C <= B ? " << ((C <= B) ? " TRUE " : " FALSE ") << endl;

	return 0;
}
