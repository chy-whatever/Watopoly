#include "GameField.h"
#include "Player.h"
#include "Non-Property.h"
#include "Buyable.h"
#include <iomanip>

std::vector<std::shared_ptr<Grid>>& Game_Field::getMap()
{
    return field;
}

void Game_Field::loadBoard(std::ifstream& fin)
{
    InitBoard();
}

void Game_Field::saveBoard(std::ofstream& fout)
{
    for (std::vector<std::shared_ptr<Grid>>::iterator i = field.begin(); i != field.end(); ++i)
    {
        if ((*i)->getBuyable())
        {
            fout << (*i)->getName() << " ";
            if (dynamic_cast<Buyable_Building*>((*i).get())->getOwner() == nullptr)
            {
                fout << "nullptr" << " ";
            }
            else
            {
                fout << dynamic_cast<Buyable_Building*>((*i).get())->getOwner()->getName() << " ";
            }
            fout << dynamic_cast<Buyable_Building*>((*i).get())->getLevel() << "\n";
        }
    }
}

void Game_Field::InitBoard()
{
    int fNum = 40;
    for (int i = 0; i < fNum; i++)
    {
        switch (i)
        {
        case 0:
            field.emplace_back(std::shared_ptr<Grid>(new Non_Property_Building(i, "OSAP")));
            field.at(i)->setBuyable(false);
            break;
        case 1:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(40, 2, 50, i, "AL")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 2:
            field.emplace_back(std::shared_ptr<Grid>(new Non_Property_Building(i, "SLC")));
            field.at(i)->setBuyable(false);
            break;
        case 3:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(60, 4, 50, i, "ML")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 4:
            field.emplace_back(std::shared_ptr<Grid>(new Non_Property_Building(i, "Tuition")));
            field.at(i)->setBuyable(false);
            break;
        case 5:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(200, 25, 0, i, "MKV")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Accumulative");
            break;
        case 6:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(100, 6, 50, i, "ECH")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 7:
            field.emplace_back(std::shared_ptr<Grid>(new Non_Property_Building(i, "NeedlesHall")));
            field.at(i)->setBuyable(false);
            break;
        case 8:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(100, 6, 50, i, "PAS")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 9:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(120, 8, 50, i, "HH")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 10:
            field.emplace_back(std::shared_ptr<Grid>(new Non_Property_Building(i, "DCTims")));
            field.at(i)->setBuyable(false);
            break;
        case 11:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(140, 10, 100, i, "RCH")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 12:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(150, 0, 0, i, "PAC")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Accumulative");
            break;
        case 13:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(140, 10, 100, i, "DWE")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 14:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(160, 12, 100, i, "CPH")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 15:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(200, 25, 0, i, "UWP")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Accumulative");
            break;
        case 16:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(180, 14, 100, i, "LHI")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 17:
            field.emplace_back(std::shared_ptr<Grid>(new Non_Property_Building(i, "SLC")));
            field.at(i)->setBuyable(false);
            break;
        case 18:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(180, 14, 100, i, "BMH")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 19:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(200, 16, 100, i, "OPT")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 20:
            field.emplace_back(std::shared_ptr<Grid>(new Non_Property_Building(i, "Goose")));
            field.at(i)->setBuyable(false);
            break;
        case 21:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(220, 18, 150, i, "EV1")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 22:
            field.emplace_back(std::shared_ptr<Grid>(new Non_Property_Building(i, "NeedlesHall")));
            field.at(i)->setBuyable(false);
            break;
        case 23:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(220, 18, 150, i, "EV2")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 24:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(240, 20, 150, i, "EV3")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 25:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(200, 25, 0, i, "V1")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Accumulative");
            break;
        case 26:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(260, 22, 150, i, "PHYS")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 27:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(260, 22, 150, i, "B1")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 28:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(150, 0, 0, i, "CIF")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Accumulative");
            break;
        case 29:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(280, 24, 150, i, "B2")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 30:
            field.emplace_back(std::shared_ptr<Grid>(new Non_Property_Building(i, "GoTims")));
            field.at(i)->setBuyable(false);
            break;
        case 31:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(300, 26, 200, i, "EIT")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 32:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(300, 26, 200, i, "ESC")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 33:
            field.emplace_back(std::shared_ptr<Grid>(new Non_Property_Building(i, "SLC")));
            field.at(i)->setBuyable(false);
            break;
        case 34:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(320, 28, 200, i, "C2")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 35:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(200, 25, 0, i, "REV")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Accumulative");
            break;
        case 36:
            field.emplace_back(std::shared_ptr<Grid>(new Non_Property_Building(i, "NeedlesHall")));
            field.at(i)->setBuyable(false);
            break;
        case 37:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(350, 35, 200, i, "MC")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;
        case 38:
            field.emplace_back(std::shared_ptr<Grid>(new Non_Property_Building(i, "Coop")));
            field.at(i)->setBuyable(false);
            break;
        case 39:
            field.emplace_back(std::shared_ptr<Grid>(new Buyable_Building(400, 50, 200, i, "DC")));
            field.at(i)->setBuyable(true);
            dynamic_cast<Buyable_Building*>(field.at(i).get())->setKind("Academic");
            break;

        default:
            break;
        }
    }

    for (int i = 0; i < fNum; i++)
    {
        switch (i)
        {
        case 0:
            break;
        case 1:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(3).get()));
            break;
        case 2:
            break;
        case 3:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(1).get()));
            break;
        case 4:
            break;
        case 5:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(15).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(25).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(35).get()));
            break;
        case 6:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(8).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(9).get()));
            break;
        case 7:
            break;
        case 8:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(6).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(9).get()));
            break;
        case 9:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(6).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(8).get()));
            break;
        case 10:
            break;
        case 11:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(13).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(14).get()));
            break;
        case 12:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(28).get()));
            break;
        case 13:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(11).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(14).get()));
            break;
        case 14:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(13).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(11).get()));
            break;
        case 15:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(5).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(25).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(35).get()));
            break;
        case 16:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(18).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(19).get()));
            break;
        case 17:
            break;
        case 18:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(16).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(19).get()));
            break;
        case 19:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(18).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(16).get()));
            break;
        case 20:
            break;
        case 21:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(23).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(24).get()));
            break;
        case 22:
            break;
        case 23:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(21).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(24).get()));
            break;
        case 24:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(23).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(21).get()));
            break;
        case 25:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(5).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(15).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(35).get()));
            break;
        case 26:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(27).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(29).get()));
            break;
        case 27:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(26).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(29).get()));
            break;
        case 28:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(12).get()));
            break;
        case 29:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(27).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(26).get()));
            break;
        case 30:
            break;
        case 31:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(32).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(34).get()));
            break;
        case 32:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(31).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(34).get()));
            break;
        case 33:
            break;
        case 34:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(32).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(31).get()));
            break;
        case 35:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(5).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(15).get()));
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(25).get()));
            break;
        case 36:
            break;
        case 37:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(39).get()));
            break;
        case 38:
            break;
        case 39:
            dynamic_cast<Buyable_Building*>(field.at(i).get())->
                attach_neighbours(dynamic_cast<Buyable_Building*>(field.at(37).get()));
            break;

        default:
            break;
        }
    }

    std::shared_ptr<Grid> t = std::shared_ptr<Grid>(new Non_Property_Building(2, "SLC", field.at(0).get(), field.at(10).get()));
    field.at(2).swap(t);
    field.at(2)->setBuyable(false);

    t = std::shared_ptr<Grid>(new Non_Property_Building(17, "SLC", field.at(0).get(), field.at(10).get()));
    field.at(17).swap(t);
    field.at(17)->setBuyable(false);

    t = std::shared_ptr<Grid>(new Non_Property_Building(30, "GoTims", field.at(0).get(), field.at(10).get()));
    field.at(30).swap(t);
    field.at(30)->setBuyable(false);

    t = std::shared_ptr<Grid>(new Non_Property_Building(33, "SLC", field.at(0).get(), field.at(10).get()));
    field.at(33).swap(t);
    field.at(33)->setBuyable(false);

    field.at(0)->setPrev(field.at(39).get());
    field.at(0)->setNext(field.at(1).get());
    field.at(39)->setPrev(field.at(38).get());
    field.at(39)->setNext(field.at(0).get());
    for (int i = 1; i < 39; i++)
    {
        field.at(i)->setPrev(field.at(i - 1).get());
        field.at(i)->setNext(field.at(i + 1).get());

    }
}

void printplayer(Grid* g, std::vector<std::shared_ptr<Player>>& p) {
    int index = 1;
    int times = 0;
    for (std::vector<std::shared_ptr<Player>>::iterator i = p.begin(); i != p.end(); i++) {
        if ((*i)->get_position()->getName() == g->getName()) {
            std::cout << (*i)->get_player_char();
            index = 0;
            times++;
        }
        index++;
    }
    while (times <= 6) {
        std::cout << " ";
        times++;
    }
   
}

void Game_Field::ShowMap(std::vector<std::shared_ptr<Player>>& p)
{
    // line 1
    std::cout << "|---------------------------------------------------------------------------------------|" << std::endl;
    // line 2
    for (int i = 20; i < 31; i++) {
        if (field.at(i)->getName() == "Goose") {
            std::cout << "|Goose  ";
        }
        else if (field.at(i)->getName() == "NeedlesHall") {
            std::cout << "|NEEDLES";
        }
        else if (field.at(i)->getName() == "V1") {
            std::cout << "|V1     ";
        }
        else if (field.at(i)->getName() == "CIF") {
            std::cout << "|CIF    ";
        }
        else if (field.at(i)->getName() == "GoTims") {
            std::cout << "|GO TO  ";
        }
        else {
            std::cout << "|";
            std::cout << dynamic_cast<Buyable_Building*>(field.at(i).get())->getLevel();
            std::cout << "      ";
        }
    }
    std::cout << "|" << std::endl;
    // line 3
    for (int i = 20; i < 31; ++i) {
        if (field.at(i)->getName() == "Goose") {
            std::cout << "|Nesting";
        }
        else if (field.at(i)->getName() == "NeedlesHall") {
            std::cout << "|HALL   ";
        }
        else if (field.at(i)->getName() == "V1") {
            std::cout << "|       ";
        }
        else if (field.at(i)->getName() == "CIF") {
            std::cout << "|       ";
        }
        else if (field.at(i)->getName() == "GoTims") {
            std::cout << "|TIMS   ";
        }
        else {
            std::cout << "|-------";
        }
    }
    std::cout << "|" << std::endl;
    // line 4
    for (int i = 20; i < 31; ++i) {
        if ((field.at(i)->getName() != "Goose") && (field.at(i)->getName() != "NeedlesHall") &&
            (field.at(i)->getName() != "V1") && (field.at(i)->getName() != "CIF")
            && (field.at(i)->getName() != "GoTims")) {
            std::cout << "|" << std::setfill(' ') << std::setw(7) << field.at(i)->getName();
        }
        else {
            std::cout << "|       ";
        }
    }
    std::cout << "|" << std::endl;
    // line 5 : display players
    for (int i = 20; i < 31; ++i) {
        std::cout << "|";
        printplayer(field.at(i).get(), p);

    }
    std::cout << "|" << std::endl;
    // line 6 
    for (int i = 0; i < 11; ++i) {
        std::cout << "|-------";
    }
    std::cout << "|" << std::endl;
    // line 7
    std::cout << "|";
    std::cout << dynamic_cast<Buyable_Building*>(field.at(19).get())->getLevel();
    std::cout << "      ";
    std::cout << "|                                                                       |";
    std::cout << dynamic_cast<Buyable_Building*>(field.at(31).get())->getLevel();
    std::cout << "      ";
    std::cout << "|" << std::endl;
    // line 8
    std::cout << "|-------|                                                                       |-------|" << std::endl;
    // line 9
    std::cout << "|OPT    |                                                                       |EIT    |" << std::endl;
    // line 10 : display players
    std::cout << "|";
    printplayer(field.at(19).get(), p);
    std::cout << "|                                                                       |";
    printplayer(field.at(31).get(), p);
    std::cout << "|" << std::endl;
    // line 11
    std::cout << "|_______|                                                                       |_______|" << std::endl;
    // line 12 ---18,32
    std::cout << "|";
    std::cout << dynamic_cast<Buyable_Building*>(field.at(18).get())->getLevel();
    std::cout << "      ";
    std::cout << "|                                                                       |";
    std::cout << dynamic_cast<Buyable_Building*>(field.at(32).get())->getLevel();
    std::cout << "      ";
    std::cout << "|" << std::endl;
    // line 13
    std::cout << "|-------|                                                                       |-------|" << std::endl;
    // line 14
    std::cout << "|BMH    |                                                                       |ESC    |" << std::endl;
    // line 15 : display players 18, 32
    std::cout << "|";
    printplayer(field.at(18).get(), p);
    std::cout << "|                                                                       |";
    printplayer(field.at(32).get(), p);
    std::cout << "|" << std::endl;
    // line 16
    std::cout << "|_______|                                                                       |_______|" << std::endl;
    // line 17
    std::cout << "|SLC    |                                                                       |SLC    |" << std::endl;
    // line 18 
    std::cout << "|       |                                                                       |       |" << std::endl;
    // line 19
    std::cout << "|       |                                                                       |       |" << std::endl;
    // line 30 : display players 17,33
    std::cout << "|";
    printplayer(field.at(17).get(), p);
    std::cout << "|                                                                       |";
    printplayer(field.at(32).get(), p);
    std::cout << "|" << std::endl;
    // line 31
    std::cout << "|_______|                                                                       |_______|" << std::endl;
    // line 32
    std::cout << "|";
    std::cout << dynamic_cast<Buyable_Building*>(field.at(16).get())->getLevel();
    std::cout << "      ";
    std::cout << "|                                                                       |";
    std::cout << dynamic_cast<Buyable_Building*>(field.at(34).get())->getLevel();
    std::cout << "      ";
    std::cout << "|" << std::endl;
    // line 33
    std::cout << "|-------|                                                                       |-------|" << std::endl;
    // line 34
    std::cout << "|LHI    |                                                                       |C2     |" << std::endl;
    // line 35 display players 16, 34
    std::cout << "|";
    printplayer(field.at(16).get(), p);
    std::cout << "|                                                                       |";
    printplayer(field.at(34).get(), p);
    std::cout << "|" << std::endl;
    // line 31
    std::cout << "|_______|            |---------------------------------------------|            |_______|" << std::endl;
    // line 32
    std::cout << "|UWP    |            | #   #  ##  #####  ###  ###   ###  #   #   # |            |REV    |" << std::endl;
    // line 33
    std::cout << "|       |            | #   # #  #   #   #   # #  # #   # #   #   # |            |       |" << std::endl;
    // line 34
    std::cout << "|       |            | # # # ####   #   #   # ###  #   # #    # #  |            |       |" << std::endl;
    // line 35 displayer players 15, 35
    std::cout << "|";
    printplayer(field.at(15).get(), p);
    std::cout << "|            | # # # #  #   #   #   # #    #   # #     #   |            |";
    printplayer(field.at(35).get(), p);
    std::cout << "|" << std::endl;
    // line 36
    std::cout << "|_______|            | ##### #  #   #    ###  #     ###  ####  #   |            |_______|" << std::endl;
    // line 37 cout improve
    std::cout << "|";
    std::cout << dynamic_cast<Buyable_Building*>(field.at(15).get())->getLevel();
    std::cout << "      ";
       std::cout << "|            |_____________________________________________|            |NEEDLES|" << std::endl;
    //line 38
    std::cout << "|-------|                                                                       |HALL   |" << std::endl;
    // line 39
    std::cout << "|CPH    |                                                                       |       |" << std::endl;
    // line 40 display player
    std::cout << "|";
    printplayer(field.at(14).get(), p);
    std::cout << "|                                                                       |";
    printplayer(field.at(36).get(), p);
    std::cout << "|" << std::endl;
    // line 41
    std::cout << "|_______|                                                                       |_______|" << std::endl;
    // line 42
    std::cout << "|";
    std::cout << dynamic_cast<Buyable_Building*>(field.at(13).get())->getLevel();
    std::cout << "      ";
    std::cout << "|                                                                       |";
    std::cout << dynamic_cast<Buyable_Building*>(field.at(37).get())->getLevel();
    std::cout << "      ";
    std::cout << "|" << std::endl;
    // line 43 
    std::cout << "|-------|                                                                       |-------|" << std::endl;
    // line 44
    std::cout << "|DWE    |                                                                       |MC     |" << std::endl;
    // line 45 : display players13, 37
    std::cout << "|";
    printplayer(field.at(13).get(), p);
    std::cout << "|                                                                       |";
    printplayer(field.at(37).get(), p);
    std::cout << "|" << std::endl;
    // line 46
    std::cout << "|_______|                                                                       |_______|" << std::endl;
    // line 47
    std::cout << "|PAC    |                                                                       |COOP   |" << std::endl;
    // line 48
    std::cout << "|       |                                                                       |FEE    |" << std::endl;
    // line 49
    std::cout << "|       |                                                                       |       |" << std::endl;
    // line 50 : ----print
    std::cout << "|";
    printplayer(field.at(12).get(), p);
    std::cout << "|                                                                       |";
    printplayer(field.at(38).get(), p);
    std::cout << "|" << std::endl;
    // line 51
    std::cout << "|_______|                                                                       |_______|" << std::endl;
    // line 52-----improvement

    std::cout << "|";
    std::cout << dynamic_cast<Buyable_Building*>(field.at(11).get())->getLevel();
    std::cout << "      ";
    std::cout << "|                                                                       |";
    std::cout << dynamic_cast<Buyable_Building*>(field.at(39).get())->getLevel();
    std::cout << "      ";
    std::cout << "|" << std::endl;
    // line 53
    std::cout << "|-------|                                                                       |-------|" << std::endl;
    // line 54
    std::cout << "|RCH    |                                                                       |DC     |" << std::endl;
    // line 55 : ------printplayer
    std::cout << "|";
    printplayer(field.at(11).get(), p);
    std::cout << "|                                                                       |";
    printplayer(field.at(39).get(), p);
    std::cout << "|" << std::endl;
    // line 56
    std::cout << "|_______|_______________________________________________________________________|_______|" << std::endl;
    // line 57
    for (int i = 10; i >= 0; --i) {
        if (field.at(i)->getName() == "DCTims") {
            std::cout << "|DC Tims";
        }
        else if (field.at(i)->getName() == "NeedlesHall") {
            std::cout << "|NEEDLES";
        }
        else if (field.at(i)->getName() == "MKV") {
            std::cout << "|MKV    ";
        }
        else if (field.at(i)->getName() == "Tuition") {
            std::cout << "|TUITION";
        }
        else if (field.at(i)->getName() == "SLC") {
            std::cout << "|SLC    ";
        }
        else if (field.at(i)->getName() == "OSAP") {
            std::cout << "|COLLECT";
        }
        else {
            std::cout << "|";
            std::cout << dynamic_cast<Buyable_Building*>(field.at(i).get())->getLevel();
            std::cout << "      ";
        }
    }
    std::cout << "|" << std::endl;
    // line 58
    for (int i = 10; i >= 0; --i) {
        if (field[i]->getName() == "DCTims") {
            std::cout << "|Line   ";
        }
        else if (field[i]->getName() == "NeedlesHall") {
            std::cout << "|HALL   ";
        }
        else if (field[i]->getName() == "MKV" && field[i]->getName() == "Tuition" && field[i]->getName() == "SLC") {
            std::cout << "|       ";
        }
        else if (field[i]->getName() == "OSAP") {
            std::cout << "|OSAP   ";
        }
        else {
            std::cout << "|-------";
        }
    }
    std::cout << "|" << std::endl;
    // line 59
    for (int i = 10; i >= 0; --i) {
        if (field.at(i)->getName() != "DCTims" && field.at(i)->getName() != "NeedlesHall" &&
            field.at(i)->getName() != "MKV" && field.at(i)->getName() != "Tuition" && field.at(i)->getName() != "SLC"
            && field.at(i)->getName() != "OSAP") {
            std::cout << "|" << std::setfill(' ') << std::setw(7) << field.at(i)->getName();
        }
        else {
            std::cout << "|       ";
        }
    }
    std::cout << "|" << std::endl;
    //line 60
    for (int i = 10; i >= 0; --i) {
        std::cout << "|";
        //print players
        printplayer(field.at(i).get(), p);
    }
    std::cout << "|" << std::endl;
    // line 61
    for (int i = 0; i < 11; ++i) {
        std::cout << "|_______";
    }
    std::cout << "|" << std::endl;
}

