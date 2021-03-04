#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h"


int
main(int argc, char *argv[])
{
  char *xargv[argc+1];
  char buf[MAXARG];
  char *c = 0, *p;
  int i;

  for(i = 1; i < argc; i++){
    xargv[i-1] = argv[i];
    // memmove(buf[i-1], argv[i], MAXARG);
  }
  xargv[argc-1] = buf;
  xargv[argc] = 0; 

  p = buf;
  while(read(0, c, 1)){
    if(*c == '\n'){
      *p = '\0';
      // &buf[4][0] = (char *)0;
      // xargv[argc] = 0;
      if(!fork()){
        // child
        exec(xargv[0], xargv);
      }
      p = buf;
    }else{
      *p++ = *c;
    }
  }

  exit(0);
}
