#include <iostream> 

using  namespace  std;

int vybor(int max_num)
{
	string buf;

	while(true)
	{
		cout << "Ваш выбор: " << endl;
		fflush(stdin);//Очищаем поток ввода, там может что-то быть
		cin >> buf;
                if( isdigit(buf[0]) && buf.at(0) - '0' <= max_num && buf.at(0) - '0' > 0 && buf.length() == 1 )
//if( isdigit(buf[0])  проверка, что первый введённый символ - цифра 
// buf.at(0) - '0' <= max_num	и эта цифра меньше числа пунктов в меню (https://upload.wikimedia.org/wikipedia/commons/7/7b/Ascii_Table-nocolor.svg) 
//  buf.at(0) - '0' > 0  и эта цифра больше нуля
//  buf.length() == 1 ) и введён только 1 символ
			break;
		else
			cout << "Неверный ввод " << endl;
	}

	return buf.at(0) - '0';
}

