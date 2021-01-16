#include "Grid.h"

void Grid::setBuyable(bool b)
{
    buyable = b;
}

bool Grid::getBuyable()
{
    return buyable;
}

Grid::Grid(int position, std::string name, Grid* prev, Grid* next) :
    position(position), name(name), prev(prev), next(next) {}

std::string Grid::getName() {
    return this->name;
}

int Grid::getPosition() {
    return this->position;
}

Grid* Grid::getPrev() {
    return this->prev;
}

Grid* Grid::getNext() {
    return this->next;
}

void Grid::setPrev(Grid* g) {
    this->prev = g;
}

void Grid::setNext(Grid* g) {
    this->next = g;
}
