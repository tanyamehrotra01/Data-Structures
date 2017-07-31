https://www.hackerrank.com/challenges/picking-numbers/problem

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void sort(int *a, int n)
{
    int i,j;
    for(i = 0 ; i < n-1 ; i++)
    {
        for( j = 0 ; j  < n-i-1 ; j++)
        {
            if( a[j] > a[j+1])
            {
                int t = a[j];
                a[j]= a[j+1];
                a[j+1] = t;
            }
        }
    }
}

int main(){
    int n; 
    scanf("%d",&n);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    int i;
    int max_count = 0;
    int count = 0;
    sort (a,n);
    for( i = 0 ; i < n ; i++)
    {
         int j;
        for( j = i ; j < n ; j++)
        {
            if(abs(a[i]-a[j]) <= 1)
            {
                count++;
                
            }
            
        }
        if(count > max_count)
             max_count = count;
        count = 0;
    }
    printf("%d",max_count);
    return 0;
}

