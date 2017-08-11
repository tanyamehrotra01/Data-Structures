/* https://www.hackerrank.com/challenges/cut-the-sticks */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int main(){
    int n; 
    scanf("%d",&n);
    int a[n];
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&a[arr_i]);
    }
   int i,j;
    for( i = 0 ; i < n - 1 ; i++)
    {
        for(j = 0 ; j < n - i - 1; j++)
        {
            if(a[j] > a[j+1])
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    
    printf("%d\n",n);
    for( i = 1 ; i < n ; i++)
    {
        if(a[i] != a[i-1])
            printf("%d\n",n-i);
    }
    
    return 0;
}
