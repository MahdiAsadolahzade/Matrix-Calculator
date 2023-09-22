#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int matA[100][100];
double matB[100][100];
double c[100][100];
int determinanA(int matA[100][100], int rowa, int cola);
int determinanB(int matB[100][100], int rowb, int colb);
int rowa, cola, rowb, colb, N, i, j, q, p;


int determinanA(int matA[100][100], int rowa, int cola)
{
	int i = 0;
	int j = 0;
	int sum = 0;
	int tempmatrix[100][100];

	if (rowa == cola)
	{
		if (rowa == 1)
		{
			sum = matA[0][0];
			return sum;
		}
		else if (rowa == 2)
		{
			sum = (matA[0][0] * matA[1][1]) - (matA[0][1] * matA[1][0]);
			return sum;

		}
		else
		{
			for (int p = 0; p < rowa; p++)
			{
				int h = 0;
				int k = 0;
				for (i = 1; i < cola; i++)
				{
					for (j = 0; j < rowa; j++)
					{
						if (j == p)
							continue;
						tempmatrix[h][k] = matA[i][j];
						k++;
						if (k == rowa - 1)
						{
							h++;
							k = 0;
						}
					}
				}
				sum = sum + matA[0][p] * pow(-1, p) * determinanA(tempmatrix, rowa - 1, cola - 1);
			}
			return sum;
		}

	}
	else
	{
		cout << "matrix matA isn't quadratic matrix" << endl;
	}

	cout << endl << "**********************" << endl;
}


int main() {
	cout << "menu:" << endl;
	cout << "1-enter the matrix matA" << endl;
	cout << "2-enter the matrix matB" << endl;
	cout << "3-transfer matA to matB" << endl;
	cout << "4-transfer matB to matA" << endl;
	cout << "5-Comput matA + matB = matA" << endl;
	cout << "6-Comput matA - matB = matA" << endl;
	cout << "7-Comput matA * matB = matA" << endl;
	cout << "8-Comput matA / matB = matA" << endl;
	cout << "9-Comput a * matA = matA" << endl;
	cout << "10-Comput determinant matA" << endl;
	cout << "11-Comput determinant matB" << endl;
	cout << "12-print matA" << endl;
	cout << "13-print matB" << endl;

	string between = "13";
	while (between == "13") {
		cout << "enter your number(1 to 13):";
		cin >> N;
		while (N < 1 || N > 13) {
			cout << "error" << endl;
			cout << "try again" << endl;
			cout << "please enter the number between 1 to 13:";
			cin >> N;
		}

		switch (N)
		{
		case 1:

			cout << "enter row:";
			cin >> rowa;
			cout << "enter col:";
			cin >> cola;
			while (rowa > 100 && cola > 100) {
				cout << "Error the number of the col and row is too much" << endl;
				cout << "enter row:" << endl;
				cin >> rowa;
				cout << "enter col:" << endl;
				cin >> cola;
			}
			cout << "enter your matrix matA :" << endl;
			for (i = 0; i < rowa; i++) {
				for (int j = 0; j < cola; j++) {
					cout << "matA[" << i + 1 << "][" << j + 1 << "] = ";
					cin >> matA[i][j];
				}
				if (j == cola - 1) {
					cout << endl;
				}
			}
			break;

		case 2:
			cout << "enter row:" << endl;
			cin >> rowb;
			cout << "enter col:" << endl;
			cin >> colb;
			while (rowb > 100 && colb > 100) {
				cout << "Error the number of the col and row is too much" << endl;
				cout << "enter row: ";
				cin >> rowb;
				cout << "enter col:";
				cin >> colb;
			}
			cout << "enter your matrix matB :" << endl;
			for (q = 0; q < rowb; q++) {
				for (int p = 0; p < colb; p++) {
					cout << "matB[" << q + 1 << "][" << p + 1 << "] = ";
					cin >> matB[q][p];
				}
				if (j == colb - 1) {
					cout << endl;
				}
			}
			break;
		case 3:
			cout << "matA TO matB IS:" << endl;
			for (int i = 0; i < rowa; i++)
				for (int j = 0; j < cola; j++) {
					c[i][j] = matA[i][j];
					cout << c[i][j] << "  ";
					if (j == cola - 1) {
						cout << endl;
					}
				}
			break;

		case 4:
			cout << "matB TO matA IS:" << endl;
			for (int i = 0; i < rowb; i++)
				for (int j = 0; j < colb; j++) {
					c[i][j] = matB[i][j];
					cout << c[i][j] << "  ";
					if (j == colb - 1) {
						cout << endl;
					}
				}
			break;

		case 5:
			cout << "sum of two matrix is:" << endl;
			for (i = 0; i < rowa; i++)
				for (j = 0; j < cola; j++) {
					if (rowa == rowb && cola == colb)
					{
						c[i][j] = matA[i][j] + matB[i][j];
						cout << c[i][j] << "  ";
					}
					if (j == cola - 1) {
						cout << endl;
					}
				}
			break;

		case 6:
			cout << "sub of two matrix is:" << endl;
			for (i = 0; i < rowa; i++)
				for (j = 0; j < cola; j++) {
					if (rowa == rowb && cola == colb)
					{
						c[i][j] = matA[i][j] - matB[i][j];
						cout << c[i][j] << "  ";
					}
					if (j == cola - 1) {
						cout << endl;
					}
				}
			break;

		case 7:
			if (cola != rowb)
			{
				cout << "Matrices cannot be multiplied!";
				exit(0);
			}

			for (i = 0; i < rowa; i++)
			{
				for (j = 0; j < colb; j++)
				{
					c[i][j] = 0;
					for (int k = 0; k < rowb; k++)
					{
						c[i][j] += matA[i][k] * matB[k][j];
					}
				}
			}
			cout << "Mult of matrices\n";
			for (i = 0; i < rowa; i++)
			{
				for (j = 0; j < colb; j++)
					cout << c[i][j] << "  ";
				cout << "\n";
			}
			break;

		case 9:
			int a;
			cout << "Enter a number : ";
			cin >> a;
			for (int i = 0; i < rowa; i++)
				for (int j = 0; j < cola; j++) {
					matA[i][j] = a * matA[i][j];
					cout << matA[i][j] << " ";
					if (j == cola - 1) {
						cout << endl;
					}
				}
			break;
		case 10:

			int det = determinanA(matA, rowa, cola);
			cout << "Determinan of matrix A is =" << det << endl;
			break;

		}
	}
}