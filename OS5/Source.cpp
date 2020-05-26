#include <fstream>
#include <iostream>
#include <iomanip>
#include "Process_pool.h"
#include <time.h>
using namespace std;
const string output = "output.txt";
const string input = "input.txt";



int main()
{



	ofstream fout(output);
	Process_pool A;
	A.Read(input);


	int tiks = 1;
	while (!A.Processing_done())
	{
		A.UPD(tiks);
		A.PSJF(tiks);
		A.tik(tiks);
		fout << "Такт " << setw(3) << tiks << " ";
		A.Print(fout);
		fout << endl;
		tiks++;
	}
	A.Statistic(fout);

	fout.close();

	return 0;
}