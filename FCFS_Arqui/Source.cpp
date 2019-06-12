#include <iostream>
#include<conio.h>
using namespace std;
using namespace System;

class Proceso
{
private:
	int NumeroProceso;
	int BT;
	int AT;
	int ET;
	int WT;
	bool Activado;

public :

	Proceso()
	{
		Activado = false;
	}
	int get_NumeroProceso()
	{
		return NumeroProceso;
	}
	int get_BT()
	{
		return BT;
	}
	int get_AT()
	{
		return AT;
	}
	int get_ET()
	{
		return ET;
	}
	int get_WT()
	{
		return WT;
	}
	bool get_Activado()
	{
		return Activado;
	}
	void set_NumeroProceso(int numeroProceso)
	{
		NumeroProceso = numeroProceso;
	}
	void set_BT(int bt)
	{
		BT = bt;
	}
	void set_AT(int at)
	{
		AT = at;
	}
	void set_ET(int et)
	{
		ET = et;
	}
	void set_WT(int wt)
	{
		WT = wt;
	}
	void set_Activado(bool activado)
	{
		Activado = activado;
	}
	~Proceso()
	{

	}
};

class Control
{
private:
	int *N;
	Proceso **Arreglo;
	Proceso **Arreglo2;
	int *N2;
	int TCT;
	int Tiempo;
public :
	Control()
	{
		N= new int;
		*N = 0;
		N2 = new int;
		*N2 = 0;
		Arreglo = NULL;
		Arreglo2 = NULL;
		Tiempo = 0;
		TCT = 0;
	}
	int get_N()
	{
		return *N;
	}
	int get_N2()
	{
		return *N2;
	}
	int get_Tiempo()
	{
		return Tiempo;
	}
	void set_Tiempo(int tiempo)
	{
		Tiempo = tiempo;
	}
	void Agregar(Proceso *obj)
	{
		Proceso**ArrTemporal;
		ArrTemporal = new Proceso*[*N+1];
		for (int i=0; i<*N;i++)
		{
			ArrTemporal[i] = Arreglo[i];
		}
		ArrTemporal[*N] = obj;
		*N = *N + 1;
		Arreglo = ArrTemporal;

	}
	Proceso** ObtenerArreglo()
	{
		return Arreglo;
	}
	Proceso**ObtenerArreglo2()
	{
		return Arreglo2;
	}

	void Ordenar()
	{
		Proceso *Aux=NULL;

		for (int i=0;i<*N-1;i++)
		{
			for (int j=i+1;j<*N;j++)
			{
				if (Arreglo[i]->get_AT()>Arreglo[j]->get_AT())
				{
					
					Aux = Arreglo[i];
					Arreglo[i] = Arreglo[j];
					Arreglo[j] = Aux;
				}
			}
		}
	}
	void AgregarArr2(Proceso *obj)
	{
		Proceso**ArrTemporal;
		ArrTemporal = new Proceso*[*N2 + 1];
		for (int i = 0; i<*N2; i++)
		{
			ArrTemporal[i] = Arreglo2[i];
		}
		ArrTemporal[*N] = obj;
		*N2 = *N2 + 1;
		Arreglo2 = ArrTemporal;
	}
	void EliminarArr2()
	{
		Proceso**ArrTemporal;
		ArrTemporal = new Proceso*[*N2 - 1];
		int j = 0;
		for (int i = 0; i<*N2; i++)
		{
			if (i!=0)
			{
				ArrTemporal[j] = Arreglo2[i];
				j = j + 1;
			}
			
		}
		*N2 = *N2 - 1;
		Arreglo2 = ArrTemporal;
	}

};

int main()
{
	Control *objArreglo = new Control();
	Proceso *obj = new Proceso();
	obj->set_NumeroProceso(1);
	obj->set_BT(3);
	obj->set_AT(0);
	objArreglo->Agregar(obj);
	obj = new Proceso();
	obj->set_NumeroProceso(2);
	obj->set_BT(9);
	obj->set_AT(6);
	objArreglo->Agregar(obj);
	obj = new Proceso();
	obj->set_NumeroProceso(3);
	obj->set_BT(6);
	obj->set_AT(14);
	objArreglo->Agregar(obj);
	obj = new Proceso();
	obj->set_NumeroProceso(4);
	obj->set_BT(12);
	obj->set_AT(18);
	objArreglo->Agregar(obj);
	obj = new Proceso();
	obj->set_NumeroProceso(5);
	obj->set_BT(7);
	obj->set_AT(20);
	objArreglo->Agregar(obj);
	
	objArreglo->Ordenar();

	for (int x=0;x<45;x++)
	{
		for (int i=0;i<objArreglo->get_N();i++)
		{
			
			if (objArreglo->ObtenerArreglo()[i]->get_AT()<=objArreglo->get_Tiempo())
			{
				objArreglo->AgregarArr2(objArreglo->ObtenerArreglo()[i]);

				if (objArreglo->ObtenerArreglo2()[0]->get_Activado()==false)
				{
					objArreglo->ObtenerArreglo2()[0]->set_ET(objArreglo->get_Tiempo());
					
					objArreglo->ObtenerArreglo2()[0]->set_Activado(true);
				}
			}


		}
		if (objArreglo->ObtenerArreglo2()[0]->get_BT()+ objArreglo->ObtenerArreglo2()[0]->get_ET()==objArreglo->get_Tiempo())
		{
			objArreglo->EliminarArr2();
		}
	
			objArreglo->set_Tiempo(objArreglo->get_Tiempo()+1);




	}









	return 0;
}