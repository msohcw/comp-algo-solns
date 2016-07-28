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
		
		int N;
		int num = 0;
		vii P;

		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			int a;
			scanf("%d", &a);
			num+=a;
			P.push_back(make_pair(a, i));
		}

		sort(P.begin(),P.end());
		reverse(P.begin(), P.end());

		int diff = P[0].first - P[1].first;
		for(int i = 0; i < diff; i++) printf("%c ", 65 + P[0].second);
		P[0].first = P[1].first;
		for(int i = 2; i < P.size(); i++){
			for(int j = 0; j < P[i].first; j++)	printf("%c ", 65 + P[i].second);
		}
		for(int i = 0; i < P[0].first; i++) printf("%c%c ", 65 + P[0].second, 65 + P[1].second);
		printf("\n");
	}
}