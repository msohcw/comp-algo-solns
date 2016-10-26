#include "contest.h"
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <stdarg.h>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
//#include <unordered_map>
//#include <unordered_set>
#include <bitset>

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

int N;

ll G[400][400];
ll g[800][410];
int dp[810][410][410];
int p[410][410];


int bound(int x){ return min(N-1, max(0, x)); }

int main(){  
  scanf("%d", &N);
  memset(G, 0, sizeof(G));
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      int a;
      scanf("%d", &a);
      G[i][j] = a;
    }
  }

/*
  2 2 2
  1 2 1
  2 2 2

  2 0 0
  1 2 0
  2 2 2
  0 2 1
  0 0 2
*/

  memset(g, 0 , sizeof(g));
  int r, c;
  r = c = 0;
  for(int i = 0; i < N*2-1; ++i){
    int start = (i < N) ? 0 : i - (N-1);
    int end = (i < N) ? i+1 : N; 
    for(int j = start; j < end; ++j){
      g[i][j] = G[r][c];
      if(c+1 >= N || r-1 < 0){
        r = (i+1 < N) ? i+1 : N-1;
        c = (i+1 < N) ? 0 : i - N + 2;
      }else{
        r--;
        c++;
      }
    }
  }
  dp[0][0][0] = g[0][0];
  
  for(int i = 1; i < N*2-2; ++i){
    int start = (i < N) ? 0 : (i-N) + 1;
    int end = (i < N)? i + 1 : N;
    //printf("%d to %d\n", start, end);
    for(int j = start; j < end-1; ++j){
      for(int k = j+1; k < end; ++k){
        //printf("j:%d k:%d ", j, k);
        dp[i][j][k] = max(dp[i-1][j][k-1], dp[i-1][j][k]);
        if(j != 0) dp[i][j][k] = max(max(dp[i][j][k], dp[i-1][j-1][k]), dp[i-1][j-1][k-1]);
        dp[i][j][k] += g[i][j] + g[i][k];
        //printf("%d\n", dp[i][j][k]);
      }
    }
  }
  printf("%d\n", dp[N*2-3][N-2][N-1] + G[N-1][N-1]);
}
