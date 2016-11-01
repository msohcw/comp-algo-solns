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
vi days;
vi subs;
int sum = 0;

bool valid(int n){
  bool taken[100010];
  int total = 0;
  int study_time = sum;
  memset(taken, 0, sizeof(taken));
  // printf("trying %d\n", n);
  for(int i = N-n-1; i < N; ++i){
    if(study_time == 0 && total == M) return true;
    if(days[i] && !taken[days[i]]){
      if((N-i-1) - study_time - (M-total-1) < 0) continue;
      // printf("doing exam %d on %d\n", days[i], N-i-1);
      study_time -= subs[days[i]];
      taken[days[i]] = true;
      total++;
    }
  }
  return false;
}

int main(){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; ++i){
    int a; 
    scanf("%d", &a); days.push_back(a);
  }
  subs.push_back(0); 
  for(int j = 0; j < M; ++j){
    int a; scanf("%d", &a); 
    subs.push_back(a);
    sum += a;
  }
  reverse(days.begin(), days.end());   

  int L, R, G;
  L = 0;
  R = N;
  while(L < R){
    G = (L + R)/2;
    if(valid(G)){
      // printf("%d is valid\n", G);
      R = G;
    }else{
      L = G+1;
    }
  }
  if(L == N){
    printf("-1\n");
  }else{
    printf("%d\n", R + 1);
  }
}
