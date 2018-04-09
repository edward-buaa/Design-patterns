
#include "implementation.h"

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

	system("pause");
	return 0;
}