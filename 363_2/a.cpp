#include <stdio.h>
#include <algorithm>

using namespace std;


int minT = 1000000000;

bool pos = false;
int N;
int particle[200010][2];

int main(){
    scanf("%d\n", &N);
    for(int i = 0; i < N; i++){
        char c;
        scanf("%c",&c);
        if(c == 'L') particle[i][0] = 1;
        if(c == 'R') particle[i][0] = 0;
    }

    for(int i = 0; i < N; i++) scanf("%d", &particle[i][1]);

    for(int i = 0; i < N-1; i++){
        if(particle[i][0] == 0 && particle[i+1][0] == 1){
            pos = true;
            minT = min(minT, (particle[i+1][1] - particle[i][1])/2);
        } 
    }
    if(!pos) minT = -1;
    printf("%d\n", minT);
}
