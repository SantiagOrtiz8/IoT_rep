#include <unistd.h>

int main(){
    int fd[2];
    int pid;
    pipe(fd);
    pid = fork();

    if(pid == 0){
        close(STDIN_FILENO);
        //execlp("ls","ls","-l",NULL);
        dup(fd[0]); //Va a usar la entrada del nuevo buffer.
        close(fd[1]);
        execlp("wc","wc","-l",NULL);
    } else{
        close(STDOUT_FILENO);
        dup(fd[1]);
        close(fd[0]);
        execlp("ls","ls",NULL);
    }

    return 0;
}