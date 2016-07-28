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
	for(int i = 0; i < N/2; i++) printf("aZ");
}