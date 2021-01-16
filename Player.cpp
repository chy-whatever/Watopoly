#pragma once
#include "Player.h"
#include "PlayerInfoException.h"
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Buyable.h"

void Player::Mortgage(Buyable_Building* b)
{
	if (b->getLevel() == -1)
	{
		std::cout << b->getName() << " has already been mortgaged!\n";
		return;
	}
	else if (b->getLevel() > 0)
	{
		std::cout << b->getName() << " still has some improvements in it!\n";
		return;
	}
	else
	{
		money += (b->getPrice()) / 2;
		std::cout << "Building " << b->getName() << " mortgaged successfully, you got $" << (b->getPrice()) / 2 << std::endl;
		b->setLevel(-1);
	}
}

void Player::UnMortgage(Buyable_Building* b)
{
	if (b->getLevel() == -1)
	{
		if (money < (b->getPrice()) * 0.6)
		{
			std::cout << "Insufficient funds!\n";
		}
		else
		{
			money -= (b->getPrice()) * 0.6;
			b->setLevel(0);
			std::cout << b->getName() << " is now unmortgaged!\n";
		}
	}
	else
	{
		std::cout << b->getName() << " is already unmortgaged!\n";
	}
}

std::string Player::get_player_char()
{
	return player_char;
}

void Player::set_player_char(std::string s)
{
	player_char = s;
}

void Player::position_on(Grid*g)
{
	position = g;
}

Player::Player(std::string name, Grid* position, int money, int itemNum, bool jailed, int jailed_turn, bool status, int moveNum)
	: name(name), position(position), money(money), itemNum(itemNum), status(status), moveNum(moveNum), jailed_turn(jailed_turn), jailed(jailed)
{ }

std::string Player::getName()
{
	return name;
}


void Player::show_Player()
{
	std::cout << "---------------------------------------------------------------\n";
	std::cout << "Player: " << std::left << std::setw(15) << name << "\n" << "Cash: " << std::setw(10) << money
		<< "Item: " << std::setw(5) << itemNum << "\n" << "Now at: " << std::setw(10) << position->getName() << "\n"
		 << "Buildings: ";
	int num = 0;
	for (std::vector<Buyable_Building*>::iterator i = buildings.begin(); i != buildings.end(); ++i)
	{

		num++;
		std::cout << std::left << std::setw(5) << (*i)->getName();
		if (num == 3)
		{
			std::cout << std::endl;
		}
	}
	std::cout << "\n";

}


std::vector<Buyable_Building*> Player::get_Buildings()
{
	return buildings;
}

void Player::add_building(Buyable_Building* g)
{
	buildings.emplace_back(g);
}

void Player::remove_building(Buyable_Building* g)
{
	std::vector<Buyable_Building*>::iterator i = std::find(buildings.begin(), buildings.end(), g);
	if (i != buildings.end())
	{
		buildings.erase(i);
	}
	else
	{
		std::cerr << "Cannot find the target building" << std::endl;
		throw PlayerInfoException(); //make new exception
	}
}

int Player::get_Money()
{
	return money;
}

void Player::changeMoney(int num)
{
	money += num;
	if (money < 0)
	{
		while (1)
		{
			std::cout << "You are losing all of your cash with a loan of $" << money << ",\nenter \"bankrupt\" if you want to bankrupt and quit the game,\n"
				<< "enter \"mortgage building_name\" if you want to mortgage a building\n"
				<< "enter \"improve building_name\" if you want to sell a improvement in a building\n";
			std::cout << "Here is your situaion:\n";
			show_Player();
			std::string str;
			std::cin >> str;
			if (str.substr(0, 1) == "b" || str.substr(0, 1) == "B")
			{
				this->bankrupt();
				return;
			}
			else if (str.substr(0, 1) == "i" || str.substr(0, 1) == "I")
			{
				std::cin >> str;
				std::vector<Buyable_Building*>::iterator i = buildings.begin();
				for (i = buildings.begin(); i != buildings.end(); ++i)
				{
					if ((*i)->getName() == str)
					{
						break;
					}
				}
				if (i == buildings.end())
				{
					std::cout << "You do not own building " << str << " so you cannot manage its improvements!\n";
				}
				else
				{
					if ((*i)->getLevel() == 0 || (*i)->getKind() == "Accumulative")
					{
						std::cout << "There is no improvement in the building\n";
					}
					else if ((*i)->getLevel() == -1)
					{
						std::cout << "You must unmortgage your building before sell improvements for it\n";
					}
					else
					{
						std::cout << name << "'s improvement sold\n";
						money += (*i)->getImprove() / 2;
						(*i)->setLevel((*i)->getLevel() - 1);
						(*i)->updateRent();
					}
				}
			}
			else if (str.substr(0, 1) == "m" || str.substr(0, 1) == "M")
			{
				std::cin >> str;
				std::vector<Buyable_Building*>::iterator i = buildings.begin();
				for (i = buildings.begin(); i != buildings.end(); ++i)
				{
					if ((*i)->getName() == str)
					{
						Mortgage(*i);
						break;
					}
				}
				if (i == buildings.end())
				{
					std::cout << "You do not own building " << str << " and you cannot mortgage it!\n";
				}
			}
			else
			{
				std::cout << "Your expression is too vague\n";
			}
			if (money >= 0)
			{
				break;
			}
		}
	}
}

int Player::get_itemNum()
{
	return itemNum;
}

void Player::changeItem(int num)
{
	itemNum += num;
}

bool Player::get_status()
{
	return status;
}

int Player::get_moveNum()
{
	return moveNum;
}

Grid* Player::get_position()
{
	return position;
}

void Player::bankrupt()
{
	status = true;
	for (std::vector<Buyable_Building*>::iterator i = buildings.begin(); i != buildings.end(); ++i)
	{
		(*i)->setOwner(nullptr);////////////
		(*i)->notifyObservers();
		(*i)->notified();
		(*i)->setLevel(0);
		(*i)->updateRent();
	}
}

void Player::Move()
{
	srand((int)time(0));
	int a = rand() % 5 + 1;
	int b = rand() % 5 + 1;
	std::cout << "You rolled " << a << " and " << b << std::endl;
	moveNum = a + b;
	for (; moveNum != 0; moveNum--)
	{
		position = position->getNext();
		if (position->getName() == "OSAP" && moveNum != 1)
		{

			position->visit(this);
		}
	}

	position->visit(this);
}

void Player::Move(int fst, int snd)
{
	moveNum = fst + snd;
	if(moveNum > 0)
	{
		for (; moveNum != 0; moveNum--)
		{
			position = position->getNext();
			if (position->getName() == "OSAP" && moveNum != 1)
			{
				position->visit(this);
			}
		}
	}
	else
	{
		for (; moveNum != 0; moveNum++)
		{
			position = position->getPrev();
			if (position->getName() == "OSAP" && moveNum != -1)
			{
				position->visit(this);
			}
		}
	}
	position->visit(this);
}

void Player::Move_to(Grid* g)
{
	position = g;
	g->visit(this);
}

bool Player::getJailed()
{
	return jailed;
}

int Player::getJailedTurn()
{
	return jailed_turn;
}

void Player::jailing()
{
	jailed = true;
	if (jailed_turn == 3)
	{
		if (itemNum > 1)
		{
			std::cout << "Use item or pay?" << std::endl;
			std::string c;
			std::cin >> c;
			while (c != "I" && c != "i" && c != "U" && c != "u")
			{
				std::cout << "Use item or pay?" << std::endl;
			}
			if (c == "I" || c == "i")
			{
				itemNum --;
				jailed_turn = 0;
				jailed = false;
				position = position->getNext();
			}
			else
			{
				money -= 50;
				jailed_turn = 0;
				jailed = false;
				position = position->getNext();
			}
		}
		else
		{
			std::cout << "You finally got your coffee and paid $50" << std::endl;
			money -= 50;
			jailed_turn = 0;
			jailed = false;
			position = position->getNext();
		}
	}
	else
	{
		jailed_turn++;
		if (itemNum > 1)
		{
			std::cout << "Use item, roll or pay?" << std::endl;
			std::string c;
			std::cin >> c;
			while (c != "I" && c != "i" && c != "U" && c != "u")
			{
				std::cout << "Use item, roll or pay?" << std::endl;
			}
			if (c == "I" || c == "i")
			{
				itemNum--;
				jailed_turn = 0;
				jailed = false;
				position = position->getNext();
			}
			else if (c == "U" || c == "u")
			{
				money -= 50;
				jailed_turn = 0;
				jailed = false;
				position = position->getNext();
			}
			else
			{
				srand((int)time(0));
				int a = rand() % 5 + 1;
				int b = rand() % 5 + 1;
				std::cout << "You rolled " << a << "and " << b << std::endl;
				if (a == b)
				{
					std::cout << "You are free!" << std::endl;
					jailed_turn = 0;
					jailed = false;
					position = position->getNext();
				}
				else
				{
					std::cout << "You are still not free!" << std::endl;
				}
			}
		}
		else
		{
			std::cout << "Roll or pay?" << std::endl;
			std::string c;
			std::cin >> c;
			if (c == "U" || c == "u")
			{
				money -= 50;
				jailed_turn = 0;
				jailed = false;
				position = position->getNext();
			}
			else
			{
				srand((int)time(0));
				int a = rand() % 5 + 1;
				int b = rand() % 5 + 1;
				std::cout << "You rolled " << a << "and " << b << std::endl;
				if (a == b)
				{
					std::cout << "You are free!" << std::endl;
					jailed_turn = 0;
					jailed = false;
					position = position->getNext();
				}
				else
				{
					std::cout << "You are still not free!" << std::endl;
				}
			}
		}
	}
}
