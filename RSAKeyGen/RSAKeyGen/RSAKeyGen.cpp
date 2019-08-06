#include <iostream>
#include <cstdlib>
#include <ctgmath>

using namespace std;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b);
unsigned long long int mod_inverse(unsigned long long int a, unsigned long long int b);

int main()
{
	unsigned long long int p = 11930;
	unsigned long long int q = 12473;
	unsigned long long int n = 0;
	unsigned long long int totient = 0;
	unsigned long long int e = 10000;
	unsigned long long int d = 0;

	bool pqNotPrime = false;

	cout << "Input p (Must be prime): ";
	/*string input;
	getline(cin, input);
	p = stoull(input);*/
	cout << "Input q (Must be prime): ";
	//getline(cin, input);
	//q = stoull(input);

	n = p * q;
	totient = (p-1)*(q-1);
	unsigned long long int track;

	while(e<totient) {
      track = gcd(e,totient);
      if(track==1)
         break;
      else
         e++;
	}
	unsigned long long int d1 = 1/e;
	d=mod_inverse(d1,totient);

	cout << "e = " << e << " n = " << n << " d = " << d << endl;

}

unsigned long long int mod_inverse(unsigned long long int a, unsigned long long int b) 
{ 
    unsigned long long int g[100], u[100], v[100];
	unsigned long long int i = 1;
	unsigned long long int y;
	g[0]=b;
	g[1]=a;
	u[0]=v[1]=1;
	u[1]=v[0]=0;
	while(g[i])
	{
		g[i]=u[i] * b+ v[i] * a;
		y=g[i-1]/g[i];
		g[i+1]=g[i-1]-y*g[i];
		u[i+1]=u[i-1]-y*u[i];
		i++;
	}

	if (v[i-1] <= 0)
	{
		return v[i-1]+b;
	}
	else
	{
		return v[i-1]+2*b;
	}
} 

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
   unsigned long long int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}