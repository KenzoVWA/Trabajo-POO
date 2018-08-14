using namespace System;
using namespace System::Drawing;

class CFondo
{
	private:
		int X, Y;
		int Ancho, Largo;

		int XI, YI;
		int AnchoI, LargoI;
		int AnchoM;

	public:
		CFondo(int X, int Y, int Ancho, int Largo, int XI, int YI, int AnchoI, int LargoI, int AnchoM);
		~CFondo();

		void Dibujar(Graphics ^g, Bitmap ^i);
		int Get_Ancho();
		bool ValidarLimite(int Mario_X, int Mario_Ancho, int Mario_dX);
		void Set_XI(int dX);
};

CFondo::CFondo(int X, int Y, int Ancho, int Largo, int XI, int YI, int AnchoI, int LargoI, int AnchoM)
{
	this->X = X;
	this->Y = Y;
	this->Ancho = Ancho;
	this->Largo = Largo;

	this->XI = XI;
	this->YI = YI;
	this->AnchoI = AnchoI;
	this->LargoI = LargoI;

	this->AnchoM = AnchoM;
}

CFondo::~CFondo()
{

}

void CFondo::Dibujar(Graphics ^g, Bitmap ^i)
{
	Rectangle origen = Rectangle(XI, YI, AnchoI, LargoI);
	Rectangle destino = Rectangle(X, Y, Ancho, Largo);

	g->DrawImage(i, destino, origen, GraphicsUnit::Pixel);
}

int CFondo::Get_Ancho()
{
	return this->Ancho;
}

bool CFondo::ValidarLimite(int Mario_X, int Mario_Ancho, int Mario_dX)
{
	return !(Mario_X + Mario_dX < 0 || Mario_X + Mario_dX + Mario_Ancho > AnchoM);
}

void CFondo::Set_XI(int dX)
{
	this->XI += dX;
}

