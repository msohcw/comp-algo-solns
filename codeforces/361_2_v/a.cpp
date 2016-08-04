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
int num[100];
int col[100];
int row[100];

bool valid(int x, int y){
  bool w = false;
  bool h = false;
  if(x >= 0 && x < 3) w = true;
  if(y >= 0 && y < 4) h = true;
  if(w && h && !(x == 0 && y == 3) && !(x==2 && y ==3)) return true;
  return false;
}


int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    scanf("%1d", &num[i]);
    col[i] = (num[i]-1)%3;
    if(num[i] == 0) col[i] = 1;
    row[i] = ((num[i]+9)%10)/3;
  }
  bool possible = false;
  for(int i = -1; i < 2; ++i){
    for(int j = -1; j < 2; ++j){
      if(i == 0 && j == 0) continue;
      bool valid_shift = true;
      for(int k = 0; k < N; k++){
        if(!valid(col[k]+i, row[k]+j)){
          valid_shift = false;
          break;
        }
      }
      if(valid_shift){
        possible = true;
        break;
      }
    }
  }
  if(possible){
    printf("NO\n");
  }else{
    printf("YES\n");
  }
}
