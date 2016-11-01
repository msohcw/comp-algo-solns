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
int sum[5010][5010];
int vsum[5010][5010];
int dp[5010][5010];
int plants[5010];

int main(){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; ++i){
    scanf("%d", &plants[i]);
    sum[plants[i]-1][i] = 1;
    double x;
    scanf("%lf", &x);
  }
  for(int i = 0; i < M; ++i){
    for(int j = 1; j < N; ++j){
      sum[i][j] += sum[i][j-1];
    }
  }
  for(int i = 0; i < M; ++i){
    for(int j = 0; j < N; ++j){
      if(i == 0){
        vsum[i][j] = sum[i][j];
      }else{
        vsum[i][j] = sum[i][j] + vsum[i-1][j];
      }
    }
  }
  
  memset(dp, MEMSET_INF, sizeof(dp));
  dp[0][0] = sum[0][N-1];
  for(int i = 1; i <= N; ++i){
    int prev_plant_out = i-1 - sum[0][i-2];
    int plant_in = sum[0][N-1] - sum[0][i-1];
    int plant_out = i - sum[0][i-1];
    dp[0][i] = dp[0][i-1] + prev_plant_out < plant_in + plant_out)? dp[0][i-1] : plant_in;
    //dp[0][i] = dp[0][i-1] + i - 1 - sum[0][i-2];// min(dp[0][i-1], sum[0][N-1] - sum[0][i-1] + i - sum[0][i-1]);
  }
  for(int i = 1; i < M; ++i){
    for(int j = i; j <= N; ++j){
      int prev_plant_out = j-1 - vsum[i][j-2];
      int plant_in = sum[i][N-1] - sum[i][j-1];
      int plant_out = j - vsum[i][j-1];
      dp[i][j] = dp[i][j-1] + prev_plant_out < plant_in + plant_out)? dp[i][j-1] : plant_in;
      // dp[i][j] = min(dp[i][j-1], dp[i-1][j] + sum[i][N-1] - sum[i][j-1] + (N-vsum[i][j-1]));
    }
  }

  printf("sum\n");
  for(int i = 0; i < M; ++i){
    for(int j = 0; j < N; ++j) printf("%d ", sum[i][j]);
    printf("\n");
  }
  printf("vsum\n");
  for(int i = 0; i < M; ++i){
    for(int j = 0; j < N; ++j) printf("%d ", vsum[i][j]);
    printf("\n");
  }
  printf("dp\n");
  for(int i = 0; i < M; ++i){
    for(int j = 0; j <= N; ++j) printf("%d ", dp[i][j]);
    printf("\n");
  }

  printf("%d\n", dp[M-1][N]);
}
