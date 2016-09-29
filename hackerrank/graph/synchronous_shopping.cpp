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
typedef pair<int, pair<int, int> > iii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define I18F 1000000000000000000 // 10^18
#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int N, M, K;
int visited[1010][1100];
int mindist[1010][1110];
vii adj[1010];
int fish[1010];
priority_queue<iii, vector<iii>, greater<iii> > Q;

int print_bin(int x){
  for(int i = 0; i < K; ++i) printf("%d ", (x >> i) & 1);
}

int main(){
  scanf("%d%d%d", &N, &M, &K);
  for(int i = 0; i < N; ++i){
    int k;
    int f = 0;
    scanf("%d", &k);
    for(int j = 0; j < k; ++j){
      int a;
      scanf("%d", &a);
      f |= (1 << (a-1));
    }
    fish[i] = f;
  }
  
  for(int i = 0; i < M; ++i){
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    a--;
    b--;
    adj[a].push_back(make_pair(b,w));
    adj[b].push_back(make_pair(a,w));
  }

  //memset(mindist, 63, sizeof(mindist[0][0]) * 1010 * 1110);
  for(int i = 0 ; i < N; ++i){
    for(int j = 0; j < 1 << K; ++j){
      mindist[i][j] = INF;
    }
  }

  mindist[0][fish[0]] = 0;
  Q.push(make_pair(0,make_pair(0, fish[0])));
  
  while(!Q.empty()){
    iii top = Q.top();
    int w, at, bot;
    w = top.first;
    at = top.second.first;
    bot = top.second.second;

    //printf("at %d, ", at);
    //print_bin(bot);
    //printf("dist %d\n", w);

    Q.pop();
    for(int i = 0; i < adj[at].size(); ++i){
      int next = adj[at][i].first;
      //printf("next %d mindist %d ", next, mindist[at][bot | fish[next]]);
      //print_bin(bot | fish[next]);
      //printf("\n");
      if(w + adj[at][i].second < mindist[next][bot | fish[next]]){
        mindist[next][bot | fish[next]] = w + adj[at][i].second;
        Q.push(make_pair(w + adj[at][i].second, make_pair(next, bot | fish[next])));
      }
    }
  }
  int min_total = 2000000000;
  for(int i = 0; i < 1 << K; ++i){
    for(int j = 0; j < 1 << K; ++j){
      if((i | j) != (1 << K) - 1) continue;
      //printf("trying ");
      //print_bin(i);
      //printf(" ");
      //print_bin(j);
      //printf(" %d, %d\n", mindist[N-1][i], mindist[N-1][j]);

      min_total = min(min_total, max(mindist[N-1][i], mindist[N-1][j]));
    }
  }
  printf("%d\n", min_total);
}
