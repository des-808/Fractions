#include"Header.h"

class String;



class String {
	int length;
	char* str;

public:
	char get_size()const { return  length; }
	const char* get_str()const { return str; }

	String(int length = 80) {//����������� ������ 
		this->length = length;
		this->str = new char[length]{};
		cout << "������ ����� char � �������� �� ���������" << endl;
	}
	String(const char* str)
	{
		this->length = strlen(str) + 1;
		this->str = new char[length] {};
		for (int i = 0; i < length; i++) {
			this->str[i] = str[i];
		}cout << "Construktor:\t" << this << endl;

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
		for (int i = 0; i < length; i++) {this->str[i] = other.str[i];
		}
		 
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	void print()const {
		cout << "Length:\t" << length << endl;
		cout << "Str:\t" << str << endl;
	}

};

std::ostream& operator<<(std::ostream& os,const String& obj) {
	return os<< obj.get_str();
}

int main() {
	setlocale(LC_ALL, "Russian");
	String C;
	C.print();
	String E (44);
	E.print();
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
	return 0;
}


//� Solution IntroductionToOOP �������� ������ String � ����������� � ��� ����� String,
//����������� ������.���������� ��������� �������� �������� �������� :
//String str1;		//������� ������ ������ �������� 80 Byte
//String str2(44);	//������� ������ ������ ��������� �������, � ������ ������ 44 �����
//String str3 = "Hello";
//String str4 = "World";
//String str5 = str3 + str4;
//cout << str5 << endl;
//
//cout << "������� ������: "; cin >> str1;



/*
������

������ - ��� ������ ��������� ���� ���
��������� ��������� �������� �������� ascii ������ � ����� ���� '\0'
���� ���������� ����� ������ �� ����� ������ �������� NULL TERMINATED LINES

����������
������ �� �� ��� ����� �������� �����
1 ��������� ����� ��� ������� ������ ����������� �����
2 ����� ������ �������� ������ ��� ������� ���� � ��� �� ������ ������������ ������
*/