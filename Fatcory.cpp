#include "Fatcory.h"

Goose* Factory::produceGoose()
{
    return new Goose();
}

Tims* Factory::produceTims()
{
    return new Tims();
}

Go_Tims* Factory::produceGoTims(Grid* TIMS)
{
    return new Go_Tims(TIMS);
}

Get_Funds* Factory::produceGetFunds()
{
    return new Get_Funds();
}

Get_Funds* Factory::produceGetFunds(int f)
{
    return new Get_Funds(f);
}

Get_Move* Factory::produceGetMove(Grid* OSAP, Grid* TIMS)
{
    return new Get_Move(OSAP, TIMS);
}
