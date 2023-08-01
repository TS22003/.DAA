//GCD of two non-negative integers

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE *fp1,*fp2;

//Euclid's algorithm
void gcd1(int m,int n){
    int count=0,rem;
    while(n!=0){
        count++;
        rem=m%n;
        m=n;
        n=rem;
    }
    fprintf(fp1,"%d\t",m);
    fprintf(fp2,"%d\t",count);
}

//Subtraction method
void gcd2(int m,int n){
    int count=0;
    while(m!=n){
        count++;
        if(m>n) m=m-n;
        else   n=n-m;
    }
    fprintf(fp1,"%d\t",m);
    fprintf(fp2,"%d\t",count);
}

//Consecutive integer method
void gcd3(int m,int n){
    int count=0,t;
    t=(m<n)?m:n;
    while(n!=1){
        count++;
        if(m%t==0)
            if(n%t==0)
                break;
        t=t-1;
    }
    fprintf(fp1,"%d\n",t);
    fprintf(fp2,"%d\n",count);
}

void main(){
    int m,n;
    srand(time(0));
    system("gcd.txt");
    system("gcdcount.txt");
    fp1=fopen("gcd.txt","w");
    fp2=fopen("gcdcount.txt","w");
    for(int i=1;i<=10;i++){
        m=rand()%100;
        n=rand()%100;
        fprintf(fp1,"%d\t %d\t",m,n);
        fprintf(fp2,"%d\t %d\t",m,n);
        gcd1(m,n);
        gcd2(m,n);
        gcd3(m,n);
    }
    fclose(fp1);
    fclose(fp2);
}
