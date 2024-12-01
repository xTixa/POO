#ifndef LEITOR_H
#define LEITOR_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

// Classe base
class Leitor 
{
    protected:
        std::string nome;
        int idade;

    public:
        // Construtor e destrutor
        Leitor(const std::string& nome, int idade);
        virtual ~Leitor();

        // Método virtual para exibir informações
        virtual void exibirInformacoes() const = 0;

        // Método virtual para obter o número máximo de livros
        virtual int maximoLivros() const = 0;

    static std::vector<Leitor*> carregarLeitores(const std::string& ficheiro);
    static void guardarLeitores(const std::vector<Leitor*>& leitores, const std::string& ficheiro);
};

// Subclasse: LeitorComum
class LeitorComum : public Leitor 
{
    public:
        LeitorComum(const std::string& nome, int idade);
        void exibirInformacoes() const override;
        int maximoLivros() const override;
};

// Subclasse: Estudante
class Estudante : public Leitor 
{
    private:
        std::string escola;

    public:
        Estudante(const std::string& nome, int idade, const std::string& escola);
        void exibirInformacoes() const override;
        int maximoLivros() const override;
};

// Subclasse: Professor
class Professor : public Leitor 
{
    private:
        std::string departamento;

    public:
        Professor(const std::string& nome, int idade, const std::string& departamento);
        void exibirInformacoes() const override;
        int maximoLivros() const override;
};

// Subclasse: Senior
class Senior : public Leitor 
{
    public:
        Senior(const std::string& nome, int idade);
        void exibirInformacoes() const override;
        int maximoLivros() const override;
};

#endif
