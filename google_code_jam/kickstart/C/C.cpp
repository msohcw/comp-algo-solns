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

short dp[60][60][60][2];

int main(){
  int TC; scanf("%d", &TC);
  for(int _tc = 1; _tc <= TC; ++_tc){
    printf("Case #%d: ", _tc);
    int N, Q; scanf("%d%d", &N,&Q);
    char G[60][60];
    int qn[60][60];
    int ans[100];
    memset(qn, 0, sizeof(qn));

    for(int i = 0; i < N+1; ++i){
      cin >> G[i];
    }

    for(int i = 0; i < N; ++i){
      for(int j = 1; j <= Q; ++j){
        qn[i][j] = (G[i][j-1] == 'T') ? 1 : 0;
      }
    }

    for(int i = 1; i <= Q; ++i){
      ans[i] = (G[N][i-1] == 'T')?1:0;
    }

    if(N == 1){
      for(int i = 0; i <= Q; ++i) qn[1][i] = -1;
    }

    for(int i = 0; i <= Q; ++i){
      for(int j = 0; j <= Q; ++j){
        for(int k = 0; k <= Q; ++k){
          for(int tf = 0; tf < 2; ++tf){
            dp[i][j][k][tf] = -1;
          }
        }
      }
    }

    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;

    for(int i = 0; i <= Q; ++i){
      for(int j = 0; j <= Q; ++j){
        for(int k = 0; k <= Q; ++k){
            int prevmax = max(dp[i][j][k][0], dp[i][j][k][1]);
            for(int atf = 0; atf < 2; ++atf){
              if(dp[i][j][k][atf] < 0) continue;
              for(int tf = 0; tf < 2; ++tf){
                int jadd, kadd;
                jadd = (qn[0][i+1] == tf) ? 1 : 0;
                kadd = (qn[1][i+1] == tf) ? 1 : 0;
                dp[i+1][j+jadd][k+kadd][tf] = (ans[i+1] == tf) ? prevmax + 1 : prevmax;
              }
            }
            if(N == 1) break;
        }
      }
    }
    int tru[10]; tru[1] = 0;
    for(int i = 0; i < N; ++i) scanf("%d", &tru[i]);
    printf("%d\n", max(dp[Q][tru[0]][tru[1]][0],dp[Q][tru[0]][tru[1]][1]));
  }
}
