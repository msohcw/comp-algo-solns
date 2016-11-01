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
vi walks;
vi walks_rev;

int main(){
  scanf("%d%d", &N, &K);

  if(N == 1){
    int d;
    scanf("%d", &d);
    printf("%d\n%d\n", 0, d);
    return 0;
  }else{
    for(int i = 0; i < N; ++i){
      int a;
      scanf("%d", &a);
      walks.push_back(a);
    }
  }

  int total = 0;



  for(int i = 1; i < N; ++i){  
    if((walks[i-1] + walks[i]) < K){
      int diff = K - walks[i-1] - walks[i];
      walks[i] += diff;
      total += diff;
    }
  }

    printf("%d\n", total);
    for(int i = 0; i < walks.size(); ++i) printf("%d ", walks[i]);
    printf("\n");
}
