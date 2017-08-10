/*Write a method to replace all the spaces in a string with ‘%20’. You may assume that the string has sufficient space (or allocated memory) at the end to hold the additional characters,

Input:
The first line of input contains an integer T denoting the number of test cases. The T test cases follow. Each test case contains an string and integer with length of string with extra spaces.

Output:
Print the string with spaces replaced by "%20".

Constraints:
1<=T<=1000
1<=length of result string<=1000

Example:
Input:
2
Mr John Smith
13
Mr Benedict Cumberbatch  
25

Output:
"Mr%20John%20Smith"
"Mr%20Benedict%20Cumberbatch */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    char *s = malloc(sizeof(char) * 100000);
	    scanf(" %[^\n]s",s);
	    int i;
	    int l;
	    scanf("%d",&l);
	    int len = strlen(s);
	    for(i = len-1; i >=0 ; i--)
	    {
	        if(isalpha(s[i]))
	            break;
	        else if(s[i] == ' ')
	            s[i] = '\0';
	    }
	    for( i = 0 ; i < len ; i++)
	    {
	        if(s[i] == ' ')
	            printf("%%20");
	       else
	        printf("%c",s[i]);
	    }
       printf("\n");
	    
	} 
	return 0;
}
