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

int N, T;
vii adj[500];
int source, sink, wizards, skills;
int main(){
  scanf("%d%d", &N, &T);
  source = 0;
  sink = 1 + N*2 + T;
  wizards = 1 + N*2;
  skills = 1 + N;
  for(int i = 0; i < N; ++i){
    int c;
    scanf("%d", &c);
    adj[0].push_back(make_pair(i+1,c));  
    adj[1+i].push_back(make_pair(0,-c));
    adj[skills+i].push_back(make_pair(sink, 1));
    adj[sink].push_back(make_pair(skills+i,-1));
  }
  for(int i = 0; i < T; ++i){
    int l;
    scanf("%d", &l);
    for(int j = 0; j < l; ++j){
      int a;
      scanf("%d", &a);
      adj[a].push_back(make_pair(wizards + i, 1));
      adj[wizards + i].push_back(make_pair(a, -1));
    }
    scanf("%d", &l);
    for(int j = 0; j < l; ++j){
      int a;
      scanf("%d", &a);
      adj[wizards + i].push_back(make_pair(skills+a-1, 1));
      adj[skills+a-1].push_back(make_pair(wizards+i, -1));
    }
  }
  /*
  for(int i = 0; i <= sink; ++i){
    printf("%d: ", i);
    for(int j = 0; j < adj[i].size(); ++j){
      printf("%d/%d ", adj[i][j].first, adj[i][j].second);
    }
    printf("\n");
  }
  */
   
}
