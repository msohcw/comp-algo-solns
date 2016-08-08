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
int nots[100000];
int apps[100000];
int total = 0;
int read = 0;

int main(){
  scanf("%d%d", &N, &Q);
  for(int i = 0; i < Q; ++i){
    int t, a;
    scanf("%d%d", &t, &a);
    if(t == 1){
      nots[total] = a;
      apps[a]++;
      total++;
    }else if(t == 2){
      read += apps[a];
      apps[a] = 0;
    }else if(t == 3){
      for(int j = 0; j < a; ++j){
        if(apps[nots[j]] > 0){
          read++;
          apps[nots[j]]--;
        }
      }
    }
    printf("%d\n", total - read);
  }
}
