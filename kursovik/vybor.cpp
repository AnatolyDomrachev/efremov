#include <iostream> 

using  namespace  std;

int vybor(int max_num)
{
	string buf;

	while(true)
	{
		cout << "Ваш выбор: " << endl;
		fflush(stdin);
		cin >> buf;
		if( isdigit(buf[0]) && buf.at(0) - 48 <= max_num && buf.length() == 1 )
			break;
		else
			cout << "Неверный ввод " << endl;
	}

	return buf.at(0) - 48;
}

