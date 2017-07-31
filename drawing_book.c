https://www.hackerrank.com/challenges/drawing-book/problem

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int solve(int n, int p)
{
    int min ;
    min = (n/2) - (p/2);
    if(min > (p/2))
        min = (p/2);
    return min;
    
}

int main()
{
    int n; 
    scanf("%d", &n);
    int p; 
    scanf("%d", &p);
    int result ;
    result = solve(n, p);
    printf("%d\n", result);
    return 0;
}
