#pragma once
class Subject;

class Observer
{
public:
	void notify(Subject& s);
	virtual void notified() = 0;
};
