#pragma once
#ifndef TRAIN
#define TRAIN
#include <string>
#include <iostream>
using namespace std;

// Поезд
class Train {
private:
	string city;
	int hour;
	int minute;
	int numberoftrain;
	int number;
public:
	Train();

	void setCity(string c);
	string getCity();

	void setHour(int p);
	int getHour();

	void setMinute(int p);
	int getMinute();

	void setNumberoftrain(int p);
	int getNumberoftrain();

	void setNumber(int p);
	int getNumber();

	friend istream& operator >> (istream &is, Train &q);
};
#endif

