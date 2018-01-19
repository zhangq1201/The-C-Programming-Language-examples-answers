#include<stdio.h>
#define MAXLINE 1000

int getLine(char line[],int maxline);

int main()
{
 	int len;
	char line[MAXLINE];

	while((len = getLine(line,MAXLINE))>0)
	    printf("%4d:%s",len,line);
	return 0;	
}
int getLine(char s[],int lim)
{
	int c,i;
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
		s[i]=c;	
	if(c=='\n'){
	   s[i]=c;
	   ++i;
	}
	s[i]='\0';
	return i;
}
