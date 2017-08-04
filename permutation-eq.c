https://www.hackerrank.com/challenges/permutation-equation

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
   int n;
    scanf("%d",&n);
    int p;
    int i;
    int * v = malloc(sizeof(int) * n);
    for( i = 1 ; i <= n ; i++)
    {
        scanf("%d",&p);
        v[p] = i;
    }
    for( i = 1 ; i <= n ; i++)
    {
        printf("%d\n", v[v[i]]);
    }/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
