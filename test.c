#include "stdio.h"
void plus(int a){
	a++;
}
int main(){
	int a = 0;
	plus(a);
	printf("%d",a);
}