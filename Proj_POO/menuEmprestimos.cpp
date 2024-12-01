#include <iostream>

using namespace std;
#include "Emprestimo.cpp"

int menuEmprestimos() 
{
    cout << "********Menu Emprestimos*******" << endl;
    cout << "1 - Adicionar Emprestimo" << endl;
    cout << "2 - Remover Emprestimo" << endl;
    cout << "3 - Listar Emprestimos" << endl;
    cout << "4 - Retroceder" << endl;
    cout << "5 - Sair" << endl;
    cout << "************************" << endl;
    cout << "Escolha uma opcao: " << endl;

    int opcao;
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        cout << "Adicionar Emprestimo" << endl;
        break;
    case 2:
        cout << "Remover Emprestimo" << endl;
        break;
    case 3:
        cout << "Listar Emprestimos" << endl;
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