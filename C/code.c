#include <stdio.h>

int x = 10;

static int func(int y){
    printf("%d %d\n", x, y);
}

int main(){
    int y = 100;
    func(y);
}