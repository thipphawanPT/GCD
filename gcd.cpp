#include <iostream>
#include <cstdlib>
using namespace std;

/* 
* The description is from wikipedia.org, "Greatest common divisor". Coding by myself 'PT9843' 
*/




/* Euclid's algorithm
* The method introduced by Euclid for computing greatest common divisors is based on fact that, given two positive
* integers a and b such that a > b, the common divisors of a and b are the same as the common divisors of a-b and b.
* So, Euclid's method for computing the greatest common divisor of two positive integers consists of replacing 
* the larger number by the difference of the numbers, and repeating this until the two numbers are equal: 
* that is their greatest common divisor.
*
* Note : This method can be very slow if one number is much larger than the other. 
*/


int gcd(int a, int b)
{
	int m = a;
	int n = b;
	while (m!=n)
	{
		if(m>n)
			m = m-n;
		else
			n = n-m;
	}

 return m;
}



/* Euclidean algorithm
* A more efficient method is the Euclidean algorithm, a variant in which the difference of the two numbers a and b
* is replaced by the remainder of the Euclidean division (also called division with remainder) of a by b.
* Denoting this remainder as a mod b, the algorithm replaces (a, b) by (b, a mod b) repeatedly until the pair is (d, 0), 
* where d is the greatest common divisor.
*/


int gcd_recursive(int a,int b)
{
	if (b == 0)
		return a;
	else
		return gcd_recursive(b, a%b);
}


/* Binary Euclidean algorithm */
// DOI: https://doi.org/10.1007/0-387-23483-7_26

int binary_gcd(int a, int b)
{
	int u = a;
	int v = b;
	int g = 1;
	while (u%2==0 && v%2==0)
	{
		u = u/2;
		v = v/2;
		g = 2*g;
	}
	while (u != 0)
	{
		while (u%2 == 0)
		{
			u = u/2;
		}
		while (v%2 ==0)
		{
			v = v/2;
		}
		
		int t = abs(u-v);	
		
		if(u >= v)
		{
			u=t;	
		}
		else
		{
			v=t;
		}
	}
	return g*v;
}

int main()
{
	int result1 = gcd(48,18);
	int result2 = gcd_recursive(48,18); 
	int result3 = binary_gcd(48,18);
	
	cout << "1 Euclid's algorithm : " << result1 << endl;
	cout << "2 Euclidean algorithm : " << result2 << endl;
	cout << "3 Binary Euclidean algorithm : " << result3 << endl; 
}