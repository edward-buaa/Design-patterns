
#include "memento.h"
#include <thread>


int main(int argc, char* argv[])
{
	Originator* o = new Originator();
	o->SetState("old");
	o->PrintState();

	Memento* m = o->CreateMemento();
	o->SetState("new");
	o->PrintState();

	o->RestoreToMemento(m);
	o->PrintState();

	std::this_thread::sleep_for(std::chrono::seconds(10));
	return 0;
}