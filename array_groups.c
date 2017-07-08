/*Given an array Arr[] of N distinct integers. Write a program to find the count of groups of 2 or 3 integers that can be formed by choosing integers from the given array such that sum of integers in each of the group is divisible by three.

Input:
First line of input contains a single integer T which denotes the number of test case. Then T test case follows. First line of each test case contains a single integer N which denotes number of elements in the array. Second line of each test case contains N space separated integers.

Output:
For each test case, print the count of all the groups of 2 or 3 integers formed from the given array such that sum of elements in the group is divisible by 3.

Constraints:
1<=T<=100
1<=N<=105
1<=Arr[i]<=105

Example:
Input:
2
6
1 5 7 2 9 14
4
3 6 9 12
Output:
13
10*/

#include<stdio.h>
#include<stdib.h>

int comb(int n, int r)
{
	if(r == 2)
		return (int)(n * (n-1))/2;
	return (int)(n * (n-1) * (n-2))/6;
}

int main()
{
	int t;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int *a = malloc(sizeof(int)*n);
		int i;
		for ( i = 0 ; i < n ; i++)
		{
			scanf("%d",&a[i]);
			int mod = *a[i]%3;
			if(mod == 0)
				j++;
			else if(mod == 1)
				k++;
			else
				l++;
		}
		int result = 0;
		if(j >= 2)
			result = result + comb(j,2);
		if(j >= 3)
			result = result + comb(j,3);
		if(k >= 3)
			result = result + comb(k,3);
		if(l >= 3)
			result = result + comb(l,3);
		result = result + ( j * k * l);
		result = result + ( k * l);
		printf("%d\n", result);
	}
}