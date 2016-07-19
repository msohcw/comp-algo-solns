#include <stdio.h>

using namespace std;

int main(){
    char c;
    bool left = true;
    while(scanf("%c",&c) != EOF){
        if(c != '"'){
            printf("%c",c);
        }else if(left){
            printf("``");
            left = false;
        }else{
            printf("''");
            left = true;
        }
    }
}
