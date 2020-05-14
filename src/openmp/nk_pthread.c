

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
#include "pthreadtypes.h"
#include "pthread.h"
//#include <rt/openmp/nk_pthread.h>
#define __PTHREAD_COND_SHARED_MASK 1
#define PTHREAD_MUTEX_PSHARED_BIT 128


#define ERROR(fmt, args...) ERROR_PRINT("pthread: " fmt, ##args)
#define DEBUG(fmt, args...) DEBUG_PRINT("pthread: " fmt, ##args)
#define INFO(fmt, args...)   INFO_PRINT("pthread: " fmt, ##args)

int pthread_mutexattr_init(pthread_mutexattr_t *attr){

  DEBUG("pthread_mutexattr_init\n");
  /* if (sizeof (struct pthread_mutexattr) != sizeof (pthread_mutexattr_t)) */
  /*      memset (attr, '\0', sizeof (*attr)); */
  /* We use bit 31 to signal whether the mutex is going to be
     process-shared or not.  By default it is zero, i.e., the mutex is
     not process-shared.  */
  ((struct pthread_mutexattr *) attr)->mutexkind = PTHREAD_MUTEX_NORMAL;
DEBUG("FIN");
  return 0; 
}
int pthread_cond_init(pthread_cond_t *cond,
              const pthread_condattr_t * cond_attr){
  DEBUG("pthread_cond_init");
  struct pthread_condattr *icond_attr = (struct pthread_condattr_t *) cond_attr;
  memset(cond, 0, sizeof(pthread_cond_t));
  if (icond_attr != NULL && (icond_attr->value & 1) != 0)
     cond->__data.__wrefs |= __PTHREAD_COND_SHARED_MASK;
  DEBUG("FIN");
  return 0;
}


static const struct pthread_mutexattr default_mutexattr =
  {
    /* Default is a normal mutex, not shared between processes.  */
    .mutexkind = PTHREAD_MUTEX_NORMAL
  };

int pthread_mutex_init(pthread_mutex_t * mutex,
        const pthread_mutexattr_t * mutexattr){

  DEBUG("pthread_mutex_init\n");
  const struct pthread_mutexattr *imutexattr;
  
  imutexattr = ((const struct pthread_mutexattr *) mutexattr ?: &default_mutexattr);

  /* Clear the whole variable.  */
  memset (mutex, '\0', __SIZEOF_PTHREAD_MUTEX_T);
  /* Copy the values from the attribute.  */
  int mutex_kind = imutexattr->mutexkind & ~PTHREAD_MUTEXATTR_FLAG_BITS;

  mutex_kind |= PTHREAD_MUTEX_PSHARED_BIT;
  mutex->__data.__kind = mutex_kind;

  //atomic_store_relaxed (&(mutex->__data.__kind), mutex_kind);
  DEBUG("FIN");
  return 0;
   
}
int pthread_condattr_init(pthread_condattr_t *attr){

  DEBUG("pthread_condattr_init\n");
  struct pthread_condattr *iattr = (struct pthread_condattr *) attr;
  /* Default is not pshared and CLOCK_REALTIME.  */
  // iattr-> value = CLOCK_REALTIME << 1;
  return 0;
}

//#define pthread_key_t nk_tls_key_t
int pthread_key_create(pthread_key_t *key, void (*destructor)(void*))
{
  DEBUG("pthread_key_create\n");
  DEBUG("FIN");
  return nk_tls_key_create(key, destructor);
}

int pthread_attr_init (pthread_attr_t *__attr){
  DEBUG(" pthread_attr_init\n");
  DEBUG("FIN");
  return 0;
}

