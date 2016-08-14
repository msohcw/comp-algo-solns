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

int N;
int a, b, c;
int ribbon[4010];

int main(){
  memset(ribbon, 0, sizeof(ribbon));
  scanf("%d", &N);
  scanf("%d%d%d", &a, &b, &c);

  ribbon[a-1] = ribbon[b-1] = ribbon[c-1] = 1;
  for(int i = 0; i <= N; ++i){
    if(ribbon[i] == 0) continue;
    if(i+a <= N) ribbon[i+a] = max(ribbon[i]+1, ribbon[i+a]);
    if(i+b <= N) ribbon[i+b] = max(ribbon[i]+1, ribbon[i+b]);
    if(i+c <= N) ribbon[i+c] = max(ribbon[i]+1, ribbon[i+c]);
  }
  printf("%d\n", ribbon[N-1]);
}
