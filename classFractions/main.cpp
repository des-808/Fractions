#include"classFraction.h"


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
//Fraction A;
//double xz = 3.14+0.000000001;
//A.set_integer(xz) ;//преобразовываем дробь в целое число при этом дробь отбрасывается
//xz = xz - A.get_integer();//получаем дробную часть
//xz *= 100000000;
//A.set_numerator(xz);
//A.set_denominator (100000000);
//xz = A.maxKrChislo(A.get_numerator(),A. get_denominator());
//A.set_numerator(A.get_numerator() / xz);
//A.set_denominator(A.get_denominator() / xz);
//cout << A << endl;



cout << "xz" << endl;
Fraction A;
A = 3.14;
Fraction B = 3.14;
cout << A << endl;
cout << B<< endl;
B *= 3.14;
cout << B << endl;
cout << "--------------------------------" << endl;
A ( 2 ,3,4);
cout << A << endl;
cout << "--------------------------------" << endl;
B (3, 4);
A += B;
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