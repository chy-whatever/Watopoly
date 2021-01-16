#include "Non-Property.h"
#include <iostream>
#include "Player.h"
#include <ctime>


void Non_Property_Building::setOSAP(Grid* o)
{
	OSAP = o;
}

void Non_Property_Building::setTIMS(Grid* t)
{
	TIMS = t;
}

void Non_Property_Building::visit(Player* p)
{
	if (name == "OSAP")
	{
		std::shared_ptr<Get_Funds>(produceGetFunds(200))->visit(p);
	}
	else if (name == "DCTims")
	{
		std::shared_ptr<Tims>(produceTims())->visit(p);
	}
	else if (name == "SLC")
	{
		srand((int)time(0));
		if (rand() % 100 == 0)
		{
			std::cout << "You get a Roll Up the Rim cup!" << std::endl;
			p->changeItem(1);
		}
		else
		{
			std::shared_ptr<Get_Move>(produceGetMove(OSAP, TIMS))->visit(p);
		}
	}
	else if (name == "Tuition")
	{
		std::cout << "Choose between paying $300 tuition or 10% of your total worth" << std::endl;
		std::cout << "Press 3 for paying $300 and otherwise for 10% of your total worth" << std::endl;
		std::string c;
		std::cin >> c;
		if (c == "3")
		{
			std::shared_ptr<Get_Funds>(produceGetFunds(-300))->visit(p);
		}
		else
		{
			std::shared_ptr<Get_Funds>(produceGetFunds(-0.1 * p->get_Money()))->visit(p);
		}
	}
	else if (name == "NeedlesHall")
	{

		srand((int)time(0));
		if (rand() % 100 == 0)
		{
			std::cout << "You get a Roll Up the Rim cup!" << std::endl;
			p->changeItem(1);
		}
		else
		{

			std::shared_ptr<Get_Funds>(produceGetFunds())->visit(p);
		}
	}
	else if (name == "Goose")
	{
		std::shared_ptr<Goose>(produceGoose())->visit(p);
	}
	else if (name == "GoTims")
	{
		std::cout << "You are tired and want a cup of coffee" << std::endl;
		std::shared_ptr<Go_Tims>(produceGoTims(TIMS))->visit(p);
	}
	else
	{
		std::cout << "Pay your coop fee! -$150" << std::endl;
		std::shared_ptr<Get_Funds>(produceGetFunds(-150))->visit(p);
	}

}

Non_Property_Building::Non_Property_Building(int position, std::string name, Grid* OSAP, Grid* TIMS, Grid* prev, Grid* next)
	: Grid(position, name, prev, next), OSAP(OSAP), TIMS(TIMS)
{
}
