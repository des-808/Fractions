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
	
	unsigned int maxKrChislo(unsigned int numerator, unsigned int denominator) {
		if (numerator == denominator)
			return numerator;
		if (numerator > denominator)
			return maxKrChislo(numerator - denominator, denominator);
		return maxKrChislo(numerator, denominator - numerator);
	}
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
	Fraction& operator= (const Fraction& other) {// оператор присвоения
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

	explicit operator int()const {
		return integer;
	}
	 operator double()const {
		return integer+(double)numerator/denominator;
	}
	 
	 
	 Fraction (double xz) {
		 integer = xz;//преобразовываем дробь в целое число при этом дробь отбрасывается
		 xz = xz - integer;//получаем дробную часть
		 xz *= 100000000;
		 numerator = xz;
		 denominator = 100000000;
		 xz = maxKrChislo(numerator, denominator);
		 set_numerator(numerator/xz);
		 set_denominator(denominator/xz);
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

//1. Арифметические операторы : +, -, *, / ;
//2. Составные присваивания : +=, -=, *=, /=;
//3. Incremento / Decremento;
//4. Операторы сравнения : == , != , > , < , >= , <= ;

bool operator==( Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	/*if ((left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }*/
	return (left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator());
}
bool operator!=(const Fraction& left,const Fraction& right) {
	return !(left == right);
}
//bool operator!=( Fraction left, Fraction right) {
//	left.to_improper();
//	right.to_improper();
//	/*if ((left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator())) { return true; }
//	else { return false; }*/
//	return (left.get_numerator() * right.get_denominator()) != (left.get_denominator() * right.get_numerator());
//}
bool operator> ( Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	/*if ((left.get_numerator() * right.get_denominator()) > (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }*/
	return (left.get_numerator() * right.get_denominator()) > (left.get_denominator() * right.get_numerator());
}
bool operator< ( Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	/*if ((left.get_numerator() * right.get_denominator()) < (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }*/
	return (left.get_numerator() * right.get_denominator()) < (left.get_denominator() * right.get_numerator());
}
bool operator>=( const Fraction& left, const  Fraction& right) {
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
		sz_numbers[n++]=pch;
	}
	obj = Fraction();
	//for (int i = 0; i < n; i++)cout << sz_numbers[i] << "\t"; cout << endl;
	switch (n) {
	case 1: obj.set_integer(atoi(sz_numbers[0])); break;
	case 2: 
		obj.set_numerator(atoi(sz_numbers[0])); 
		obj.set_denominator(atoi(sz_numbers[1])); break;
	case 3:obj(atoi(sz_numbers[0]),atoi(sz_numbers[1]), atoi(sz_numbers[2]));

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



Fraction operator+( Fraction left, Fraction right) {
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
//#define DEBUG
//#define DEBUG2
#define CONVERSION_HOME_WORK
//#define CONVERSION
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

	//Fraction A( 2, 3, 4);  A.print();
	////Fraction B( 2, 3, 4);  B.print();
	//Fraction B( 3, 4, 5);  B.print();
	//Fraction C = A * B;    C.print();

#ifdef DEBUG
	
   cout << "A+B  = "; (A + B). print();
   cout << "A-B  = "; (A - B). print();
   cout << "A*B  = "; (A * B). print();
   cout << "A/B  = "; (A / B). print();
A(2, 3, 4);cout << "A+=B = "; (A += B).print();
A(2, 3, 4);cout << "A-=B = "; (A -= B).print();
A(2, 3, 4);cout << "A*=B = "; (A *= B).print();
A(2, 3, 4);cout << "A/=B = "; (A /= B).print();
A(2, 3, 4);cout << "A = "   ;  A.print();
cout << "------------ A++ -----------" << endl;
B = A++;cout << "A++ "; A.print(); cout << "B = "; B.print();
B = ++A;cout << "++A "; A.print(); cout << "B = "; B.print();
cout << "------------END-------------" << endl;

cout << "------------ A-- -----------" << endl;
B = A--; cout << "A-- "; A.print(); cout << "B = "; B.print();
B = --A; cout << "--A "; A.print(); cout << "B = "; B.print();
cout << "------------END-------------" << endl;


cout <<"C == B ? " << ((C == B) ? " TRUE " : " FALSE ") << endl;
cout <<"C != B ? " << ((C != B) ? " TRUE " : " FALSE ") << endl;
cout <<"C >  B ? " << ((C >  B) ? " TRUE " : " FALSE ") << endl;
cout <<"C <  B ? " << ((C <  B) ? " TRUE " : " FALSE ") << endl;
cout <<"C >= B ? " << ((C >= B) ? " TRUE " : " FALSE ") << endl;
cout <<"C <= B ? " << ((C <= B) ? " TRUE " : " FALSE ") << endl;
cout << A << endl;
cin >> A;
cout << A << endl;
#endif // DEBUG
#ifdef DEBUG2
int a = A;
cout << a << endl;



double b = A;
cout << b << endl;
#endif // DEBUG2
//////////////////////////////////////////////////////////////////////////////////
#ifdef CONVERSION_HOME_WORK
Fraction A;
double xz = 3.14;
A.set_integer(xz) ;//преобразовываем дробь в целое число при этом дробь отбрасывается
xz = xz - A.get_integer();//получаем дробную часть
xz *= 100000000;
A.set_numerator(xz);
A.set_denominator (100000000);
xz = A.maxKrChislo(A.get_numerator(),A. get_denominator());
A.set_numerator(A.get_numerator() / xz);
A.set_denominator(A.get_denominator() / xz);
cout << A << endl;




A = 2.3;
cout << A << endl;
#endif // CONVERSION_HOME_WORK
//////////////////////////////////////////////////////////////////////////////////
#ifdef CONVERSION
Fraction A(2, 3, 4);
cout << A << endl;

cin >> A;
cout << A << endl;
#endif // CONVERSION



	return 0;
}

/*
потоки ostream и istream всегда передаются и возвращаются по ссылке
их нельзя передать в функцию или вернуть из функции по значению
*/




/*
ПРЕОБРАЗОВАНИЕ ТИПОВ
в языке с++ существует явное и неявное преобразование типов
ЯВНОЕ преобразование типов выполняет программист
а НЕЯВНОЕ - компилятор.

для того что-бы явно преобразовать значение в другой тип данных необходимо написать желаемый тип данных в круглых скобках перед значением
(type)value;си подобная форма записи
	или же преобразуемое значение написать в круглых скобках после желаемого типа данных
type(value);функцианальная форма записи

как явные так и не явные преобразования бывают от меньшего к большему или от большего к меньшему
при чём 2е может привести к потере данных
при этом компилятор выдаёт предупреждение С4244

все операторы С++ по возможности преобразуют все значения в выражении к наибольшему типу тоесть в 
основном неявные преобразования производятся от меньшего к большему
но операторы присваивания всегда преобразуют значения с права к типу с лева и не важно произойдет при этом потеря данных или нет

ПРЕОБРАЗОВАНИЕ ТИПОВ В ООП
в ооп кроме явных и неявных преобразований существуют так же 2 направления преобразования типов
1е например из других типов в наш
2е направление из нашего типа в другие типы
  
  1е выполняет конструктор с 1м параметром и оператор присваивания
  single argument constructor i copuassigment
  2 выполняют операторы преобразования типов

  для того что бы значения преобр в обьекты наше класса в класе должны быть конструктор с 1м парам этого типа
  single argument constructor i assigment operator при чем второй без первого не работает

  ключевое слово ecsplicit(явный) запрещает неявные преобразования типов и позволяет только явные преобразования

ПРЕОБРАЗОВАНИЕ НАЩЕГО ТИПА В ДРУГИЕ ТИПЫ
	для того что бы обьекты нашего класса преобразовывать в другие типы в классе должны быть соответствующие операторы преобразования.
операторы преобразования - это самые обычные методы имя которых состоит из ключевого слова оператор и спецификатора существующего типа данных

operator type(){
	.....
	.....
	return....
}
в операторах преобразования ни когда не пишется тип возвращаемого значения по скольку он является частью имени метода и следовательно и так понятен
операторы преобразования могут быть перегружены только в нутри класса






*/