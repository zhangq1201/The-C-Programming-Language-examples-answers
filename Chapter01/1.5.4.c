#include<stdio.h>
#define IN 1   
#define OUT 0  
int main()
{
	int c,nc,nw,nr,state;
	nc=0;nw=0;nr=0;
	state=OUT;
	while((c=getchar())!=EOF){
		++nc;
		if (c == '\n')
		    ++nr;
		if(c == ' '||c == '\n'||c == '\t')
		    state=OUT;
		else if(state == OUT){
		    state=IN;
		    ++nw;
		}
	}
	printf("%d %d %d\n",nr,nw,nc);
}
