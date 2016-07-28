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

int ascii(int x){
	if(x >= 97){ //a
		return x - 71; // 26
	}else{
		return x - 65; // 0;
	}
}

int F[100010][60];
int seen[60];
int uniques = 0;

int main(){
	scanf("%d\n", &N);
	memset(F, 0, sizeof(F));

	for(int i = 1; i <= N; i++){
		char c;
		scanf("%c", &c);
		int a = ascii((int) c);
		// printf("%d\n", a);
		F[i][a] = 1;
		if(seen[a] == 0){
			seen[a] = 1;
			uniques++;
		}
	}

	for(int i = 1; i <= N; i++){
		for(int j = 0; j < 52; j++){
			F[i][j] += F[i-1][j];
		}
	}

	int s = 0;
	int e = uniques;
	int minflat = N;
	bool shift_s = false;

	while(s != N - uniques + 1){
		int caught = 0;

		for(int i = 0; i < 52; i++){
			if(F[e][i] - F[s][i] > 0) caught++;
			if(caught == uniques) break;
		}

		if(caught == uniques){
			minflat = min(minflat, e-s);
			if(!shift_s) shift_s = true;
		}else{
			shift_s = false;
		}

		if(e - s < uniques) shift_s = false;
		if(e == N) shift_s = true;

		if(shift_s){
			s++;
		}else{
			e++;
		}
	}
	printf("%d\n", minflat);
}