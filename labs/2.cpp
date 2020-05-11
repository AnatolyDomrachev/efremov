#include <iostream> 
#include <stdlib.h>
#include <cmath>

using  namespace  std;

int main()
{
	int a=1,b=1,c=1;
	double x,sum,slag,tochnost;

	cout << "Enter x, tochnost: ";
	cin >> x >> tochnost;
	if(abs(x) <= 1)
	{
		cout << "Net reshenia";
		return 1;
	}

	double y = asin(1/x);
	cout << "Tochnoe znachenie = " << y;

	slag = 1/x;
	sum = slag;

	cout <<endl;
	cout << "sum\tabs(y-sum)"<<endl;
	cout << sum<< "\t" << abs(y-sum)<<endl;
	int i = 1;
	while(abs(slag) >= tochnost)
	{
		a *= i;
		b = i+2;
		c *= i+1;
		slag = a/(c*b*pow(x,b));
		sum += slag;
		cout << sum<< "\t" << abs(y-sum)<<endl;
		i+=2;
	}

	return 0;
}


