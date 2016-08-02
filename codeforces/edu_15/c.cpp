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
ll s, e, r;

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
  s = 0;
  e = INF;
  
  while(s < e){
    r = (s+e)/2;
    bool covered = true;
    for(int i = 0; i < N; i++){
      int low = lower_bound(towers.begin(), towers.end(), cities[i]) - towers.begin();
      int high = upper_bound(towers.begin(), towers.end(), cities[i]) - towers.begin();
      if(towers[low] == cities[i]) continue;
      if(low != 0) low--; // the one before cities[i]
      if(high == M) high--;
      if(abs(towers[low] - cities[i]) <= r || abs(towers[high] - (ll) cities[i]) <= r) continue;
      covered = false;
      break;
    }
    if(covered){
      e = r;
    }else{
      s = r+1; 
    }
  }
  cout << s << endl;
}
