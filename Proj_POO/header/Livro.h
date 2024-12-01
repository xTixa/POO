#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

// Classe base
class Livro 
{
    protected:
        int ISBN;
        std::string titulo;
        std::string autor;
        int anoPublicacao;

    public:
        Livro(int ISBN, const std::string& titulo, const std::string& autor, int anoPublicacao);
        virtual ~Livro();

        virtual void exibirInformacoes() const = 0;

    static std::vector<Livro*> carregarLivros(const std::string& ficheiro);
    static void guardarLivros(const std::vector<Livro*>& livros, const std::string& ficheiro);

};

// Subclasse: LivroFiccao
class LivroFiccao : public Livro 
{
    private:
        std::string genero;

    public:
        LivroFiccao(int ISBN, const std::string& titulo, const std::string& autor, int anoPublicacao, const std::string& genero);
        void exibirInformacoes() const override;
};

// Subclasse: LivroCientifico
class LivroCientifico : public Livro 
{
    private:
        std::string areaCientifica;

    public:
        LivroCientifico(int ISBN, const std::string& titulo, const std::string& autor, int anoPublicacao, const std::string& areaCientifica);
        void exibirInformacoes() const override;
};

// Subclasse: LivroEducativo
class LivroEducativo : public Livro 
{
    private:
        std::string grauEscolaridade;

    public:
        LivroEducativo(int ISBN, const std::string& titulo, const std::string& autor, int anoPublicacao, const std::string& grauEscolaridade);
        void exibirInformacoes() const override;
};

// Subclasse: Revista
class Revista : public Livro 
{
    private:
        int numeroEdicao;

    public:
        Revista(int ISBN, const std::string& titulo, const std::string& autor, int anoPublicacao, int numeroEdicao);
        void exibirInformacoes() const override;
};

// Subclasse: Jornal
class Jornal : public Livro 
{
    private:
        std::string dataPublicacao;

    public:
        Jornal(int ISBN, const std::string& titulo, const std::string& autor, int anoPublicacao, const std::string& dataPublicacao);
        void exibirInformacoes() const override;
};

#endif