https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int k; 
    int e = 100;
    scanf("%d %d",&n,&k);
    int *c = malloc(sizeof(int) * n);
    for(int c_i = 0; c_i < n; c_i++){
       scanf("%d",&c[c_i]);
    }
    int i;
    for( i = 0 ; i < n ; i+=k)
    {
        if(i > n)
        {
            i = n - i;
            if ( i == 0)
                break;
        }
        
        else
        {
        if(c[i] == 1)
        {
            e = e - 2 - 1;
        }
        else 
        {
            e = e - 1;
        }
        }
    }
    printf("%d",e);
    return 0;
}
