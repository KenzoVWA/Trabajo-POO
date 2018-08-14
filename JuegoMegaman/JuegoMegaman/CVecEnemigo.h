using namespace System::Drawing;

#include <stdio.h>

#include "CEnemigo.h"

class CVecEnemigo
{
	private:
		CEnemigo** Vec;
	    int *N;
		int Puntaje;
		int Nivel;

	public:
		CVecEnemigo();
		~CVecEnemigo();

		CEnemigo*  Get_Enemigo(int Pos);
		int*  Get_N();

		void Agregar_Enemigo(int X, int Y, int Direccion);
	    void Dibujar(Graphics ^g, Bitmap ^img);
		int Get_Puntaje();
		int Get_Nivel();
		void set_nivel(int x);
		void Verificar_Colision(CMegaman *objMegaman);
		void Verificar_Colision(CBala *objBala);
		void Eliminar_Todos();
		void Especial();
		void Especial2();
};

CVecEnemigo::CVecEnemigo()
{	
	N= new int;
	*N = 0;
	Vec = NULL;
	Puntaje=0;
	Nivel=1;
}

CVecEnemigo::~CVecEnemigo()
{	
	for (int i=0;i<*N;i++)
		delete Vec[i];

	delete N;
}

void  CVecEnemigo::Agregar_Enemigo(int X, int Y, int Direccion)
{
	CEnemigo** Aux =new CEnemigo*[*N+1];

	if (Aux != NULL)
	{
		CEnemigo* nuevo = new CEnemigo(X, Y, Direccion);

		for (int i=0;i<*N;i++)
			Aux[i] = Vec[i];
	
		Aux[*N] = nuevo;
		*N=*N+1;

		if (Vec != NULL)
			delete Vec;

		Vec = Aux;
	}
}

void  CVecEnemigo::Especial()
{
	for (int i=0;i<*N;i++){
		Vec[i]->Set_Estado(false);
	Puntaje=Puntaje+(*N*10);
	}
}

void  CVecEnemigo::Especial2()
{
	for (int i=0;i<*N;i++)
		Vec[i]->Set_Movimiento(1);
}

void CVecEnemigo::Dibujar(Graphics ^g, Bitmap ^img)
{
	g->DrawString("Puntaje :", gcnew Font("Arial", 14), Brushes::White, 530, 10);
	g->DrawString("Nivel :", gcnew Font("Arial", 14), Brushes::White, 300, 10);
	g->DrawString(Puntaje.ToString(), gcnew Font("Arial", 14), Brushes::Cyan, 620, 10);
	g->DrawString(Nivel.ToString(), gcnew Font("Arial", 14), Brushes::White, 365, 12);
	for (int i=0; i<*N; i++)
		Vec[i]->Dibujar(g, img);
}


CEnemigo*  CVecEnemigo::Get_Enemigo(int Pos)
{
	return Vec[Pos];
}

int*  CVecEnemigo::Get_N()
{
	return N;
}

void CVecEnemigo::Verificar_Colision(CMegaman *objMegaman)
{
	for (int i=0; i<*N; i++)
		if (Vec[i]->HayColision(objMegaman))
		{
			Vec[i]->Set_Estado(false);
			objMegaman->QuitarNroVidas(1);
		}

	Eliminar_Todos();
}

void CVecEnemigo::Verificar_Colision(CBala *objBala)
{
	for (int i=0; i<*N; i++)
		if (Vec[i]->HayColision(objBala))
		{
			Vec[i]->Set_Estado(false);
			objBala->Set_Estado(false);
			Puntaje=Puntaje+10;
		}

	Eliminar_Todos();
}

void CVecEnemigo::Eliminar_Todos()
{
	int M = 0;

	for(int i=0; i<*N; i++)
		if (!Vec[i]->Get_Estado())
			M++;

	if (M > 0)
	{
		CEnemigo** Aux =new CEnemigo*[*N-M];

		if (Aux != NULL)
		{ 
			for(int i=0, j=0; i<*N; i++)
				if (Vec[i]->Get_Estado())
				{
					Aux[j] = Vec[i];
					j++;
				}

			*N = *N - M;
			  
			if (Vec != NULL)
				  delete Vec;

			  Vec = Aux;
		}
	}
}

int CVecEnemigo::Get_Puntaje(){
	return this->Puntaje;
}

int CVecEnemigo::Get_Nivel(){
	return this->Nivel;
}

void CVecEnemigo::set_nivel(int x){
	this->Nivel=x;
}