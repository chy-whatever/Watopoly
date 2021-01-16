#include <iostream>
#include "Controller.h"
#include "GameException.h"
#include <string>
#include <fstream>

int main()
{
    Controller controller;
    std::cout << "New Game or Load Game?\n";
    std::cout << "Please type n for New Game and type l for Load Game\n";
    std::string command;
    std::cin >> command;
    while (command != "n" && command != "l")
    {
        std::cout << "Please type n for New Game and type l for Load Game\n";
        std::cout << "New Game or Load Game?\n";
        std::cin >> command;
    }
    if (command == "n")
    {
        controller.InitGame();
    }
    else
    {
        std::cout << "Please enter your wanted saving\n";
        char FilePath[1024];
        std::cin >> FilePath;
        std::ifstream saving(FilePath);
        while (!saving.is_open())
        {
            std::cout << "The wanted saving cannot be opened or do not exist\n";
            std::cout << "Please enter your wanted saving again\n";
            std::cin >> FilePath;
            std::ifstream saving(FilePath);
        }
        controller.loadGame(saving);
    }
    controller.setTest(false);

    std::cout << "Test?\n";
    std::cin >> command;
    if (command == "t")
    {
        controller.setTest(true);
    }

    while (true)
    {
        try {
            controller.receiveCommand();
        }
        catch (GameException& e)
        {
            std::cout << "Game ended\n";
            break;
        }
    }
}
