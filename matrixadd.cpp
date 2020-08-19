#include <iostream>
#define N 30

using namespace std;

void input(int M[][N], int r, int c)
{
	cout << "Enter Matrix Elements : \n";
	for (int i = 0; i <= r - 1; i++)
	{
		for (int j = 0; j <= c - 1; j++)
		{
			cin >> M[i][j];
		}
	}
}
void output(int M[][N], int r, int c)
{
	cout << "Matrix Elements are : \n";
	for (int i = 0; i <= r - 1; i++)
	{
		for (int j = 0; j <= c - 1; j++)
		{
			cout << M[i][j] << ' ';
		}
		cout << endl;
	}
}
void add(int A[][N], int B[][N], int r1, int c1, int r2, int c2, int M[][N])
{
	for (int i = 0; i <= r1 - 1; i++)
	{
		for (int j = 0; j <= c1 - 1; j++)
		{
			M[i][j] = A[i][j] + B[i][j];
		}
	}
}
void subtract(int A[][N], int B[][N], int r1, int c1, int r2, int c2, int M[][N])
{
	for (int i = 0; i <= r1 - 1; i++)
	{
		for (int j = 0; j <= c1 - 1; j++)
		{
			M[i][j] = A[i][j] - B[i][j];
		}
	}
}
void multiply(int A[][N], int B[][N], int r1, int c1, int r2, int c2, int M[][N])
{
	for (int i = 0; i <= r1 - 1; i++)
	{
		for (int j = 0; j <= c2 - 1; j++)
		{
			int sum = 0;
			for (int k = 0; k <= c1 - 1; k++)
			{
				sum += (A[i][k] * B[k][j]);
			}
			M[i][j] = sum;
		}
	}
}
int main()
{
	int A[N][N], B[N][N], M[N][N];
	int r1, c1, r2, c2;
	cout << "Dimensions for Matrix A (R1 C1) <=30 : ";
	cin >> r1 >> c1;
	cout << "Dimensions for Matrix B (R2 C2) <=30 : ";
	cin >> r2 >> c2;
	input(A, r1, c1);
	output(A, r1, c1);
	input(B, r2, c2);
	output(B, r2, c2);
	int choice;
	cout << "Select Operation : \n";
	cout << "1. Addition \n";
	cout << "2. Substraction \n";
	cout << "3. Multiplication\n";
	cout << "Enter Choice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		if (r1 == r2 and c1 == c2)
		{
			add(A, B, r1, c1, r2, c2, M);
			cout << "Result : \n";
			output(M, r1, c1);
		}
		else
		{
			cout << "Cannot Perform Addition\n";
		}
		break;
	case 2:
		if (r1 == r2 and c1 == c2)
		{
			subtract(A, B, r1, c1, r2, c2, M);
			cout << "Result : \n";
			output(M, r1, c1);
		}
		else
		{
			cout << "Cannot Perform Subtraction\n";
		}
		break;
	case 3:
		if (c1 == r2)
		{
			multiply(A, B, r1, c1, r2, c2, M);
			cout << "Result : \n";
			output(M, r1, c2);
		}
		else
		{
			cout << "Cannot Perform Multiplication\n";
		}
		break;
	default:
		cout << "Wrong Operation\n";
	}

	return 0;
}
