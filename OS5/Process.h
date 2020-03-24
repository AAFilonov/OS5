#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

enum state {
	WAIT,
	ACTIVE,
	NOT_STARTED,
	FINISHED

};
class Process
{
	state State;
	int time_begin;
	int time_process;
	int time_wait_count;
	int time_go_count;
	int priority;

	
public:
	inline void Set_state(state st) {  State=st; }
	inline state state() { return State; }
	inline int tb() { return time_begin; }
	inline int tp() { return time_process; }
	inline int tg() { return time_go_count; }
	inline int tw() { return time_wait_count; }
	inline int pri() { return priority; }

	void tik_wait();
	void tik_process();
	friend ostream& operator<<(ostream& out, const Process& B);
	friend istream& operator>>(istream& in, Process& B);
	void Generate(int tb1, int tb2, int tp1, int tp2 );
	Process(int tb = 0, int tp = 0);
	Process(int tb1, int tb2, int tp1, int tp2);
	~Process();
};



