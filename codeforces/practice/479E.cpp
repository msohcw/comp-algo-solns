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
int mod = 1000000000 + 7;
ll dp[5010][5010];
ll sum[5010];
int minmax[5010][2];
int main(){
  scanf("%d%d%d%d", &N, &a, &b, &k);
  for(int i = 1; i <= N; ++i){
    minmax[i][0] = N;
    minmax[i][1] = 0;
  }
  for(int i = 1; i <= N; ++i){
    for(int j = 1; j <=N; ++j){
      if(abs(i-j) >= abs(i-b)) continue;
      if(j == i) continue;
      minmax[j][0] = min(i, minmax[j][0]);
      minmax[j][1] = max(i, minmax[j][1]);
    }
  }
  
  memset(dp, 0, sizeof(dp));
  dp[0][a] = 1;
  for(int i = 0; i < k; ++i){
    sum[0] = 0;
    for(int j = 1; j <= N; ++j) sum[j] = dp[i][j] + sum[j-1];
    for(int j = 1; j <= N; ++j){
      if(j == b || minmax[j][0] > minmax[j][1]) continue;
      dp[i+1][j] = (sum[minmax[j][1]] - sum[minmax[j][0]-1]);
      if(minmax[j][1] >= j && minmax[j][0] <= j) dp[i+1][j] -= dp[i][j];
      dp[i+1][j] %= mod;
    }
  }
  
  int ans = 0;
  for(int i = 1; i <= N; ++i){
    ans += dp[k][i];
    ans %= mod;
  }
  printf("%d\n", ans);
}
