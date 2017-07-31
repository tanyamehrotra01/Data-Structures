https://www.hackerrank.com/challenges/electronics-shop

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

 int getMoneySpent(int* keyboards,int n, int* drives, int m, int s){
    int i,j;
     int z = -1;
     
    for( i = 0 ; i < n ; i++)
    { 
        for( j = 0 ; j < m ; j++)
        {
            int sum = keyboards[i] + drives[j];
           
            if(sum <= s && sum > z)
                z = sum;
            
        }
    }
    return z;// Complete this function
}

int main() {
    int s; 
    int n; 
    int m; 
    scanf("%d %d %d", &s, &n, &m);
    int *keyboards = malloc(sizeof(int) * n);
    for(int keyboards_i = 0; keyboards_i < n; keyboards_i++){
       scanf("%d",&keyboards[keyboards_i]);
    }
    int *drives = malloc(sizeof(int) * m);
    for(int drives_i = 0; drives_i < m; drives_i++){
       scanf("%d",&drives[drives_i]);
    }
    //  The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
     int moneySpent = getMoneySpent(keyboards,n, drives,m, s);
    printf("%d\n", moneySpent);
    return 0;
}
