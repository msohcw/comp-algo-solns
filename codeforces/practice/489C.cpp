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


int M, S;

bool can(int m, int s){ return s >= 0 && s <= m*9; }

int minC[110];
int maxC[110];

int main(){
  scanf("%d%d", &M, &S);
  int maxsum = S;
  int minsum = S;
  int places = (S+8)/9;
  if(M == 1 && S == 0){
    printf("0 0");
  }else if(places > M || places == 0){
    printf("-1 -1");
  }else{
    for(int i = 0; i < M; ++i){
      for(int d = 0; d < 10; ++d){
        if((i > 0 || d > 0 || (M == 1 && d == 0)) && can(M-i-1, minsum-d)){
          minC[i] = d;
          minsum -= d;
          break;
        }
      }
      for(int d = 9; d >= 0; --d){
        if((i > 0 || d > 0 || (M == 1 && d == 0)) && can(M-i-1, maxsum-d)){
          maxC[i] = d;
          maxsum -= d;
          break;
        }
      }
    }
  
    for(int i = 0; i < M; ++i) printf("%d", minC[i]);
    printf(" ");
    for(int i = 0; i < M; ++i) printf("%d", maxC[i]);
  }
  printf("\n");
}
