
#include "implementation.h"
#include <thread>


int main()
{
	ImplSubject* sub = new ImplSubject();
	Observer* o1 = new ImplObserver(sub);
	Observer* o2 = new ImplObserver(sub);
	sub->attch(o1);
	sub->attch(o2);
	sub->SetStatus("old");
	sub->notify();
	sub->SetStatus("new");
	sub->notify();


	std::this_thread::sleep_for(std::chrono::seconds(10));

	return 0;
}