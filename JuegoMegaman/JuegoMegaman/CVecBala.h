using namespace System::Drawing;

#include <stdio.h>

#include "CBala.h"
#include "CVecEnemigo.h"

class CVecBala
{
	private:
		CBala** Vec;
	    int *N;
	public:
		CVecBala();
		~CVecBala();

		CBala*  Get_Bala(int Pos);
		int*  Get_N();

		void Agregar_Bala(int X, int Y, int Direccion);
	    void Dibujar(Graphics ^g, Bitmap ^img);

		void Verificar_Colision(CVecEnemigo *arrEnemigo);
		void Eliminar_Todos();
};

CVecBala::CVecBala()
{	
	N= new int;
	*N = 0;
	Vec = NULL;
}

CVecBala::~CVecBala()
{	
	for (int i=0;i<*N;i++)
		delete Vec[i];

	delete N;
}

void  CVecBala::Agregar_Bala(int X, int Y, int Direccion)
{
	if(*N<10){
	CBala** Aux =new CBala*[*N+1];

	if (Aux != NULL)
	{
		CBala* nuevo = new CBala(X, Y, Direccion);

		for (int i=0;i<*N;i++)
			Aux[i] = Vec[i];
	
		Aux[*N] = nuevo;
		*N=*N+1;

		if (Vec != NULL)
			delete Vec;

		Vec = Aux;
	}
	}
}

void CVecBala::Dibujar(Graphics ^g, Bitmap ^img)
{
	
	
	for (int i=0; i<*N; i++){
		if(Vec[i]->Get_X()+Vec[i]->Get_Ancho()<0)
			Vec[i]->Set_Estado(false);
		if(Vec[i]->Get_X()+Vec[i]->Get_Ancho()>745)
			Vec[i]->Set_Estado(false);
		Vec[i]->Dibujar(g, img);
	}
}


CBala*  CVecBala::Get_Bala(int Pos)
{
	return Vec[Pos];
}

int*  CVecBala::Get_N()
{
	return N;
}


void CVecBala::Verificar_Colision(CVecEnemigo *arrEnemigo)
{
	for (int i=0; i<*N; i++)
		arrEnemigo->Verificar_Colision(Vec[i]);

	Eliminar_Todos();
}

void CVecBala::Eliminar_Todos()
{
	int M = 0;

	for(int i=0; i<*N; i++)
		if (Vec[i]->Get_Estado())
			M++;

	if (M > 0)
	{
		CBala** Aux =new CBala*[M];

		if (Aux != NULL)
		{ 
			for(int i=0, j=0; i<*N; i++)
				if (Vec[i]->Get_Estado())
				{
					Aux[j] = Vec[i];
					j++;
				}

			*N = M;
			  
			if (Vec != NULL)
				  delete Vec;

			  Vec = Aux;
		}
	}
}