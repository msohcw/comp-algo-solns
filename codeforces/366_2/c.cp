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
set<int> unread;
queue<int> apps[300010];
int total = 0;

int main(){
  scanf("%d%d", &N, &Q);
  for(int i = 0; i < Q; ++i){
    int t, d;
    scanf("%d%d", &t , &d);
    if(t == 1){
      apps[d].push(total);
      unread.insert(total);
      total++;
    }else if(t == 2){
      while(!apps[d].empty()){
        unread.erase(apps[d].front());
        apps[d].pop();
      }
    }else if(t == 3){
      while(!unread.empty()){
        if(*(unread.begin()) < d){
          unread.erase(unread.begin());
        }else{
          break;
        }
      }
    }
    int ret = (int) unread.size();
    printf("%d\n", ret);
  }
}
