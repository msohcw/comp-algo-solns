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
		int N, L;
		ll outlets[200];
		ll devices[200];
		scanf("%d %d", &N, &L);

		for(int t = 0; t < 2 ; t++){
			for(int i = 0; i < N; i++){
				ll x = 0;
				int a;
				char A[200];
				scanf("%s", &A);

				for(int j = 0; j < L; j++) x = (x << 1) | (int(A[j]) - 48);
				
				// printf("%lld ", x);
				
				if(!t){
					outlets[i] = x;
				}else{
					devices[i] = x;
				}
			}
		}

		int min_flip = L;
		int possible = false;

		for(int i = 0; i < N; i++){
			ll flip = devices[0] ^ outlets[i];

			bool used[200];
			bool charged[200];
			memset(used, 0, sizeof(used));
			memset(charged, 0, sizeof(charged));

			used[i] = true;
			charged[0] = true;
			
			int total_charged = 1;

			// printf("flip:%lld\n", flip);

			for(int j = 0; j < N; j++){
				if(used[j]) continue;
				for(int k = 1; k < N; k++){
					if(charged[k]) continue;
					if((outlets[j] ^ flip) == devices[k]){
						total_charged++;
						used[j] = true;
						charged[k] = true;
						break;
					}
				}
			}

			// 111

			int flips = 0;
			
			if(total_charged == N){
				possible = true;
				// for(int j = 0; j<L; j++) if((flip >> j) & 1) flips++;
				for(int j = 0; j<L; j++){
					if((flip >> j) & 1){
						flips++;
						// printf("1");
					}else{
						// printf("0");
					}
				}
				// printf("\n");
				min_flip = min(min_flip, flips);
			}
		}

		if(!possible){
			printf("NOT POSSIBLE\n");
		}else{
			printf("%d\n", min_flip);
		}
	}
}