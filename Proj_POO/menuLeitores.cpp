#include <iostream>

using namespace std;
#include "Leitor.cpp"

int menuLeitores() 
{
    cout << "********Menu Leitores*******" << endl;
    cout << "1 - Adicionar Leitores" << endl;
    cout << "2 - Remover Leitores" << endl;
    cout << "3 - Listar Leitores" << endl;
    cout << "4 - Retroceder" << endl;
    cout << "5 - Sair" << endl;
    cout << "************************" << endl;
    cout << "Escolha uma opcao: " << endl;

    int opcao;
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        cout << "Adicionar Leitores" << endl;
        break;
    case 2:
        cout << "Remover Leitores" << endl;
        break;
    case 3:
        cout << "Listar Leitoress" << endl;
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

