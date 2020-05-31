//    5. ���� �襭�� ����砥� ᫥���騥 ��� ��� �ਡ������� ᯮᮡ� �襭�� �।�������� ��⨬���樮���� ����� (����� �롮� �������� �襭�� �� ������⢠ �����⨬�� �襭��):
//        5.1. ������᪮� �襭��;
//        5.2. ����� ��ॡ�� ������⢠ �����⨬� �襭��.

#include <iostream> 
#include <vector> //�⮡� �ᯮ�짮���� vector
#include "main.h"
#include <algorithm> //�⮡� �ᯮ�짮���� ������� vector
#include <string.h>

using  namespace  std;

struct node
{
	int i;
	int j;
};

void reshenie()
{
	void (*operations[])() = {reshenie_1, reshenie_2, nothing};

	cout << "1. ������᪮� �襭��;" << endl;
	cout << "2. ����� ��ॡ�� ������⢠ �����⨬� �襭��." << endl;
	cout << "3. ������ � ������� ����"<< endl;

	int var;
	var = vybor(3);
	operations[var-1]();
}

void reshenie_1()
{
	vector<int> result;	

	//���� �������쭮�� �६��� ���室�
	int imin=0, jmin=0, ib, jb;
	int *begin, *end;
	double tmin = T[0][1];
	double tmini,tminj;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if(i != j && T[i][j] < tmin)
			{
				tmin = T[i][j];
				imin = i;
				jmin = j;
			}

	result.push_back(imin);
	result.push_back(jmin);
	
	for(auto x: result )
		cout << x+1 << " ";
	cout << endl;

	// ������塞 ��⠫�� ��⠫�
	while( result.size() != N )
	{
		//�஢��塞 �� ��⠫� ����� i ��� ��� � १����
		for (int i=0; i<N; i++)
			if(find(result.begin(),result.end(),i) == result.end()) //���� ���祭�� i � ����� result
			//�᫨ �� �������
			{
				imin = i;
				break;
			}

		// �饬 �� ����� ��⠫� ����॥ �ᥣ� ��३� � ��ࢮ� ��⠫� १����
		// ����� �� ��⠢���� ���⠢��� ��। ��ࢮ� � १����
		tmini = T[imin][result.front()]; //��⠥�, �� �������쭮� �६� �� ���室 �� imin � ��ࢮ�� ������ result

		for (int i=imin; i<N; i++)
			if(i != result.front() && find(result.begin(),result.end(),i) == result.end() && T[i][result.front()] < tmini)
			//if(i != result.front() - i �� ���� ����� १����
			 //find(result.begin(),result.end(),i) == result.end() - i ��� � १����
			 //T[i][result.front()] < tmini) - ���室 �� i � ��ࢮ�� ������ १���� ����� tmini
			{
				tmini = T[i][result.front()];
				imin = i;
			}

		// �饬 � ����� ��⠫� ����॥ �ᥣ� ��३� �� ��᫥���� ��⠫� १����
		// ����� �� ��⠢���� ���⠢��� ��᫥ ��᫥���� � १����
		for (int j=0; j<N; j++)
			if(find(result.begin(),result.end(),j) == result.end())
			{
				jmin = j;
				break;
			}

		tminj = T[result.back()][jmin];

		for (int j=jmin; j<N; j++)
			if(j != result.back() && find(result.begin(),result.end(),j) == result.end() && T[result.back()][j] < tminj)
			{
				tminj = T[result.front()][j];
				jmin = j;
			}

		//�஢��塞 ��� �룮���� ���⠢��� ��⥫� - ���砫� ��� ����� १����
		if(tmini < tminj)
			result.insert(result.begin(), imin); //���������� ��⠫� � ��砫� १����
		else
			result.push_back(jmin); //���������� ��⠫� � ����� १����
	
		//�뢮� १����
		for(auto x: result )
			cout << x+1 << " ";
		cout << endl;
	
	}
}

int factorial()
{
	  int res = 1;
	  for (int i = 1; i <= N; i++) {
		res = res * i;
	  }

	  return res;
}

bool NextSet(int *a, int n)
{
  int j = n - 2;
  while (j != -1 && a[j] >= a[j + 1]) j--;
  if (j == -1)
    return false; // ����� ����⠭���� ���
  int k = n - 1;
  while (a[j] >= a[k]) k--;
  swap(a[j], a[k]);
  int l = j + 1, r = n - 1; // ����㥬 ��⠢����� ���� ��᫥����⥫쭮��
  while (l<r)
    swap(a[l++], a[r--]);
  return true;
}

int dtime(int* a)
{
	int s = 0;
	for (int i = 0; i < N-1; i++)
	{
		int d1,d2;
		d1 = a[i];
		d2 = a[i+1];
		s += T[d1][d2];
	}

	return s;
}

void reshenie_2()
{
	int* a = new int[N];
	int* amin = new int[N];

	for (int i = 0; i < N; i++)
		a[i] = i;

	int tmin = dtime(a);
	memcpy(amin, a, N*sizeof(int));

	while( NextSet(a, N))
	{
		for (int i = 0; i < N; i++)
			cout << a[i]+1 << " ";
		cout << " : " <<  dtime(a) << endl;
		
		if(dtime(a) < tmin)
		{
			tmin = dtime(a);
			memcpy(amin, a, N*sizeof(int));
		}	
	}

	for (int i = 0; i < N; i++)
		cout << amin[i] + 1 << " ";

	cout << endl;
}

