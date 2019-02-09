#pragma once
#include <iostream>

using namespace System;
using namespace System::Threading;


public delegate void MyDel();

ref class Timer1 {
	int interval;
	int timeOutVal;
	bool clear = false;
	void task1();
	void task2();
	MyDel^ d1;

public:
	Timer1();
	~Timer1();
	void enable();
	void disable();
	void setInterval(int);
	int getInterval(void);
	void setTimeOut(int);
	int getTimeOutVal();
	//template<typename Function>
	void setEventFn(MyDel^ fn);
	void start();
};
