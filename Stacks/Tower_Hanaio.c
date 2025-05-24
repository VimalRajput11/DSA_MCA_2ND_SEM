#include<stdio.h>

int Tower_Hanio(int n, char s, char d, char Aux);

int count=0;
int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    char s='A',d='B',Aux='C';
    int moves = Tower_Hanio(n,s,d,Aux);
    printf("Total moves: %d\n",moves);
    return 0;
}

int Tower_Hanio(int n,char s,char d,char Aux){

    if(n==0)
        return 0;
    else{
        Tower_Hanio(n-1,s,Aux,d);
        printf("Move disk %d from %c to %c\n",n,s,d);
        count++;
        Tower_Hanio(n-1,Aux,d,s);
    }
    return count;
}


