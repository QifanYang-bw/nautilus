#ifndef _NK_446_HEADER_H_
#define _NK_446_HEADER_H_
#include "nl_types.h"
#include <nautilus/libccompat.h>

#define pid_t uint64_t
#define locale_t uint64_t
#define pthread_mutex_t uint64_t
#define pthread_mutexattr_t uint64_t
#define pthread_cond_t uint64_t
#define pthread_condattr_t uint64_t
#define pthread_key_t uint64_t
#define pthread_t uint64_t
#define pthread_attr_t uint64_t
#define pthread_mutex_t uint64_t
#define pthread_mutex_t uint64_t

#define sigset_t uint64_t


#define DIR struct dirent

#define Fcomplex uint64_t
#define _Complex uint64_t
#define Dcomplex uint64_t

#define nk_stderr stderr
#define nk_stdout stdout
struct dirent{
    int dir;
};
struct sigaction{
    int time;
};
struct timezone{
    int time;
};

struct timeval{
    int time;
};


nl_catd catopen(const char *name, int flag);

char *catgets(nl_catd catalog, int set_number,
                     int message_number,
                     const char *message);

nl_catd catopen(const char *name, int flag);

int catclose(nl_catd catalog);

char *strerror_r (int errnum);

#endif