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

int N, M;
int x[100010];
int y[100010];
int xuniq = 0;
int yuniq = 0;

long long empty;

int main(){
	scanf("%d %d", &N, &M);

	empty = N;
	empty *= N;
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		empty -= (N-1) * 2 + 1;
		
		if(x[a]) empty += (N-1) + 1;
		if(y[b]) empty += (N-1) + 1;
		if(x[a] && y[b]) empty -= 1;

		if(x[a] && y[b] == 0) empty += (xuniq - 1);
		if(y[b] && x[a] == 0) empty += (yuniq - 1);
		if(x[a] == 0 && y[b] == 0) empty += xuniq + yuniq;

		if(x[a] == 0){
			x[a] = 1;
			xuniq++;
		}
		if(y[b] == 0){
			y[b] = 1;
			yuniq++;
		}

		cout << empty << " ";
	}
}
