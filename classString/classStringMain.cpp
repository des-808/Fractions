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

	String(int length = 80) {//����������� ������ 
		this->length = length;
		this->str = new char[length]{};
		cout << "������ ����� char � �������� �� ���������" << endl;
	}
	String(const char* str){
		this->length = strlen(str) + 1;
		this->str = new char[length] {};
		for (int i = 0; i < length; i++) {this->str[i] = str[i];}
		cout << "Construktor:\t" << this << endl;
	}
	/*String& Concat(const String& other)
		{
		    length += other.length;
		    char* tmp = new char[length + 1];
			::strcpy(tmp, str);
		    ::strcat(tmp, other.str);
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
	~String() {//���������� ������
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
		char *buffer = new char[length] {};
		int i = 0;
		for (; i < length; i++) {
			buffer[i] = (this->str[i] > 0x60 && this->str[i] < 0x7B)?this->str[i] - (byte)32:this->str[i];
		}
		buffer[i-1] = '\0';
		*this = buffer;
	}
	void to_lower() {
		char* buffer = new char[length] {};
		int i = 0;
		for (; i < length; i++) {
			buffer[i] = (this->str[i] > 0x40 && this->str[i] < 0x5B)?this->str[i] + (byte)32:this->str[i];
		}
		buffer[i - 1] = '\0';
		*this = buffer;
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
	char *buffer = new char[256]{};
	is.getline(buffer, 255);
	//is >> buffer;
			/*int lenght = sizeof(buffer);other.set_size(lenght+1);*/
	other.set_size(strlen(buffer));
	other = buffer;
	delete[] buffer;
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
//String str;
//cout << "������� ������: ";
//cin >> str;
////cout << str << endl;
////cout << (str.get_size()) << endl;
//str.print();
//str.to_upper();
//str.print();
//str.to_lower();
//str.print();
//String str1 = "abrakadabra";
String str1;
cin >> str1;
str1.revers();
str1.print();
str1.to_upper();
str1.print();
cout << ((str1.is_palindrome()) ? "���������" : "�����������")<< endl; 
//std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	return 0;
}


//1. ��� ������ String ����������� �������� ����� :
//String str;  cout << "������� ������: "; cin >> str;
//2. �������� ����� void to_upper(), ������� ��������� ������ � ������� �������;
//3. �������� ����� void to_lower(), ������� ��������� ������ � ������ �������;
//4. ����������� ����� ? ? ? is_palindrome(? ? ? ), ������� �����������,
//�������� �� ������ �����������





/*
������

������ - ��� ������ ��������� ���� ���
��������� ��������� �������� �������� ascii ������ � ����� ���� '\0'
���� ���������� ����� ������ �� ����� ������ �������� NULL TERMINATED LINES

����������
������ �� �� ��� ����� �������� �����
1 ��������� ����� ��� ������� ������ ����������� �����
2 ����� ������ �������� ������ ��� ������� ���� � ��� �� ������ ������������ ������



���� ����� �������� �������� (������ ������ � ������� ���� ��� �������)
� ��� ����������� ����� ��������� � ����������� ���� ����������� �������� []

*/