#pragma once
#include "Process.h"
#include <vector>


using namespace std;
class Process_pool
{
	size_t process_count;
	size_t active;
	vector <Process> Pool;
public:

	void Add_Process(Process p);
	void select_active(size_t s);
	void Read(string filename);
	bool Processing_done();
	void Print(ofstream &out);
	vector <vector<char>> Out_Matrix();
	void UPD(int tik);
	int PSJF(int tik);
	int FCFS(int tik);
	ofstream& Statistic(ofstream& out);

	void tik(int t);
	Process_pool();
};

