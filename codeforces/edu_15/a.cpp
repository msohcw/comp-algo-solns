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
int maxLen = 0;
int curr = 0;
int last = -1;

int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    int a;
    scanf("%d", &a);
    if(a > last){
      curr++;
      maxLen = max(maxLen, curr);
    }else{
      curr = 1;
    }
    last = a;
  }
  printf("%d\n", maxLen);
}
