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
vi prices; 
int Q;

int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    int a;
    scanf("%d", &a);
    prices.push_back(a);
  }
  sort(prices.begin(), prices.end());
  scanf("%d", &Q);
  for(int i = 0; i < Q; ++i){
    int a;
    scanf("%d", &a);
    int num = upper_bound(prices.begin(), prices.end(), a) - prices.begin();
    printf("%d\n", num);
  }
}
