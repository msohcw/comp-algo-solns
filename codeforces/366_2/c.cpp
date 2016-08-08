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

int N, Q;
ii apps[300010];
int nots[300010];
int total = 0;
int read = 0;
int tsubbed = 0;
map<int, int> treads;

int main(){
  scanf("%d%d", &N, &Q);
  for(int i = 1; i <= N; ++i) apps[i] = make_pair(0,0);
  for(int i = 0; i < Q; ++i){
    int type, a;
    scanf("%d%d", &type, &a);
    if(type == 1){
      apps[a].first++;
      nots[total] = a;
      total++;
    }else if(type == 2){
      read += apps[a].first - apps[a].second;
      apps[a].second = apps[a].first;
    }else if(type == 3){
      printf("do from %d to %d\n", tsubbed, a);
      if(a > tsubbed){
        for(int j = tsubbed; j < a; ++j){
          printf("MORE FOR %d\n", nots[j]);
          if(treads[nots[j]]){
            treads[nots[j]] = treads[nots[j]]+1;
          }else{
            treads[nots[j]] = 1;
          }
        }
        map<int, int>::iterator it;
        for(it = treads.begin(); it!= treads.end(); ++it){
          printf("update app %d %d\n", (*it).first, (*it).second);
          if(apps[(*it).first].second < (*it).second){
            read += (*it).second - apps[(*it).first].second;
            apps[(*it).first].second = (*it).second;
          }
        }
      }
      tsubbed = a;
    }
    printf("%d\n", total - read);
  }
}
