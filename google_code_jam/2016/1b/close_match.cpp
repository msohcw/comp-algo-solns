#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

#define INF 999999999999999999

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int TC;

char C[20];
char J[20];
int c[20], j[20];
int L;

// vector<pair<long, long>> poss;

ll pow10(int a){
	return (long long) pow(10,a);
}

ll diff(ll a, ll b){
	if(a > b) return a - b;
	return b - a;
}

int main(){
	scanf("%d", &TC);
	for(int Tn = 1; Tn <= TC; Tn++){
		printf("Case #%d: ", Tn);
		
		memset(C, 0, sizeof(C));
		memset(J, 0, sizeof(J));
		memset(c, 0, sizeof(c));
		memset(j, 0, sizeof(j));

		scanf("%s %s", &C, &J);
		L = strlen(C);

		int blanks = 0;
		ll baseC = 0;
		ll baseJ = 0;


		for(int i = 0 ; i < L; i++){
			if(C[i] == '?'){
				c[i] = -1;
				blanks++;
			}else{
				c[i] = int(C[i]) - 48;
				baseC += c[i] * pow10(L-i-1);
			}
		}
		for(int i = 0 ; i < L; i++){
			if(J[i] == '?'){
				j[i] = -1;
				blanks++;
			}else{
				j[i] = int(J[i]) - 48;
				baseJ += j[i] * pow10(L-i-1);
			}
		}

		_min = (blanks == 0)? INF : diff(baseJ, baseC);

		for(int i = 0; i < pow10(blanks) - 1){
			for(int j = 0; j < L; j++){
				if(c[j] != -1) continue;
			}
		}
		

		printf("%0*lld %0*lld\n", L, cC,L, cJ);
	}
}

