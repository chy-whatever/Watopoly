#include "Controller.h"
#include <conio.h>
#include <algorithm>

void Controller::setTest(bool t)
{
	test = t;
}

void Controller::loadGame(std::ifstream& fin)
{
	int pNum;
	fin >> pNum;
	std::vector<int> posis;
	for (int i = 0; i < pNum; i++)
	{
		std::string name;
		std::string name_temp;
		fin >> name;
		fin >> name_temp;
		while (name_temp.size() != 1)
		{
			name = name + " " + name_temp;
			fin >> name_temp;
		}

		if (name_temp == "G")
		{
			name = "Goose";
		}
		else if (name_temp == "B")
		{
			name = "GRT Bus";
		}
		else if (name_temp == "D")
		{
			name = "Tim Hortons Doughnut";
		}
		else if (name_temp == "P")
		{
			name = "Professor";
		}
		else if (name_temp == "S")
		{
			name = "Students";
		}
		else if (name_temp == "$")
		{
			name = "Money";
		}
		else if (name_temp == "L")
		{
			name = "Laptop";
		}
		else
		{
			name = "Pink tie";
		}

		int item;
		fin >> item;

		int money;
		fin >> money;
		
		int pos;
		fin >> pos;
		posis.emplace_back(pos);
		bool jailed = false;
		int jailedt = 0;
		if (pos == 10)
		{
			fin >> jailed;
			fin >> jailedt;
		}

		std::shared_ptr<Player> p = std::shared_ptr<Player>(new Player(name, nullptr, money, item, jailed, jailedt));
		p->set_player_char(name_temp);
		players.emplace_back(p);
		turn.push(p);
	}

	field.loadBoard(fin);

	std::string owner;
	std::string owner_temp;
	int level;
		for (int i = 0; i < 40; i++)
		{
			if (field.getMap().at(i)->getBuyable())
			{

				fin >> owner;

				fin >> owner;
				fin >> owner_temp;
				while (owner_temp.size() != 1)
				{
					if (owner_temp == "-1")
					{
						break;
					}
					owner = owner + " " + owner_temp;
					fin >> owner_temp;
				}
				level = std::stoi(owner_temp);
				if (owner != "nullptr")
				{
					for (std::vector<std::shared_ptr<Player>>::iterator j = players.begin(); j != players.end(); ++j)
					{
						if ((*j)->getName() == owner)
						{
							dynamic_cast<Buyable_Building*>(field.getMap().at(i).get())->setOwner((*j).get());

							break;
						}
					}
				}
				dynamic_cast<Buyable_Building*>(field.getMap().at(i).get())->setLevel(level);
			}
		}

		for (int i = 0; i <= 39; i++)
		{
			if (field.getMap().at(i)->getBuyable())
			{
				dynamic_cast<Buyable_Building*>(field.getMap().at(i).get())->notifyObservers();
				dynamic_cast<Buyable_Building*>(field.getMap().at(i).get())->updateRent();
			}
		}

		for (int i = 0; i < players.size(); i++)
		{
			players.at(i)->position_on(field.getMap().at(posis[i]).get());
			if (players.at(i)->get_position() == nullptr)
			{
				players.at(i)->position_on(field.getMap().at(0).get());
			}
		}

		for (std::vector<std::shared_ptr<Grid>>::iterator i = field.getMap().begin(); i != field.getMap().end(); ++i)
		{
			if ((*i)->getBuyable())
			{
				Player* pl = dynamic_cast<Buyable_Building*>((*i).get())->getOwner();
				if (pl != nullptr)
				{
					pl->add_building(dynamic_cast<Buyable_Building*>((*i).get()));//////////////////////////////may cause problems
				}
			}
		}
}

void Controller::saveGame(std::ofstream& fout)
{
	fout << turn.size() << "\n";
	int maxp = turn.size();
	for(int j = 0; j < maxp; j ++)
	{
		std::shared_ptr<Player> i = turn.front();
		fout << i->getName() << " ";
		if (i->getName() == "Goose")
		{
			fout << "G" << " ";
		}
		else if (i->getName() == "GRT Bus")
		{
			fout << "B" << " ";
		}
		else if (i->getName() == "Tim Hortons Doughnut")
		{
			fout << "D" << " ";
		}
		else if (i->getName() == "Professor")
		{
			fout << "P" << " ";
		}
		else if (i->getName() == "Students")
		{
			fout << "S" << " ";
		}
		else if (i->getName() == "Money")
		{
			fout << "$" << " ";
		}
		else if (i->getName() == "Laptop")
		{
			fout << "L" << " ";
		}
		else
		{
			fout << "T" << " ";
		}
		fout << i->get_itemNum() << " ";
		fout << i->get_Money() << " ";
		fout << i->get_position()->getPosition();
		if (i->get_position()->getPosition() == 10)
		{
			fout << " " << i->getJailed();
			if (i->getJailed())
			{
				fout << " " << i->getJailedTurn();
			}
		}
		fout << "\n";
		turn.pop();
		turn.push(i);
	}

	field.saveBoard(fout);
}

void Controller::InitGame()
{
	field.InitBoard();
	std::cout << "New Field Generated" << std::endl;
	std::cout << "Please enter the Number of Players" << std::endl;
	std::string playern;
	std::cin >> playern;

	while (1)
	{
		if (!std::stoi(playern)) {
			std::cout << "Error: Invalid Input for Number of Players" << std::endl;
			std::cout << "Please re-enter the Number of Players, q for quit" << std::endl;
			std::cin.clear();
			std::cin.sync();
			std::cin >> playern;
		}
		else if (std::stoi(playern) > 8 || std::stoi(playern) < 6)
		{
			std::cout << "Error: Invalid Input for Number of Players" << std::endl;
			std::cout << "The number of players should be 6 - 8" << std::endl;
			std::cout << "Please re-enter the Number of Players, q for quit" << std::endl;
			std::cin.clear();
			std::cin.sync();
			std::cin >> playern;
		}
		else if (playern == "q" || playern == "Q")
		{
			std::cout << "Quitted" << std::endl;
			return;
		}
		else
		{
			break;
		}
	}

	int playerSize = std::stoi(playern);
	for (int i = 0; i < playerSize; i++) {
		std::shared_ptr<Player> newp;
		Grid* start = (field.getMap().at(0)).get();
		switch (i) {
		case 0:
			newp = std::shared_ptr<Player>(new Player("Goose", start));
			newp->set_player_char("G");
			break;
		case 1:
			newp = std::shared_ptr<Player>(new Player("GRT Bus", start));
			newp->set_player_char("B");
			break;
		case 2:
			newp = std::shared_ptr<Player>(new Player("Tim Hortons Doughnut", start));
			newp->set_player_char("D");
			break;
		case 3:
			newp = std::shared_ptr<Player>(new Player("Professor", start));
			newp->set_player_char("P");
			break;
		case 4:
			newp = std::shared_ptr<Player>(new Player("Student", start));
			newp->set_player_char("S");
			break;
		case 5:
			newp = std::shared_ptr<Player>(new Player("Money", start));
			newp->set_player_char("$");
			break;
		case 6:
			newp = std::shared_ptr<Player>(new Player("Laptop", start));
			newp->set_player_char("L");
			break;
		case 7:
			newp = std::shared_ptr<Player>(new Player("Pink tie", start));
			newp->set_player_char("T");
			break;
		}
		this->players.emplace_back(newp);
		this->turn.push(newp);
	}

}

void Controller::receiveCommand()
{
	field.ShowMap(players);
	std::shared_ptr<Player> cp = turn.front();
	if (turn.size() == 1)
	{
		std::cout << cp->getName() << " was the last player!" << std::endl;
		std::cout << cp->getName() << " was victorious!" << std::endl;
		throw(GameException());
	}
	std::cout << "Player " << cp->getName() << "'s turn" << std::endl;
	cp->show_Player();
	std::cout << "What do you want to do?\n";
	std::string command;
	std::cin >> command;

	if (command == "q" || command == "Q")
	{

		std::cout << "Game quitted!" << std::endl;
		throw(GameException());
	}
	else if (command.substr(0, 1) == "s" || command.substr(0, 1) == "S")
	{
		std::cin >> command;
		std::ofstream fout(command + ".txt");

		saveGame(fout);
		std::cout << "Game saved in " << command << ".txt" << std::endl;
	}
	else if (command.substr(0, 1) == "r" || command.substr(0, 1) == "R")
	{
		if (cp->getJailed())
		{
			std::cout << "Since you are buying coffee, you cannot roll for steps!\n";
			cp->jailing();
			if (cp->get_status())
			{
				std::cout << cp->getName() << " bankrupted!\n";
			}
			else
			{
				turn.push(cp);
			}
			turn.pop();
			std::cout << "Press any key to continue\n";
			_getch();
			return;
		}
		if (test)
		{
			int f = 0;
			int s = 0;
			std::cout << "Please enter the value of your first dice\n";
			std::cin >> f;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.sync();
				std::cout << "Please enter a integer value for your first dice\n";
				std::cin >> f;
			}
			std::cout << "Please enter the value of your second dice\n";
			std::cin >> s;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.sync();
				std::cout << "Please enter a integer value for your second dice\n";
				std::cin >> s;
			}
			cp->Move(f, s);
		}
		else
		{
			cp->Move();
		}
		if (cp->get_status())
		{
			std::cout << cp->getName() << " bankrupted!\n";
			std::cout << cp->getName() << "'s loans will be paid by government,\nbut instead," 
				<< cp->getName() <<"'s properties will be taken away by the government\n";
		}
		else
		{
			turn.push(cp);
		}
		turn.pop();
	}
	else if (command.substr(0, 1) == "m" || command.substr(0, 1) == "M")
	{
		std::cin >> command;
		std::vector<Buyable_Building*> bu = cp->get_Buildings();
		std::vector<Buyable_Building*>::iterator i = bu.begin();
		for (i = bu.begin(); i != bu.end(); ++i)
		{
			if ((*i)->getName() == command)
			{
				cp->Mortgage(*i);
				break;
			}
		}
		if (i == bu.end())
		{
			std::cout << "You do not own building " << command << " and you cannot mortgage it!\n";
		}
	}
	else if (command.substr(0, 1) == "T" || command.substr(0, 1) == "t")
	{
		std::string give;
		std::string want;
		bool giveMoney = false;
		bool wantMoney = false;
		std::cin >> command;
		std::cin >> give;
		std::cin >> want;
		if (command == cp->getName())
		{
			std::cout << "You cannot trade with yourself\n";
		}
		else
		{
			Player* trader = nullptr;
			std::vector<std::shared_ptr<Player>>::iterator i = players.begin();
			for (std::vector<std::shared_ptr<Player>>::iterator i = players.begin(); i != players.end(); ++i)
			{
				if ((*i)->getName() == command)
				{
					trader = (*i).get();
					break;
				}
			}
			if (trader == nullptr)
			{
				std::cout << command << " is not in the game\n";
			}
			else
			{
				if (give[0] >= '0' && give[0] <= '9')
				{
					giveMoney = true;
				}
				if (want[0] >= '0' && want[0] <= '9')
				{
					wantMoney = true;
				}

				if (giveMoney == true && wantMoney == true)
				{
					std::cout << "You cannot trade money with money, it doesn't make sense!\n";
				}
				else if (giveMoney == true)
				{
					int give_thing = stoi(give);
					Buyable_Building* want_thing = nullptr;
					std::vector<Buyable_Building*> bu = trader->get_Buildings();
					std::vector<Buyable_Building*>::iterator i = bu.begin();
					for (i = bu.begin(); i != bu.end(); ++i)
					{
						if ((*i)->getName() == want)
						{
							want_thing = (*i);
							break;
						}
					}
					if (i == bu.end())
					{
						std::cout << trader->getName() << " does not own building " << want << " and you cannot want for it!\n";
					}
					else if (give_thing > cp->get_Money())
					{
						std::cout << "You" << " do not have enough money for the trade\n";
					}
					else if (want_thing->getLevel() > 0)
					{
						std::cout << want << " still has improvements in it!\n";
					}
					else if (want_thing->getLevel() < 0)
					{
						std::cout << want << " has been mortgaged!\n";
					}
					else
					{
						bool agree = false;
						std::cout << "Does " << trader->getName() << " agree?\n";
						std::cout << "Please enter \"Yes\" for agree, otherwise to reject\n";
						std::cin >> command;
						if (command == "Yes")
						{
							agree = true;
						}
						if (agree == true)
						{
							trader->changeMoney(give_thing);
							cp->changeMoney(-give_thing);
							trader->remove_building(want_thing);
							cp->add_building(want_thing);
							want_thing->setOwner(cp.get());
							want_thing->notifyObservers();
							want_thing->notified();
						}
						else
						{
							std::cout << trader->getName() << " rejected the trade\n";
						}
					}
				}
				else if (wantMoney == true)
				{
					int want_thing = stoi(want);
					Buyable_Building* give_thing = nullptr;
					std::vector<Buyable_Building*> bu = cp->get_Buildings();
					std::vector<Buyable_Building*>::iterator i = bu.begin();
					for (i = bu.begin(); i != bu.end(); ++i)
					{
						if ((*i)->getName() == give)
						{
							give_thing = (*i);
							break;
						}
					}
					if (i == bu.end())
					{
						std::cout << "You do not own building " << give << " and you cannot trade it!\n";
					}
					else if (want_thing > trader->get_Money())
					{
						std::cout << trader->getName() << " does not have enough money for the trade\n";
					}
					else if (give_thing->getLevel() > 0)
					{
						std::cout << give << " still has improvements in it!\n";
					}
					else if (give_thing->getLevel() < 0)
					{
						std::cout << give << " has been mortgaged!\n";
					}
					else
					{
						bool agree = false;
						std::cout << "Does " << trader->getName() << " agree?\n";
						std::cout << "Please enter \"Yes\" for agree, otherwise to reject\n";
						std::cin >> command;
						if (command == "Yes")
						{
							agree = true;
						}
						if (agree == true)
						{
							trader->changeMoney(-want_thing);
							cp->changeMoney(want_thing);
							cp->remove_building(give_thing);
							trader->add_building(give_thing);
							give_thing->setOwner(trader);
							give_thing->notifyObservers();
							give_thing->notified();
						}
						else
						{
							std::cout << trader->getName() << " rejected the trade\n";
						}
					}
				}
				else
				{
					Buyable_Building* give_thing = nullptr;
					Buyable_Building* want_thing = nullptr;
					std::vector<Buyable_Building*> bu = trader->get_Buildings();
					std::vector<Buyable_Building*>::iterator i = bu.begin();
					for (i = bu.begin(); i != bu.end(); ++i)
					{
						if ((*i)->getName() == want)
						{
							want_thing = (*i);
							break;
						}
					}
					std::vector<Buyable_Building*> gi = cp->get_Buildings();
					std::vector<Buyable_Building*>::iterator j = gi.begin();
					for (j = gi.begin(); j != gi.end(); ++j)
					{
						if ((*j)->getName() == give)
						{
							give_thing = (*j);
							break;
						}
					}
					if (i == bu.end())
					{
						std::cout << trader->getName() << " does not own building " << want << " and you cannot want for it!\n";
					}
					else if (j == gi.end())
					{
						std::cout << cp->getName() << " does not own building " << give << " and you cannot trade it!\n";
					}
					else if (want_thing->getLevel() > 0)
					{
						std::cout << want << " still has improvements in it!\n";
					}
					else if (give_thing->getLevel() > 0)
					{
						std::cout << give << " still has improvements in it!\n";
					}
					else if (want_thing->getLevel() < 0)
					{
						std::cout << want << " has been mortgaged!\n";
					}
					else if (give_thing->getLevel() < 0)
					{
						std::cout << give << " has been mortgaged!\n";
					}
					else
					{
						bool agree = false;
						std::cout << "Does " << trader->getName() << " agree?\n";
						std::cout << "Please enter \"Yes\" for agree, otherwise to reject\n";
						std::cin >> command;
						if (command == "Yes")
						{
							agree = true;
						}
						if (agree == true)
						{
							trader->remove_building(want_thing);
							cp->add_building(want_thing);
							want_thing->setOwner(cp.get());
							want_thing->notifyObservers();
							want_thing->notified();

							cp->remove_building(give_thing);
							trader->add_building(give_thing);
							give_thing->setOwner(trader);
							give_thing->notifyObservers();
							give_thing->notified();
							std::cout << "Trade finished!\n";
						}
						else
						{
							std::cout << trader->getName() << " rejected the trade\n";
						}
					}
				}
			}
		}
		
	}
	else if (command.size() >= 2 && (command.substr(1, 1) == "s" || 
		command.substr(1, 1) == "S") && (command.substr(0, 1) == "A" || command.substr(0, 1) == "a"))
	{
		cp->show_Player();
	}
	else if (command.size() >= 2 && (command.substr(1, 1) == "l" || 
	command.substr(1, 1) == "L") && (command.substr(0, 1) == "A" || command.substr(0, 1) == "a"))
	{
		for (std::vector<std::shared_ptr<Player>>::iterator i = players.begin(); i != players.end(); ++i)
		{
			(*i)->show_Player();
		}
	}
	else if (command.substr(0, 1) == "u" || command.substr(0, 1) == "U")
	{
		std::cin >> command;
		std::vector<Buyable_Building*> bu = cp->get_Buildings();
		std::vector<Buyable_Building*>::iterator i = bu.begin();
		for (i = bu.begin(); i != bu.end(); ++i)
		{
			if ((*i)->getName() == command)
			{
				cp->UnMortgage(*i);
				break;
			}
		}
		if (i == bu.end())
		{
			std::cout << "You do not own building " << command << " and you cannot unmortgage it!\n";
		}
	}
	else if (command.substr(0, 1) == "i" || command.substr(0, 1) == "I")
	{
		std::cin >> command;
		std::vector<Buyable_Building*> bu = cp->get_Buildings();
		std::vector<Buyable_Building*>::iterator i = bu.begin();
		for (i = bu.begin(); i != bu.end(); ++i)
		{
			if ((*i)->getName() == command)
			{
				std::cin >> command;
				if (command.substr(0, 1) == "B" || command.substr(0, 1) == "b")
				{
					(*i)->LevelUp();
					break;
				}
				else if (command.substr(0, 1) == "S" || command.substr(0, 1) == "s")
				{
					(*i)->LevelDown();
					break;
				}
				else
				{
					std::cout << "Your command is too vague!\n";
					break;
				}
			}
		}
		if (i == bu.end())
		{
			std::cout << "You do not own building " << command << " so you cannot manage its improvements!\n";
			std::cin >> command;
		}
	}
	else
	{
		std::cout << "Your command is too vague, please try again!\n";
	}

	
	std::cout << "Press any key to continue\n";
	_getch();
}


