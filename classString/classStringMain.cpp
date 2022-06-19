#include "Strings.h"


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