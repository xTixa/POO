#include "header/Livro.h"
#include <iostream>

// Implementação da classe base
Livro::Livro(int ISBN, const std::string& titulo, const std::string& autor, int anoPublicacao)
    : titulo(titulo), autor(autor), anoPublicacao(anoPublicacao) {}

Livro::~Livro() {}

std::vector<Livro*> Livro::carregarLivros(const std::string& ficheiro) 
{
    std::vector<Livro*> livros;
    std::ifstream inFile(ficheiro);

    if (!inFile.is_open()) {
        std::cerr << "Erro ao abrir o ficheiro " << ficheiro << "\n";
        return livros;
    }

    int ISBN;
    std::string tipo, titulo, autor, extra;
    int anoPublicacao;

    while (inFile >> tipo >> titulo >> autor >> anoPublicacao >> extra) 
    {
        if (tipo == "Ficcao") 
        {
            livros.push_back(new LivroFiccao(ISBN, titulo, autor, anoPublicacao, extra));
        }
        else if (tipo == "Cientifico") 
        {
            livros.push_back(new LivroCientifico(ISBN, titulo, autor, anoPublicacao, extra));
        }
        else if (tipo == "Educativo") 
        {
            livros.push_back(new LivroEducativo(ISBN, titulo, autor, anoPublicacao, extra));
        }
        else if (tipo == "Revista") 
        {
            livros.push_back(new Revista(ISBN, titulo, autor, anoPublicacao, std::stoi(extra)));
        }
        else if (tipo == "Jornal") 
        {
            livros.push_back(new Jornal(ISBN, titulo, autor, anoPublicacao, extra));
        }
    }

    inFile.close();
    return livros;
}

void Livro::guardarLivros(const std::vector<Livro*>& livros, const std::string& ficheiro) 
{
    std::ofstream outFile(ficheiro);

    if (!outFile.is_open()) 
    {
        std::cerr << "Erro ao abrir o ficheiro " << ficheiro << "\n";
        return;
    }

    for (const auto& livro : livros) 
    {
        // Use polimorfismo para salvar as informações específicas de cada livro.
        outFile << "Ficcao" << " " << livro->titulo << " " << livro->autor << " " << livro->anoPublicacao << " " << "Extra\n";
        outFile << "Cientifico" << " " << livro->titulo << " " << livro->autor << " " << livro->anoPublicacao << " " << "Extra\n";
        outFile << "Educativo" << " " << livro->titulo << " " << livro->autor << " " << livro->anoPublicacao << " " << "Extra\n";
        outFile << "Revista" << " " << livro->titulo << " " << livro->autor << " " << livro->anoPublicacao << " " << "Extra\n";
        outFile << "Jornal" << " " << livro->titulo << " " << livro->autor << " " << livro->anoPublicacao << " " << "Extra\n";
    }

    outFile.close();
}

void Livro::exibirInformacoes() const 
{
    std::cout << "Título: " << titulo << "\n"
              << "Autor: " << autor << "\n"
              << "Ano de Publicação: " << anoPublicacao << "\n";
}

// Implementação de LivroFiccao
LivroFiccao::LivroFiccao(int ISBN, const std::string& titulo, const std::string& autor, int anoPublicacao, const std::string& genero)
    : Livro(ISBN, titulo, autor, anoPublicacao), genero(genero) {}

void LivroFiccao::exibirInformacoes() const 
{
    Livro::exibirInformacoes();
    std::cout << "Gênero: " << genero << "\n";
}

// Implementação de LivroCientifico
LivroCientifico::LivroCientifico(int ISBN, const std::string& titulo, const std::string& autor, int anoPublicacao, const std::string& areaCientifica)
    : Livro(ISBN, titulo, autor, anoPublicacao), areaCientifica(areaCientifica) {}

void LivroCientifico::exibirInformacoes() const 
{
    Livro::exibirInformacoes();
    std::cout << "Área Científica: " << areaCientifica << "\n";
}

// Implementação de LivroEducativo
LivroEducativo::LivroEducativo(int ISBN, const std::string& titulo, const std::string& autor, int anoPublicacao, const std::string& grauEscolaridade)
    : Livro(ISBN, titulo, autor, anoPublicacao), grauEscolaridade(grauEscolaridade) {}

void LivroEducativo::exibirInformacoes() const 
{
    Livro::exibirInformacoes();
    std::cout << "Grau de Escolaridade: " << grauEscolaridade << "\n";
}

// Implementação de Revista
Revista::Revista(int ISBN, const std::string& titulo, const std::string& autor, int anoPublicacao, int numeroEdicao)
    : Livro(ISBN, titulo, autor, anoPublicacao), numeroEdicao(numeroEdicao) {}

void Revista::exibirInformacoes() const 
{
    Livro::exibirInformacoes();
    std::cout << "Número da Edição: " << numeroEdicao << "\n";
}

// Implementação de Jornal
Jornal::Jornal(int ISBN, const std::string& titulo, const std::string& autor, int anoPublicacao, const std::string& dataPublicacao)
    : Livro(ISBN, titulo, autor, anoPublicacao), dataPublicacao(dataPublicacao) {}

void Jornal::exibirInformacoes() const 
{
    Livro::exibirInformacoes();
    std::cout << "Data de Publicação: " << dataPublicacao << "\n";
}
