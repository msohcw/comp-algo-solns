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

int N, a, b, k;
ll dp[5010][5010];
int mod = 1000000000 + 7;

int ways(int at, int t){
  if(t == 0) return 1;
  if(dp[at][t] != -1) return dp[at][t];
  int sum = 0;
  for(int i = 1; i <= N; ++i){
    if(i == at) continue;
    if(abs(at - i) >= abs(at - b)) continue;
    sum += ways(i, t - 1);
    sum %= mod;
  }
  dp[at][t] = sum % mod;
  return sum % mod;
}

int main(){
  scanf("%d%d%d%d", &N, &a, &b, &k);
  for(int i = 0; i <= N; ++i){
    for(int j = 0; j <= k; ++j){
      dp[i][j] = -1;
    }
  }
  printf("%d\n", ways(a, k));
}
