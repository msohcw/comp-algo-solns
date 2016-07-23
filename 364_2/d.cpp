#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
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

int N, L, V1, V2, K;
long double n, l, v1, v2, k;

int main(){
	// I can't believe this is just math >:<
	scanf("%d%d%d%d%d", &N, &L , &V1, &V2, &K);
	n = N;
	l = L;
	v1 = V1;
	v2 = V2;
	k = K;
	long double trips = ceil(n/k) - 1.0;
	long double d  =  (2*v1*trips)/(v1*(1+2*trips)+v2); 
	long double t = d*l/v1 + (1.0-d)*l/v2;
	cout.precision(12);
	cout << t << endl;
}
