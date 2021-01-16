#pragma once
#include "Visitor.h"
#include <string>
class Player;
class Buyable_Building;

class Grid : public Visitor
{
protected:
	std::string name;
	int position;
	Grid* prev;
	Grid* next;
	bool buyable;
public:
	void setBuyable(bool b);
	bool getBuyable();
	virtual void visit(Player*) = 0;
	Grid(int position, std::string name, Grid* prev = nullptr, Grid* next = nullptr);
	std::string getName();
	int getPosition();
	Grid* getPrev();
	Grid* getNext();
	void setPrev(Grid* g);
	void setNext(Grid* g);
};
