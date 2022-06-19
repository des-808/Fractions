#include"Header.h"
#define ENTER 13
class String;

String operator+(const String& left, const String& right);

class String {
	int length;
	char* str;

public:
	char get_size()const { return  length; }
	const char* get_str()const { return str; }
	char* get_str() { return str; }
	void set_size(int integer) { this->length = integer; }

	
	String(int length = 80): length(length), str (new char[length] {})
	{//конструктор класса 
		/*this->length = length;
		this->str = new char[length] {};*/
		cout << "Default Construktor\t" << this<< endl;
	}
	//String(const char* str):length ( strlen(str) + 1), str(new char[length] {})
	//{
	//	/*this->length = strlen(str) + 1;
	//	this->str = new char[length] {};*/
	//	for (int i = 0; i < length; i++) {this->str[i] = str[i];}
	//	cout << "Construktor:\t" << this << endl;
	//}
	String(const char* str):String(strlen(str)+1)
	{
		
		for (int i = 0; i < length; i++) {this->str[i] = str[i];}
		cout << "Construktor:\t" << this << endl;
	}
	/*String(const String& other): length(other.length), str(new char[length] {})
	{
		for (int i = 0; i < length; i++) {
			this->str[i] = other.str[i];
		}cout << "CopyConstruktor:\t" << this << endl;
	}*/
	String(const String& other):String(other.str)
	{
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
		for (int i = 0; i < length; i++) {this->str[i] = other.str[i];}
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	String& operator+=(String other) {//
		return *this = *this + other;
	}
	char operator[](int i)const {
		return str[i];
	}
	char& operator[](int i) {
		return str[i];
	}
	void print()const {
		cout << "----------------------------" << endl;
		cout << "print() " << "  Length: " << length << "\tStr: " << str << endl;
		cout << "----------------------------" << endl;
	}

	void to_upper() {
		int i = 0;
		for (; i < length; i++) {
			this->str[i] = toupper(this->str[i]);
		
		}
	}
	void to_lower() {
		int i = 0;
		for (; i < length; i++) {
			this->str[i] = tolower(this->str[i]);
		}
	}
	void revers() {
		int len;
		char t;
		char* start, * end;
		len = strlen(str);
		start = this->str;
		end = &this->str[len - 1];
		while (start < end) {
			t = *start;
			*start = *end;
			*end = t;
			start++;
			end--;
		}
	} 
	bool is_palindrome() {
		int len;
		char t;
		char* start, * end;
		len = strlen(str);
		start = this->str;
		end = &this->str[len - 1];
		for (int i = 0;i<length/2;i++) {
			if (!(*start == *end)) { return false; }
			start++;
			end--;
		}
		return true;
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
	char *buffer = new char[USHRT_MAX]{};//USHRT_MAX
	SetConsoleCP(1251);
	//is.getline(buffer, USHRT_MAX-1);
	is >> buffer;
	SetConsoleCP(866);
	other.set_size(strlen(buffer));
	other = buffer;
	delete[] buffer;
		return is;
	}
std::istream& getline(std::istream& is ,String& obj) {
	SetConsoleCP(1251);
	is.getline(obj.get_str(), obj.get_size());
	SetConsoleCP(866);
	return is;
}


//#define CONSTRAKTORS_CHECK
//#define XZ
//#define HOMEWORK
#define KEYBOARD_INPU_CHECK
int main() {
	//setlocale(LC_ALL, "Russian");
	setlocale(LC_ALL, "Rus");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

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
//String str;
//cout << "Введите строку: ";
//cin >> str;
////cout << str << endl;
////cout << (str.get_size()) << endl;
//str.print();
//str.to_upper();
//str.print();
//str.to_lower();
//str.print();
//String str1 = "abrakadabra";
#ifdef HOMEWORK
cout << "Введите строку: " << endl;
String str1;
cin >> str1;
str1.to_lower();
str1.print();
str1.to_upper();
str1.print();
str1.revers();
str1.print();
cout << ((str1.is_palindrome()) ? "Палиндром!!" : "НеПалиндром!!")<< endl;   
#endif // HOMEWORK

#ifdef KEYBOARD_INPU_CHECK
//cout << "Введите строку: " << endl;
//String str2;
//getline(cin, str2);
//cout << str2 << endl;
String str2 = "Hello world!!";
str2.to_lower();
str2.print();
str2.to_upper();
str2.print();
#endif // KEYBOARD_INPU_CHECK
String str3 = str2;
str3.print();
	return 0;  
}


//1. Для класса String перегрузить оператор ввода :
//String str;  cout << "Введите строку: "; cin >> str;
//2. Написать метод void to_upper(), который переводит строку в верхний регистр;
//3. Написать метод void to_lower(), который переводит строку в нижний регистр;
//4. Реализовать метод ? ? ? is_palindrome(? ? ? ), который опеределяет,
//является ли строка палиндромом





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