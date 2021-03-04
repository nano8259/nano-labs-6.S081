#include "kernel/types.h"
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
    sleep(100);
    int ret = read(p1[0], c, 1);
    printf("%d, %d\n", c, ret);
  }else{
    // parent process
    write(p1[1], "1", 1);
    close(p1[1]);
  }
  exit(0);
}
