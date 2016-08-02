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
vi cities;
vi towers;
ll c, t;
ll r = 0;

int main(){
  scanf("%d%d", &N, &M);
  int a;
  for(int i = 0; i < N; ++i){
    scanf("%d", &a);
    cities.push_back(a);
  }
  for(int i = 0; i < M; ++i){
    scanf("%d", &a);
    towers.push_back(a);
  }

  c = 0;
  t = 1;
  if(towers[0] > cities[0]){
    r = towers[0] - cities[0];
    c = 1;
  }
  while(c<N){
    while(cities[c] > towers[t] && t < M) t++;
    int d = cities[c] - towers[t-1];
    if(t < M) d = min(d, towers[t] - cities[c]);
    r = max(r,(ll) d);
    c++;
  }
  cout << r << endl;
}
