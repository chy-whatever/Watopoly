#ifndef PLAYER_INFO_EXCEPTION_H
#define PLAYER_INFO_EXCEPTION_H
#include "GameException.h"
#include <string>

class PlayerInfoException : public GameException {
  public:
    std::string message() override {
        return "Invalid Input for PlayerInfo";
    }
};

#endif
