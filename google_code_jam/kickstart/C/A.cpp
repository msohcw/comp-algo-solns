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

char sub(char A, char B){
  return (char) (((((int) A - 65) - ((int) B - 65) + 26) % 26) + 65);
}

int main(){
  int TC; scanf("%d", &TC);
  for(int _tc = 1; _tc <= TC; ++_tc){
    printf("Case #%d: ", _tc);
    char word[100];
    cin >> word;
    int N = strlen(word);
    bool solved[N];
    char out[N];
    //for(int i = 0; i < N; ++i) out[i] = '!';
    memset(solved, 0, sizeof(solved));
    int solvect = 2;
    out[1] = word[0];
    out[N-2] = word[N-1];
    solved[1] = 1;
    solved[N-2] = 1;

    for(int j = 0; j < N+1; ++j){
      for(int i = 0; i < N; ++i){
        if(solvect >= N) break;
        if(!solved[i]){
          //printf("%d\n", i);
          if(i >=2 && solved[i-2]){
            solved[i] = true;
            out[i] = sub(word[i-1], out[i-2]);
            solvect++;
          }
          if(i+2 < N && solved[i+2] && !solved[i]){
            solved[i] = true;
            out[i] = sub(word[i+1], out[i+2]);
            solvect++;
          }
        }
        //if(word[i] == 'A'){
          //if(i >= 1 && !solved[i-1]) {
            //solved[i-1] = true;
            //out[i-1] = 'A';
            //solvect++;
          //}
          //if(i+1 < N && !solved[i+1]) {
            //solved[i+1] = true;
            //out[i+1] = 'A';
            //solvect++;
          //}
        //}
      }
      //for(int i = 0; i < N; ++i) printf("%c", out[i]);
      //printf("\n");
    }

    if(solvect >= N){
      for(int i = 0; i < N; ++i) printf("%c", out[i]);
      printf("\n");
    }else{
      printf("AMBIGUOUS\n");
    }
  }
}
