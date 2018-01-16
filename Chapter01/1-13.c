#include<stdio.h>
#define IN 1
#define OUT 0
#define MAXWORD 11
#define MAXHIST 15
int main()
{
	int c,i,j,nc,over,state;
	int len,maxvalue;
	over=0;
	state = OUT;
	int w[MAXWORD];
	for(i=0;i<MAXWORD;++i){
		w[i]=0;
	}
	while((c=getchar())!=EOF){
		if(c==' '||c=='\n'||c=='\t'){
			state=OUT;
			if(nc>0){
			   if(nc<MAXWORD)
				++w[nc];
			   else
				++over;
		 	}
		}else if(state==OUT){
		    state=IN;
		    nc=1;
		}else{
		    ++nc;
		}
	}
	maxvalue=0;
	for(i=1;i<MAXWORD;++i){
		if(w[i]>maxvalue){
			maxvalue=w[i];
		}
	}
	printf("Horizontal histogram:\n");
	for(i=1;i<MAXWORD;++i){
		printf("%5d-%5d:",i,w[i]);
		if(w[i]>0){
		   if((len=w[i]*MAXHIST/maxvalue)<=0){
			len=1;
		   }
		}else{
		   len=0;
		}
		while(len>0){
		   putchar('*');
		   --len;
		}
		putchar('\n');
	}
	printf("\nVertical histogram:\n");
	for(i=MAXHIST;i>0;--i){
	   for(j=1;j<MAXWORD;++j){
		if(w[j]*MAXHIST/maxvalue>=i)
		   printf("%4s","*");
		else
		   printf("%4s"," ");
	   }
	   putchar('\n');
	}
	for(i=1;i<MAXWORD;++i)
	   printf("%4d",i);
	putchar('\n');
	for(i=1;i<MAXWORD;++i)
	   printf("%4d",w[i]);
	putchar('\n');

	if(over>0)
	  printf("There are %d words>=%d\n",over,MAXWORD);
}	

