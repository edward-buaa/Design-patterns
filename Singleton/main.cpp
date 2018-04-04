


#include <iostream>
#include <thread>
#include "singleton.h"

int main()
{
	singleton* p = singleton::getInstance();
	singleton* p1 = singleton::getInstance();
	singleton* p2 = singleton::getInstance();

	std::this_thread::sleep_for(std::chrono::seconds(1));
	return 0;
}