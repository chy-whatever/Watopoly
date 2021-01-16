#pragma once
#include "Fatcory.h"
#include <string>

class Buyable_Building;

class Non_Property_Building : public Grid, public Factory
{
private:
	Grid* OSAP;
	Grid* TIMS;
public:
	void setOSAP(Grid*);
	void setTIMS(Grid*);
	virtual void visit(Player*);
	Non_Property_Building(int position, std::string name, Grid* OSAP = nullptr, Grid* TIMS = nullptr,
		Grid* prev = nullptr, Grid* next = nullptr);

};
