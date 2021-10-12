#include "Menu.h"

char* Menu::GetOption()
{
	return opc;
}

void Menu::GetMenu()
{
    cout << "___________________________________" << endl;
    cout << "|\t1)Insert First\t\t  |" << endl;
    cout << "___________________________________" << endl;
    cout << "|\t2)Insert Last\t          |" << endl;
    cout << "___________________________________" << endl;
    cout << "|\t3)Print List\t          |" << endl;
    cout << "___________________________________" << endl;
    cout << "|\t4)Number of elements      |" << endl;
    cout << "___________________________________" << endl;
    cout << "|\t5)Search\t          |" << endl;
    cout << "___________________________________" << endl;
    cout << "|\t6)Modify\t          |" << endl;
    cout << "___________________________________" << endl;
    cout << "|\t7)Delete\t          |" << endl;
    cout << "___________________________________" << endl;
    cout << "|\t8)Exit\t\t          |" << endl;
    cout << "___________________________________" << endl;
    cin >> opc;
}
