#ifndef Schedule_H
#define Schedule_H
#include<iostream>
#include<string.h>
#include <iomanip>

using namespace std;

typedef char Time[5];
typedef char String[100];

typedef struct //Armazena as informações da agenda do Treinador
{
 	String Timing[7][7];
			
}AgendaTreinador;

typedef struct //Armazena as informações da agenda do Aluno
{
	Time Timing[7];
			
}AgendaAluno;

AgendaAluno AddAgendaAluno(void) //Insere as informações de Agenda ALuno
{
		AgendaAluno MS;
		cout<<"Segunda: ";scanf("%s",MS.Timing[0]);
		cout<<"Terca: ";scanf("%s",MS.Timing[1]);
		cout<<"Quarta: ";scanf("%s",MS.Timing[2]);
		cout<<"Quinta: ";scanf("%s",MS.Timing[3]);
		cout<<"Sexta: ";scanf("%s",MS.Timing[4]);
		cout<<"Sabado: ";scanf("%s",MS.Timing[5]);
		cout<<"Domingo: ";scanf("%s",MS.Timing[6]);
		return MS;
}

AgendaTreinador AddAgendaTreinador(void) //Insere as informações de Agenda Treinador
{
	String dias[7]={"Segunda","Terca","Quarta","Quinta","Sexta","Sabado","Domingo"};
	String hora[7]={"1-2","2-3","3-4","4-5","5-6","6-7", "7-8"};
	AgendaTreinador TS;
	
		for(int i=0;i<7;i++)
		{
			cout<<"Agenda para "<<dias[i]<<endl;
				for(int j=0;j<7;j++)
				{ cout<<hora[j]<<" -> ";
					scanf("%s",TS.Timing[i][j]);
				}
		
		}
		
		return TS;
}

void MostrarAgenda(AgendaAluno Ms) //Imprime agenda Aluno (Polimorfismo)
{
	cout<<"\n--------------------------------------------------------------------------------";
	
	cout<<"\n      "<<setw(10)<<left<<"Seg"<<setw(10)<<left<<"Ter"<<setw(10)<<left<<"Qua"<<setw(10)<<left<<"Qui"<<setw(10)<<left<<"Sex"<<setw(10)<<left<<"Sab"<<setw(10)<<left<<"Dom\n";
	
	for(int i=0;i<7;i++)
	cout<<setw(10)<<left<<Ms.Timing[i];

	cout<<"\n--------------------------------------------------------------------------------";
}

void MostrarAgenda(AgendaTreinador Ts) //Imprime agenda Treinador (Polimorfismo)
{
	String Times[7]={"1-2","2-3","3-4","4-5","5-6","6-7","7-8"};
	
	cout<<"\n"<<"         "<<setw(10)<<left<<"Seg"<<setw(10)<<left<<"Ter"<<setw(10)<<left<<"Qua"<<setw(10)<<left<<"Qui"<<setw(10)<<left<<"Sex"<<setw(10)<<left<<"Sab"<<setw(10)<<left<<"Dom";

	cout<<"\n--------------------------------------------------------------------------------\n";
	for(int i=0;i<7;i++){
	
	cout<<Times[i]<<"->\t";
	for(int j=0;j<7;j++)
	
	cout<<setw(10)<<left<<Ts.Timing[j][i];
	cout<<"\n";
	}
	cout<<"\n--------------------------------------------------------------------------------";
	
}
#endif

