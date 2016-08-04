#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int N, K;
int b[100010];
bool cap[100010];
ll sum = 0;
ll bmass = 0;
ll prev_cap = 0;

set<ii> paths;

int main(){
  scanf("%d%d", &N, &K);
  for(int i = 0; i < N; ++i){
    scanf("%d", &b[i]);
    if(i!=0) sum += b[i-1]*b[i];
    bmass += b[i];
  }
  sum += b[0] * b[N-1];
  memset(cap,0,sizeof(cap));
  for(int i = 0; i < K; ++i){
    int c;
    scanf("%d", &c);
    c--;
    cap[c] = true;
    ll cap_mass = bmass;
    cap_mass -= b[c]; // self
    cap_mass -= prev_cap; // prev_caps
    int L = (c-1+N)%N;
    int R = (c+1)%N;
    if(!cap[L]) cap_mass -= b[L]; // left
    if(!cap[R]) cap_mass -= b[R]; // right
    sum += cap_mass * b[c];
    prev_cap += b[c];
  }
  printf("%I64d\n", sum);
}
