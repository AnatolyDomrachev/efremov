/*
 * � �祭�� ᬥ�� ������ ��⮬�⨧�஢����� �ந�����⢮ (���) ��ࠡ��뢠�� n ⨯�� ��⠫��.
 * �����⭮ �६� ��७������ ��� � ������ ⨯� ��⠫�� �� ��㣮� tij, i=1..n, j=1..n.
 * ��।����� ⠪�� ���冷� ��७������, �� ���஬ �६� ����� ����㤮����� �������쭮.
 * ��᫥ �����襭�� ��ࠡ�⪨ ��� ��⠫�� �ந�����⢮ ᫥��� ����ந�� �� ��⠫� ��室���� ⨯� ��� �����⮢�� ᫥���饣� 横�� �ந�����⢠
 */

#include <iostream>
#include "main.h"
#include <stdlib.h>

using  namespace  std;

int N;
double ** T;

int main()
{
	void (*operations[])() = {vvod, vyvod, reshenie, sohr, vost, end}; //���ᨢ 㪠��⥫�

	while(true)
	{
		cout << "������� ����" << endl;
		cout << "1. ��ନ஢���� ��室��� ������" << endl;
		cout << "2. �뢮�� ��室��� ������ �� �࠭ ���짮��⥫�" << endl;
		cout << "3. ��襭�� ����� ࠧ���묨 ᯮᮡ���" << endl;
		cout << "4. ���࠭���� ��室��� ������ � 䠩��� �� �������� ��᪠�" << endl;
		cout << "5. ����⠭������� ��室��� ������ � 䠩��� �� �������� ��᪠�" << endl;
		cout << "6. ���e�襭�� ࠡ���" << endl;

		int var;
		var = vybor(6);
		operations[var-1]();
	}

	return 0;
}

void end() {exit(0);}
void nothing() {}
