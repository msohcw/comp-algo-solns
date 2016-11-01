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
char line[10][10];
vi rep;
int translate[30];
int chars = 0;
int length = 0;

int ctoi(char a){return ((int) a) - 65;}
int digit(char a){return rep[translate[ctoi(a)]];}
int colsum(int c, int carry){
  int sum = 0;
  for(int i = 0; i < N-1; ++i){
    if(c >= strlen(line[i])) continue;
    sum += digit(line[i][strlen(line[i]) - c - 1]);
  }
  return sum + carry;
}

int ways = 0;

int fact(int x){return (x == 0 || x == 1)? 1 : x * fact(x-1);}

int main(){
  scanf("%d", &N);
  for(int i = 0; i < 10; ++i) rep.push_back(i);
  for(int i = 0; i < 26; ++i) translate[i] = -1;
  for(int i = 0; i < N; ++i){
    cin >> line[i];
    length = max(length, (int) strlen(line[i]));
    for(int j = 0; j < strlen(line[i]); ++j){
      if(translate[ctoi(line[i][j])] == -1){
        translate[ctoi(line[i][j])] = chars;
        chars++;
      }
    }
  }
  do{  
    bool flag = false;
    for(int i = 0; i < N; ++i){
      if(rep[translate[ctoi(line[i][0])]] == 0){
        flag = true;
        break;
      }
    }
    if(flag) continue;

    int carry = 0;
    for(int i = 0; i < length; ++i){
      int result = colsum(i, carry);
      if(result % 10 != digit(line[N-1][strlen(line[N-1]) - i - 1])){
        flag = true;
        break;
      }else{
        carry = result / 10;
      }
    }
    if(flag) continue;
    if(carry == 0) ways++;    
  } while (next_permutation(rep.begin(), rep.end()));
  printf("%d\n", int(double(ways)/double(fact(10 - chars))));
}
