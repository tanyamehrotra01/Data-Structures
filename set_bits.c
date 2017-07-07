/*Given a number N. Write a program to check whether every bit in the binary representation of the given number is set or not.

Input:
First line of input contains a single integer T which denotes the number of test cases. T test cases follows. First line of each test case contains a single integer N which denotes the number to be checked.

Output:
For each test case, print "YES" without quotes if all bits of N are set otherwise print "NO".

Constraints:
1<=T<=1000
0<=N<=1000

Example:
Input:
3
7
14
4
Output:
YES
NO
NO */

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t, i;
	scanf("%d", &t);
	for ( i = 0 ; i < t; i++ )
	{
		int n;
		scanf("%d", &n);
		int x = binary(n);
		int ch = check(x);
		if( ch == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 1;
}

int binary( int n)
{
	int remainder = 0, i = 1, binary = 0;
	while( n!=0)
	{
		remainder = n%2;
		n = n/2;
		binary = binary + (remainder*i);
		i = i * 10;
	}
	return binary;
}

int check(int binary)
{
	while(binary != 0)
	{
		int r = binary % 10;
		binary = binary / 10;
		if( r == 0)
			return 0;
	}
	return 1;
}