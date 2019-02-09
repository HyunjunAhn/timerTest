#include "Timer1.h"

Timer1::Timer1(){

}

Timer1::~Timer1(){

}

void Timer1::task1() {
	while (true) {
		if (this->clear) return;
		_sleep(getInterval());
		if (this->clear) return;
		d1();
	}
}

void Timer1::task2() {
	while (true) {
		if (this->clear) return;
		_sleep(getTimeOutVal());
		if (this->clear) return;
		disable();
	}
}

void Timer1::enable() {
	this->clear = false;
}

void Timer1::disable() {
	this->clear = true;
}

void Timer1::setInterval(int _interval) {
	interval = _interval;
}

int Timer1::getInterval() {
	return interval;
}

void Timer1::setTimeOut(int _timeOutVal){
	timeOutVal = _timeOutVal;
	Thread^ t1 = gcnew Thread(gcnew ThreadStart(this, &Timer1::task2));
	t1->Start();
}

int Timer1::getTimeOutVal() {
	return timeOutVal;
}


void Timer1::start(){
	Thread^ t1 = gcnew Thread(gcnew ThreadStart(this, &Timer1::task1));
	t1->Start();
}

//template<typename Function>
void Timer1::setEventFn(MyDel^ fn)
{
	d1 = fn;
}
