#include "Process_pool.h"

void Process_pool::Add_Process(Process p)
{
	Pool.push_back(p);
	process_count++;
}

void Process_pool::select_active(size_t s)
{
	active = s;
}

void Process_pool::Read(string filename)
{
	ifstream fin(filename);
	if (fin.is_open())
	{
		fin >> process_count;
		for (size_t i = 0; i < process_count; i++)
		{
			Process tmp;
			fin >> tmp;
			Pool.push_back(tmp);

		}
	}
	else 
	{
		cout << "cant open file" << filename << endl;
	}
}

bool Process_pool::Processing_done()
{

	for (size_t i = 0; i < process_count; i++)
	{
		if (Pool[i].state()!=FINISHED) {
			return false;
		}
	}
	return true;
}

void Process_pool::Print(ofstream& out)
{
	for (size_t i = 0; i < process_count; i++)
	{
		switch (Pool[i].state())
		{
		case NOT_STARTED:
			out << ' ';
			break;
		case FINISHED:
			out << ' ';
			break;
		case ACTIVE:
			out << 'A';
			break;
		case WAIT:
			out << 'w';
			break;

		}
	}
	
}
void Process_pool::UPD(int tik) 
{
	for (size_t i = 0; i < process_count; i++)
	{
		if (Pool[i].state() == NOT_STARTED && Pool[i].tb() <= tik)
		{
			Pool[i].Set_state(WAIT);
		}
		if (Pool[i].state() == ACTIVE)
		{
			Pool[i].Set_state(WAIT);
		}
		if (Pool[i].tg()>= Pool[i].tp())
		{
			Pool[i].Set_state(FINISHED);
		}
	}
}
int Process_pool::PSJF(int tik)
{
	active;
	int pmin = 10000;
	int min = 0;
	bool was = false;
	for (size_t i = 0; i < process_count; i++)
	{
		if (Pool[i].state() != NOT_STARTED && Pool[i].state() != FINISHED && Pool[i].tp()* (1/Pool[i].pri()) < pmin)
		{
			was = true;
			pmin = Pool[i].tp() * (1 / Pool[i].pri());
			min = i;
		}
	}
	if (was)
	{
		Pool[min].Set_state(ACTIVE);
		active = min;
	}
	return 0;
}

ofstream& Process_pool::Statistic(ofstream& out)
{
	int sT = 0;
	int sW = 0;
	double sR = 0;
	double sP = 0;
	for (size_t i = 0; i < process_count; i++)
	{
		int T = Pool[i].tg() + Pool[i].tw();
		double R = double(Pool[i].tg()) / (double)T;
		double P = (double)T / double(Pool[i].tg()); 
		sT += T;
		sW += Pool[i].tw();
		sR += R;
		sP += P;
		out << "Процесс " << i << ": общее время T = " << T << " потерянное время М = " << Pool[i].tw() << " R = " << R << " P = " << P << endl;
	}
	out << "Средние величины "<< ": общее время T = " << (double)sT/ process_count << " потерянное время М = " << (double)sW/process_count << " R = " << sR / process_count << " P = " << sP / process_count << endl;
	return out;
}

void  Process_pool::tik(int t)
{

	for (size_t i = 0; i < process_count; i++)
	{
		switch (Pool[i].state())
		{
		case NOT_STARTED:
		case FINISHED:
			break;
		case ACTIVE:
			Pool[i].tik_process();
			break;
		case WAIT:
			Pool[i].tik_wait();
			break;

		}
	}


}

Process_pool::Process_pool()
:active(0), process_count(0)
{
}
