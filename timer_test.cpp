
#include <stdio.h>
#include <iostream>
#include <thread>

using std::cout;
using std::endl;

class Timer {
	bool clear = false;

public:
	template<typename Function>
	void setTimeout(Function function, int delay);

	template<typename Function>
	void setInterval(Function function, int interval);

	void stop();
};


template<typename Function>
void Timer::setTimeout(Function function, int delay) {
	this->clear = false;
	std::thread t([=]() {
		if (this->clear) return;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		if (this->clear) return;
		function();
	});
	t.detach();
}


template<typename Function>
void Timer::setInterval(Function function, int interval) {
	this->clear = false;
	std::thread t([=]() {
		while (true) {
			if (this->clear) return;
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if (this->clear) return;
			function();
		}
	});
	t.detach();
}


void Timer::stop() {
	this->clear = true;
}


int main(){
	Timer t = Timer();

	t.setInterval([&]() {
		cout << "Hey.. After each 1s..." << endl;
	}, 1000);

	t.setTimeout([&]() {
		cout << "Hey.. After 5.2s. But I will stop the timer!" << endl;
		t.stop();
	}, 5200);

	while (1){
	}
}
