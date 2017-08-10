/*Given two numbers. Add the numbers and find the count of carries in their addition.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two integer N and M as input.

Output:
For each test case, In new line print the count of carries.

Constraints:
1<=T<=1000
1<=N,M<=1018

Example:
Input:
2
345 234
2345 535

Output:
0
1 */

#include <stdio.h>

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    unsigned long long int a,b;
	    scanf("%llu %llu",&a,&b);
	    if( a == 0 && b == 0)
	        break;
	   unsigned long long int count = 0, carry = 0;
	   while( a != 0 || b != 0)
	   {
	       int r1 = a % 10;
	       int r2 = b % 10;
	       int sum = r1 + r2;
	       if( sum > 9)
	       {
	           count++;
	           carry++;
	       }
	       a = a / 10;
	       b = b / 10;
	   }
	   carry = 0;
	   printf("%llu\n",count);
	}
	
	return 0;
}

/*The first test case where your code failed:

Input:
19038672367386932 74914628 

Its Correct output is:
7

And Your Output is:
6*/
