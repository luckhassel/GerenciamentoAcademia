#ifndef Profiles_H
#define Profiles_H
#include"Schedule.h"
#include<string.h>
#include<iostream>

using namespace std;

typedef char String[100];

class Pessoa //Classe Mae
{
	public:
	String Nome;
	String Telefone;
	String Endereco; 
	virtual void GetData(){ 
		//Função virtual na classe pessoa 
	}

};


class Treinador:public Pessoa //Aplicação da herança simples - Treinador herda Pessoa
{
	public:
	float Experiencia;
	float Salario;
	float Altura;
	float Peso;	
	AgendaTreinador agenda_treinador;

	
	void GetData() //Retorna as Informações dos Treinadores
	{
		fflush(stdin);
		system("cls");
	 	cout<<" -----------------------------------------------------------------\n";
      	cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
      	cout<<" -----------------------------------------------------------------\n";
		cout<<"\n";
		cout<<"\t --------------------------  \n     ";
    	cout<<"   |   Adicionar treinador   ";cout<<"|\t\t\t\t      \n";
    	cout<<"         -------------------------- \n\n";
		cout<<"Primeiro nome: "; scanf ("%[^\n]%*c", &Nome);
		cout<<"Telefone: "; scanf ("%[^\n]%*c", &Telefone);	
		cout<<"Endereco: ";scanf ("%[^\n]%*c", &Endereco);
		cout<<"Experiencia: ";scanf ("%[^\n]%*c", &Experiencia);
		cout<<"Salario (Inteiro): "; cin>>Salario;
		cout<<"Altura em cm (Inteiro): "; cin>>Altura;
		cout<<"Peso em kg (Inteiro): "; cin>>Peso;
		cout<<"\nPreencha a agenda ('0' para tempo livre)\n";
		agenda_treinador=AddAgendaTreinador();
	}
	
};

class Aluno:public Pessoa //Aplicação da herança simples - Aluno herda Pessoa
{
	public:
	double Mensalidade;
	AgendaAluno agenda_aluno;
	String treinador;

	void GetData() //Retorna as Informações dos Alunos
	{
		fflush(stdin);
		system("cls");
		cout<<" -----------------------------------------------------------------\n";
      	cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
      	cout<<" -----------------------------------------------------------------\n";
		cout<<"\n";
		cout<<"\t --------------------------  \n     ";
    	cout<<"   |   Adicionar aluno       ";cout<<"|\t\t\t\t      \n";
    	cout<<"         -------------------------- \n\n";
		cout<<"Nome: "; scanf ("%[^\n]%*c", &Nome);
		cout<<"Telefone: "; scanf ("%[^\n]%*c", &Telefone);	
		cout<<"Endereco: "; scanf ("%[^\n]%*c", &Endereco);
		cout<<"Treinador: "; scanf ("%[^\n]%*c", &treinador);
		cout<<"Mensalidade (Inteiro): ";cin>>Mensalidade;		
		cout<<"\nPreencha a agenda ('0' para tempo livre)\n";
		agenda_aluno=AddAgendaAluno();
	}
	//Altera o valor da Mensalidade
	void operator++ ()
	{
		Mensalidade = Mensalidade * 0.95;
	}
	void operator-- ()
	{
		Mensalidade = Mensalidade * 1.05;
	}
};

class Metas:public Aluno, public Treinador{ //Herança Multipla - Metas herda Aluno e Treinador
	public:
		float imc, pesoMeta, pesoAtual, altura;
		bool metaAtingida;
		String objetivo;
		void setMetas(Aluno a, String nomeTr){
			fflush(stdin);
			system("cls");
			cout<<" -----------------------------------------------------------------\n";
	      	cout<<" | ";cout<<"\t\t\tACADEMIA UFPR - TRAINER\t\t\t";cout<<" |\n";
	      	cout<<" -----------------------------------------------------------------\n";
			cout<<"\n";
			cout<<"\t -------------------------- \n";
	    	cout<<"\t |   Adicionar Metas      | \n";
	    	cout<<"\t -------------------------- \n\n";
	    	cout<<"Informe o objetivo do treino: ";
	    	cin>>this->objetivo;
	    	cout<<"Informe o peso atual: ";
	    	cin>>this->pesoAtual;
	    	cout<<"Informe a meta de peso desejada: ";
	    	cin>>this->pesoMeta;
	    	cout<<"Informe a altura: ";
	    	cin>>this->altura;
	    	
	    	imc = calculaIMC();
	    	
	    	if(pesoAtual<pesoMeta){
	    		this->metaAtingida = true;
				++a;	
			} 
			this->Mensalidade = a.Mensalidade;
	    	
	    	strcpy(this->Aluno::Nome, a.Nome);
	    	strcpy(this->Treinador::Nome, nomeTr);
		}

		float calculaIMC(){
			return this->pesoAtual/(altura*altura);
		}
};

#endif

