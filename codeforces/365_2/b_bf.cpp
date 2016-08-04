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

int N, K;
int b[100010];
int cap[100010];
ll sum = 0;
set<ii> paths;

int main(){
  scanf("%d%d", &N, &K);
  for(int i = 0; i < N; ++i){
    scanf("%d", &b[i]);
    if(i!=0) paths.insert(make_pair(i-1,i));
  }
  paths.insert(make_pair(0,N-1));
  for(int i = 0; i < K; ++i){
    int c;
    scanf("%d", &c);
    c--;
    for(int j = 0; j < N; ++j){
      if(j == c) continue;
      paths.insert(make_pair(min(c,j), max(c,j)));
    }
  }
  set<ii>::iterator it;
  for(it = paths.begin(); it!= paths.end(); it++){
    //printf("%d %d\n", (*it).first+1, (*it).second+1);
    sum += b[(*it).first] * b[(*it).second];
  }
  printf("%lld\n", sum);
}
