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
bool color = false;

int main(){
  scanf("%d %d\n", &N, &M);
  for(int i = 0; i < N; ++i){
    char line[300];
    memset(line, 0, sizeof(line));
    fgets(line, 300, stdin);
    for(int j = 0; j < strlen(line); ++j){
      if(line[j] == 'C' || line[j] == 'M' || line[j] == 'Y') color = true;
    }
  }
  if(color){
    printf("#Color\n");
  }else{
    printf("#Black&White\n");
  }
}
