//test
#include<stdio.h>

int gcd;

int mod(int a , int b){
    int count = 0;
    int r = 1;
    while(r!=0){
        r = a%b;
        a = b;
        b = r;
        ++count;
    }
    gcd = a;
    return count;
}

int sub(int a, int b){
    int count = 0;
    while ( b != 0){
        ++count;
        if ( a > b )
            a = a - b;
        else
            b = b - a;
    }
    gcd = a;
    return count;
}

int repeat(int a, int b){
    int count = 0, min, temp;
    if ( a < b)
        min = a;
    else 
        min = b;

    while(min != 1){
        ++count;
        temp = a%min;
        if ( temp == 0){
            temp = b%min;
            if ( temp == 0)
                break;
        }
        --min;
    }
    gcd = min;
    return count;
}

void main(){
    int a, b;
    printf("Enter 2 numbers >> ");
    scanf("%d %d", &a, &b);

    printf("\nCount for Modulo >> %d\n", mod(a, b));
    printf("Count for Subtraction >> %d\n", sub(a, b));
    printf("Count for Int check > %d\n", repeat(a, b));
    printf("\nGCD >> %d\n", gcd);
}
