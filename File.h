#include"Profile.h"
#include<iostream>
#include<fstream>
#include <iomanip>
#include"Schedule.h"
using namespace std;



void deletar_aluno();
void deletar_treinador();
bool get_treinador();
bool get_aluno();
bool cadastraMeta();
bool consultaMeta();

Treinador t;
Aluno m;
Metas meta;

void adicionar() //Adiciona as informações sobre as pessoas
{
	fstream fil;
	int opcao;
	system("cls");
	cout<<" -----------------------------------------------------------------\n";
    cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
    cout<<" -----------------------------------------------------------------\n";
    cout<<"\t ------------------------------  \n     ";
    cout<<"   |   Adicionar novo registro   ";cout<<"|\t\t\t\t      \n";
    cout<<"   ------------------------------------------- \n";
    cout<<"   | <1> Adicionar treinador                  |\n";
    cout<<"   |------------------------------------------|\n";
    cout<<"   | <2> Adicionar aluno                      |\n";      
    cout<<"   |------------------------------------------|\n";
    cout<<"\n\n";
	cout<<"Digite uma opcao: ";
	
	cin>>opcao;
	if(opcao==1)
	{
	char ch='y';
	Treinador treinador;
	fil.open("Trainer.dat",ios::app| ios::binary);
	while(ch=='y' || ch =='Y')
	{
		treinador.GetData();
		fil.write((char*)&treinador, sizeof(treinador));
		cout<<"Dados salvos com sucesso..\n Desejar continuar (Y/N)?";
		cin>>ch;
	}
	fil.close();
	}
	else if(opcao==2)
	{
	char ch='y';
	Aluno aluno;
	fil.open("Member.dat",ios::app| ios::binary);
	while(ch=='y' || ch =='Y')
	{
		aluno.GetData();
		fil.write((char*)&aluno, sizeof(aluno));
		cout<<"Dados salvos com sucesso..\n Desejar continuar (Y/N)?";
		cin>>ch;
	}
	fil.close();
	}
	else
	{
		cout<<"Opcao invalida!\n Tentar novamente?(Y/N)";
		char c;
		cin>>c;
		if(c=='Y'|| c=='y') adicionar();
		
	}
	
	
	
}
 
void agendamento() // Chama o método para prencher a agenda das pessoas
{
	int opcao;
	system("cls");
	cout<<" -----------------------------------------------------------------\n";
    cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
    cout<<" -----------------------------------------------------------------\n";
    cout<<"\t ------------- \n     ";
    cout<<"   |   Agenda   ";cout<<"|\t\t\t\t      \n";
    cout<<"   ------------------------------------------- \n";
    cout<<"   | <1> Agenda dos treinadores               |\n";
    cout<<"   |------------------------------------------|\n";
    cout<<"   | <2> Agenda dos alunos                    |\n";      
    cout<<"   |------------------------------------------|\n";
    cout<<"\n\n";
	cout<<"Digite uma opcao: ";
	
	cin>>opcao;		
	if(opcao==1){
		if(get_treinador())
		MostrarAgenda(t.agenda_treinador);
}
else if(opcao==2)
{
	if(get_aluno())
	MostrarAgenda(m.agenda_aluno);	
}

	else
	cout<<"Opcao invalida.";
	
}

bool get_treinador() //Verifica se o treinador buscado existe no arquivo .dat
{
	fstream fil;
	char n[100];
	bool achou=false;
	cout<<"Entre o nome do treinador: ";
	scanf("%s",&n);
	Treinador treinador;
	fil.open("Trainer.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"Arquivo nao encontrado!";
		return false;
	}
	else
	{
		system("cls");
		cout<<" -----------------------------------------------------------------\n";
    	cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
    	cout<<" -----------------------------------------------------------------\n\n";
    	cout<<"     "<<n<<endl;
    	cout<<" -----------------------------------------------------------------\n\n";
		fil.read((char*)&treinador, sizeof(treinador));
		while(!fil.eof())
		{
			if(strcmp(n,treinador.Nome)==0)
			{
			achou=true;
			t=treinador;
			return true;
			}
			else
			{
				
			}
			fil.read((char*)&treinador, sizeof(treinador));
		}
		if(!achou)
		{cout<<"\n Treinador nao encontrado!\n";
		return false;
		}
	}
	
	fil.close();
}

bool get_aluno() //Verifica se o aluno buscado existe no arquivo .dat
{
	fstream fil;
	char n[100];
	bool achou=false;
	cout<<"Entre o nome do aluno: ";
	scanf("%s",&n);
	Aluno aluno;
	fil.open("Member.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"Arquivo nao encontrado!";
		return false;
		
	}
	else
	{
		system("cls");
		cout<<" -----------------------------------------------------------------\n";
    	cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
    	cout<<" -----------------------------------------------------------------\n\n";
    	cout<<"     "<<n<<endl;
    	cout<<" -----------------------------------------------------------------\n\n";
		fil.read((char*)&aluno, sizeof(aluno));
		while(!fil.eof())
		{
			if(strcmp(n,aluno.Nome)==0)
			{
				achou=true;
				m= aluno;
				return true;
			}
			
			fil.read((char*)&aluno, sizeof(aluno));
		}
		if(!achou)
		{
			cout<<"\n Aluno nao encontrado!";
			return false;
		}
	}
	
	fil.close();
}

void deletar() //Verifica se a pessoa buscado existe e o deleta do arquivo .dat
 {
 	int opcao;
 	system("cls");
	cout<<" -----------------------------------------------------------------\n";
    cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
    cout<<" -----------------------------------------------------------------\n";
    cout<<"\t ------------------------------  \n     ";
    cout<<"   |        Deletar registro      ";cout<<"|\t\t\t\t      \n";
    cout<<"   ------------------------------------------- \n";
    cout<<"   | <1> Deletar treinador                    |\n";
    cout<<"   |------------------------------------------|\n";
    cout<<"   | <2> Deletar aluno                        |\n";      
    cout<<"   |------------------------------------------|\n";
    cout<<"\n\n";
	cout<<"Digite uma opcao: ";
 	
 	cin>>opcao;
 	if(opcao==2)deletar_aluno();
 	else if(opcao==1)deletar_treinador();
 	else cout<<"Opcao invalida";
 	
 }

void deletar_aluno() //Verifica se a aluno buscado existe e o deleta do arquivo .dat
{
	fstream fil;
	char n[100];
	bool achou=false;
	cout<<"Digite o nome do aluno: ";
	scanf("%s",&n);
	Aluno aluno;
	ofstream o;
	o.open("new.dat",ios::out|ios::binary);
	fil.open("Member.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"Arquivo nao encontrado!";
		exit(0);
	}
	else
	{
		fil.read((char*)&aluno, sizeof(aluno));
		while(!fil.eof())
		{
			if(strcmp(n,aluno.Nome)!=0)
			{
				o.write((char*)&aluno, sizeof(aluno));
			}
			else
			{
				achou=true;
				 cout<<"Aluno deletado com sucesso!"<<endl;
				
			}
			fil.read((char*)&aluno, sizeof(aluno));
		}
	}
	o.close();
	fil.close();
	remove("Member.dat");
	rename("new.dat", "Member.dat");
}

void deletar_treinador() //Verifica se a treinador buscado existe e o deleta do arquivo .dat
{
	fstream fil;
	char n[100];
	cout<<"Entre o nome do treinador: ";
	scanf("%s",&n);
	Treinador treinador;
	ofstream o;
	bool achou=false;
	o.open("new.dat",ios::out|ios::binary);
	fil.open("Trainer.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"Arquivo nao encontrado!";
		exit(0);
	}
	else
	{
		fil.read((char*)&treinador, sizeof(treinador));
		while(!fil.eof())
		{
			if(strcmp(n,treinador.Nome)!=0)
			{
				o.write((char*)&treinador, sizeof(treinador));
			}
			else
			{
				achou=true;
				 cout<<"Treinador deletado com sucesso"<<endl;
				
			}
			fil.read((char*)&treinador, sizeof(treinador));
		}
	}
	if(!achou)cout<<"\nTreinador nao encontrado!";
	
	o.close();
	fil.close();
	remove("Trainer.dat");
	rename("new.dat", "Trainer.dat");
}

void mostrar_treinadores() //Mostra os treinadores
{
	fstream fil;
	int contador=0;
	Treinador treinador;
	fil.open("Trainer.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"Arquivo nao encontrado!";
		exit(0);
	}
	else
	{
		system("cls");
		cout<<" -----------------------------------------------------------------\n";
      	cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
      	cout<<" -----------------------------------------------------------------\n";
		cout<<"\n";
		cout<<"\t --------------------------  \n     ";
    	cout<<"   |       Treinadores       ";cout<<"|\t\t\t\t      \n";
    	cout<<"         -------------------------- \n"; 
    	cout<<"\n--------------------------------------------------------------------------------";
    	cout<<"\n"<<"   "<<setw(25)<<left<<"Nome"<<setw(18)<<left<<"Telefone"<<setw(10)<<left<<"Altura"<<setw(10)<<left<<"Peso"<<setw(10)<<left<<"Salario";
	
		
		fil.read((char*)&treinador, sizeof(treinador));
		while(!fil.eof())
		{
		
			contador++;			
			
			
			cout<<"\n"<<contador<<"  "<<setw(25)<<left<<treinador.Nome<<setw(18)<<left<<treinador.Telefone<<setw(10)<<left<<treinador.Altura<<setw(10)<<left<<treinador.Peso<<setw(10)<<left<<treinador.Salario;
			fil.read((char*)&treinador, sizeof(treinador));
		}
	}cout<<"\n--------------------------------------------------------------------------------";
	
	fil.close();
}
void mostrar_alunos() //Mostra alunos
{
	fstream fil;
	int contador=0;
	Aluno aluno;
	fil.open("Member.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"Arquivo nao encontrado!";
		exit(0);
	}
	else
	{
		system("cls");
		cout<<" -----------------------------------------------------------------\n";
      	cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
      	cout<<" -----------------------------------------------------------------\n";
		cout<<"\n";
		cout<<"\t --------------------------  \n     ";
    	cout<<"   |          Alunos         ";cout<<"|\t\t\t\t      \n";
    	cout<<"         -------------------------- \n"; 
    	cout<<"\n-------------------------------------------------------------------------------------------------------";
    	cout<<"\n"<<"   "<<setw(25)<<left<<"Nome"<<setw(18)<<left<<"Telefone"<<setw(18)<<left<<"Treinador"<<setw(16)<<left<<"Mensalidade"<<setw(15)<<left<<"Mensalidade com reducao";
		
		
		fil.read((char*)&aluno, sizeof(aluno));
		while(!fil.eof())
		{
		
		contador++;
		
			cout<<"\n"<<contador<<"  "<<setw(25)<<left<<aluno.Nome<<setw(18)<<left<<aluno.Telefone<<setw(18)<<left<<aluno.treinador<<setw(16)<<left<<aluno.Mensalidade;
			//operacao de sobrecarga
			++aluno;
			cout<<setw(16)<<left<<aluno.Mensalidade;
			fil.read((char*)&aluno, sizeof(aluno));
		}
	}	cout<<"\n-------------------------------------------------------------------------------------------------------";
	
	fil.close();
}

void metas() //MOstra o Menu das Metas
{
	int opcao;
	system("cls");
	cout<<" -----------------------------------------------------------------\n";
    cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
    cout<<" -----------------------------------------------------------------\n";
    cout<<"\t ------------- \n     ";
    cout<<"   |   Metas    ";cout<<"|\t\t\t\t      \n";
    cout<<"   ------------------------------------------- \n";
    cout<<"   | <1> Cadastrar Metas                      |\n";
    cout<<"   |------------------------------------------|\n";
    cout<<"   | <2> Consultar Metas                      |\n";      
    cout<<"   |------------------------------------------|\n";
    cout<<"\n\n";
	cout<<"Digite uma opcao: ";
	
	cin>>opcao;		
	if(opcao==1){
		cadastraMeta();
	}
	else if(opcao==2)
	{
		consultaMeta();
	}else
		cout<<"Opcao invalida.";
	
}

bool cadastraMeta() //Cadastra a meta para o Aluno no arquivo .dat
{ 
	Metas meta1;
	fstream fil;
	system("cls");
	cout<<" -----------------------------------------------------------------\n";
  	cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
  	cout<<" -----------------------------------------------------------------\n";
	cout<<"\n";
	cout<<"\t --------------------- \n";
	cout<<"\t |       Metas       | \n"; 
	cout<<"\t --------------------- \n"; 
	cout<<"\n----------------------------------------------------------------\n";
	
	get_aluno();
	get_treinador();
	meta1.setMetas(m, t.Nome);
	
	fil.open("Metas.dat",ios::app| ios::binary);
	fil.write((char*)&meta1, sizeof(meta1));
	cout<<"Dados salvos com sucesso..\n";
	fil.close();
	
}

bool consultaMeta() //Consulta e mostra as metas salvas no arquivo .dat
{
	system("cls");
	cout<<" -----------------------------------------------------------------\n";
  	cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
  	cout<<" -----------------------------------------------------------------\n";
	cout<<"\n";
	cout<<"\t --------------------- \n";
	cout<<"\t |       Metas       | \n";
	cout<<"\t --------------------- \n"; 
	cout<<"\n----------------------------------------------------------------\n";
	
	fstream fil;
	char n[100];
	bool achou=false;
	cout<<"Entre o nome do aluno: ";
	scanf("%s",&n);
	Metas meta1;
	fil.open("Metas.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"Arquivo nao encontrado!";
		return false;
	}
	else
	{
		system("cls");
		cout<<" -----------------------------------------------------------------\n";
    	cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
    	cout<<" -----------------------------------------------------------------\n\n";
    	cout<<"     "<<n<<endl;
    	cout<<" -----------------------------------------------------------------\n\n";
		fil.read((char*)&meta1, sizeof(meta1));
		while(!fil.eof())
		{
			if(strcmp(n,meta1.Aluno::Nome)==0)
			{
				achou=true;
				meta = meta1;
			}
			
			fil.read((char*)&meta1, sizeof(meta1));
		}
		if(!achou)
		{
			cout<<"\n Aluno nao encontrado!";
			return false;
		}
	}
	
	fil.close();
	
	system("cls");
	cout<<" -----------------------------------------------------------------\n";
  	cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
  	cout<<" -----------------------------------------------------------------\n";
	cout<<"\n";
	cout<<"\t -------------------------- \n";
	cout<<"\t |          Metas         | \n";
	cout<<"\t -------------------------- \n"; 
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\n"<<"   "<<setw(13)<<left<<"Nome"<<setw(16)<<left<<"Peso Atual"<<setw(16)<<left<<"Peso Meta"<<setw(16);
	cout<<left<<"Altura"<<setw(16)<<left<<"Meta atingida"<<setw(16)<<left<<"Treinador"<<setw(16)<<left<<"Mensalidade com reducao";
	cout<<"\n"<<"   "<<meta.Aluno::Nome<<"\t\t"<<meta.pesoAtual<<"\t\t"<<meta.pesoMeta<<"\t\t"<<meta.altura<<"\t\t";
	if(meta.metaAtingida) cout<<"Sim\t\t";
	else cout<<"Nao\t\t";
	cout<<meta.Treinador::Nome<<"\t\t"<<meta.Mensalidade;
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
	
}
