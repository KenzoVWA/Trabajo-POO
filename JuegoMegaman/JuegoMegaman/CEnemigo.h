using namespace System;
using namespace System::Drawing;

class CEnemigo
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
	CEnemigo(int X, int Y, int Direccion);
	~CEnemigo();
	void Set_Movimiento(int TipoMovimiento);
	void Dibujar(Graphics ^g, Bitmap ^i);

	void Set_Estado(bool Estado);
	bool Get_Estado();

	bool Contiene(int aX, int aY);
	bool HayColision(CMegaman *objMegaman);
	bool HayColision(CBala *objBala);
};

CEnemigo::CEnemigo(int X, int Y, int Direccion)
{
	this->X = X;
	this->Y = Y;
	this->Direccion = Direccion;
	this->Estado = true;

	Set_Movimiento(0);
}

CEnemigo::~CEnemigo()
{
}

void CEnemigo::Set_Movimiento(int TipoMovimiento)
{
	this->Indice = 0;
	this->TipoMovimiento = TipoMovimiento;

	switch (TipoMovimiento)
	{
		case 0: // CAMINAR

			NroMovimiento = 4;
			Vec = new CMovimiento*[NroMovimiento];

			Vec[0] = new CMovimiento(168, 2189, 5, 0, 34, 22);
			Vec[1] = new CMovimiento(200, 2185, 5, 0, 34, 25);
			Vec[2] = new CMovimiento(234, 2189, 5, 0, 34, 22);
			Vec[3] = new CMovimiento(267, 2187, 5, 0, 33, 24);
			this->dX = 3;
			this->dY = 0;
			this->DesviacionX = 0;
		break;
		
		case 1: //explotar
			NroMovimiento = 4;
			Vec = new CMovimiento*[NroMovimiento];
			Vec[0] = new CMovimiento(676, 2183, 0, 0, 695-676, 2201-2183);
			Vec[1] = new CMovimiento(696, 2185, 0, 0, 713-696, 2203-2185);
			Vec[2] = new CMovimiento(716, 2186, 0, 0, 729-716, 2203-2186);
			Vec[3] = new CMovimiento(732, 2186, 0, 0, 748-732,  2203-2186);
			this->dX = 0;
			this->dY = 0;
			this->DesviacionX = 0;
	}
}

void CEnemigo::Dibujar(Graphics ^g, Bitmap ^i)
{
	Rectangle origen = Rectangle(Vec[Indice]->Get_X(), 
		                         Vec[Indice]->Get_Y(),
		                         Vec[Indice]->Get_Ancho(), 
		                         Vec[Indice]->Get_Largo());

	Rectangle destino = Rectangle(Direccion == 1 ? X : X + DesviacionX, 
							      Y - Vec[Indice]->Get_Largo() , 
								  Direccion *(-1)*Vec[Indice]->Get_Ancho(), 
								  Vec[Indice]->Get_Largo());

	g->DrawImage(i, destino, origen, GraphicsUnit::Pixel);

	X += (Direccion * dX);
	Y += dY;

	if (Indice == NroMovimiento - 1)
			Indice = 0;
	else
		Indice++;
}

bool CEnemigo::Contiene(int aX, int aY)
{
	return aX >= X && aX <= X + Vec[Indice]->Get_Ancho() &&  
		   aY >= Y && aY <= Y + Vec[Indice]->Get_Largo();
}

bool CEnemigo::HayColision(CMegaman *objMegaman)
{
	return Contiene(objMegaman->Get_X(), objMegaman->Get_Y()) ||
		   Contiene(objMegaman->Get_X() + objMegaman->Get_Ancho(), objMegaman->Get_Y()) ||
		   Contiene(objMegaman->Get_X(), objMegaman->Get_Y() + objMegaman->Get_Largo()) ||
		   Contiene(objMegaman->Get_X() + objMegaman->Get_Ancho(), objMegaman->Get_Y() + objMegaman->Get_Largo());
}

bool CEnemigo::HayColision(CBala *objBala)
{
	return Contiene(objBala->Get_X(), objBala->Get_Y()) ||
		   Contiene(objBala->Get_X() + objBala->Get_Ancho(), objBala->Get_Y()) ||
		   Contiene(objBala->Get_X(), objBala->Get_Y() + objBala->Get_Largo()) ||
		   Contiene(objBala->Get_X() + objBala->Get_Ancho(), objBala->Get_Y() + objBala->Get_Largo());
}

void CEnemigo::Set_Estado(bool Estado)
{
	this->Estado = Estado;
}

bool CEnemigo::Get_Estado()
{
	return this->Estado;
}
