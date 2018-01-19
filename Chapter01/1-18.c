#include<stdio.h>
#define MAXLINE 1000

int getLine(char line[],int maxline);
int removeblank(char line[]);
int main()
{
 	int len;
	char line[MAXLINE];

	while((len = getLine(line,MAXLINE))>0){
	    if(removeblank(line)>0)
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
int removeblank(char line[])
{
	int i;
	i=0;
	while(line[i]!='\n')
		++i;
	--i;
	while(i>0 &&(line[i]==' '||line[i]=='\t'))
		--i;
	if(i>=0){
	   ++i;
	   line[i]='\n';
	   ++i;
	   line[i]='\0';
	}
	return i;		
}	

