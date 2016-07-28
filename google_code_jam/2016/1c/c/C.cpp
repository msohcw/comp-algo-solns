#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

#define INF 2000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int TC;

int main(){
	scanf("%d", &TC);
	for(int Tn = 1; Tn <= TC; Tn++){
		printf("Case #%d: ", Tn);

		int worn[400][400];
		int J, P, S, K;
		scanf("%d %d %d %d", &J, &P, &S, &K);
		
		memset(worn,0,sizeof(worn));
		int num = 0;

		for(int i = 1; i <= S; i++){
			for(int j = 1; j <= P; j++){
				for(int k = 1; k <= J; k++){
					// printf("%d %d %d\n", i, j*10, k*100);
					if(worn[i][j*10] >= K || worn[i][k*100] >= K || worn[j*10][k*100] >= K) continue;  
					worn[i][j*10] +=1;
					worn[i][k*100] +=1;
					worn[j*10][k*100] +=1;
					num++;
				}
			}
		}

		printf("%d\n", num);
		memset(worn,0,sizeof(worn));
		for(int i = 1; i <= S; i++){
			for(int j = 1; j <= P; j++){
				for(int k = 1; k <= J; k++){
					if(worn[i][j*10] >= K || worn[i][k*100] >= K || worn[j*10][k*100] >= K) continue;  
					printf("%d %d %d\n", k, j, i);
					worn[i][j*10] +=1;
					worn[i][k*100] +=1;
					worn[j*10][k*100] +=1;
					// num++;
				}
			}
		}
		
	}
}