#include "Process.h"

ostream& operator<<(ostream& out, const Process& B)
{
	out << B.time_begin << " " << B.time_process << " " <<B.time_go_count<< " "  <<B.time_wait_count << endl;
	return out;
}

istream& operator>>(istream& in, Process& B)
{
	in >> B.time_begin;
	in >> B.time_process;
	in >> B.priority;
	return in;
}

void Process::tik_wait()
{

	time_wait_count++;

}

void Process::tik_process()
{
	
	time_go_count++;
	
}

void Process::Generate(int tb1, int tb2, int tp1, int tp2)
{
	time_begin = rand() % tb2 + tb1;
	time_process = rand() % tp2 + tp1;
}

Process::Process(int tb,int tp)
	:time_begin(tb),time_process(tp), time_wait_count(0),time_go_count(0), State(NOT_STARTED)
{
}

Process::Process(int tb1, int tb2, int tp1, int tp2)
	:  time_wait_count(0), time_go_count(0), State(NOT_STARTED)
{
	time_begin = rand() % tb2 + tb1;
	time_process = rand() % tp2 + tp1;
}
Process::~Process()
{
}
