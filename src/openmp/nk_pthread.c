

#include <nautilus/nautilus.h>
#include <nautilus/libccompat.h>
#include <nautilus/thread.h>
#include <nautilus/errno.h>
#include <nautilus/random.h>
#include <dev/hpet.h>
#include <rt/openmp/openmp.h>
#include <nautilus/env.h>
//kmp
#include <nautilus/spinlock.h>
#include <nautilus/sysconf.h>
//#include <rt/openmp/nk_pthread.h>

#define pthread_t nk_thread_id_t
#define pthread_condattr_t unsigned
#define pthread_cond_t unsigned
#define pthread_mutex_t spinlock_t
#define pthread_mutexattr_t unsigned
#define pthread_attr_t unsigned

int pthread_mutexattr_init(pthread_mutexattr_t *attr){
  return 0; 
}
int pthread_cond_init(pthread_cond_t *restrict cond,
              const pthread_condattr_t *restrict attr){
       return 0;
}



int pthread_mutex_init(pthread_mutex_t *restrict mutex,
        const pthread_mutexattr_t *restrict attr){
    return 0;
}
int pthread_condattr_init(pthread_condattr_t *attr){
       return 0;
}

#define pthread_key_t nk_tls_key_t
int pthread_key_create(pthread_key_t *key, void (*destructor)(void*))
{
  return nk_tls_key_create(key, destructor);
}

int pthread_attr_init (pthread_attr_t *__attr){
  return 0;
}

