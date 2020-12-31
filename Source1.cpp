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

	//--------------------------------------- ������ � �����
	List<int> iq;
	int i, g;

	cout << "������� ������ (int): " << endl;
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

	cout << "������������ ������ (int) ��� ������ �������������� ��������� [] ��� ������ ������ ���������:\n";
	cout << iq[0] << " " << iq[1] << " " << iq[2] << " " << iq[3] << " " << iq[4] << endl;

	auto iit = List<int>::Iterator(iq.begin()); 

	cout << "������������ ������ (int) ��� ������ �������������� ��������� [] c ������� ������ ���������:\n";
	do{
		if(iit!=nullptr)
		cout << *iit << " ";
		iit++;
	} while (iit != iq.end());

	cout << "\n\n����: ";
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

	cout << "������������ ������ (int) ��� ������ �������������� ��������� [] ��� ������ ������ ���������:\n";
	cout << iq[0] << " " << iq[1] << " " << iq[2] << " " << iq[3] << " " << iq[4] << endl;


	iq.popFront();
	iit = List<int>::Iterator(iq.begin());
	cout << "\n�������� ������� � ������:\n";
	do {
		if (iit != nullptr)
			cout << *iit << " ";
		iit++;
	} while (iit != iq.end());

	iq.popBack();
	iit = List<int>::Iterator(iq.begin());
	cout << "\n�������� ���������� � ������:\n";
	do {
		if (iit != nullptr)
			cout << *iit << " ";
		iit++;
	} while (iit != iq.end());


	//---------------------------------------- ������ � �����
	List<char> cl;
	char c;

	cout << "������� ������ (char): " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		cl.pushBack(c);
	}cl.popFront();

	cout << "\n\n������������ ������ (char) ��� ������ �������������� ��������� [] ��� ������ ������ ���������:\n";
	cout << cl[0] << " " << cl [1] << " " << cl[2] << " " << cl[3] << " " << cl[4] << endl;

	auto cit = List<char>::Iterator(cl.begin());
	cout << "������������ ������ (char) ��� ������ �������������� ��������� [] c ������� ������ ���������:\n";
	while (cit != cl.end()) {
		cout << *cit << " ";
		cit++;
	}

	cout << "\n\n����: ";
	cin >> c;
	cl.find(c);

	cl.Puzir_Sort(cl);
	cout << "\n\n������������ ������ (char) ��� ������ �������������� ��������� [] ��� ������ ������ ���������:\n";
	cout << cl[0] << " " << cl[1] << " " << cl[2] << " " << cl[3] << " " << cl[4] << endl;

	cit = List<char>::Iterator(cl.begin());
	cl.popFront();
	cout << "�������� �������:\n";
	while (cit != cl.end()) {
		cout << *cit << " ";
		cit++;
	}

	cit = List<char>::Iterator(cl.begin());
	cl.popBack();
	cout << "�������� ����������:\n";
	while (cit != cl.end()) {
		cout << *cit << " ";
		cit++;
	}

	//----------------------------------------- ������ � �������
	List<double> dl;
	double d;

	cout << "������� ������ (double): " << endl;
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

	cout << "\n\n������������ ������ (double) ��� ������ �������������� ��������� [] ��� ������ ������ ���������:\n";
	cout << dl[0] << " " << dl[1] << " " << dl[2] << " " << dl[3] << " " << dl[4] << endl;

	auto dit = List<double>::Iterator(dl.begin());
	cout << "������������ ������ (double) ��� ������ �������������� ��������� [] c ������� ������ ���������:\n";
	while (dit != dl.end()) {
		cout << *dit << " ";
		dit++;
	}

	cout << "\n\n����: ";
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


	//---------------------------------------------- ������ � ������
	List<float> fl;
	float f;

	cout << "������� ������ (double): " << endl;
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


	cout << "\n\n������������ ������ (float) ��� ������ �������������� ��������� [] ��� ������ ������ ���������:\n";
	cout << fl[0] << " " << fl[1] <<" "<< fl[2] << " " << fl[3] << " " << fl[4] << endl;

	auto fit = List<float>::Iterator(fl.begin());
	cout << "������������ ������ (float) ��� ������ �������������� ��������� [] c ������� ������ ���������:\n";
	while (fit != fl.end()) {
		cout << *fit << " ";
		fit++;
	}

	cout << "\n\n����: ";
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

	//--------------------------------------------- ������ � �������
	List<string> sl;
	string s;

	cout << "������� ������ (string): " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		sl.pushBack(s);
	}sl.popFront();


	cout << "\n\n������������ ������ (string) ��� ������ �������������� ��������� [] ��� ������ ������ ���������:\n";
	cout << sl[0] << " " << sl[1] << " " << sl[2] << " " << sl[3] << " " << sl[4] << endl;

	auto sit = List<string>::Iterator(sl.begin());
	cout << "������������ ������ (string) ��� ������ �������������� ��������� [] c ������� ������ ���������:\n";
	while (sit != sl.end()) {
		cout << *sit << " ";
		sit++;
	}

	cout << "\n\n����: ";
	cin >> s;
	sl.find(s);

	getchar(); getchar();
}