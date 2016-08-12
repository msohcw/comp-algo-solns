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


int main(){
  srand(time(NULL));
  printf("200000\n");
  for(int i = 0; i < 2000; ++i){
    for(int j = 0; j < 99; ++j) printf("+ %d\n", rand() % 1000000000);
    printf("? %d\n", rand() % 1000000000);
  }
}
