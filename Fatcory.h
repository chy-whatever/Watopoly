#include "Products.h"

class Factory
{
public:
	Goose* produceGoose();//��
	Tims* produceTims();//TIMs
	Go_Tims* produceGoTims(Grid* TIMS);//ȥTIMS
	Get_Funds* produceGetFunds();//OSAP\NEEDLES
	Get_Funds* produceGetFunds(int f);//OSAP\NEEDLES
	Get_Move* produceGetMove(Grid* OSAP, Grid* TIMS);//SLC
};