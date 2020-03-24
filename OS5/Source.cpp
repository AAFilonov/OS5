#include <fstream>
#include <iostream>
#include <iomanip>
#include "Process_pool.h"

#include <time.h>
using namespace std;
const string output = "output.txt";
const string input = "Text.txt";



int main() 
{
	setlocale(LC_ALL, "Russian");
	ofstream fout(output);
	Process_pool A;
	A.Read(input);
	int choise = 0;
	do {
		cout << "Выберите алгорим распределения:\n1)FCFC\n2)SJF с приоритетом\n";
		cin >> choise;
	} while (choise != 1 && choise != 2);


	int tiks = 1;
	while (!A.Processing_done()) 
	{
		A.UPD(tiks);

		switch (choise)
		{
		case 1:
			A.FCFS(tiks);
			break;
		case 2:
			A.SJF_P(tiks);
			break;
		}

		A.tik(tiks);
		
		fout << "Такт " <<setw(3) << tiks <<" ";
		A.Print(fout);
		fout << endl;
		tiks++;
	}
	A.Statistic(fout);

	fout.close();

	return 0;
}