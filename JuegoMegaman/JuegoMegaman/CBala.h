using namespace System;
using namespace System::Drawing;

class CBala
{
private:
	int X, Y;
	int dX, dY;
	int Direccion, Indice;
	int DesviacionX;
	int TipoMovimiento;
	bool Estado;

	CMovimiento **Vec;
	int NroMovimiento;

public:
	CBala(int X, int Y, int Direccion);
	~CBala();
	void Set_Movimiento(int TipoMovimiento);
	void Dibujar(Graphics ^g, Bitmap ^i);

	void Set_Estado(bool Estado);
	bool Get_Estado();

	int Get_X();
	int Get_Y();
	int Get_Ancho();
	int Get_Largo();
};

CBala::CBala(int X, int Y, int Direccion)
{
	this->X = X;
	this->Y = Y;
	this->Direccion = Direccion;
	this->Estado = true;

	Set_Movimiento(0);
}

CBala::~CBala()
{
}

void CBala::Set_Movimiento(int TipoMovimiento)
{
	this->Indice = 0;
	this->TipoMovimiento = TipoMovimiento;

	switch (TipoMovimiento)
	{
		case 0: // MOVER

			NroMovimiento = 1;
			Vec = new CMovimiento*[NroMovimiento];

			Vec[0] = new CMovimiento(815, 571, 10, 0, 46, 42);

			this->dX = 7;
			this->dY = 0;
			this->DesviacionX = 34;
		break;
	
	}
}

void CBala::Dibujar(Graphics ^g, Bitmap ^i)
{
	Rectangle origen = Rectangle(Vec[Indice]->Get_X(), 
		                         Vec[Indice]->Get_Y(),
		                         Vec[Indice]->Get_Ancho(), 
		                         Vec[Indice]->Get_Largo());

	Rectangle destino = Rectangle(Direccion == 1 ? X : X + DesviacionX, 
							      Y - Vec[Indice]->Get_Largo() , 
								  Direccion * Vec[Indice]->Get_Ancho(), 
								  Vec[Indice]->Get_Largo());

	g->DrawImage(i, destino, origen, GraphicsUnit::Pixel);
	X += (Direccion * dX);
	Y += dY;

	if (Indice == NroMovimiento - 1)
			Indice = 0;
	else
		Indice++;
}

void CBala::Set_Estado(bool Estado)
{
	this->Estado = Estado;
}

bool CBala::Get_Estado()
{
	return this->Estado;
}

int CBala::Get_X()
{
	return this->X;
}

int CBala::Get_Y()
{
	return this->Y;
}

int CBala::Get_Ancho()
{
	return this->Vec[Indice]->Get_Ancho();
}

int CBala::Get_Largo()
{
	return this->Vec[Indice]->Get_Largo();
}
