#include "Products.h"

class Factory
{
public:
	Goose* produceGoose();//¶ì
	Tims* produceTims();//TIMs
	Go_Tims* produceGoTims(Grid* TIMS);//È¥TIMS
	Get_Funds* produceGetFunds();//OSAP\NEEDLES
	Get_Funds* produceGetFunds(int f);//OSAP\NEEDLES
	Get_Move* produceGetMove(Grid* OSAP, Grid* TIMS);//SLC
};