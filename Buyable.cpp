#include "Buyable.h"
#include "Player.h"
#include "GameException.h"
#include <ctime>

int Buyable_Building::getLevel()
{
    return level;
}

void Buyable_Building::setLevel(int l)
{
    level = l;
}

std::string Buyable_Building::getKind()
{
    return kind;
}

void Buyable_Building::setKind(std::string s)
{
    kind = s;
}

Player* Buyable_Building::getOwner()
{
    return owner;
}

int Buyable_Building::getRent()
{
    return rent;
}

int Buyable_Building::getImprove()
{
    return improve;
}

bool Buyable_Building::getUpGradeable()
{
    return upGradeable;
}

void Buyable_Building::visit(Player * p)
{
    if (owner != nullptr) 
    {
        if(owner->getName() != p->getName())
        {
            if (level == -1)
            {
                std::cout << "You are at " << owner->getName() << "'s " << name << "\n";
                std::cout << "But the building has been mortgaged and you do not need to purchase!" << "\n";
                return;
            }
            if (name == "CIF" || name == "PAC")
            {
                srand((int)time(0));
                int a = rand() % 6;
                int b = rand() % 6;
                std::cout << "You are at " << owner->getName() << "'s " << name << "\n";
                if (level == 0)
                {
                    rent = (a + b) * 4;
                    std::cout << "You rolled " << a << " and " << b << "!\n";
                }
                else
                {
                    rent = (a + b) * 10;
                    std::cout << "You rolled " << a << " and " << b << "!\n";
                }
            }
            else if (kind == "Accumulative")
            {
                if (level == 0)
                {
                    rent = 25;
                }
                else if (level == 1)
                {
                    rent = 50;
                }
                else if (level == 2)
                {
                    rent = 100;
                }
                else if(level == 3)
                {
                    rent = 200;
                }
                else
                {
                    rent = 0;
                }
            }
            std::cout << "You are at " << owner->getName() << "'s " << name << "\n";
            std::cout << "You need to pay $" << rent << " to the owner " << owner->getName() << std::endl;
            p->changeMoney(-rent);
            owner->changeMoney(rent);
        }
        else
        {
            std::cout << "You walked passed your building " << name << std::endl;
        }
        
    }
    else 
    {
        if (p->get_Money() < price)
        {
            std::cout << "You walked pass the building, but you do not have enough money to purchase for it" << std::endl;
            return;
        }
        std::cout << "Do you want to buy this building? Enter Yes / No" << std::endl;
        std::string response;
        std::cin >> response;
        if (response.substr(0, 1) == "Y" || response.substr(0, 1) == "y") {
            sell_to(p);
            std::cout << "Now " << name << " is now yours!\n";
        }
        else
        {
            std::cout << "You walked passed the building, and nothing happened" << std::endl;
        }
    }
}

void Buyable_Building::notified()
{
    if (kind == "Accumulative") {
        int up = 0;
        if (!owner)
        {
            level = 0;
            return;
        }
        for (std::vector<Observer*>::iterator i = neighbours.begin(); i != neighbours.end(); i++)
        {

            if (dynamic_cast<Buyable_Building*>(*i)->getOwner() != nullptr)
            {
                if (dynamic_cast<Buyable_Building*>(*i)->getOwner()->getName() == owner->getName())
                {
                    up++;
                }
            }
        }
        level = up;/*neighbours with same owner*/
    } 
    else {
        bool up = true;
        if (owner == nullptr)
        {
            upGradeable = false;
            return;
        }
        for (std::vector<Observer*>::iterator i = neighbours.begin(); i != neighbours.end(); i++)
        {
           if (dynamic_cast<Buyable_Building*>(*i)->getOwner() == nullptr || 
               dynamic_cast<Buyable_Building*>(*i)->getOwner()->getName() != owner->getName())
           {
               up = false;
               break;
           }
        }
        upGradeable = up;
    }
}

int Buyable_Building::getPrice()
{
    return price;
}

void Buyable_Building::sell_to(Player* p)
{
    try {
        p->changeMoney(-price);
        setOwner(p);
        notify(*this);
        notified();
        p->add_building(this);
    } catch (GameException &e) {
        //bankruptcy check
        return;
    }
}

void Buyable_Building::setOwner(Player* p)
{
    owner = p;
}

Buyable_Building::Buyable_Building(int price, int rent, int improve, int position, 
    std::string name, Grid* prev, Grid* next, Player* owner) :
    Grid(position, name, prev, next), owner(owner), price(price), rent(rent), improve(improve)
{ }

void Buyable_Building::updateRent()
{
    if (kind == "Academic")
    {
        RentDic dic;
        std::map<std::string, std::vector<int>>::iterator i = dic.rentDic.find(name);
        if (level < 0)
        {
            rent = (*i).second.at(0);
        }
        else
        {
            rent = (*i).second.at(level);
        }
    }
    else if (kind == "Accumulative")
    {
        rent = level * 25;
    }
}

void Buyable_Building::LevelUp()
{
    if (upGradeable)
    {

        if (owner->get_Money() < improve)
        {
            std::cout << "Insufficient funds!\n";
        }
        else if(level == 5)
        {
            std::cout << "There is no room for more improvements!\n";
        }
        else if (kind == "Accumulative")
        {
            std::cout << "There is no need to upgrade a residence or gym building\n";
        }
        else if (level == -1)
        {
            std::cout << "You must unmortgage your building before buy improvements for it\n";
        }
        else
        {
            std::cout << name << " improved\n";
            owner->changeMoney(-improve);
            level++;
            updateRent();
        }
    }
    else
    {
        std::cout << "You need to own all buildings in a block to buy improvements for them!\n";
    }
}

void Buyable_Building::LevelDown()
{
    if (level == 0 || kind == "Accumulative")
    {
        std::cout << "There is no improvement in the building\n";
    }
    else if (level == -1)
    {
        std::cout << "You must unmortgage your building before sell improvements for it\n";
    }
    else
    {
        std::cout << name << "'s improvement sold\n";
        owner->changeMoney(improve / 2);
        level--;
        updateRent();
    }
}

