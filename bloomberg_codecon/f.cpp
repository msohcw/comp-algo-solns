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
#define INF 2000000000 // 2 billion
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int R, C, M, N;
int food[100][100];
int snake[100][100];
ii dir[100][100];
int sx = 0;
int sy = 0;
int tx = 0;
int ty = 0;
int bite = -1;

int main(){
  scanf("%d %d %d", &R, &C, &M);
  
  memset(food, 0, sizeof(food));
  memset(snake, 0, sizeof(snake));
  
  for(int i = 0; i < M; ++i){
    int r, c;
    scanf("%d %d", &r, &c);
    food[r][c] = 1;
  }

  scanf("%d\n", &N);
  
  snake[sy][sx] = 1;

  for(int i = 0; i < N; ++i){
    char a;
    scanf("%c\n", &a);  
  
    ii ndir = make_pair(0,0);
    if(a == 'U') ndir.second = -1;
    if(a == 'D') ndir.second = 1;
    if(a == 'L') ndir.first = -1;
    if(a == 'R') ndir.first = 1;
    
    dir[sy][sx] = ndir;
    
    sx += ndir.first;
    sy += ndir.second;
    
    if(food[sy][sx] == 1){
      food[sy][sx] = 0;
      if(snake[sy][sx] == 1){
        bite = i + 1;
        break;
      }else{
        snake[sy][sx] = 1;
      }
    }else{
      snake[ty][tx] = 0;
      ii shift = dir[ty][tx];
      ty += shift.second;
      tx += shift.first;
      if(snake[sy][sx] == 1){
        bite = i+1;
        break;
      }else{
        snake[sy][sx] = 1;
      }
    }
    
    // for(int i = 0; i < R; ++i){
    //  for(int j = 0; j < C; ++j){
    //    printf("%d", snake[i][j]);
    //  }
    //  printf("\n");
    // }
    // printf("\n");
  }
  printf("%d\n", bite);
}
