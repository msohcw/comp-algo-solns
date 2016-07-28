#include <stdio.h>

using namespace std;

int main(){
    char c;
    bool word = false;
    int words = 0;
    while(scanf("%c",&c)!=EOF){
        int a = (int) c;
        if((a >=97 && a <=122) || (a >=65 && a <= 90)){
            word = true;
        }else{
            if(word){
                words++;
                word = false;
            }
            if(c == '\n'){
                printf("%d\n",words);    
                words = 0;
            }
        }
    }
}
