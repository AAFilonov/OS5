#pragma once
#include "Process.h"
#include <vector>


using namespace std;
class Process_pool
{
	int process_count;
	size_t active;
	vector <Process> Pool;
public:

	void Add_Process(Process p);
	void select_active(size_t s);
	void Read(string filename);
	bool Processing_done();
	void Print(ofstream &out);
	void UPD(int tik);
	int SJF_P(int tik);
	int FCFS(int tik);
	ofstream& Statistic(ofstream& out);

	void tik(int t);
	Process_pool();
};

