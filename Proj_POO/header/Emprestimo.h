#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "Livro.h"
#include "Leitor.h"
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <iostream>

// Classe responsável por gerir empréstimos
class Emprestimo 
{
    private:
        Livro* livro;
        Leitor* leitor;
        std::time_t dataEmprestimo;
        std::time_t dataDevolucao;

    public:
        // Construtor
        Emprestimo(Livro* livro, Leitor* leitor);

        // Calcular a data de devolução com base no tipo de leitor e livro
        void calcularDataDevolucao();

        // Exibir as informações do empréstimo
        void exibirInformacoes() const;

        // Função auxiliar para converter time_t para string
        static std::string formatarData(std::time_t data);

    static std::vector<Emprestimo*> carregarEmprestimos(const std::string& ficheiro, const std::vector<Livro*>& livros, const std::vector<Leitor*>& leitores);
    static void guardarEmprestimos(const std::vector<Emprestimo*>& emprestimos, const std::string& ficheiro);
};

#endif
