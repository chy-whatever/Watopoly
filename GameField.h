#include <vector>
#include <fstream>
#include <memory>
#include <fstream>
class Grid;
class Player;

class Game_Field
{
public:
	std::vector<std::shared_ptr<Grid>> field;
	std::vector<std::shared_ptr<Grid>> & getMap();
	void loadBoard(std::ifstream& fin);
	void saveBoard(std::ofstream& fout);
	void InitBoard();
	void ShowMap(std::vector<std::shared_ptr<Player>>& p);
};
