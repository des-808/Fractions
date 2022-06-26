#include"point.h"

	double Point::get_x()const { return x; }
	double Point::get_y()const { return y; }

	void Point::set_x(double x) { this->x = x; }
	void Point::set_y(double y) { this->y = y; }
	void Point::set_xy(double x, double y) {
		this->x = x;
		this->y = y;
	}
	double Point::lenghtToPoint(const Point& other) {//cout << "lenghtToPoint " << this << endl;
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}
	void Point::print() { cout << "X = " << this->x << "\t" << "Y = " << this->y << endl; }
	Point& Point::operator= (const Point& other) {// оператор присвоения
		this->x = other.x;
		this->y = other.y;
		cout << "copyAssigment  " << this << endl;
		return *this;
	}
	Point& Point::operator++() {
		x++;
		y++;
		return *this;
	}
	Point& Point::operator++(int) {
		Point old = *this;
		this->x++;
		this->y++;
		return old;
	}
	Point& Point::operator--() {
		this->x--;
		this->y--;
		return *this;
	}
	Point& Point::operator--(int) {
		Point old = *this;
		this->x--;
		this->y--;
		return old;
	}
	Point& Point::operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}
	Point::Point(double x, double y ) {//конструктор класса с инициализацией
		this->x = x;
		this->y = y;
		//cout << "constructor " << this << endl;
	}
	Point::Point(const Point& other) {//копирующий конструктор
		this->x = other.x;
		this->y = other.y;
		//cout << "copyconstructor" << this << endl;
	}
	//Point::Point(double x) {//конструктор класса по умолчанию
	//	this->x = x;
	//	this->y = 0;
	//	cout << "constructor single parametr " << this << endl;
	//}
	//Point::Point() {//конструктор класса по умолчанию
	//	this->x = 0;
	//	this->y = 0;
	//	cout << "constructor zero " << this << endl;
	//}

	Point::~Point() {//деструктор класса
		//cout << "destructor "<< this<< endl;
	}


Point& operator+(const Point& left, const Point& right) {
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}
Point& operator-(const Point& left, const Point& right) {
	Point result;
	result.set_x(left.get_x() - right.get_x());
	result.set_y(left.get_y() - right.get_y());
	return result;
}
Point& operator*(const Point& left, const Point& right) {
	Point result;
	result.set_x(left.get_x() * right.get_x());
	result.set_y(left.get_y() * right.get_y());
	return result;
}
Point& operator/(const Point& left, const Point& right) {
	Point result;
	result.set_x(left.get_x() / right.get_x());
	result.set_y(left.get_y() / right.get_y());
	return result;
}
double LenghtPointToPoint(Point& A, Point& B);
//2. Написать метод ? ? ? distance(? ? ? ), который возвращает расстояние до указанной точки;
//3. Написать функцию ? ? ? distance(? ? ? ), которая возвращает расстояние между двумя точками;
