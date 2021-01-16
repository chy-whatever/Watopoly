#include <string>
#include <fstream>
#include <memory>
#include <vector>
#include "Buyable.h"
#include "Non-Property.h"
#include "Player.h"
#include "GameField.h"
#include "GameException.h"
#include "PlayerCharException.h"
#include "PlayerInfoException.h"
#include "TimCupsException.h"
#include "PlayerMoneyException.h"
#include "PlayerPosException.h"
#include "PlayerJailedException.h"
#include <queue>

class Player;
class Game_Field;

class Controller
{
	std::string command;
	Game_Field field;
	std::vector<std::shared_ptr<Player>> players;
	std::queue<std::shared_ptr<Player>> turn;
	bool test;
public:
	void setTest(bool t);
	void loadGame(std::ifstream& fin); 
	void saveGame(std::ofstream& fout); 
	void InitGame();
	void receiveCommand();
};
