#include"Header.h"

class String;



class String {
	const  int length =  80;
	char* buffer {};

public:
    //int get_size() { return buffe[].size(); }
	char get_string()const { return  this->buffer[0]; }
	void set_string(char str[]) { for (int i = 0; i < length;i++){*buffer = str[0];} }
	String() {//конструктор класса 
		buffer[length];
		cout << "создаём масив char с размером по умолчанию" << endl;
	}
	//String(const int SIZE, char sz_buffer) {//конструктор класса 
	//	sz_buffer[SIZE];
	//	cout << "создаём масив char с указанным размером" << endl;
	//}
	String(int SIZE) {//конструктор класса 
		buffer[SIZE-1] = {};
		cout << "задаём масиву char указанный размер" << endl;
	}
	String(string &new_buffer ) {//конструктор класса 
		
		buffer[length];
		int count = new_buffer.size();
		/*for (int i = 0; buffer[i] == 0; i++) {
			count++;
		}*/
		for (int i = 0;
			i <= count; 
			i++) { 
			this->buffer[i] = new_buffer[i]; };
		cout << "задаём массиву размер по умолчанию и копируем массив char  в него "<< endl;
	}
	//String(int SIZE, int numerator, int denominator) {//конструктор класса с инициализацией
	//	this->integer = integer;
	//	this->numerator = numerator;
	//	this->set_denominator(denominator);
	//}
	//String(const String& other) {//копирующий конструктор
	//	SIZE = other.SIZE;
	//	*sz_buffer = *other.sz_buffer;
	//	//cout << "copyconstructor" << this << endl;
	//}
	~String() {//деструктор класса
		//cout << "destructor "<< this<< endl;
	}
	String& size(String& obj) {
		obj.buffer.resize();
		buffer.size()

	}
	/*String& operator()(const char* sz_buffer[]) {
		int count = sz_buffer.size();
		
		for (int i = 0; i <= count; i++) { this->sz_buffer[i] = *sz_buffer[i]; };
		cout << "operator() 1 " << this << endl;
		return *this;
	}*/
	String& operator()(int SIZE, char sz_buffer[]) {
		
		cout << "operator() 2 " << this << endl;
		return *this;
	}

};
std::ostream& operator<<(std::ostream& os,  String& obj) {
	//int count = obj.get_string().size();
	//for()
	int size = obj.size();
	char xz[80];
	for (int i = 0; i < 80; i++) {os << obj.get_string(); };
	/*xz[0] = obj.get_string();
	if (obj.get_string())os << obj.get_string();*/
	return os;
}
//std::istream& operator>>(std::istream& is, String& obj) {
//	const int SIZE = 256;
//	char sz_buffer[SIZE] = {};
//	//is >> sz_buffer;
//	is.getline(sz_buffer, SIZE);
//	char* sz_numbers[3] = {};
//	char sz_delimetrs[] = "() /";
//	int n = 0;
//	for (char* pch = strtok(sz_buffer, sz_delimetrs); pch != 0; pch = strtok(NULL, sz_delimetrs))
//	{
//		sz_numbers[n++] = pch;
//	}
//	obj = String();
//	//for (int i = 0; i < n; i++)cout << sz_numbers[i] << "\t"; cout << endl;
//	switch (n) {
//	case 1: obj.set_integer(atoi(sz_numbers[0])); break;
//	case 2:
//		obj.set_numerator(atoi(sz_numbers[0]));
//		obj.set_denominator(atoi(sz_numbers[1])); break;
//	case 3:obj(atoi(sz_numbers[0]), atoi(sz_numbers[1]), atoi(sz_numbers[2]));
//
//	}

	/*int integer,numerator,denominator;
	cin >> integer >> numerator >> denominator;
	obj(integer,numerator,denominator);*/


	/*int a;
	is >> a; obj.set_integer(a);
	is >> a; obj.set_numerator(a);
	is >> a; obj.set_denominator(a);*/
//	return is;
//}


//class String;
//String operator+(String left, String right);
//
//
//
//class String
//{
//public:
//    // добавить строку в конец текущей строки
//    void Concat(const String& str);
//    int Sravn(const String& str1, const String& str2);
//private:
//    char* str;
//    int length;
//
//
//
//
//
//    String& operator+= (String other) {//
//        return *this = *this + other;
//    }
//};
//void String::Concat(const String& x)
//{
//    length += x.length;
//    char* tmp = new char[length + 1];
//    ::strcpy(tmp, str);
//    ::strcat(tmp, x.str);
//    delete[] str;
//    str = tmp;
//}
//int String::Sravn(const String& str1, const String& str2)
//{
//    // возвращает:
//    //0 - str1 = str2
//    //1 - str1 < str2
//    //2 - str1 > str2
//    char* cp1 = str1.str;
//    char* cp2 = str2.str;
//    while (true)
//    {
//        if (*cp1 < *cp2)
//            return (1);
//        else if (*cp1 > *cp2)
//            return (2);
//        else
//        {
//            cp1++;
//            cp2++;
//            if ((*cp2 == 0) && (*cp1 == 0))        // конец строки
//                return (0); //строки равны
//            else if ((*cp1 == 0) && (*cp2 != 0))
//                return (2);
//            else if ((*cp2 == 0) && (*cp1 != 0))
//                return (1);
//        }
//    }
//}
//
////String operator+(String left, String right) {
////    String result;
////    //String:: Concat(left);
////    
////    return result;
////
////
////}


int main() {
	setlocale(LC_ALL, "Russian");
	string xz = "какая-то фигня";
	string A = " тут происходит ";
    string B = A + xz;
	cout << A << endl;
    cout << B << endl;
	return 0;
}




//В Solution IntroductionToOOP добавить проект String и реализовать в нем класс String,
//описывающий строку.Обеспечить следующие варианты создания объектов :
//String str1;		//создает пустую строку размером 80 Byte
//String str2(44);	//создает пустую строку заданного размера, в данном случае 44 Байта
//String str3 = "Hello";
//String str4 = "World";
//String str5 = str3 + str4;
//cout << str5 << endl;
//
//cout << "Введите строку: "; cin >> str1;