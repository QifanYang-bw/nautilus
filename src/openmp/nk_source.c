
#include "nk_header.h"

//#include <nautilus/libccompat.h>
//#include <nautilus/naut_string.h>
//#include "signal.h"
//#include "unistd.h"
//#include <dirent.h>
//#include "math.h"
nl_catd catopen(const char *name, int flag){
    nl_catd* ptr;
    return *ptr;
}
char *catgets(nl_catd catalog, int set_number,
                     int message_number,
                     const char *message){
      return NULL;
}

int catclose(nl_catd catalog){
    return 0;
}

char *strerror_r (int errnum)
{
    UNDEF_FUN_ERR();
    return NULL;
}

// int strerror_r(int errnum, char *buf, size_t buflen){
//      return 0;
// }
          
// char *strerror_r(int errnum, char *buf, size_t buflen){
//      return 0;
// }

//Doesnt exists in nautilus 
pid_t getpid(void){
      return 0;
}

int atexit(void (*function)(void)){
       return  0;
}


void qsort(void *base, size_t nmemb, size_t size,
            int (*compar)(const void *, const void *)){
       //empty
}

void qsort_r(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *, void *),
           void *arg){
       //empty
}

//in nautilus
// int toupper(int c){
//        return 0;
// }
// int tolower(int c){
//        return 0;
// }


int toupper_l(int c, locale_t locale){
       return 0;
}

int tolower_l(int c, locale_t locale){
       return 0;
}


//defined in <nautilus/libccompat.h> // char *strerror(int errnum);

// //important
//defined already
// char *strtok(char *str, const char *delim){
//        return NULL;
// }

// char *strtok_r(char *str, const char *delim, char **saveptr){
//        return NULL;
// }

//  #include <unistd.h>

int gethostname(char *name, size_t len){
       return 0;
}
int sethostname(const char *name, size_t len){
       return 0;
}

int pthread_cancel(pthread_t thread){
       return 0;
}


// int fgetc(FILE *stream);char *fgets(char *s, int size, FILE *stream);
// int getc(FILE *stream);int getchar(void);char *gets(char *s);int ungetc(int c, FILE *stream);

// #include <sched.h>
int sched_yield(void){
    return 0;
}

// #include <pthread.h>

int pthread_attr_init(pthread_attr_t *attr){
       return 0;
}
int pthread_attr_destroy(pthread_attr_t *attr){
       return 0;
}


int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize){
       return 0;
}
int pthread_attr_getstacksize(const pthread_attr_t *attr, size_t *stacksize){
       return 0;
}

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, 
                     void *(*start_routine) (void *), void *arg){
       return 0;
}
//  #include <pthread.h>

pthread_t pthread_self(void){
       pthread_t *ptr;
       return *ptr;
}

//  #define _GNU_SOURCE             /* See feature_test_macros(7) */
int pthread_getattr_np(pthread_t thread, pthread_attr_t *attr){
       return 0;
}


void *pthread_getspecific(pthread_key_t key){
       //empty
}

int pthread_setcancelstate(int state, int *oldstate){
       return 0;
}
int pthread_setcanceltype(int type, int *oldtype){
       return 0;
}

void pthread_exit(void *retval){
      //empty
}
int pthread_join(pthread_t thread, void **retval){
       return 0;
}

int pthread_condattr_init(pthread_condattr_t *attr){
       return 0;
}

int pthread_condattr_destroy(pthread_condattr_t *attr){
       return 0;
}

int pthread_cond_destroy(pthread_cond_t *cond){
       return 0;
}

int pthread_cond_init(pthread_cond_t *restrict cond,
              const pthread_condattr_t *restrict attr){
       return 0;
}

int pthread_mutex_destroy(pthread_mutex_t *mutex){
       return 0;
}

// int pthread_mutex_init(pthread_mutex_t *restrict mutex,
//               const pthread_mutexattr_t *restrict attr){
//        return 0;
//               }

int pthread_mutex_trylock(pthread_mutex_t *mutex){
       return 0;
}

int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex){
       return 0;
}


int pthread_cond_timedwait(pthread_cond_t *cond,  
              pthread_mutex_t *mutex, const struct timespec *abstime){
                     return 0;
              }

int pthread_cond_signal(pthread_cond_t *cond){
       return 0;
}


int pthread_cond_broadcast(pthread_cond_t *cond){
       return 0;
}


int pthread_key_delete(pthread_key_t key){
       return 0;
}

int pthread_key_create(pthread_key_t *key, void (*destructor)(void*)){
       return 0;
}

int pthread_atfork(void (*prepare)(void), void (*parent)(void),
                          void (*child)(void)){
       return 0;
                          }


//clock_t times(struct tms *buf);

 

int sigemptyset(sigset_t *set){
       return 0;
}

int sigfillset(sigset_t *set){
       return 0;
}

int sigaddset(sigset_t *set, int signum){
       return 0;
}

int sigdelset(sigset_t *set, int signum){
       return 0;
}

int sigismember(const sigset_t *set, int signum){
       return 0;
}
int sigaction(int signum, const struct sigaction *act,
              struct sigaction *oldact){
                     return 0;
              }

// getrusage
void environ(){

}
void fgetc(){

}
void pthread_attr_getstack(){

}

void pthread_attr_setdetachstate(){

}
void pthread_mutexattr_init(){

}
void pthread_setspecific(){

}
void setenv(){

}
// void stderr(){

// }
// void stdout(){

// }

void times(){

}

// void pthread_attr_getstack(){

// }

// vfscanf

// getrlimit

// #include <unistd.h>
long sysconf(int name){
       return 0;
}

unsigned int sleep(unsigned int seconds){
       return 0;
}

int gettimeofday (struct timeval *tv, struct timezone *tz){
        return 0;
}

int settimeofday(const struct timeval *tv, const struct timezone *tz){
       return 0;
}


int getrusage(){
       return 0;
}
DIR *opendir(const char *name){
       return NULL;
}
int closedir(const char *name){
       return 0;
}
DIR *fdopendir(int fd){
       return NULL;
}
struct dirent *readdir(DIR *dirp){
       return NULL;
}
int close(int fd){
       return 0;
}

int open(const char *pathname, int flags){
       return 0;
}

//int open(const char *pathname, int flags, mode_t mode);


// #include <dlfcn.h>

void *dlsym(void *handle, const char *symbol){
       //empty
}

//#define _GNU_SOURCE
//#include <dlfcn.h>

void *dlvsym(void *handle, char *symbol, char *version){
       //empty
}
void *dlopen(const char *filename, int flags){
       
       //empty
}

//int dlclose(void *handle);

int sched_getcpu(void){
       return 0;
}

Fcomplex __mulsc3(float __a, float __b, float __c, float __d)
{
          Fcomplex *ptr;
          return *ptr;
}
float __divsc3(float __a, float __b, float __c, float __d){
     return 0;
}


//COMPILER_RT_ABI 
Dcomplex __muldc3(double __a, double __b, double __c, double __d){
       Dcomplex *ptr;
       return *ptr;
}
double __divdc3 (double a, double b, double c, double d){
       return 0;
}
long double __divxc3 (long double a, long double b, long double c, long double d){
       return 0;
}
long double __mulxc3 (long double a, long double b, long double c, long double d){
       return 0;
}

int unsetenv(const char *name){
       return 0;
}

//extern char **environ;


void vfscanf(void ){

}

void getrlimit(void ){

}