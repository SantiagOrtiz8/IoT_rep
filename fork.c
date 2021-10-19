#include <stdio.h>
#include <unistd.h>

int main() {
    int a =5;
    int pid=fork();
    if(pid==0){
        printf("Soy el proceso hijo ; pid = %d",pid);
    } else{
        printf("Soy el proceso padre ; pid = %d",pid);
    }
}