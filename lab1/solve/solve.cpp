#include <iostream>
#include <iomanip>
#include <locale.h>
#include <sstream>
#include <string>
using namespace std;


bool FindRoot(double a, double b, double c, double &x1, double &x2)
{
	double discriminant = b*b - 4 * a*c;

	if (discriminant < 0)
	{
		return false;
	}

	else if (discriminant == 0)
	{
		x1 = -b / (2 * a);
		return true;
	}

	else
	{
		discriminant = sqrt(discriminant);
		x1 = (-b + discriminant) / (2 * a);
		x2 = (-b - discriminant) / (2 * a);
		return true;
	}
}

bool CheckNumber(string N, double n)
{
	if ((istringstream(N) >> n >> ws).eof())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TransformToDouble(string N, double &n, stringstream &nn)
{
	if ((istringstream(N) >> n >> ws).eof())
	{
		nn >> n;
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	if (argc != 4)
	{
		cout << "������� ������ ������ ����������! (solve.exe <A> <B> <C>)";
		return 1;
	}

	string A(argv[1]), B(argv[2]), C(argv[3]);
	double a = 0, b = 0, c = 0;

	stringstream aa;
	if (!TransformToDouble(A, a, aa))
	{
		cout << "��������   " << A << "   �� �������� ������!" << endl;
		system("pause");
		return 1;
	}

	stringstream bb(B);
	if (!TransformToDouble(B, b, bb))
	{
		cout << "��������   " << B << "   �� �������� ������!" << endl;
		system("pause");
		return 1;
	}
	stringstream cc(C);

	if (!TransformToDouble(C, c, cc))
	{
		cout << "��������   " << C << "   �� �������� ������!" << endl;
		system("pause");
		return 1;
	}

	if (a == 0)
	{
		cout << "��� ��������� �� �������� ����������";
	}

	double x1, x2;
	if (!FindRoot(a, b, c, x1, x2))
	{
		cout << "��� ��������� �� ����� �������������� ������:" << endl;
	}

	else
	{
		if (x1 == x2)
		{
			cout << "��� ��������� ����� ������������ ������: " << x1 << endl;
			cout << fixed << setprecision(4) << "x1 = " << x1 << endl;
		}

		else
		{
			cout << "����� ���������:" << endl;
			cout << fixed << setprecision(4) << "x1 = " << x1 << "\n" << "x2 = " << x2 << endl;
		}
	}

	system("pause");
	return 0;
}