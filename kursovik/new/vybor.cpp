#include <iostream> 

using  namespace  std;

int vybor(int max_num)
{
	string buf;

	while(true)
	{
		cout << "��� �롮�: " << endl;
		fflush(stdin);//��頥� ��⮪ �����, ⠬ ����� ��-� ����
		cin >> buf;
                if( isdigit(buf[0]) && buf.at(0) - '0' <= max_num && buf.at(0) - '0' > 0 && buf.length() == 1 )
//if( isdigit(buf[0])  �஢�ઠ, �� ���� ������ ᨬ��� - ��� 
// buf.at(0) - '0' <= max_num	� �� ��� ����� �᫠ �㭪⮢ � ���� (https://upload.wikimedia.org/wikipedia/commons/7/7b/Ascii_Table-nocolor.svg) 
//  buf.at(0) - '0' > 0  � �� ��� ����� ���
//  buf.length() == 1 ) � ����� ⮫쪮 1 ᨬ���
			break;
		else
			cout << "������ ���� " << endl;
	}

	return buf.at(0) - '0';
}

