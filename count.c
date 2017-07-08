/*Given two unsorted arrays A, B. They can contain duplicates. For each element in A , count elements less than or equal to it in array B .

Time Complexity: O(n)

Input:
The first line contains a single integer T i.e. the number of test cases. The first line of each test case consists of a integer N. The second and third line of each test case consists of N spaced integers representing array A and array B respectively. 

Output: 
In one line for each element in array A print the elements less than or equal to it in array B with a comma ',' in between .

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
6
1 2 3 4 7 9
0 1 2 1 1 4
7
95 39 49 20 67 26 63 
77 96 81 65 60 36 55 
Output:
4,5,5,6,6,6
6,1,1,0,4,0,3*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		int *a, *b;
		int n;
		scanf("%d",&n);
		a = malloc(sizeof(int)*n);
		b = malloc(sizeof(int)*n);
		int x,y;
		for( x = 0 ; x < n ; x++)
			scanf("%d", &a[x]);
		for( y = 0 ; y < n ; y++)
			scanf("%d", &b[y]);
	
		int i,j;
		for( i = 0 ; i < n ; i++)
		{
			int count = 0;
			for( j = 0 ; j < n ; j++)
			{
				if ( a[i] >= b[j])
					count++;
			}
			if( i != n-1)
				printf("%d,",count);
			else
				printf("%d\n",count);
		}
	}
}