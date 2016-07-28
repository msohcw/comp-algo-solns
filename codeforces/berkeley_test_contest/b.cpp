#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int f[110][110];
bool matched[110];
int max_matched = 0;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) scanf("%1d", &f[i][j]);
		matched[i] = false;
	}

	for(int i = 0; i < n; i++){
		if(matched[i]) continue;
		matched[i] = true;
		int matches = 0;

		for(int j = i; j < n; j++){
			bool flag = true;
			for(int k = 0; k < n; k++){
				if(f[i][k] != f[j][k]){
					flag = false;
					break;
				}
			}
			if(flag){
				matched[j] = true;
				matches++;
			}
		}

		max_matched = max(matches, max_matched);
	}

	printf("%d\n", max_matched);
}