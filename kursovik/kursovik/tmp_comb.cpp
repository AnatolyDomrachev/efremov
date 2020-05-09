#include <iostream>
using namespace std;
/*
int factorial()
{
	  int res = 1;
	  for (int i = 1; i <= N; i++) {
		res = res * i;
	  }

	  return res;
}
*/

bool NextSet(int *a, int n)
{
  int j = n - 2;
  while (j != -1 && a[j] >= a[j + 1]) j--;
  if (j == -1)
    return false; // больше перестановок нет
  int k = n - 1;
  while (a[j] >= a[k]) k--;
  swap(a[j], a[k]);
  int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
  while (l<r)
    swap(a[l++], a[r--]);
  return true;
}

void Print(int *a, int n)  // вывод перестановки
{
  static int num = 1; // номер перестановки
  cout.width(3); // ширина поля вывода номера перестановки
  cout << num++ << ": ";
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}

int main() 
{
  int n, *a;
  cout << "N = ";
  cin >> n;
  a = new int[n];
  for (int i = 0; i < n; i++)
    a[i] = i + 1;
  Print(a, n);


  while (NextSet(a, n))
    Print(a, n);
  return 0;
}
