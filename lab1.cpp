#include <iostream>
#include <conio.h>
#include <string>
#include "TRAIN.h"
#include "Spisok.h"

using namespace std;


int main() {

	Spisok p;
	Train q;
	int minaf,houraf;
	int wnumber;

	cout << "Write the number of train, city and hour and minute of departure :" << endl;
	for (int i = 0; i < 3; i++) {

		cin >> q;
		p += q;

	}
	p.sort();
	cout << p;

	int r;
	bool fl = true;
	while (fl) {
		cout << "0 - exit" << endl;
		cout << "1 - add objects" << endl;
		cout << "2 - delete object" << endl;
		cout << "3 - show objects" << endl;
		cout << "4 - show trains after time" << endl;

		cin >> r;
		switch (r) {
		case 0:
			fl = false;
			break;
		case 1:
			cout << "Write the number of train, city and hour and minute of departure:" << endl;
			cin >> q;

			p += q;

			p.sort();
			break;
		case 2:
			cout << "Write the number, which you want to delete :" << endl;
			cin >> wnumber;
			try
			{
				p -= wnumber;
			}
			catch (int e)
			{
				cout << e << " " << "Error! Wrong number" << endl;
			}
			catch (...)
			{
				cout << "Error" << endl;
			}
			break;
		case 3:
			p.sort();
			cout << p;
			cout << endl;
			break;
		case 4:
			cout << "write a time:" << endl;
			cin >> houraf;
			cin >> minaf;
			p.trainaftertime(houraf,minaf);// ����� ���� ������� ��������
			break;

			_getch();
		}
	}

}

