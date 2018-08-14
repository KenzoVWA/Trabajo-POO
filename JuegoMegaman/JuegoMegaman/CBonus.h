using namespace System;
using namespace System::Drawing;
#include <math.h>
class CBonus
{
private:
	int X, Y;
	int dX, dY;
    int Indice;
	int TipoMovimiento;
	bool Estado;

	CMovimiento **Vec;
	int NroMovimiento;

public:
	CBonus(int X, int Y, int dye);
	~CBonus();
	void Set_Movimiento(int TipoMovimiento);
	void Dibujar(Graphics ^g, Bitmap ^i, int largof);

	void Set_Estado(bool Estado);
	bool Get_Estado();
	int get_tipomovimiento();

	bool Contiene(int aX, int aY);
	bool HayColision(int xa, int ya,int anchoa, int largoa, int xb, int yb,int anchob, int largob);
	int Get_X();
	int Get_Y();
	int Get_Ancho();
	int Get_Largo();
};

CBonus::CBonus(int X, int Y, int dye)
{
	this->X = X;
	this->Y = Y;
	dY=dye;
	this->Estado = true;

	Random ^r=gcnew Random(DateTime::Now.Ticks); int f=r->Next(1,3);
	f==1?Set_Movimiento(0):Set_Movimiento(1);
}

CBonus::~CBonus()
{
}

void CBonus::Set_Movimiento(int TipoMovimiento)
{
	this->Indice = 0;
	this->TipoMovimiento = TipoMovimiento;

	switch (TipoMovimiento)
	{
		case 0: 

			NroMovimiento = 2;
			Vec = new CMovimiento*[NroMovimiento];

			Vec[0] = new CMovimiento(18, 2, 0, 5, 10, 50);
			Vec[1] = new CMovimiento(786, 2, 0, 5, 10, 50);

			this->dX = 0;
			this->dY = 5;
		break;

		case 1:

			NroMovimiento = 1;
			Vec = new CMovimiento*[NroMovimiento];

			Vec[0] = new CMovimiento(830,307,0,5,12,66);
			
			

			this->dX = 0;
			this->dY = 5;
		break;
	}
}

void CBonus::Dibujar(Graphics ^g, Bitmap ^i, int largof)
{
	Rectangle origen = Rectangle(Vec[Indice]->Get_X(), 
		                         Vec[Indice]->Get_Y(),
		                         Vec[Indice]->Get_Ancho(), 
		                         Vec[Indice]->Get_Largo());

	Rectangle destino = Rectangle(X, 
							      Y-Vec[Indice]->Get_Largo(), 
								 30, 
								  50);
	g->DrawImage(i, destino, origen, GraphicsUnit::Pixel);

	X += dX;
	Y += dY;

	if(Y+Vec[Indice]->Get_Largo() > largof || Y+Vec[Indice]->Get_Largo()+dY> largof){
		Set_Estado(false);
	}
	if (Indice == NroMovimiento - 1)
			Indice = 0;
	else
		Indice++;

}

bool CBonus::Contiene(int aX, int aY)
{
	return aX >= X && aX <= X + Vec[Indice]->Get_Ancho() &&  
		   aY >= Y && aY <= Y + Vec[Indice]->Get_Largo();
}

bool CBonus::HayColision(int xa, int ya,int anchoa, int largoa, int xb, int yb,int anchob, int largob){
	int cxa=xa+(anchoa/2);
	int cya=ya+(largoa/2);
	int cxb=xb+(anchob/2);
	int cyb=yb+(largob/2);

	int distanciaC=(int)(sqrt((cxa-cxb)*(cxa-cxb)*1.0+(cya-cyb)*(cya-cyb)*1.0));

	if(distanciaC<=((anchoa)+(anchob)))
		return true;
	return false;

}

void CBonus::Set_Estado(bool Estado)
{
	this->Estado = Estado;
}

bool CBonus::Get_Estado()
{
	return this->Estado;
}

int CBonus::get_tipomovimiento()
{
	return this->TipoMovimiento;
}
int CBonus::Get_X()
{
	return this->X;
}

int CBonus::Get_Y()
{
	return this->Y;
}

int CBonus::Get_Ancho()
{
	return this->Vec[Indice]->Get_Ancho();
}

int CBonus::Get_Largo()
{
	return this->Vec[Indice]->Get_Largo();
}
