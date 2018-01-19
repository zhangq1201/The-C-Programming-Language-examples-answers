#include<stdio.h>
#define MAXLINE 1000

int getLine(char line[],int maxline);
void reverse(char s[]);
int main()
{
 	int len;
	char line[MAXLINE];

	while((len = getLine(line,MAXLINE))>0){
	    reverse(line);
	    printf("%s",line);
	}
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
void reverse(char s[])
{
	int i,n=0;
	char tmp;
	while(s[n]!='\n')
	    ++n;
	for(i=0;i<(n-1)/2;++i){
	    int j=n-i-1;
	    tmp=s[i];
	    s[i]=s[j];
	    s[j]=tmp;
	}	
}
