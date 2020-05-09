
#include "nk_header.h"
#include <nautilus/libccompat.h>

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

// #include <ctype.h>

// #include <string.h>

// //important
// char *strtok(char *str, const char *delim);

// char *strtok_r(char *str, const char *delim, char **saveptr);

//  #include <unistd.h>

//        int gethostname(char *name, size_t len);
//        int sethostname(const char *name, size_t len);
// fgetc
//        #include <pthread.h>

//        int pthread_cancel(pthread_t thread);

// #include <stdio.h>
// int fgetc(FILE *stream);char *fgets(char *s, int size, FILE *stream);
// int getc(FILE *stream);int getchar(void);char *gets(char *s);int ungetc(int
// c, FILE *stream);

// #include <sched.h>
// int sched_yield(void){
//     return 0
// }

// #include <pthread.h>

// int pthread_attr_init(pthread_attr_t *attr);
// int pthread_attr_destroy(pthread_attr_t *attr);

// #include <pthread.h>

//        int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize);
//        int pthread_attr_getstacksize(const pthread_attr_t *attr, size_t *stacksize);

// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
//                    void *(*start_routine) (void *), void *arg);
//  #include <pthread.h>

//        pthread_t pthread_self(void);

//  #define _GNU_SOURCE             /* See feature_test_macros(7) */
//        #include <pthread.h>

//        int pthread_getattr_np(pthread_t thread, pthread_attr_t *attr);

// #include <pthread.h>

// void *pthread_getspecific(pthread_key_t key);

// int pthread_setcancelstate(int state, int *oldstate);int
// pthread_setcanceltype(int type, int *oldtype);

// void pthread_exit(void *retval);
// int pthread_join(pthread_t thread, void **retval);

 
// #include <signal.h>

// int sigemptyset(sigset_t *set);

// int sigfillset(sigset_t *set);

// int sigaddset(sigset_t *set, int signum);

// int sigdelset(sigset_t *set, int signum);

// int sigismember(const sigset_t *set, int signum);
// int sigaction(int signum, const struct sigaction *act,
//               struct sigaction *oldact);

// int sigismember(const sigset_t *set, int signo);
// int pthread_atfork(void (*prepare)(void), void (*parent)(void),
//                           void (*child)(void));

// int pthread_condattr_init(pthread_condattr_t *attr);
// int pthread_condattr_destroy(pthread_condattr_t *attr);
// int pthread_cond_destroy(pthread_cond_t *cond);
// int pthread_cond_init(pthread_cond_t *restrict cond,
//        const pthread_condattr_t *restrict attr);

// int pthread_mutex_destroy(pthread_mutex_t *mutex);
// int pthread_mutex_init(pthread_mutex_t *restrict mutex,
//        const pthread_mutexattr_t *restrict attr);
//  int pthread_mutex_trylock(pthread_mutex_t *mutex);  
// int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
// int pthread_cond_timedwait(pthread_cond_t *cond, 
//     pthread_mutex_t *mutex, const struct timespec *abstime);

// int pthread_cond_signal(pthread_cond_t *cond);
// int pthread_cond_broadcast(pthread_cond_t *cond);

// int pthread_key_delete(pthread_key_t key);
// #include <sys/times.h>

//        clock_t times(struct tms *buf);
// int pthread_key_create(pthread_key_t *key, void (*destructor)(void*));       
// getrusage


// vfscanf

// getrlimit

// #include <unistd.h>
// long sysconf(int name);
//  unsigned int sleep(unsigned int seconds);
// int (struct timeval *tv, struct timezone *tz);

//        int settimeofday(const struct timeval *tv, const struct timezone *tz);



// #include <sys/types.h>
// #include <dirent.h>
// DIR *opendir(const char *name);
// DIR *fdopendir(int fd);
// struct dirent *readdir(DIR *dirp);
// int close(int fd);
// int open(const char *pathname, int flags);
//        int open(const char *pathname, int flags, mode_t mode);
// #include <dlfcn.h>

//        void *dlsym(void *handle, const char *symbol);

//        #define _GNU_SOURCE
//        #include <dlfcn.h>

//        void *dlvsym(void *handle, char *symbol, char *version);
// void *dlopen(const char *filename, int flags);

//        int dlclose(void *handle);

//  int sched_getcpu(void);


// COMPILER_RT_ABI Fcomplex __mulsc3(float __a, float __b, float __c, float __d)

// float _Complex __divsc3(float __a, float __b, float __c, float __d)

// COMPILER_RT_ABI Dcomplex __muldc3(double __a, double __b, double __c,
//                                   double __d)
// complex double __divdc3 (double a, double b, double c, double d)
// complex long double __divxc3 (long double a, long double b, long double c, long double d)
// complex long double __mulxc3 (long double a, long double b, long double c, long double d)
// int unsetenv(const char *name); [Option End]
// extern char **environ;
