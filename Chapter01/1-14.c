#include<stdio.h>
#define MAXHIST 15
int main()
{
	int c,i,len,maxvalue=0;
	int w[100];
	for(i=0;i<100;i++)
		w[i]=0;
	while((c=getchar())!=EOF){
		if(c >= 'a'|| c <= 'z'||c >= 'A'|| c <= 'Z'){
			++w[c-'A'];
		}
	}
	for(i=0;i<100;i++){
		if(w[i]>maxvalue){
		   maxvalue=w[i];
		}
	}
	for(i=0;i<100;++i){
		if(w[i]>0){
		    len=w[i]*MAXHIST/maxvalue;
		    printf("%c-%3d：",i+'A',w[i]);
		    while(len>0){
		       putchar('*');
		       --len;
		    }
		    putchar('\n');
		}
	}
}
        

