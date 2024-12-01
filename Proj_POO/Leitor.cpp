#include "header/Leitor.h"
#include <iostream>

// Implementação da classe base Leitor
Leitor::Leitor(const std::string& nome, int idade) : nome(nome), idade(idade) {}
Leitor::~Leitor() {}

std::vector<Leitor*> Leitor::carregarLeitores(const std::string& ficheiro) {
    std::vector<Leitor*> leitores;
    std::ifstream inFile(ficheiro);

    if (!inFile.is_open()) {
        std::cerr << "Erro ao abrir o ficheiro " << ficheiro << "\n";
        return leitores;
    }

    std::string tipo, nome;
    int idade;

    while (inFile >> tipo >> nome >> idade) 
    {
        if (tipo == "Comum") 
        {
            leitores.push_back(new LeitorComum(nome, idade));
        }
        else if (tipo == "Estudante") 
        {
            std::string escola;
            inFile >> escola;
            leitores.push_back(new Estudante(nome, idade, escola));
        }
        else if (tipo == "Professor") 
        {
            std::string departamento;
            inFile >> departamento;
            leitores.push_back(new Professor(nome, idade, departamento));
        }
        else if (tipo == "Senior") 
        {
            leitores.push_back(new Senior(nome, idade));
        }
    }

    inFile.close();
    return leitores;
}


// Implementação da subclasse LeitorComum
LeitorComum::LeitorComum(const std::string& nome, int idade) : Leitor(nome, idade) {}

void LeitorComum::exibirInformacoes() const 
{
    std::cout << "Leitor Comum\n"
              << "Nome: " << nome << "\n"
              << "Idade: " << idade << "\n";
}

int LeitorComum::maximoLivros() const 
{
    return 3; // Leitor comum pode requisitar até 3 livros
}

// Implementação da subclasse Estudante
Estudante::Estudante(const std::string& nome, int idade, const std::string& escola)
    : Leitor(nome, idade), escola(escola) {}

void Estudante::exibirInformacoes() const 
{
    std::cout << "Estudante\n"
              << "Nome: " << nome << "\n"
              << "Idade: " << idade << "\n"
              << "Escola: " << escola << "\n";
}

int Estudante::maximoLivros() const 
{
    return 5; // Estudantes podem requisitar até 5 livros
}

// Implementação da subclasse Professor
Professor::Professor(const std::string& nome, int idade, const std::string& departamento)
    : Leitor(nome, idade), departamento(departamento) {}

void Professor::exibirInformacoes() const 
{
    std::cout << "Professor\n"
              << "Nome: " << nome << "\n"
              << "Idade: " << idade << "\n"
              << "Departamento: " << departamento << "\n";
}

int Professor::maximoLivros() const 
{
    return 10; // Professores podem requisitar até 10 livros
}

// Implementação da subclasse Senior
Senior::Senior(const std::string& nome, int idade) : Leitor(nome, idade) {}

void Senior::exibirInformacoes() const 
{
    std::cout << "Senior\n"
              << "Nome: " << nome << "\n"
              << "Idade: " << idade << "\n";
}

int Senior::maximoLivros() const 
{
    return 2; // Leitores seniores podem requisitar até 2 livros
}
