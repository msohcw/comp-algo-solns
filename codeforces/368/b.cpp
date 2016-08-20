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

int N, M, K;
vector<iii> roads;
bool storages[100010];
int minD = INF;

int main(){
  scanf("%d%d%d", &N, &M, &K);
  for(int i = 0; i < M; ++i){
    int u, v, l;
    scanf("%d%d%d", &u, &v, &l);
    roads.push_back(make_pair(make_pair(v,u),l));
    roads.push_back(make_pair(make_pair(u,v),l));
  }
  if(K == 0){
    printf("-1\n");
  }else{
    memset(storages,0,sizeof(storages));
    for(int i = 0; i < K; ++i){
      int a;
      scanf("%d", &a);
      storages[a] = true;
    }
    for(int i = 0; i < roads.size(); ++i){
      int a = roads[i].first.first;
      int b = roads[i].first.second;
      int w = roads[i].second;
      if(storages[a] && !storages[b]) minD = min(minD, w);
    }
    if(minD == INF){
      printf("-1\n");
    }else{
      printf("%d\n", minD);
    }
  }
}
