#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int N;
vii cards;

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int a;
		scanf("%d", &a);
		cards.push_back(make_pair(a,i + 1));
	}
	sort(cards.begin(), cards.end());
	for(int i = 0; i < N/2; i++){
		printf("%d %d\n", cards[i].second, cards[N-i-1].second);
	}
}
