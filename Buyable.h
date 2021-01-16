#pragma once
#include "Observer.h"
#include "Subject.h"
#include "Grid.h"
#include "RentDictionary.h"

class Player;

class Buyable_Building : public Grid, public Observer, public Subject
{
protected:
	bool upGradeable;
	Player* owner;
	int price;
	int rent;
	std::string kind;
	int level;// level
	int improve;//level up cost
	RentDic dic;
public:
	int getImprove();
	bool getUpGradeable();
	virtual void visit(Player*);
	virtual void notified();
	int getLevel();
	void setLevel(int);
	std::string getKind();
	void setKind(std::string);
	Player* getOwner();
	int getRent();
	int getPrice();
	void sell_to(Player* p);
	void setOwner(Player* p);
	Buyable_Building(int price, int rent, int improve, int position, std::string name, Grid* prev = nullptr,
		Grid* next = nullptr, Player* owner = nullptr);
	void updateRent();
	void LevelUp();
	void LevelDown();
};
