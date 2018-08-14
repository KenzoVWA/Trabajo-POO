using namespace System;
using namespace System::Drawing;

#include "CMegaman.h"
#include "CVecBala.h"
#include "CVecBonus.h"

enum Tipo_Movimiento { Estatico, Caminar_Izquierda, Caminar_Derecha, Saltar, Poder , Especial};

class CJuego
{
	private:
		CMegaman *objMegaman;
		CFondo *objFondo;
		CVecBonus *arrBonus;
		CVecEnemigo *arrEnemigo;
		CVecBala *arrBala;

		int Y, Contador, Contador2;
		int AnchoF;
		int Timer; int Timer2;
		int Vidas;

	public:
		CJuego(int AnchoF, int LargoF);
		~CJuego();

		void Dibujar(Graphics ^g, Bitmap ^imgMegaman, Bitmap ^imgEnemigo, Bitmap ^imgPoder, Bitmap ^imgFondo);
		bool EstaMovimiento();
		int get_vida();
		void Set_Movimiento(Tipo_Movimiento TipoMovimiento);
		int get_puntaje();
		void set_puntaje();
		void set_timer(int x);
		CMegaman* get_Megaman();
		void set_nivel(int x);
};

CJuego::CJuego(int AnchoF, int LargoF)
{
	this->Y = 350;

	objMegaman = new CMegaman(AnchoF/2, Y, 30, 40);
	objFondo = new CFondo(0, 0, AnchoF, LargoF, 600, 402, 400, 233, 4221); 
	arrBonus= new CVecBonus();
	arrEnemigo = new CVecEnemigo();
	arrBala = new CVecBala();

	this->AnchoF = AnchoF;
	this->Contador = 0;
	Timer=40;
	this->Contador2 = 0;
	Timer2=60;
	arrBala->Agregar_Bala(0, 0, 0);
}

CJuego::~CJuego()
{
	delete objMegaman;
	delete objFondo;
	delete arrEnemigo;
	delete arrBala;
}

void CJuego::Dibujar(Graphics ^g, Bitmap ^imgMegaman, Bitmap ^imgEnemigo, Bitmap ^imgPoder, Bitmap ^imgFondo)
{
	if (Contador % Timer == 0)
	{
		Random ^r = gcnew Random(DateTime::Now.Ticks);

		int Zona = r->Next(0, 2); // IZQUIERDA O DERECHA
		int Direccion = Zona == 0 ? 1 : -1; // VECTOR DIRECCIÓN
		int X = Direccion == 1 ? 10 : AnchoF;

		arrEnemigo->Agregar_Enemigo(X, Y, Direccion);

		Contador = 1;

		delete r;
	}

	if (Contador2 % Timer2 == 0)
	{
		Random ^r = gcnew Random(DateTime::Now.Ticks);
		int h=r->Next(4,720);
		int dye=r->Next(5,7);
		arrBonus->Agregar_Bonus(h, 7,dye);

		Contador = 1;

		delete r;
	}
	arrEnemigo->Verificar_Colision(objMegaman);
	arrBala->Verificar_Colision(arrEnemigo);
	arrBonus->Verificar_Colision(objMegaman);
	
	objFondo->Dibujar(g, imgFondo);
	objMegaman->Dibujar(g, imgMegaman, objFondo);
	arrBala->Dibujar(g, imgMegaman);
	arrEnemigo->Dibujar(g, imgEnemigo);
	arrBonus->Dibujar(g, imgMegaman, 499);
	


	Contador++;
	Contador2++;
}

bool CJuego::EstaMovimiento()
{
	return objMegaman->EstaMovimiento();
}

void CJuego::Set_Movimiento(Tipo_Movimiento TipoMovimiento)
{
	if (TipoMovimiento == Tipo_Movimiento::Caminar_Derecha)
	{
		objMegaman->Set_Movimiento(1);
		objMegaman->Set_Direccion(1);
	}
	else if (TipoMovimiento == Tipo_Movimiento::Caminar_Izquierda)
	{
		objMegaman->Set_Movimiento(1);
		objMegaman->Set_Direccion(-1);
	}
	else if (TipoMovimiento == Tipo_Movimiento::Saltar)
	{
		objMegaman->Set_Movimiento(2);
	}
	else if (TipoMovimiento == Tipo_Movimiento::Poder)
	{
		int X = objMegaman->Get_Direccion() == 1 ? objMegaman->Get_X() + objMegaman->Get_Ancho() : objMegaman->Get_X() - objMegaman->Get_Ancho();
		int Y = objMegaman->Get_Y() - objMegaman->Get_Largo()/4;
		objMegaman->Set_Movimiento(3);
		arrBala->Agregar_Bala(X, 357, objMegaman->Get_Direccion());
	}
	else if (TipoMovimiento == Tipo_Movimiento::Especial)
	{
		objMegaman->Set_Movimiento(4);
		arrEnemigo->Especial2();
		arrEnemigo->Especial();
	}
}

int CJuego::get_vida(){

	return objMegaman->Get_NroVidas();

}

int CJuego::get_puntaje(){

	return arrEnemigo->Get_Puntaje();

}

void CJuego::set_puntaje(){


}

void CJuego::set_timer(int x){

	this->Timer=x;

}

void CJuego::set_nivel(int x){

	arrEnemigo->set_nivel(x);

}
CMegaman* CJuego::get_Megaman(){

return objMegaman;
}