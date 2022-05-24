#include"Header.h"

//using namespace std;

//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHEK
//#define COPI_ASSIGMENT_1
#define COPI_ASSIGMENT_2

//������ ���������
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
	void set_denominator(int denominator) { this->denominator = denominator; }
	void set_ind(int integer, int numerator,int denominator) {
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
	}
	
	//void print() { cout << "����� = " << this->integer << "\t" << "��������� = " << this->numerator << "\t" << "����������� = " << this->denominator << endl; }
	void print() { cout << "����� = " << this->integer << "\t"  << this->numerator << "/"  << this->denominator << endl; }
	Fraction& operator= (const Fraction& other) {// �������� ����������
		if (other.numerator > other.denominator) {
			this->integer = other.numerator / other.denominator; this->numerator = other.numerator % other.denominator;
		}
		else {
		this->integer = other.integer;
		this->numerator = other.numerator;}
		this->denominator = other.denominator;
		//cout << "copyAssigment  " << this << endl;
		return *this;
	}
	Fraction& operator++() {
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
	}
	Fraction& operator()(int integer,int numerator, int denominator)
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
	Fraction(int integer = 0, int numerator = 1, int denominator = 0) {//����������� ������ � ��������������
		if (!denominator) { denominator = numerator; numerator = integer; integer = 0; }
		this->integer = 0;
		if (integer) { this->numerator = integer * denominator + numerator; }
		else { this->numerator = numerator; }
		this->denominator = denominator;
		//cout << "constructor " << this << endl;
	}
	Fraction(const Fraction& other) {//���������� �����������
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "copyconstructor" << this << endl;
	}
	~Fraction() {//���������� ������
		//cout << "destructor "<< this<< endl;
	}
};

bool operator==(const Fraction left, const Fraction right) {
	if ((left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}
bool operator>=(const Fraction left, const Fraction right) {
	if ((left.get_numerator() * right.get_denominator()) >= (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}
bool operator<=(const Fraction left, const Fraction right) {
	if ((left.get_numerator() * right.get_denominator()) <= (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}
bool operator> (const Fraction left, const Fraction right) {
	if ((left.get_numerator() * right.get_denominator()) > (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}
bool operator< (const Fraction left, const Fraction right) {
	if ((left.get_numerator() * right.get_denominator()) < (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}

Fraction& operator+(const Fraction& left, const Fraction& right) {
	Fraction result;
	if (left.get_denominator() == right.get_denominator()) {
		result.set_numerator(left.get_numerator() + right.get_numerator()) ;
		result.set_denominator(left.get_denominator());

	}
	else {
	result.set_numerator(left.get_numerator() + right.get_numerator());
	result.set_denominator(left.get_denominator() + right.get_denominator());}
	return result;
}

//Fraction& operator-(const Fraction& left, const Fraction& right) {
//	Fraction result;
//	result.set_x(left.get_x() - right.get_x());
//	result.set_y(left.get_y() - right.get_y());
//	return result;
//}
//Fraction& operator*(const Fraction& left, const Fraction& right) {
//	Fraction result;
//	result.set_x(left.get_x() * right.get_x());
//	result.set_y(left.get_y() * right.get_y());
//	return result;
//}
//Fraction& operator/(const Fraction& left, const Fraction& right) {
//	Fraction result;
//	result.set_x(left.get_x() / right.get_x());
//	result.set_y(left.get_y() / right.get_y());
//	return result;
//}

int main() {
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT_POINT 
	Point A;
	A.x = 2;
	A.y = 6;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif
#ifdef DISTANCE
	Point Obj_A(2, 3);
	Point Obj_B(7, 8);
	Obj_A.print();
	Obj_B.print();

	cout << Obj_A.lenghtToPoint(Obj_B) << endl;
	cout << Obj_B.lenghtToPoint(Obj_A) << endl;
	cout << LenghtPointToPoint(Obj_A, Obj_B) << endl;
	cout << LenghtPointToPoint(Obj_B, Obj_A) << endl;
#endif // DISTANCE
#ifdef CONSTRUCTORS_CHEK
	Point Obj_A;
	Point Obj_B(13, 14);
	Point Obj_C = 5;
	Obj_A.print();
	Obj_B.print();
	Obj_C.print();
	Point Obj_D = Obj_C;
	Obj_D.print();
#endif // CONSTRUCTORS_CHEK
#ifdef COPI_ASSIGMENT_1
	Point A(2, 3);
	Point B = A;
	Point C;
	C = A;
#endif //

#ifdef COPI_ASSIGMENT_2
	Fraction D(3,15);
	Fraction E(4,18);
	if (D >= E) { cout << "rabotaet" << endl; }
	E.print();
	D.print();
	Fraction C;
	C = E+D;
	C.print();
	/*Fraction A(2,1, 2);
	Fraction B(3, 4);*/
	D(2,14, 17);
	D.print();
	//C = A + B;
	//C.print();
	//C = A - B;
	//C.print();
	//C = A * B;
	//C.print();
	//C = A / B;
	cout << "----------------" << endl;
	C.print();
	D.print();
	C = D++;
	C.print();
	D.print();
	//A = B = C = Point(2, 3);



#endif //

	return 0;
}


//double LenghtPointToPoint(Fraction& A, Fraction& B) {
//	return sqrt(pow((A.get_x() - B.get_x()), 2) + pow((A.get_y() - B.get_y()), 2));
//}


/*
��� � �++
��� ��� ������ ��� ������� ��������� ������� �� ��������.
������ ��� ����� �������� ������� ������� � ������������ � �������. ������� ������ ��� �������� ��� � �� ���������.
� ����� ������������ � ����������� ������������ ��� ����������� ����������.
��� ��������� ������������� ������ � ����������� � ���������� ������ � ����������� ����������.
������ ������� ���������������� ��� ��������� �� ������.
����� ��� ��������� �������� � ���������� ������� ������������� ��������� � ���������.
� ����� ������ ����� ���������������� ����� ��� ��������� ����������� ������ ��������� ��������� �������.
����� ������� ������ ����� ��������� ��� ������ ��������.
��� ������ ��� � ��������� ������� �� �����(������).
���� ������ ������ 2� �����.
���������� � ������.
����� ��� ������� � ����� ������
����� ����� ���� ������ ������ ��� ������ �� �������

������ ��� ����� ������� ����������. ������������� ��������� ��� ����� ��� ��� ������.
� �������� ��������� ��� ����� �� ������ ���� ������ ��� ������.
														����� ��� ��� ������
													  ��������� ��� ��� ������
������� ��� ���������� ������ ���� ��� ���������� ������ ������.
������ � ����� ��������
��� ������� � ����� �������� ����� ������� �������� ����� ��� �������� ������� ->
����� ��� �������� ������� ������� (����� ��������) - ������������ ��� ������� � ����� ������� �� ����� �������
������� ��� �������� ���������� ������� (arrow operator)- ������� ��� ������� � ����� ������� �� �������� �������




������ ��������� ���
��� ���������� �� 3� ��� ����������
1.������������
2.������������
3.�����������
������������ - ��� �������� ����������� ����� ������ �� �������� ����.
������������ ����������� �������������� ������� � get set ��������
� �++ ������� 3 ����� �������
private    ��� �������� ����  (��������� ������ � ����� ������) ��� ���������� ����� ������ ����������� ������ ���� � private ����� ������. ��� �������� �� �� ��������� ����������
publick    ��� �������� ���� ��������� �� ������ ����� ���������   � ���� ������ ����� ������ ������ ���� ������ ����� ���� � ���������
protected  ��� ���������� ���� �������� � ����� ������ ������ � ��� �������� ������v


������� ��� ��� ����� � ������  �� ��� � ������  ��� ���� �� ����� ������� � � ������ �������

get set ������ ������������ ��� ������� �� ��� � �������� � ���������� � ������
get() ����� ��������  ������������ ��� ������� �� ������ (��������� �������� �������� ����������)
set() ������ ���������� ��������� �������� �������� �������� ���������� �.� ������� ��� ������� � �������� ���������� �� ������
��� � ��� ����� ������ ���� � ������ ���������� � ������  �.� � ������ ����� ��� ��� ������� ����� ������� ������� � ����������

get() ������ � ������������ ������� ������ ���� �������������(const) ����������� ���������� ����� ������� �� �������� ������ ��� �������� ����������
��� ������������ ������� ����� ���� ������� ������ ����������� ������

set() ������ ��� �� ������������ ���������� ������


this ��� ��������� �� ������ ��� �������� ���������� �����
��������� �������� ����������� �������


������������ ������ � ������
� ����� ������ ����������� ������ �������������� ��������� ������
�����������
����������
� �������� ���������

����������� ��� ����� ������� ������ ������   � ������ �� �������� ������ ��� ������ � �������������� ��� ����
���������� ��� ����� ������� ���������� ������ �� ���������� ��� ������� �����.
����� ����� ������� �������� ��� ���������� ������� ��������� � ������� ���� ������ ��������
����������� � ���������� ������ ���������� ��� �� ��� � �����
�� ����� ������������ ������� ������
����������� � ���������� ������� �� ���������� �� ����� �������� � ��� ���� ����� ���� �� ������� �������� ����� void
����������� ����� ��������� ��������� �� ����� ��� � ����� ������ ������� ��� ����� �����������
� ������ �� ����� � ������ ����� ���� ������� ������ �������������
���������� ����������� ������ �� ����� �� ��������� ���������� � ������ �� ����� � ������ ����� ���� ������ ��������������
� � ���� �� ������� �� ���� ������� ��� ������� ��������� ���������


������������ ������ � �����������  ��� �����. �� ���������, ����������� �����������, ����������� ��������

����������� �� ��������� ��� ����������� ������� ����� ���� ������ ��� ����������.
��� �� ������ ���� �������� ����� ���� �� �����
������ �� ��������� ����� ���� �� �����, ���� � ������ ��� �� ������ ������������ �� ���������� �� ���� ������� ����������� �� ���������
�� �������  ��� ������ �� �������� ������� ������.

������� ������ �� ��������� ������ �������� ������ ��� ������ � ���� ��� ���� �������
����������� �� ��������� ���������� ������ ��� ����� �� ������ ������ � �� ����� ����� �� �����  �.� �� ����� ����� ���������� ����� �������
����������� �� ��������� ������ �������� �������� �� ��������� � ������ ���������� ����

����������� ����������� - ��� ����������� ������� �������� ������ � ������ ����������� ������ ������ ������ ������ �������� ������������� �������
����������� ����������� ������ ��������� ����������� ������ �� ������ ������ ������

�������� ��������� - ��� ����� ������ �������� ������ � ������ ������������ ������ ������ ������ ������ ������� ������������� �������.
��������� ����������� ����������� ��� ������� ��� ������� ������ ���������. ��� ���� ��������� �������� ������������
�������� ������������ ������ ��������� ����������� ������ �� ������

������� ��������� ��������� �� �������� �� ��������� ���� ������ �� �� �� ����� ��
�������� � ��� ��� ������� ����� ���������� �������� �� �������� �� ��������� ���� �� ������
� ��� �������� �������� �� ��������. �������� ����� ���������� ��� �� ���������� �� ����� ������

���������� ���������� ����� ��� ���� ��� �� � ��������� ������ ������ ����� ���� �������� ����� ��� �� ��� � �������� �����������
�� ������
add(A,B) ����� ���� �������� A+B

������� ���������� ����������
.1. ����������� ����� ������ ������������ ���������. ������ ����������� ����� ���������
.2. �� ��� ������������ ��������� ����� �����������. �� �������������
	.	Member selection
	.*	Pointer-to-member selection
	::	Scope resolution
	? :	Conditional
	#	Preprocessor convert to string
	##	Preprocessor concatenate
.3.������������� ��������� ��������� ���������
.4.�������������� ��������� ���������� ��� ����������� ������ �� ��������

������������� ��������� ��� ����� ������� ������� ��� ������� ������� �� ��������� ����� operator � ����� ������������� ���������
��������� ����� ���������� ��� � ������ ��� � �� �������
���� �������� ���������� � ������ �� �� �������� ������� � ����� ���� ������ ������ ��� �������� �������
���� �� �������� ��������� �� ������� �� �� ��� ����� ������� ��������
���� ������� �������� ������������� � ������ �� �� �� ����� �� ��������� �� ����� ����������
� ��� ������������ ��������� ����� ������ ��� �������� �� ���������� � �������� ����� ���������� ����� this
���� ������� �������� ������������� �� ������� �� � ���� ������� �� ��������� ���� � ������ ���� �������� - ���� �������
���� ������ �������� ������������� � ������ �� � ���� ������� �� ��������� ���� � ������ ���� �������� - ���� ������� � ����� ���
��������� � ���� ����� ������ ��� �������� �� ����������(this)

���� ������ �������� ������������� �� ������� �� � ���� ������� ����� ��������� 2 ��������� - ������� ����� � ������� � �����

��� ��������� ���������� ������� ��������� ��� ���� ��� ��������� ��������� �������� ���� �������� � ��������� ���
�� ��������� ������� �������� ���� �������� ����� ���������� � ������ ��� �� ����� ������ ������ � ���������� ������ ������
�� ��������� ��� �� �������� ���� �������� ����� ���������� �� �������






*/