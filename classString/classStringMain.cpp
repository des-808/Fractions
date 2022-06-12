#include"Header.h"
#define ENTER 13
class String;

String operator+(const String& left, const String& right);

class String {
	size_t length;
	char* str;

public:
	char get_size()const { return  length; }
	const char* get_str()const { return str; }
	char* get_str() { return str; }
	void set_size(int integer) { this->length = integer; }

	String(int length = 80) {//конструктор класса 
		this->length = length;
		this->str = new char[length]{};
		cout << "создаём масив char с размером по умолчанию" << endl;
	}
	String(const char* str)
	{
		this->length = strlen(str) + 1;
		this->str = new char[length] {};
		for (int i = 0; i < length; i++) {
			this->str[i] = str[i];
		}cout << "Construktor:\t" << this << endl;

	}
	/*String& Concat(const String& other)
		{
		    length += other.length;
		    char* tmp = new char[length + 1];
		    strcpy(tmp, str);
		    strcat(tmp, other.str);
		    delete[] str;
		    str = tmp;
		}*/

	String& operator+=(String other) {//
		return *this = *this + other;
	}

	String(const String& other) {
		this->length = other.length;
		this->str = new char[length] {};
		for (int i = 0; i < length; i++) {
			this->str[i] = other.str[i];
		}cout << "CopyConstruktor:\t" << this << endl;
	}
	~String() {//деструктор класса
		delete[] this->str;
		cout << "destructor "<< this<< endl;
	}
	String& operator=(const String& other) {
		if (this == &other)return *this;
		delete[] this->str;
		this->length = other.length;
		this->str = new char[length] {};
		for (int i = 0; i < length; i++) {this->str[i] = other.str[i];
		}
		 
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}

	char operator[](int i)const {
		return str[i];
	}
	char& operator[](int i) {
		return str[i];
	}


	void print()const {
		cout << "----------------------------" << endl;
		cout << "print() " << endl;
		cout << "Length:\t" << length << endl;
		cout << "Str:\t" << str << endl;
		cout << "----------------------------" << endl;
	}

};


String operator+(const String& left, const String& right) {
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++) {
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++) {
		//cat.get_str()[i + left.get_size()-1] = right.get_str()[i];
		cat[i + left.get_size()-1] = right[i];
	}
	return cat;
}



std::ostream& operator<<(std::ostream& os,const String& obj) {
	return os<< obj.get_str();
}

std::istream& operator>>(std::istream& is, String& other) {
	char *buffer = new char[256]{};
	is.getline(buffer, 255);
	delete[] other.get_str();
	other.set_size(strlen(buffer));
	other = new char(other.get_size() + 1);
	other = (String)buffer;
	//strcpy(other, buffer);
	delete[]buffer;
		//is >> buffer;
		//cout << "----------------------------" << endl;
		//int length = strlen(buffer)+1;
		//other = (String)buffer ;
		return is;
	}



//#define CONSTRAKTORS_CHECK
//#define XZ
int main() {
	setlocale(LC_ALL, "Russian");
	//String C;
	//C.print();
	//String E (44);
	//E.print();
#ifdef CONSTRAKTORS_CHECK
	String str3 = "Hello World";
	cout << "----------------------" << endl;
	str3 = str3;

	str3.print();
	cout << "----------------------" << endl;
	cout << str3 << endl;

	String str4 = str3;
	cout << str4 << endl;

	String str5;
	str5 = str4;
	cout << str5 << endl;
#endif // DEBUG
#ifdef XZ
String str1 = "Hello";
String str2 = "World";
String str3 = str1 + str2;
cout << str3 << endl;

str3 += str2;
cout << str3 << endl;
#endif // XZ
String str;
cout << "Введите строку: ";
//cout << str.get_size() << endl;
cin >> str;
cout << str << endl;
cout << str.get_size() << endl;
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



/*
СТРОКИ

строка - это массив элементов типа чар
последним элементом которого является ascii символ с кодом ноль '\0'
ноль показывает конец строки по этому строки называют NULL TERMINATED LINES

ПРИМЕЧАНИЕ
ошибка на эт вып дебаг асертион фиелд
1 оператору делит был передан адресс статической памти
2 когда делиту передают второй раз пердают один и тот же адресс динамической памяти



если класс является массивом (хранит данные в массиве либо сам масссив)
в нем обязательно будет указатель и обязательно надо перегружать оператор []

*/