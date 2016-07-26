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

    int nmX, modeX;
    int nmY, modeY;
    nmX = nmY = 0;
    modeX = modeY = 0;
    
    for(int i = 0; i < N; i++){
        char line[M];
        scanf("%s", &line);
        for(int j = 0; j < M; j++){
           if(line[j] == '*'){
                x[i]++;
                y[j]++;
                p[i][j] = 1;
                pts++;

                if(x[i] > nmX){
                    nmX = x[i];
                    modeX = i;
                }
                if(y[j] > nmY){
                    nmY = y[j];
                    modeY = j;
                }
           }
        }
    }
    
    
    //printf("nmX %d nmY %d modeX %d modeY %d", nmX, nmY, modeX, modeY);
    
    //edge case mode = 1;
    
    bool yes = false;

    if(nmX == 1){
        for(int i = 0; i < N ; i++){
            if(x[i] == 1){
                modeX = i;
                if(nmX + nmY == pts && p[modeX][modeY] != 1 || (nmX + nmY == pts+1 && p[modeX][modeY] == 1)){
                    yes = true;
                    break;
                }
            }
        }
    }else if(nmY == 1){
        for(int i = 0; i < M ; i++){
            if(y[i] == 1){
                modeY = i;
                if(nmX + nmY == pts && p[modeX][modeY] != 1 || (nmX + nmY == pts+1 && p[modeX][modeY] == 1)){
                    yes = true;
                    break;
                }
            }
        }
    }else if((nmX + nmY == pts && p[modeX][modeY] != 1) || (nmX + nmY == pts+1 && p[modeX][modeY] ==1) ){
        yes = true;
    }
    if(yes){
        printf("YES\n");
        printf("%d %d\n", modeX + 1, modeY + 1);
    }else{
        printf("NO\n");
    }
}
