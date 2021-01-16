#ifndef PLAYER_CHAR_EXCEPTION_H
#define PLAYER_CHAR_EXCEPTION_H
#include "GameException.h"
#include <string>

class PlayerCharException: public GameException {
  public:
    std::string message() override {
        return "Invalid Input for PlayerChar";
    }
};

#endif
