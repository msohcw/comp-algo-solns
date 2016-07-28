#include <stdio.h>

using namespace std;

int n;
int g[60][60];
int col = -1;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &g[i][j]);
			if(g[i][j] == n-1 && col == -1) col = j;
		}
	}

	for(int i = 0; i < n; i++){
		int p = g[i][col];
		if(p == 0) p = n;
		printf("%d ", p);
	}
	printf("\n");
}