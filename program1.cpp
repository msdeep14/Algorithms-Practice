#include <stdio.h>
int main(){
	int x = 10;
	int y = 10;
	int z = 10;
	x = x++;
	y++;
	z = ++z;
	printf("value of x -> %d\n",x);
	printf("value of y -> %d\n",y);
	printf("value of z -> %d\n",z);
	return 0;
}