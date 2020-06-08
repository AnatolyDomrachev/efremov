#include <iostream> 
#include <stdlib.h>
#include <cmath>

using  namespace  std;

int main()
{
	double xn, xk, dx, a, y;
	cout << " Enter xn xk dx a : ";
	cin >> xn >> xk >> dx >> a;

	cout << "x\ty" << endl;
	for(double x=xn; x<=xk; x+=dx)
	{
		if(a*x <= 3)
			y = pow((a+x), 1/5);
		else 
			if(a*x <= 5)
			y = a/x; 
			else
				y = a* sin(x);

		cout << x<< "\t" << y << endl;
	}

	return 0;
}
