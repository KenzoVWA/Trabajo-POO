class CMovimiento
{
	private:
		int X, Y;
		int Ancho, Largo;
		int dX, dY;
	public:
		CMovimiento(int X, int Y, int dX, int dY, int Ancho, int Largo);
		~CMovimiento();

		int Get_X();
		int Get_Y();
		int Get_dX();
		int Get_dY();
		int Get_Ancho();
		int Get_Largo();
};

CMovimiento::CMovimiento(int X, int Y, int dX, int dY, int Ancho, int Largo)
{
	this->X = X;
	this->Y = Y;
	this->dX = dX;
	this->dY = dY;
	this->Ancho = Ancho;
	this->Largo = Largo;
}

CMovimiento::~CMovimiento()
{

}

int CMovimiento::Get_X()
{
	return this->X;
}

int CMovimiento::Get_Y()
{
	return this->Y;
}

int CMovimiento::Get_dX()
{
	return this->dX;
}

int CMovimiento::Get_dY()
{
	return this->dY;
}

int CMovimiento::Get_Ancho()
{
	return this->Ancho;
}

int CMovimiento::Get_Largo()
{
	return this->Largo;
}
