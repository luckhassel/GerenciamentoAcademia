#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include"File.h"

using namespace std;

 void Apresentacao() //Cabeçalho
{
	cout<<" -----------------------------------------------------------------\n";
    cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
    cout<<" -----------------------------------------------------------------\n";
	cout<<"\n\n\nPressione alguma tecla para continuar...";
	getch();
	

}

int main() //Menu principal com todas opções
{
	Apresentacao();
	int opcao;
	while(1)
	{
	  system("cls");
	  cout<<" -----------------------------------------------------------------\n";
      cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
      cout<<" -----------------------------------------------------------------\n";
      cout<<"\t       ------------\t\t\t\t       \n";
      cout<<"\t       |   MENU   ";cout<<"|\t\t\t\t      \n";
      cout<<"   ------------------------------------- \n";
      cout<<"   | <1> Adicionar novo registro       |\n";
      cout<<"   |-----------------------------------|\n";
      cout<<"   | <2> Mostrar dados treinadores     |\n";      
      cout<<"   |-----------------------------------|\n";
      cout<<"   | <3> Mostrar dados alunos          |\n";      
      cout<<"   |-----------------------------------|\n";
      cout<<"   | <4> Mostrar agendas               |\n";
      cout<<"   |-----------------------------------|\n";
      cout<<"   | <5> Metas                         |\n";
      cout<<"   |-----------------------------------|\n";
      cout<<"   | <6> Deletar registro              |\n";
      cout<<"   |-----------------------------------|\n";
      cout<<"   | <7> Sair                          |\n";
      cout<<"    -----------------------------------";
      cout<<"\n\n\n\n";
	  cout<<"Digite uma opcao: ";
		cin>>opcao;
		switch(opcao)
		{
			case 1:
			{
				adicionar();
				cout<<"\nPressione qualquer tecla para continuar..."<<endl;
				getch();
				break;
			}
			case 2:
			{
				mostrar_treinadores();
				cout<<"\nPressione qualquer tecla para continuar..."<<endl;
				getch();
				break;
			}
			case 3:
			{
				mostrar_alunos();
				cout<<"\nPressione qualquer tecla para continuar..."<<endl;
				getch();
				break;
			}
			case 4:
			{
				agendamento();
				cout<<"\nPressione qualquer tecla para continuar..."<<endl;
				getch();
				break;
			}
			case 5:
			{
				metas();
				cout<<"\nPressione qualquer tecla para continuar..."<<endl;
				getch();
				break;
			}
			case 6:
			{
				deletar();
				cout<<"\nPressione qualquer tecla para continuar..."<<endl;
				getch();
				break;
			}
			case 7:
			{
				exit(0);
			}
		}
	}
}

