#include "Observer.h"
#include "Subject.h"

void Observer::notify(Subject& s)
{
	s.notifyObservers();
}
