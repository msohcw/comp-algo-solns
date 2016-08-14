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

int n1, n2, k1, k2;
int dp[110][110][10][2];
int mod = 100000000;

int main(){
  scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
  memset(dp, 0, sizeof(dp));
  
  for(int i = 0; i <= min(k1, n1); ++i) dp[i][0][i][0] = 1;
  for(int i = 0; i <= min(k2, n2); ++i) dp[0][i][i][1] = 1;

  for(int i = 0; i <= n1; ++i){
    for(int j = 0; j <= n2; ++j){
      for(int k = 1; k <= k1; ++k){
        if(i + k > n1) break;
        for(int l = 1; l <= k2; ++l){
          dp[i+k][j][k][0] += dp[i][j][l][1];
          dp[i+k][j][k][0] %= mod;
        }
      }
      for(int k = 1; k <= k2; ++k){
        if(j + k > n2) break;
        for(int l = 1; l <= k1; ++l){
          dp[i][j+k][k][1] += dp[i][j][l][0];
          dp[i][j+k][k][1] %= mod;
        }
      }

    }
  }

  int sum = 0;
  for(int i = 1; i <= k1; ++i){
    sum += dp[n1][n2][i][0];
    sum %= mod;
  }
  for(int i = 1; i <= k2; ++i){
    sum += dp[n1][n2][i][1];
    sum %= mod;
  }
  printf("%d\n", sum);
}
