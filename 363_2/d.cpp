#include <stdio.h>
#include <cstring>

using namespace std;

int G[200010];
bool fixed[200010];
bool used[200010];
int N;
int root = -1;
int changes = 0;

void dfs(int i){
    if(fixed[i]) return;
    if(used[i]){
       if(root == -1) root = i;
       // printf("changed %d->%d to %d->%d\n", i, G[i], i, root);
       if(G[i] != root) changes++;
       G[i] = root;
       fixed[i] = true;
       return;
    }else{
        used[i] = true;
        dfs(G[i]);
        fixed[i] = true;
    }
}

int main(){
    scanf("%d", &N);
    memset(used,0,sizeof(used));
    memset(used,0,sizeof(fixed));
    for(int i = 1; i <= N; i++){
        scanf("%d", &G[i]);
        if(G[i] == i && root == -1){
            root = i;
            // printf("root is now %d\n", i);
            fixed[i] = true;
        }
    }
    for(int i = 1; i <= N; i++) dfs(i);
    printf("%d\n", changes); 
    for(int i = 1; i <= N; i++) printf("%d ",G[i]);
    printf("\n");
}
