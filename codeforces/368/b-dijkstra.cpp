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
#define INF18 1000000000000000000

int N, M, K;
vector<pair<int, ll> > roads[100010];
ll dist[100010];
bool visited[100010];
priority_queue<pair<ll, int>, vector<pair<ll,int> >, std::greater<pair<ll, int> > > Q;

int main(){
  scanf("%d%d%d", &N, &M, &K);
  for(int i = 0; i < M; ++i){
    int u, v, l;
    scanf("%d%d%d", &u, &v, &l);
    roads[u].push_back(make_pair(v,(ll) l));
    roads[v].push_back(make_pair(u,(ll) l));
  }
  
  if(K == 0){
    printf("-1\n");
  }else{
    for(int i = 0; i <= N; ++i) dist[i] = INF18;
    memset(visited, 0, sizeof(visited));
    
    for(int i = 0; i < K; ++i){
      int a;
      scanf("%d", &a);
      dist[a] = 0;
      Q.push(make_pair(0,a));
    }
    
    while(!Q.empty()){
      ii top = Q.top();
      Q.pop();

      ll d = top.first;
      int at = top.second;

      if(visited[at]) continue;
      visited[at] = true;

      for(int i = 0; i < roads[at].size(); ++i){
        if(dist[at] + roads[at][i].second < dist[roads[at][i].first]){
          dist[roads[at][i].first] = d + roads[at][i].second;
          Q.push(make_pair(dist[roads[at][i].first], roads[at][i].first));
        }
      }
    }
    
    ll minD = INF18;
    for(int i = 1; i <= N; ++i){
      if(dist[i] == 0 || visited[i] == false) continue; // is storage
      minD = min(minD, dist[i]);
    }
    if(minD == INF18){
      printf("-1\n");
    }else{
      printf("%I64d\n", minD);
    }
  }
}

