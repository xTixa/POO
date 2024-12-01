#include <iostream>
#include <string>
#include <ctime>

using namespace std;
#include "menuLivros.cpp"
#include "menuLeitores.cpp"
#include "menuEmprestimos.cpp"

int main()
{
    auto livros = Livro::carregarLivros("livros.txt");
    auto leitores = Leitor::carregarLeitores("leitores.txt");
    auto emprestimos = Emprestimo::carregarEmprestimos("emprestimos.txt");

    cout << "********WELCOME*******" << endl;
    cout << "1 - Menu Livros" << endl;
    cout << "2 - Menu Leitores" << endl;
    cout << "3 - Menu Emprestimos" << endl;
    cout << "4 - Sair" << endl;
    cout << "************************" << endl;
    cout << "Escolha uma opcao: " << endl;

    int opcao;
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        cout << "Menu Livros" << endl;
        menuLivros();
        break;
    case 2:
        cout << "Menu Leitores" << endl;
        menuLeitores();
        break;
    case 3:
        cout << "Menu Emprestimos" << endl;
        menuEmprestimos();
        break;
    case 4:
        cout << "A Sair..." << endl;
        break;
    default:
        cout << "Opcao invalida" << endl;
        break;
    }

    return 0;
}