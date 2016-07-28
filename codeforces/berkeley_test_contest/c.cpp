#include <stdio.h>

using namespace std;

int n = 0;

void combine(int x){
	if(x == 0) return;
	int msb = 0;
	while((1 << msb) <= x) msb++;
	printf("%d ", msb);
	combine(x - (1 << (msb-1)));
	return;
}

int main(){
	scanf("%d", &n);
	combine(n);
	printf("\n");
}