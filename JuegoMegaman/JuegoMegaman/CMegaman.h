using namespace System;
using namespace System::Drawing;

#include "CMovimiento.h"
#include "CFondo.h"

#include <stdio.h>

class CMegaman
{
private:
	int X, Y;
	int dX, dY;
	int Ancho, Largo;
	int Direccion, Indice;
	int DesviacionX;
	int TipoMovimiento;
	int NroVidas;
	int oxigeno;

	int contador;
	int contador2;

	CMovimiento **Vec;
	int NroMovimiento;
public:
	CMegaman(int X, int Y, int Ancho, int Largo);
	~CMegaman();
	void Set_Movimiento(int TipoMovimiento);
	void Set_Direccion(int Direccion);
	void Dibujar(Graphics ^g, Bitmap ^imgMario, CFondo *objFondo);
	bool EstaMovimiento();
	void QuitarNroVidas(int dNroVidas);
	void set_oxigeno(int ox);
	void set_vida(int vi);
	int Get_X();
		int Get_dX();
	int Get_Y();
	int Get_Ancho();
	int Get_NroVidas();
	int Get_Largo();
	int Get_Direccion();
};

CMegaman::CMegaman(int X, int Y, int Ancho, int Largo)
{
	this->X = X;
	this->Y = Y;
	this->Ancho = Ancho;
	this->Largo = Largo;
	this->Direccion = 1;
	this->NroVidas = 10;
	oxigeno=8;
	contador=0;
	contador2=0;
	Set_Movimiento(0);
}

CMegaman::~CMegaman()
{
}

void CMegaman::Set_Movimiento(int TipoMovimiento)
{
	this->Indice = 0;
	this->TipoMovimiento = TipoMovimiento;

	switch (TipoMovimiento)
	{
		case 0: // ESTATICO

			NroMovimiento = 8;
			Vec = new CMovimiento*[NroMovimiento];

			Vec[0]= new CMovimiento(6,56,0,0,35,42);
			Vec[1]= new CMovimiento(56,56,0,0,35,42);
			Vec[2]= new CMovimiento(106,56,0,0,35,42);
			Vec[3]= new CMovimiento(156,56,0,0,35,42);
			Vec[4]= new CMovimiento(206,56,0,0,35,42);
			Vec[5]= new CMovimiento(256,56,0,0,35,42);
			Vec[6]= new CMovimiento(306,56,0,0,35,42);
			Vec[7]= new CMovimiento(356,56,0,0,35,42);

			this->dX = 0;
			this->dY = 0;
			
		break;

		case 1: // CAMINAR

			NroMovimiento = 4;
			Vec = new CMovimiento*[NroMovimiento];

			Vec[0]=new CMovimiento(10,207,8,0,28,39);
			Vec[1]=new CMovimiento(100,207,8,0,46,39);
			Vec[2]=new CMovimiento(210,207,8,0,28,39);
			Vec[3]=new CMovimiento(103,208,8,0,39,39);

			this->dX = 8*Direccion;
			this->dY = 0;
			this->DesviacionX = 24;

		break;

		case 2: // SALTAR

			NroMovimiento = 5;
			Vec = new CMovimiento*[NroMovimiento];

			Vec[0]=new CMovimiento(10,406,0,-15,28,42);
			Vec[1]=new CMovimiento(58,406,0,-15,32,52);
			Vec[2]=new CMovimiento(107,406,0,0,31,52);
			Vec[3]=new CMovimiento(207,406,0,15,31,50);
			Vec[4]=new CMovimiento(259,408,0,15,28,42);

			this->dX = 0;
			this->dY = 0;
			this->DesviacionX = 29;

		break;

		case 3: // DISPARANDO

			NroMovimiento = 2;
			Vec = new CMovimiento*[NroMovimiento];

			Vec[0]=new CMovimiento(3,106,0,0,48,46);
			Vec[1]=new CMovimiento(48,149,0,0,55,45);

			this->dX = 0;
			this->dY = 0;

		break;

		case 4: // ESPECIAL

			NroMovimiento = 4;
			Vec = new CMovimiento*[NroMovimiento];

			Vec[0]=new CMovimiento(197,726,0,0,59,56);
			Vec[1]=new CMovimiento(254,727,0,0,291-254,776-727);
			Vec[2]=new CMovimiento(301,724,0,0,343-301,778-724);
			Vec[3]=new CMovimiento(351,724,0,0,395-351,781-724);
			this->dX = 0;
			this->dY = 0;
			set_vida(3);
		break;
	}
}

void CMegaman::Dibujar(Graphics ^g, Bitmap ^imgMario, CFondo *objFondo)
{
	Rectangle origen = Rectangle(Vec[Indice]->Get_X(), Vec[Indice]->Get_Y(), Vec[Indice]->Get_Ancho(), Vec[Indice]->Get_Largo());
	Rectangle destino = Rectangle(Direccion == 1 ? X : X + DesviacionX, Y - Vec[Indice]->Get_Largo() , Direccion * Vec[Indice]->Get_Ancho(), Vec[Indice]->Get_Largo());

	g->DrawImage(imgMario, destino, origen, GraphicsUnit::Pixel);

	g->DrawString("Vidas :", gcnew Font("Arial", 14), Brushes::White, 10, 10);
	int lugar1=75,lugar2=19;;
	for(int h=0;h<NroVidas;h++){
	g->FillRectangle(Brushes::DeepPink, lugar1,lugar2,10,10);
	lugar1=lugar1+13;
	}
	lugar1=10;

	g->DrawString("Oxigeno :", gcnew Font("Arial", 14), Brushes::White, 10, 35);
	lugar1=97,lugar2=41;
	for(int h=0;h<oxigeno;h++){
	g->FillRectangle(Brushes::Blue, lugar1,lugar2,10,10);
	lugar1=lugar1+13;
	}
	lugar1=10;

	contador++;

	if (contador==27){
		oxigeno--;
		contador=1;
	}

	if(oxigeno<=0){
		oxigeno=0;
		contador2++;
	}

	if(oxigeno==0 && contador2==7){
		contador2=1;
		NroVidas--;
	}

	dX = Direccion * Vec[Indice]->Get_dX();

	if (objFondo->ValidarLimite(X, Ancho, dX))
	{
		if (X >= objFondo->Get_Ancho()/2 && Direccion == 1)
		{
			X += dX;
			objFondo->Set_XI(dX);
		}
		else if (X <= objFondo->Get_Ancho()/2 && Direccion == -1)
		{
			X += dX;
			objFondo->Set_XI(dX);
		}
		else
			X += dX;
			

		Y += Vec[Indice]->Get_dY();

		if (Indice == NroMovimiento - 1)
		{
			if (TipoMovimiento == 0)
				Indice = 0;
			else
				Set_Movimiento(0);
		}
		else
			Indice++;
	}
}

void CMegaman::Set_Direccion(int Direccion)
{
	this->Direccion = Direccion;
}

bool CMegaman::EstaMovimiento()
{
	return TipoMovimiento != 0;
}

int CMegaman::Get_X()
{
	return this->X;
}

int CMegaman::Get_dX()
{
	return this->dX*(-1);
}

int CMegaman::Get_Y()
{
	return this->Y;
}

int CMegaman::Get_Ancho()
{
	return this->Vec[Indice]->Get_Ancho();
}

int CMegaman::Get_Largo()
{
	return this->Vec[Indice]->Get_Largo();
}

int CMegaman::Get_Direccion()
{
	return this->Direccion;
}

void CMegaman::QuitarNroVidas(int dNroVidas)
{
	if (this->NroVidas >= NroVidas)
		this->NroVidas -= dNroVidas;
}

int CMegaman::Get_NroVidas(){
	return this->NroVidas;
}

void CMegaman::set_oxigeno(int ox){
	this->oxigeno=ox;
}

void CMegaman::set_vida(int vi){
	if(NroVidas<=10)
		this->NroVidas-=vi;
}