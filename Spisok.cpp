#include <string>
#include <iostream>
#include "Spisok.h"
using namespace std;

Spisok::Spisok()
{
	n = 8;
	tsize = 0;
	mas = new Train[n];
}

Spisok::~Spisok() {
	delete[]mas;
}

Spisok::Spisok(const Spisok &obj)
{
	mas = new Train[obj.tsize];
	for (int i = 0; i < tsize; i++)
		mas[i] = obj.mas[i];

	tsize = obj.tsize;

}

Spisok & Spisok::operator -=(int wnumber)
{
	int k = 0;

	if ((wnumber <= 0) || (wnumber > tsize)) {
		throw 123;
	}


	Train *tmp = new Train[tsize - 1];
	for (int i = 0; i < tsize; i++) {
		if (wnumber != mas[i].getNumber()) {
			tmp[k] = mas[i];
			k++;
		}
	}
	delete[] mas;
	mas = tmp;
	tsize--;

}

ostream & operator << (ostream & os, const Spisok & com)
{
	if (com.tsize == 0) {
		cout << "spisok is empty" << endl;
	}
	else {
		for (int i = 0; i < com.tsize; i++)
			cout << com.mas[i].getNumber() << " " << com.mas[i].getCity() << " " << com.mas[i].getHour() <<":" << com.mas[i].getMinute() << endl;
	}
	return os;
}


void Spisok::sort() {//сортировка пузырьком по алфавиту
	int counter = 1;
	for (int i = 0; i < tsize; i++)
		for (int j = tsize - 1; j > i; j--) {
			if (mas[j - 1].getCity() > mas[j].getCity()) {
				Train tmp = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = tmp;
			}
		}
	for (int i = 0; i < tsize; i++)
	{
		mas[i].setNumber(counter);
		counter++;
	}
}

void Spisok::trainaftertime(int houraf, int minuteaf) {
	int count = 0;
	for (int i = 0; i < tsize; i++)
		if ((mas[i].getHour() > houraf)||((mas[i].getHour() == houraf)&&(mas[i].getMinute() > minuteaf)))
		{
			cout << mas[i].getNumber() << " " << mas[i].getCity() << " " << mas[i].getHour() << ":" << mas[i].getMinute() << endl;
			count++;
		}
	if (count == 0)
	{
		cout << "Not found" << endl;
	}
}