https://www.hackerrank.com/challenges/strange-advertising?h_r=next-challenge&h_v=zen

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d",&n);
    int i;
    int tot = 0;
    int x = 5;
    for(i = 1 ; i <= n ; i++)
    {
        x = x /2;
        tot = tot + x;
        x = x * 3;
    }
    printf("%d",tot);/* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
