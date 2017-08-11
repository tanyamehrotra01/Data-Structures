/* https://www.hackerrank.com/challenges/sherlock-and-squares
INTERMEIATE VALUE THEOREM */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int i,j;
        int count = 0;
        
        count= floor(sqrt(b)) - ceil(sqrt(a)) + 1;
        printf("%d\n",count);
    }/* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
