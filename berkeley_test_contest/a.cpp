#include <stdio.h>

using namespace std;

int c = 0;

int main(){
	char a;
	while(a != '\n'){
		scanf("%c",&a);
		c++;
	}
	printf("%d\n",(c-1) * 25 + 26);
}