#include <string>
#include <iostream>
#include "TRAIN.h"
using namespace std;

void Train::setCity(string c) {
	city = c;
}

string Train::getCity() {
	return city;
}

void Train::setHour(int p) {
	hour = p;
}

int Train::getHour() {
	return hour;
}

void Train::setMinute(int p) {
	minute = p;
}

int Train::getMinute() {
	return minute;
}

void Train::setNumberoftrain(int p) {
	numberoftrain = p;
}

int Train::getNumberoftrain() {
	return numberoftrain;
}
void Train::setNumber(int p) {
	number = p;
}
int Train::getNumber() {
	return number;
}

Train::Train() {
	numberoftrain = 0;
}

istream & operator >>(istream &is, Train &q)
{
	string wcity;
	int wnumbertrain, whour, wminute;
	cin >> wnumbertrain >> wcity >> whour>> wminute;
	q.setNumberoftrain(wnumbertrain);
	q.setCity(wcity);
	q.setHour(whour);
	q.setMinute(wminute);
	return is;
}