using namespace System::Drawing;

#include <stdio.h>

#include "CBonus.h"

class CVecBonus
{
	private:
		CBonus** Vec;
	    int *N;

	public:
		CVecBonus();
		~CVecBonus();

		CBonus*  Get_Bonus(int Pos);
		int*  Get_N();

		void Agregar_Bonus(int X, int Y,int dye);
	    void Dibujar(Graphics ^g, Bitmap ^img, int largof);
		void Verificar_Colision(CMegaman *objMegaman);
		void Eliminar_Todos();
};

CVecBonus::CVecBonus()
{	
	N= new int;
	*N = 0;
	Vec = NULL;
}

CVecBonus::~CVecBonus()
{	
	for (int i=0;i<*N;i++)
		delete Vec[i];

	delete N;
}

void  CVecBonus::Agregar_Bonus(int X, int Y, int dye)
{
	CBonus** Aux =new CBonus*[*N+1];

	if (Aux != NULL)
	{
		CBonus* nuevo = new CBonus(X, Y, dye);

		for (int i=0;i<*N;i++)
			Aux[i] = Vec[i];
	
		Aux[*N] = nuevo;
		*N=*N+1;

		if (Vec != NULL)
			delete Vec;

		Vec = Aux;
	}
}

void CVecBonus::Dibujar(Graphics ^g, Bitmap ^img, int largof)
{
	for (int i=0; i<*N; i++){
		Vec[i]->Dibujar(g, img, largof);
		Eliminar_Todos();
	}
}


CBonus*  CVecBonus::Get_Bonus(int Pos)
{
	return Vec[Pos];
}

int*  CVecBonus::Get_N()
{
	return N;
}

void CVecBonus::Verificar_Colision(CMegaman *objMegaman)
{
	for (int i=0; i<*N; i++)
//	if (Vec[i]->HayColision(objMegaman))
	if(Vec[i]->HayColision(Vec[i]->Get_X(),Vec[i]->Get_Y(),Vec[i]->Get_Ancho(),Vec[i]->Get_Largo(),objMegaman->Get_X(),
				objMegaman->Get_Y(),
				objMegaman->Get_Ancho(),
				objMegaman->Get_Largo()))
		{
			Vec[i]->Set_Estado(false);
			if(Vec[i]->get_tipomovimiento()==0)objMegaman->set_oxigeno(8);
			if(Vec[i]->get_tipomovimiento()==1)objMegaman->set_vida(-3);
		}

	Eliminar_Todos();
}

void CVecBonus::Eliminar_Todos()
{
	int M = 0;

	for(int i=0; i<*N; i++)
		if (!Vec[i]->Get_Estado())
			M++;

	if (M > 0)
	{
		CBonus** Aux =new CBonus*[*N-M];

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
