#include "kernel/types.h"
#include "user/user.h"


int
main(int argc, char *argv[])
{
  int p[34][2];
  int sendnum[34];
  int pindex = 0;
  int recvnum;
  int thisnum;

  // frist close unused fd
  close(0);
  close(2);

  pipe(p[pindex]);

  for(int i = 2; i < 36; i++){
    sendnum[i-2] = i;
    write(p[pindex][1], &sendnum[i-2], 1);
  }

  close(p[pindex][1]);

  do
  {
    if(fork() == 0){
      // child
      if(read(p[pindex][0], &recvnum, 1) == 0) exit(0);
      thisnum = recvnum;
      printf("prime %d\n", thisnum);

      // pass numbers to next process
      pipe(p[pindex+1]);
      while(read(p[pindex][0], &recvnum, 1)){
        if(recvnum % thisnum){
          // if recvnum % thisnum != 0
          write(p[pindex+1][1], &recvnum, 1);
        }
      }

      close(p[pindex][0]);
      pindex += 1;
      close(p[pindex][1]);
    }else{
      wait(0);
      exit(0);
    }
  } while (1);

  // wait(child);
  // exit(0);
}
