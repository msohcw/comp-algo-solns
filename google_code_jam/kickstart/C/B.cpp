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

int main(){
  int TC; scanf("%d", &TC);
  for(int _tc = 1; _tc <= TC; ++_tc){
    printf("Case #%d: ", _tc);
    char G[100][100];
    memset(G, 0, sizeof(G));
    int N; scanf("%d", &N);
    for(int i = 0; i < N; ++i){
      cin >> G[i];
    }
    bool flag = true;
    bool onedone = false;
    set<ii> cols, rows;

    for(int i = 0; i < N; ++i){
      if(!flag) break;
      int ct = 0;
      int f, s;
      for(int j = 0; j < N; ++j){
        if(G[i][j] == 'X'){
          ct++;
          if(ct == 1) f = j;
          if(ct == 2) s = j;
        }
      }
      if(ct == 1 && !onedone){
        onedone = true;
        continue;
      }else if (ct != 2){
        flag = false;
      }else{
        cols.insert(make_pair(f, s));
      }
    }

    onedone = false;

    for(int i = 0; i < N; ++i){
      if(!flag) break;
      int ct = 0;
      int f, s;
      for(int j = 0; j < N; ++j){
        if(G[j][i] == 'X'){
          ct++;
          if(ct == 1) f = j;
          if(ct == 2) s = j;
        }
      }
      if(ct == 1 && !onedone){
        onedone = true;
        continue;
      }else if (ct != 2){
        flag = false;
      }else{
        rows.insert(make_pair(f, s));
      }
    }

    if(flag && cols.size() == (N/2) && rows.size() == (N/2)){
      printf("POSSIBLE\n");
    }else{
      printf("IMPOSSIBLE\n");
    }
  }
}
