#include"Header.h"

//создаём структуру
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
	int maxKrChislo(int numerator, int denominator) {
		int max = 0;
		int xz = (numerator > denominator) ?  denominator: numerator;
		for(int i = 2; i < xz/2;i+=2){
			if (numerator % i == 0 && denominator % i == 0) {
				max = ((numerator > denominator) ? denominator / i : numerator / i);
		}
 }
		return max;
	}
	int minKrChislo(int denominator_left, int denominator_right) {
		return denominator_left * (denominator_right / gcd(denominator_left, denominator_right));
	}
	////////////////////////////////////////////////////
	int gcd(int denominator_left, int denominator_right) {
		while (denominator_right > 0) {
			int tmp = denominator_right;
			denominator_right = denominator_left % denominator_right; // % is remainder
			denominator_left = tmp;
		}
		return denominator_left;
	}

	//int gcd(int input[]) {
	//	int result = input[0];
	//	for (int i = 1; i < input.length; i++) {
	//		result = gcd(result, input[i]);
	//	}
	//	return result;
	//}

	/*int lcm(int a, int b) {
		return a * (b / gcd(a, b));
	}*/

	//int lcm(int input[]) {
	//	int result = input[0];
	//	for (int i = 1; i < input.length; i++) {
	//		result = lcm(result, input[i]);
	//	}
	//	return result;
	//}
	////////////////////////////////////////////////////
	//void print() { cout << "Целое = " << this->integer << "\t" << "Числитель = " << this->numerator << "\t" << "Знаменатель = " << this->denominator << endl; }
	void print() {
		if (this->numerator > this->denominator) {
			//this->integer = this->numerator / this->denominator;
			//this->numerator %= this->denominator;
			cout << this->numerator / this->denominator << "." << this->numerator % this->denominator << "/" << this->denominator << endl;
		}
		else {
			cout << this->numerator << "/" << this->denominator << endl;
		}
	}
	Fraction& operator= (const Fraction& other) {// оператор присвоения
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
	/*Fraction& operator++() {
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
	}*/
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
	Fraction(int integer = 0, int numerator = 1, int denominator = 0) {//конструктор класса с инициализацией
		if (!denominator) { denominator = numerator; numerator = integer; integer = 0; }
		this->integer = 0;
		if (integer) { this->numerator = integer * denominator + numerator; }
		else { this->numerator = numerator; }
		this->denominator = denominator;
		//cout << "constructor " << this << endl;
	}
	Fraction(const Fraction& other) {//копирующий конструктор
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "copyconstructor" << this << endl;
	}
	~Fraction() {//деструктор класса
		//cout << "destructor "<< this<< endl;
	}
};

bool operator==(const Fraction& left, const Fraction& right) {
	if ((left.get_numerator() * right.get_denominator()) == (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}
bool operator>=(const Fraction& left, const Fraction& right) {
	if ((left.get_numerator() * right.get_denominator()) >= (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}
bool operator<=(const Fraction& left, const Fraction& right) {
	if ((left.get_numerator() * right.get_denominator()) <= (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}
bool operator> (const Fraction& left, const Fraction& right) {
	if ((left.get_numerator() * right.get_denominator()) > (left.get_denominator() * right.get_numerator())) { return true; }
	else { return false; }
}
bool operator< (const Fraction& left, const Fraction& right) {
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
		int nok = result.minKrChislo(left.get_denominator(), right.get_denominator());
		int mn1 = nok /  left.get_denominator();
		int mn2 = nok / right.get_denominator();
		result.set_numerator  (left.  get_numerator() * mn1 + right.  get_numerator() * mn2);
		result.set_denominator(left.get_denominator() * mn1);// + right.get_denominator() * mn2
	}
	return result;
}
Fraction& operator-(const Fraction& left, const Fraction& right) {
	Fraction result;
	if(left.get_denominator() == right.get_denominator()) {
		result.set_numerator((left.get_numerator() > right.get_numerator()) ? left.get_numerator() - right.get_numerator() : right.get_numerator() - left.get_numerator());
		result.set_denominator(left.get_denominator());
	}
	else {
	int nok = result.minKrChislo(left.get_denominator(), right.get_denominator());
	int mn1 = nok / left.get_denominator();
	int mn2 = nok / right.get_denominator();
	result.set_numerator(left.get_numerator() * mn1 - right.get_numerator() * mn2);
	result.set_denominator(left.get_denominator() * mn1 );//- right.get_denominator() * mn2
	}
	return result;
}
Fraction& operator*(const Fraction& left, const Fraction& right) {
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}
//
//Fraction& operator/(const Fraction& left, const int right) {
//	Fraction result;
//	result.set_numerator(left.get_numerator() / right);
//	result.set_denominator(left.get_denominator() / right);
//	return result;
//}

int main() {
	setlocale(LC_ALL, "Russian");

	Fraction D(2,3);
	Fraction E(1,4);
	if (D >= E) { cout << "rabotaet" << endl; }
	cout << "E =       "; E.print();
	cout << "D =       "; D.print();
	Fraction C(2,36);
	int xz=C.minKrChislo(9, 17);cout << "xz = " << xz << endl;
	
	C = E + D; cout << "C = E+D   "; C.print();
	C = E - D; cout << "C = E-D   "; C.print();
	C = E * D; cout << "C = E*D   "; C.print();
	D(2,14, 17);
	cout << "D =       ";D.print();
	//C = A + B;
	//C.print();
	//C = A - B;
	//C.print();
	//C = A * B;
	//C.print();
	//C = A / B;
	

	return 0;
}



/*
ООП в с++
ООП это подход при котором программа состоит из обьектов.
обьект это некая сущность которая существ в пространстве и времени. обьекты бывают как осязаемы так и не осязаемые.
и могут существовать в обьективной субьективной или виртуальной реальности.
ооп позволяет спроэцировать обьект с обьективной и субьективн реальн в виртуальную реальность.
обькты принято классифицировать или разделять на классы.
КЛАСС это множество обьектов с одинаковым набором характеристик состояний и поведений.
с точки зрения языка программирования класс это синтаксич конструкция котора позволяет описывать обьекты.
кроме классов обекты можно описывать при помощи структур.
как классы так и структуры состоят из полей(членов).
роля класса бывают 2х видов.
Переменные и Методы.
МЕТОД ЭТО ФУНКЦИЯ В НУТРИ КЛАССА
метод может быть вызван только для какого то обьекта

обьект это самая обычная переменная. следовательно структура или класс это тип данных.
и создавая структуру или класс мы создаём свой собств тип данных.
														КЛАСС ЭТО ТИП ДАННЫХ
													  структура это тип данных
обьекты это переменные нашего типа или экземпляры нашего класса.
ДОСТУП К ПОЛЯМ ОБЬЕКТОВ
для доступа к полям обьектов можно использ оператор точка или оператор стрелка ->
точка это оператор прчмого доступа (поинт оператор) - используются для доступа к полям обьекта по имени обьекта
стрелка это оператор косвенного доступа (arrow operator)- использ для доступа к полям обьекта по аддрессу обьекта




основн концепции ооп
ооп базируется на 3х осн концепциях
1.ИНКАПСУЛЯЦИЯ
2.НАСЛЕДОВАНИЕ
3.ПОЛИМОРФИЗМ
Инкапсуляция - это сокрытие определённой части класса от внешнего мира.
инкапсуляция реализуется модификаторами доступа и get set методами
в С++ существ 3 модиф доступа
private    это закрытые поля  (дооступны только в нутри класса) все переменные члены класса обязательно должны быть в private секци класса. это защищает их от случайной перезаписи
publick    это открытые поля доступные из любого места программы   в этой секции обычн размещ методы хотя методы могут быть и закрытыми
protected  это защищённые поля доступны в нутри нашего класса и его дочерних классоv


единств отл меж класс и структ  то что у структ  все поля по умолч открыты а у класса закрыты

get set методы используются для доступа из вне к закрытым к переменным в классе
get() взять получить  используются для доступа на чтение (позволяют получить значение переменной)
set() задать установить позволяют задавать значения закрытых переменных т.е использ для доступа к закрытым переменным на запись
гет и сет метод должен быть у каждой переменной в классе  т.е в классе будет гет сет методов ровно столько сколько и переменных

get() методы в обязательном порядке должны быть констаннтными(const) константным называется метод который не изменяет обьект для которого вызывается
для константного обьекта могут быть вызваны только константные методы

set() методы так же обеспечивают фильтрацию данных


this это указатель на обьект для которого вызывается метод
стрелочка оператор коссвенного доступа


ОБЯЗАТЕЛЬНЫЕ МЕТОДЫ В КЛАССЕ
в любом классе обязательно должны присутствовать следующие методы
КОНСТРУКТОР
ДЕСТРУКТОР
и ОПЕРАТОР ПРИСВОИТЬ

КОНСТРУКТОР ЭТО метод который создаёт обьект   а точнее он выделяет память под обьект и инициализирует его поля
ДЕСТРУКТОР это метод который уничтожает обьект по завершению его времени жизни.
время жизни обьекта истекает при завершенни области видимости в которой этот обьект обьявлен
конструктор и деструктор всегда называются так же как и класс
но перед деструктором пишется тильда
конструктор и деструктор никогда не возвращают ни каких значений и при этом перед ними не пишется ключевое слово void
конструктор может принимать параметры по этому как и любую другую функцию его можно перегрузить
и именно по этому в классе может быть сколько угодно конструкторов
деструктор перегружать нельзя ни когда ни принимает параметров и именно по этому в классе может быть только одиндеструктор
е е какм бы образом не созд обьекты все обьекты удаляются одинаково


конструкторы бывают с параметрами  без парам. по умолчанию, конструктор копирования, конструктор переноса

КОНСТРУКТОР ПО УМОЛЧАНИЮ это конструктор который может быть вызван без параметров.
или же констр кажд которого имеет знач по умолч
констр по умолчанию может быть не явным, если в классе нет ни одного конструктора то компилятор не явно добавит конструктор по умолчанию
по скольку  без констр не возможно создать обьект.

неявный констр по умолчанию просто выделяет память под обьект и иниц его поля мусором
конструктор по умолчанию вызывается всякий раз когда мы создаём обьект и не знаем какой он будет  т.е не задаём значь переменных этого обьекта
конструктор по умолчанию должен записать значение по умолчанию в каждую переменную член

КОНСТРУКТОР КОПИРОВАНИЯ - это конструктор который копирует обьект а точнее создаваемый обьект делает точной копией какогото существующего обьекта
конструктор копирования всегда принимает константную ссылку на обьект нашего класса

ОПЕРАТОР ПРИСВОИТЬ - это метод котрый копирует обьект а точнее существующий обьект делает точной копией другого существующего обьекта.
поскольку конструктор копирования для другого сущ обьекта нельзя применить. его роль выполняет оператор присваивания
оператор присваивания всегда принимает константную ссылку на обьект

функция принимает параметры по значению по указателю либо ссылке но мы ни когда не
говорили о том что функция может возвращать значение по значению по указателю либо по ссылке
и при возврате значения по значению. значение возвр переменной так же копируется на место вызова

ПЕРЕГРУЗКА ОПЕРАТОРОВ нужна для того что бы с обьектами нашего класса можно было работать точно так же как с обычными переменными
на пример
add(A,B) можно было написать A+B

ПРАВИЛА ПЕРЕГРУЗКИ ОПЕРАТОРОВ
.1. перегрузить можно только существующие операторы. нельзя придумывать новые операторы
.2. не все существующие операторы можно перегрузить. НЕ ПЕРЕГРУЖАЮТСЯ
	.	Member selection
	.*	Pointer-to-member selection
	::	Scope resolution
	? :	Conditional
	#	Preprocessor convert to string
	##	Preprocessor concatenate
.3.перегруженные операторы сохраняют приоритет
.4.переопределить поведение операторов над встроенными типами не возможно

ПЕРЕГРУЖЕННЫЕ ОПЕРАТОРЫ это самые обычные функции имя которых состоит из ключевого слова operator и знака существующего оператора
операторы можно пергружать как в классе так и за классом
если оператор перегружен в классе то он является методом и может быть вызван только для какогото обьекта
если же оператор пергружен за классом то он явл самой обычной функцией
если унарный оператор перегружается в классе то он ни когда не принимает ни каких параметров
а его единственным операндом будет обьект для которого он вызывается к которому можно обращаться через this
если унарный оператор перегружается за классом то в обяз порядке он принимает один и только один параметр - свой операнд
если бинарный оператор перегружается в классе то в обяз порядке он принимает один и только один параметр - свой операнд с права его
операндом с лева будет обьект для которого он вызывается(this)

если бирный оператор перегружается за классом то в обяз порядке будет принимать 2 параметра - операнд слева и операнд с права

при пергрузке операторов следует учитывать тот факт что некоторые операторы изменяют свои операнды а некоторые нет
те операторы которые изменяют свои операнды лучше пергружать в классе что бы иметь прямой доступ к переменным членам класса
те операторы что не изменяют свои операнды лучше пергружать за классом






*/