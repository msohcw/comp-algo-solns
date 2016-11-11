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

int N, K;
vi houses;
int radios = 0;

int main(){
  scanf("%d%d", &N, &K);
  for(int i = 0; i < N; ++i){
    int a; scanf("%d", &a);
    houses.push_back(a);
  }
  sort(houses.begin(), houses.end());
  int mid = houses[0];
  int left = houses[0];
  radios = 1;
  for(int i = 1; i < N; ++i){
    if((houses[i] - left) <= K){
      mid = houses[i];
    }else if((houses[i] - mid) > K){
      mid = left = houses[i];
      radios++;
    }
  }
  printf("%d\n", radios);
}
