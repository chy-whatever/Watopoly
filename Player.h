#include <iostream>
#include <string>
#include <vector>

class Buyable_Building;
class Grid;

class Player
{
	std::string name;
	std::vector<Buyable_Building*> buildings;
	int money;
	int itemNum;
	bool status;
	int moveNum;
	Grid* position;
	std::string player_char;
	bool jailed;
	int jailed_turn;
public:
	void Mortgage(Buyable_Building*);
	void UnMortgage(Buyable_Building*);
	std::string get_player_char();
	void set_player_char(std::string);
	void position_on(Grid*);
	Player(std::string name, Grid* position, int money = 1500, int itemNum = 0, bool jailed = false, int jailed_turn = 0, bool status = false, int moveNum = 0);
	std::string getName();
	void show_Player();
	std::vector<Buyable_Building*> get_Buildings();
	void add_building(Buyable_Building*);
	void remove_building(Buyable_Building*);
	int get_Money();
	void changeMoney(int num);//money += num
	int get_itemNum();
	void changeItem(int num);//itemNum += num
	bool get_status();
	int get_moveNum();
	Grid* get_position();
	void bankrupt();
	void Move();
	void Move(int fst, int snd);

	void Move_to(Grid*);

	bool getJailed();
	int getJailedTurn();
	void jailing();
};
