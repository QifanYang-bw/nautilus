#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <time.h> 
#include <sys/times.h> 

main () 
{


  printf("_SC_thread_: %d value %d\n", _SC_THREADS, sysconf(_SC_THREADS));	
  printf("_SC_thread_threadsmax: %d value %d\n", _SC_THREAD_THREADS_MAX, sysconf(_SC_THREAD_THREADS_MAX));	
  printf("_SC_thread_stackmin: %d value %d\n",_SC_THREAD_STACK_MIN, sysconf(_SC_THREAD_STACK_MIN));	
  printf("84: %d value %d\n", 84,sysconf(84));	
    /* clock_t ct0, ct1;  */
    /* clock_t ct0, ct1;  */
    /* clock_t ct0, ct1;  */
    /* clock_t ct0, ct1;  */
    /* struct tms tms0, tms1;  */
    /* int i;  */

    /* if ((ct0 = times (&tms0)) == -1)  */
    /*     perror ("times");  */

    /* printf ("_SC_CLK_TCK = %ld\n", sysconf (_SC_CLK_TCK));  */

    /* for (i = 0; i < 10000000; i++)  */
    /*     ;  */

    /* if ((ct1 = times (&tms1)) == -1)  */
    /*     perror ("times");  */

    /* printf ("ct0 = %ld, times: %ld %ld %ld %ld\n", ct0, tms0.tms_utime, */
    /*     tms0.tms_cutime, tms0.tms_stime, tms0.tms_cstime);  */
    /* printf ("ct1 = %ld, times: %ld %ld %ld %ld\n", ct1, tms1.tms_utime, */
    /*     tms1.tms_cutime, tms1.tms_stime, tms1.tms_cstime);  */
    /* printf ("ct1 - ct0 = %ld\n", ct1 - ct0);  */
}