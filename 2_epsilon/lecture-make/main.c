#include<stdio.h>

int main(){
	printf("hello, world\n");

	int i=0;
	if(i==1) printf("true\n");
	else printf("false\n");

	for(int i=0,n=2;i<10;i++,n++) printf("i=%i,n=%i\n",i,n);

return 0;
}