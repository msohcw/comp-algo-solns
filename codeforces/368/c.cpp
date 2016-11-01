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

int N;
bool found = false;
ll ret1, ret2;

int main(){
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i){
    if(N%i!=0) continue;
    if(found) break;
    for(int j = 1; j <= N; ++j){
      if(j * j >= (N/i)/2) break;
      if(found) break;
      double test = sqrt((N/i) - j*j);
      if(test == floor(test)){
        ll m = floor(test);
        ll a, b;
        a = i * (m*m - j*j);
        b = i * 2 * m * j;
        ret1 = a;
        ret2 = b;
        found = true;
      }
    }
  }
  
  for(int i = 1; i <= N; ++i){
    if(N%i!=0) continue;
    if(found) break;
    for(int j = 1; j <= N; ++j){
      int rem = N/i;
      if(found) break;
      double test = sqrt(rem + j*j);
      if(test > N) break;
      if(test == floor(test)){
        ll m = floor(test);
        ll a, b;
        a = i * (m*m + j*j);
        b = i * 2 * m * j;
        ret1 = a;
        ret2 = b;
        found = true;
      }
    }
  }
  for(int i = 1; i <= N; ++i){
    if(N%i!=0) continue;
    if(found) break;
    for(int j = 1; j <= N; ++j){
      int rem = N/i;
      if(j >= rem/2) break;
      if(found) break;
      double test = rem/2/j;
      if(test == floor(test)){
        ll m = floor(test);
        ll a, b;
        a = i * (m*m - j*j);
        b = i * (m*m + j*j);
        ret1 = a;
        ret2 = b;
        found = true;
      }
    }
  }
  if(found){
    printf("%I64d %I64d\n", ret1, ret2);
  }else{
    printf("-1\n");
  }

}
