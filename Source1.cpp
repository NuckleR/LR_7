#include <iostream>
#include <string>
//#include "Iterator.h"
#include "Header1.h"
#include <Windows.h>

int n = 5, n1=0;

using namespace std;

int main() {
	system("chcp 1251");
	system("CLS");

	//--------------------------------------- Пример с интом
	List<int> iq;
	int i, g;

	cout << "Введите список (int): " << endl;
	for (int i = 0; i < n; i++)
	{
		try
		{
			cin >> g;
			if (cin.fail())
			{
				throw 1;
			}
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print();
			i--; return 0;
		}
		iq.pushBack(g);
	}iq.popFront();

	cout << "Демонстрация вывода (int) при помощи перегруженного оператора [] без помощи класса итератора:\n";
	cout << iq[0] << " " << iq[1] << " " << iq[2] << " " << iq[3] << " " << iq[4] << endl;

	auto iit = List<int>::Iterator(iq.begin()); 

	cout << "Демонстрация вывода (int) при помощи перегруженного оператора [] c помощью класса итератора:\n";
	do{
		if(iit!=nullptr)
		cout << *iit << " ";
		iit++;
	} while (iit != iq.end());

	cout << "\n\nВвод: ";
	while (true) {
		try
		{
			cin >> i;
			if (cin.fail())
			{
				throw 1;
			}
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print(); return 0;
		}
		break;
	}

	iq.Puzir_Sort(iq);

	cout << "Демонстрация вывода (int) при помощи перегруженного оператора [] без помощи класса итератора:\n";
	cout << iq[0] << " " << iq[1] << " " << iq[2] << " " << iq[3] << " " << iq[4] << endl;


	iq.popFront();
	iit = List<int>::Iterator(iq.begin());
	cout << "\nУдаление первого в списке:\n";
	do {
		if (iit != nullptr)
			cout << *iit << " ";
		iit++;
	} while (iit != iq.end());

	iq.popBack();
	iit = List<int>::Iterator(iq.begin());
	cout << "\nУдаление последнего в списке:\n";
	do {
		if (iit != nullptr)
			cout << *iit << " ";
		iit++;
	} while (iit != iq.end());


	//---------------------------------------- Пример с чаром
	List<char> cl;
	char c;

	cout << "Введите список (char): " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		cl.pushBack(c);
	}cl.popFront();

	cout << "\n\nДемонстрация вывода (char) при помощи перегруженного оператора [] без помощи класса итератора:\n";
	cout << cl[0] << " " << cl [1] << " " << cl[2] << " " << cl[3] << " " << cl[4] << endl;

	auto cit = List<char>::Iterator(cl.begin());
	cout << "Демонстрация вывода (char) при помощи перегруженного оператора [] c помощью класса итератора:\n";
	while (cit != cl.end()) {
		cout << *cit << " ";
		cit++;
	}

	cout << "\n\nВвод: ";
	cin >> c;
	cl.find(c);

	cl.Puzir_Sort(cl);
	cout << "\n\nДемонстрация вывода (char) при помощи перегруженного оператора [] без помощи класса итератора:\n";
	cout << cl[0] << " " << cl[1] << " " << cl[2] << " " << cl[3] << " " << cl[4] << endl;

	cit = List<char>::Iterator(cl.begin());
	cl.popFront();
	cout << "Удаление первого:\n";
	while (cit != cl.end()) {
		cout << *cit << " ";
		cit++;
	}

	cit = List<char>::Iterator(cl.begin());
	cl.popBack();
	cout << "Удаление последнего:\n";
	while (cit != cl.end()) {
		cout << *cit << " ";
		cit++;
	}

	//----------------------------------------- Пример с даублом
	List<double> dl;
	double d;

	cout << "Введите список (double): " << endl;
	for (int i = 0; i < n; i++)
	{
		try
		{
			cin >> d;
			if (cin.fail())
			{
				throw 2;
			}
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print();
			i--; return 0;
		}
		dl.pushBack(d);
	}dl.popFront();

	cout << "\n\nДемонстрация вывода (double) при помощи перегруженного оператора [] без помощи класса итератора:\n";
	cout << dl[0] << " " << dl[1] << " " << dl[2] << " " << dl[3] << " " << dl[4] << endl;

	auto dit = List<double>::Iterator(dl.begin());
	cout << "Демонстрация вывода (double) при помощи перегруженного оператора [] c помощью класса итератора:\n";
	while (dit != dl.end()) {
		cout << *dit << " ";
		dit++;
	}

	cout << "\n\nВвод: ";
	while (true) {
		try
		{
			cin >> d;
			if (cin.fail())
			{
				throw 2;
			}
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print(); return 0;
		}
		break;
	}
	dl.find(d);


	//---------------------------------------------- Пример с флотом
	List<float> fl;
	float f;

	cout << "Введите список (double): " << endl;
	for (int i = 0; i < n; i++)
	{
		try
		{
			cin >> f;
			if (cin.fail())
			{
				throw 2;
			}
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print();
			i--; return 0;
		}
		iq.pushBack(f);
	}iq.popFront();


	cout << "\n\nДемонстрация вывода (float) при помощи перегруженного оператора [] без помощи класса итератора:\n";
	cout << fl[0] << " " << fl[1] <<" "<< fl[2] << " " << fl[3] << " " << fl[4] << endl;

	auto fit = List<float>::Iterator(fl.begin());
	cout << "Демонстрация вывода (float) при помощи перегруженного оператора [] c помощью класса итератора:\n";
	while (fit != fl.end()) {
		cout << *fit << " ";
		fit++;
	}

	cout << "\n\nВвод: ";
	while (true) {
		try
		{
			cin >> f;
			if (cin.fail())
			{
				throw 2;
			}
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print(); return 0;
		}
		break;
	}
	fl.find(f);

	//--------------------------------------------- Пример с строкой
	List<string> sl;
	string s;

	cout << "Введите список (string): " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		sl.pushBack(s);
	}sl.popFront();


	cout << "\n\nДемонстрация вывода (string) при помощи перегруженного оператора [] без помощи класса итератора:\n";
	cout << sl[0] << " " << sl[1] << " " << sl[2] << " " << sl[3] << " " << sl[4] << endl;

	auto sit = List<string>::Iterator(sl.begin());
	cout << "Демонстрация вывода (string) при помощи перегруженного оператора [] c помощью класса итератора:\n";
	while (sit != sl.end()) {
		cout << *sit << " ";
		sit++;
	}

	cout << "\n\nВвод: ";
	cin >> s;
	sl.find(s);

	getchar(); getchar();
}