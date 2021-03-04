#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  char* error = "error, you should input a number\n";
  if(argc == 1){
    write(1, error, strlen(error));
  }else{
    int time = atoi(argv[1]);
    sleep(time);
  }

  exit(0);
}
