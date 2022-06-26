#pragma once
#include<iostream>
#include<math.h>
using namespace std;


class Point {
	double x;
	double y;
public:

	double get_x()const;
	double get_y()const;

	void set_x(double x);
	void set_y(double y);
	void set_xy(double x, double y);
	double lenghtToPoint(const Point& other);
	void print();
	Point& operator= (const Point& other);
	Point& operator++();
	Point& operator++(int);
	Point& operator--();
	Point& operator--(int);
	Point& operator()(double x, double y);
	Point(double x = 0, double y = 0);
	Point(const Point& other);
	~Point();
};

Point& operator+(const Point& left, const Point& right);
Point& operator-(const Point& left, const Point& right);
Point& operator*(const Point& left, const Point& right);
Point& operator/(const Point& left, const Point& right);
double LenghtPointToPoint(Point& A, Point& B);
