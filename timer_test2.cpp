#include <iostream>
#include "Timer1.h"


using std::cout;
using std::endl;


ref class test{
public:
	void OnTimedEvent()
	{
		cout << "OnTimedEvent() is running!" << endl;
	}
};

int main(){

	Timer1 t;

	test^ t1 = gcnew test();
	MyDel^ del = gcnew MyDel(t1, &test::OnTimedEvent);
	
	t.setEventFn(del);
	t.setInterval(500);
	t.enable();
	t.start();
	t.setTimeOut(3000);

	while (1){

	}

}