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

int t, s, x;

int main(){
	scanf("%d%d%d", &t, &s, &x);
	if(x < t){
		printf("NO\n");
	}else if((x-t)%s == 0){
		printf("YES\n");
	} else if(x-1-t >=s && (x-1-t)%s ==0){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
}
