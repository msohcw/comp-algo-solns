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

int N, M;
int G[1010][1010];
int dp[1010][1010][4];

int main(){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      scanf("%d", &G[i][j]);
    }
  }
  memset(dp, 0, sizeof(dp));
  
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      dp1[i][j] = G[i][j];
      if(i == 0 && j == 0){
        continue;
      }else if (i == 0){
        dp1[i][j] += dp1[i][j-1];
      }else if (j == 0){
        dp1[i][j] += dp1[i-1][j];
      }else{
        dp1[i][j] += max(dp1[i-1][j], dp1[i][j-1]);
      }
    }
  }
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      for(int k = 0; k < 2; ++k){
        // cannot meet in 0,0 0,n m,n, 0,m
        if(k == 1 && i % (M-1) == 0 && j % (M-1) == 0) continue; 
        
      }
    }
  }
}
