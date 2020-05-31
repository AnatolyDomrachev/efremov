#include <iostream>
#include <stdlib.h>

using  namespace  std;

struct node
{
	int i;
	int j;
};

int main()
{
	struct node s;
	cin >> s.i;
	cin >> s.j;

	cout << s.i;
	cout << s.j;

	return 0;
}

