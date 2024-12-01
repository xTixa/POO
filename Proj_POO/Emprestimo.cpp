#include "header/Emprestimo.h"
#include <iostream>
#include <iomanip>
#include <sstream>

// Construtor
Emprestimo::Emprestimo(Livro* livro, Leitor* leitor)
    : livro(livro), leitor(leitor) 
    {
    // Data atual como data do empréstimo
    dataEmprestimo = std::time(nullptr);
    calcularDataDevolucao();
}

std::vector<Emprestimo*> Emprestimo::carregarEmprestimos(const std::string& ficheiro, const std::vector<Livro*>& livros, const std::vector<Leitor*>& leitores) 
{
    std::vector<Emprestimo*> emprestimos;
    std::ifstream inFile(ficheiro);

    if (!inFile.is_open()) 
    {
        std::cerr << "Erro ao abrir o ficheiro " << ficheiro << "\n";
        return emprestimos;
    }

    std::string tituloLivro, nomeLeitor, dataEmprestimo;
    while (inFile >> tituloLivro >> nomeLeitor >> dataEmprestimo) 
    {
        Livro* livro = nullptr;
        Leitor* leitor = nullptr;

        for (auto& l : livros) 
        {
            if (l->getTitulo() == tituloLivro) 
            {
                livro = l;
                break;
            }
        }

        for (auto& l : leitores) 
        {
            if (l->getNome() == nomeLeitor) 
            {
                leitor = l;
                break;
            }
        }

        if (livro && leitor) 
        {
            emprestimos.push_back(new Emprestimo(livros, leitor, dataEmprestimo));
        }
    }

    inFile.close();
    return emprestimos;
}

// Método para calcular a data de devolução
void Emprestimo::calcularDataDevolucao() 
{
    int diasAdicionais = 7; // Prazo padrão: 7 dias

    // Ajuste de prazo baseado no tipo de leitor
    if (dynamic_cast<Estudante*>(leitor)) {
        if (dynamic_cast<LivroEducativo*>(livro)) {
            diasAdicionais = 14; // Estudantes têm mais tempo para livros educativos
        }
    } else if (dynamic_cast<Professor*>(leitor)) {
        if (dynamic_cast<LivroCientifico*>(livro)) {
            diasAdicionais = 21; // Professores têm mais tempo para livros científicos
        }
    } else if (dynamic_cast<Senior*>(leitor)) {
        diasAdicionais = 10; // Seniores têm 10 dias para todos os tipos de livros
    }

    // Calcular a data de devolução
    dataDevolucao = dataEmprestimo + (diasAdicionais * 24 * 60 * 60);
}

// Método para exibir informações do empréstimo
void Emprestimo::exibirInformacoes() const 
{
    std::cout << "Informações do Empréstimo:\n";
    std::cout << "Leitor: ";
    leitor->exibirInformacoes();
    std::cout << "Livro: ";
    livro->exibirInformacoes();
    std::cout << "Data do Empréstimo: " << formatarData(dataEmprestimo) << "\n";
    std::cout << "Data de Devolução: " << formatarData(dataDevolucao) << "\n";
    std::cout << "-----------------------------\n";
}

// Método auxiliar para formatar data
std::string Emprestimo::formatarData(std::time_t data) 
{
    std::ostringstream oss;
    std::tm* tm = std::localtime(&data);
    oss << std::put_time(tm, "%d/%m/%Y");
    return oss.str();
}
