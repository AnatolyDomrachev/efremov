//3. ���� �ନ஢���� ��室��� ������  ������ �।�ᬠ�ਢ��� ��� ०���:
//3.1. ��筮� ���� ��室��� ������ ���짮��⥫�� � ����������;
//3.2. ������� �᭮����  ��ꥬ�� ��室��� ������ ��砩�� ��ࠧ��.

#include <iostream> 
#include "main.h"
#include <random> //�㦭� ��� ࠭����
#include <ctime>//�㦭� ��� ࠭����

using  namespace  std;

void vvod()
{
	void (*operations[])() = {vvod_1, vvod_2, nothing};

	cout << "1. ��筮� ���� ��室��� ������ ���짮��⥫�� � ����������;" << endl;
	cout << "2. ������� �᭮����  ��ꥬ�� ��室��� ������ ��砩�� ��ࠧ��." << endl;
	cout << "3. ������ � ������� ����"<< endl;

	int var;
	var = vybor(3);
	operations[var-1]();

}

void vvod_1()
{
	cout << "������ ������⢮ ��⠫��"<< endl;
	N = vybor(200);

	//ᮧ��� �������᪨� ��㬥�� ���ᨢ
	T = new double*[N];
	for (int i=0; i<N; i++)
		T[i] = new double[N];

	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if(i != j)
			{
				cout << "������ t["<<i+1<<"]["<<j+1<<"]"<< endl;
				cin >> T[i][j];
			}
}

void vvod_2()
{
	srand(time(0));   //��� �⮣� ���� ���� � � �� ���祭��
	cout << "������ ������⢮ ��⠫��"<< endl;
	N = vybor(20);

	//ᮧ��� �������᪨� ��㬥�� ���ᨢ
	T = new double*[N];
	for (int i=0; i<N; i++)
		T[i] = new double[N];

	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if(i != j)
			{
				T[i][j] = rand()%10+1; //࠭��� �� 1 �� 10
			}
}


