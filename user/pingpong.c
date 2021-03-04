#include "kernel/types.h"
// #include "kernel/stat.h"
#include "user/user.h"


int
main(int argc, char *argv[])
{
  int p1[2], p2[2];
  char* c[1];
  // int pid;
  pipe(p1);
  pipe(p2);
  if(fork() == 0){
    // child process
    read(p1[0], c, 1);
    // printf("%s\n", c);
    printf("%d: received ping\n", getpid());
    write(p2[1], c, 1);
  }else{
    // parent process
    write(p1[1], "1", 1);
    read(p2[0], c, 1);
    // printf("%s\n", c);
    printf("%d: received pong\n", getpid());
  }
  exit(0);
}
