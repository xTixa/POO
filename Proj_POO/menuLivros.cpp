#include <iostream>

using namespace std;
#include "Livro.cpp"

int menuLivros() 
{
    cout << "********Menu Livros*******" << endl;
    cout << "1 - Adicionar Livro" << endl;
    cout << "2 - Remover Livro" << endl;
    cout << "3 - Listar Livros" << endl;
    cout << "4 - Retroceder" << endl;
    cout << "5 - Sair" << endl;
    cout << "************************" << endl;
    cout << "Escolha uma opcao: " << endl;

    int opcao;
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        cout << "Adicionar Livro" << endl;
        break;
    case 2:
        cout << "Remover Livro" << endl;
        break;
    case 3:
        cout << "Listar Livros" << endl;
        break;
    case 4:
        cout << "Retroceder..." << endl;
        //main();
        break;
    case 5:
        cout << "A Sair..." << endl;
        break;
    default:
        cout << "Opcao invalida" << endl;
        break;
    }

    return 0;    
}