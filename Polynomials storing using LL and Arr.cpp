#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
class Poly
{
	struct Node
	{
		double coef;
		double power;

		Node* next;
	};
	Node* ListHeadPtr;
public:
	Poly() { ListHeadPtr = NULL; }

	void AddNodeAtTail(double c, double pow)
	{
		Node* ptrNew = new Node, * ptrTemp = ListHeadPtr;
		ptrNew->coef = c;
		ptrNew->power = pow;
		ptrNew->next = NULL;
		if (ListHeadPtr == NULL)
		{
			ListHeadPtr = ptrNew;
			return;
		}
		while (ptrTemp->next != NULL)
			ptrTemp = ptrTemp->next;
		ptrTemp->next = ptrNew;

	}
	void DisplayPoly(void)
	{
		ofstream file2;
		Node* ptrTemp = ListHeadPtr;
		int coef1, coef2, coef3, coef4, coef5;

		file2.open("resultlink.txt", ios::app);
		cout << endl;
		while (ptrTemp != NULL)
		{
			if (ptrTemp->coef == 0 && ptrTemp->power == 0) {
				cout << "+1";
				file2 << "+1";
				ptrTemp = ptrTemp->next;
			}
			else {
				file2 << "+(" << ptrTemp->coef << "X^" << ptrTemp->power << ")";
				cout << "+(" << ptrTemp->coef << "X^" << ptrTemp->power << ")";
				ptrTemp = ptrTemp->next;
			}

		}
		file2 << endl;
		while (ptrTemp != NULL)
		{
			if (ptrTemp->coef == 1 && ptrTemp->power == 0)
			{
				coef1 = coef1 + ptrTemp->coef;
				file2 << coef1 << "x^0 + ";
				ptrTemp = ptrTemp->next;
			}

			if (ptrTemp->coef == 1 && ptrTemp->power == 1)
			{
				coef2 = coef2 + ptrTemp->coef;
				file2 << coef2 << "x^1 + ";
				ptrTemp = ptrTemp->next;
			}

			if (ptrTemp->coef == 1 && ptrTemp->power == 2)
			{
				coef3 = coef3 + ptrTemp->coef;
				file2 << coef3 << "x^2 + ";
				ptrTemp = ptrTemp->next;
			}

			if (ptrTemp->coef == 1 && ptrTemp->power == 3)
			{
				coef4 = coef4 + ptrTemp->coef;
				file2 << coef4 << "x^3 + ";
				ptrTemp = ptrTemp->next;
			}

			if (ptrTemp->coef == 1 && ptrTemp->power == 4)
			{
				coef5 = coef5 + ptrTemp->coef;
				file2 << coef5 << "x^4 + ";
				ptrTemp = ptrTemp->next;
			}


			file2 << endl;

		}


	};

	int main()
	{
		int ans;
		cout << "Which data structure do you want to use to store the polynomial?\nPress 1 for arrays\nPress 2 for linked lists\n";
		cin >> ans;
		if (ans == 1) {

			double coef, power;
			int a = 0; int  b = 0;
			int myarray[10][5];
			int result[5];
			int res = 0;
			string secaray[10][5];
			ifstream file1;
			file1.open("data.txt");
			file1 >> a >> b;
			cout << a << endl << b << endl;
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 5; j++) {

					file1 >> myarray[i][j];

				}

			}
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 5; j++) {

					cout << myarray[i][j] << "    ";

				}
				cout << endl;
			}
			file1.close();
			ofstream file2;
			file2.open("result.txt");
			for (int i = 0; i < 5; i++) {
				result[i] = 0;
			}
			for (int i = 0; i < 10; i++) {
				cout << "P" << i + 1 << " = ";
				file2 << "P" << i + 1 << " = ";
				for (int j = 0; j < 5; j++) {
					power = j;

					coef = myarray[i][j];
					if (coef == 0 && power == 0) {
						coef = 0;
					}
					else {
						coef = pow(coef, power);
					}

					file2 << "+(" << coef << "*X^" << power << ")";
					cout << "+(" << coef << "*X^" << power << ")";

					result[j] = coef + result[j];
				}
				file2 << endl;
				cout << endl;
			}
			file2 << endl << endl << endl << "Result of Addition\n";
			cout << endl << endl << endl << "Result of Addition\n \n";
			for (int j = 0; j < 5; j++) {
				power = j;
				file2 << "+(" << result[j] << "*X^" << power << ")";
				cout << "+(" << result[j] << "*X^" << power << ")";

			}



		}
		if (ans == 2) {


			int a, b;
			double coef;
			Poly p1[10];
			ifstream file1;
			file1.open("data.txt");
			file1 >> a >> b;
			for (int j = 0; j < 10; j++) {
				for (double i = 0; i < 5; i++) {

					file1 >> coef;
					p1[j].AddNodeAtTail(coef, i);
				}

			}
			file1.close();
			ofstream file2;
			file2.open("resultlink.txt");
			file2.close();
			for (int j = 0; j < 10; j++) {


				p1[j].DisplayPoly();
			}






		}







	}