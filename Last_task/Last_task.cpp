#include <iostream>
#include <string>
#include <sstream>
#include "NodeAVL.h";
#include "Node.h";

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	string keys;
	cout << "Введите ключи дерева в формате: 7 2 3 1 8 9 23\n";
	getline(cin, keys);
	istringstream ss(keys);
	string str;

	NodeAVL* top = 0;
	while (ss>> str)
	{
		stringstream geek;
		geek << str;
		int key = 0;

		geek >> key;
		if (!top) {
			top = new NodeAVL(key);
		}
		else {
			top = top->Insert(top, key);
		}
	}

	top->Display(top, 0);

	cout << "\n\n";

	top->Display(top->Search(top, 4),0);

	cout << "\n\n";

	top->Remove(top, 4);

	top->Display(top, 0);
}

