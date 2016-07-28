#include <stdio.h>

using namespace std;

int T;
char s[10][4];
int matchLen[10];
int matchedTo[10];
bool start[10];

int aim = 39;

int tail(int c){
	if(matchedTo[c] == -1) return c;
	return tail(matchedTo[c]);
}

bool match(int a, int b, int l){
	bool flag = true;
	for(int i = 0; i < l; i++){
		if(s[a][i + 4 - l] != s[b][i]){
			flag = false;
			break;
		} 
	}
	return flag;
}

void printStr(int a){
	for(int i = matchLen[a]; i < 4; i++) printf("%c",s[a][i]);
	if(matchedTo[a] != -1) printStr(matchedTo[a]);
}

int main(){
	scanf("%d\n\n", &T);
	for(int t = 0; t < T; t++){
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 4; j++) scanf("%c", &s[i][j]);
			if(i == 9) scanf("\n\n");
			if(i < 9) scanf(" ");
			matchLen[i] = 0;
			matchedTo[i] = -1;
			start[i] = true;
		}
		int length = 40;
		for(int l = 4; l > 0; l--){
			for(int i = 0; i < 10; i++){
				for(int j = 0; j < 10; j++){
					if(i == j) continue;
					if(!start[j]) continue;
					if(matchedTo[i] != -1) continue;
					if(tail(j) == i) continue;
					if(match(i, j, l)){
						matchedTo[i] = j;
						start[j] = false;
						matchLen[j] = l;
						length -= l;
					}
				}
			}
		}
		for(int i = 0; i < 10; i++) if(start[i]) printStr(i);
		for(int i = 0; i < aim - length; i++) printf("A");
		printf("\n");
	}
	return 0;
}