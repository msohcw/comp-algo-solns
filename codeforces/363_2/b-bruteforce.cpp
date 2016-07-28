#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int x[1010];
int y[1010];
int p[1010][1010];
int pts;

int main(){
    scanf("%d%d", &N, &M);
    
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    memset(p, 0, sizeof(p));
    pts = 0;

    for(int i = 0; i < N; i++){
        char line[M];
        scanf("%s", &line);
        for(int j = 0; j < M; j++){
           if(line[j] == '*'){
                x[i]++;
                y[j]++;
                p[i][j] = 1;
                pts++;
           }
        }
    }
    int X, Y;
    bool flag = false;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(x[i] + y[j] == pts + p[i][j]){
                flag = true;
                X = i+1;
                Y = j+1;
                break;
            }
        }
        if(flag) break;
    }
    if(flag){
        printf("YES\n%d %d\n",X,Y);
    }else{
        printf("NO\n");
    }

}
