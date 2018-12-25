#pragma once
#ifndef SPISOK
#define SPISOK
#include "TRAIN.h"
#include <string>
#include <iostream>
using namespace std;

// список всех поездов
class Spisok {
public:
	int tsize, n, counter = 1;
	Train *mas;
	Spisok();

	~Spisok();

	Spisok(const Spisok &obj);


	friend Spisok operator += (Spisok &obj, const Train &p)
	{
		Train *tmp = new Train[obj.tsize + 1];

		for (int i = 0; i < obj.tsize; i++)
			tmp[i] = obj.mas[i];

		tmp[obj.tsize] = p;
		tmp[obj.tsize].setNumber(obj.counter);
		delete[] obj.mas;
		obj.mas = tmp;
		obj.tsize++;
		obj.counter++;
		return obj;
	}

	Spisok & operator -=(int wnumber);


	friend ostream & operator << (ostream & os, const Spisok & com);


	void sort();
	void trainaftertime(int houraf,int minuteaf);
};
#endif

