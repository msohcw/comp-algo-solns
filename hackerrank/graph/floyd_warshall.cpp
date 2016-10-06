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

int N, M, Q;
int dist[500][500];

int main(){
  scanf("%d%d", &N, &M);
  memset(dist, MEMSET_INF, sizeof(dist));
  for(int i = 1; i <= N; ++i) dist[i][i] = 0;
  for(int i = 0; i < M; ++i){
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    dist[a][b] = w;
  }
  for(int k = 1; k <= N; ++k){
    for(int i = 1; i <= N; ++i){
      for(int j = 1; j <= N; ++j){
        if(dist[i][k] == INF || dist[k][j] == INF) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  scanf("%d", &Q);
  for(int i = 0; i < Q; ++i){
    int a, b;
    scanf("%d %d", &a, &b);
    if(dist[a][b] == INF) dist[a][b] = -1;
    printf("%d\n", dist[a][b]);
  }
}
