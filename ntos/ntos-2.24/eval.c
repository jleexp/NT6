#include "std.h"
#include "main.h"
#include "comm.h"
#include "uvalarm.h"

int outoftime = 0;

INLINE void set_eval(int etime){
#ifndef WIN32
  signal(SIGVTALRM, sigalrm_handler);
  uvalarm(max_cost, 0);
#endif
  outoftime = 0;

}

INLINE int get_eval(){
  int ret;
#ifndef WIN32
  ret = uvalarm(2*max_cost, 0);
  uvalarm(ret, 0);
  return ret;
#else
  return 100;
#endif
}

