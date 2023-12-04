#include <stdio.h>
#include <conio.h>
#include <math.h>

int gcd(int a, int b){
	if (a < b){
		int tg = a;
		a = b;
		b = tg;
	}
	while(b){
		int tg = a;
		a = b;
		b = tg % b;
	}
	return a;
}

int gcd2(int a, int b){
	if (a < b){
		int tg = a;
		a = b;
		b = tg;
	}
	if (b == 0)
		return a;
	return gcd2(b, a % b);
}
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d %d\n",a, b);
	printf("%d\n", gcd(a, b));
	printf("%d", gcd2(a, b));
	return 0;
}