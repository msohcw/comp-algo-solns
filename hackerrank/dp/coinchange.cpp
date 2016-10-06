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

#define I18F 1000000000000000000 // 10^18
#define INF 2139062143
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int N, M;
vi C;
ll dp[1000][60];
ll memo[1000][60];

// top down
ll coin_change(int n, int m){
  if(n == 0) return 1;
  if(n < 0) return 0;
  if(m < 0) return 0;
  if(memo[n][m] != -1) return memo[n][m];
  memo[n][m] = coin_change(n - C[m], m) + coin_change(n, m-1);
  return memo[n][m];
}

int main(){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < M; ++i){
    int c;
    scanf("%d", &c);
    C.push_back(c);
  }
  sort(C.begin(), C.end());
  
  memset(dp, 0, sizeof(dp));
  for(int i = 0; i <= N; ++i){
    for(int j = 0; j <= M; ++j) memo[i][j] = -1;
  }
  
  // bottom up
  dp[0][0] = 1; 
  for(int i = 0; i <= N; ++i){
    for(int j = 0; j < M; ++j){
      if(j > 0) dp[i][j] += dp[i][j-1];
      dp[i + C[j]][j] += dp[i][j];
    }
  }
  printf("%lld\n", dp[N][M-1]);
  //printf("%lld\n", coin_change(N, M-1));
}
