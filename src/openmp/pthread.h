
#ifndef _KMP_PTHREAD_H_
#define _KMP_PTHREAD_H_

/* Detach state.  */
enum
{
  PTHREAD_CREATE_JOINABLE,
  PTHREAD_CREATE_DETACHED
};
/* Mutex types.  */
enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL,
  PTHREAD_MUTEX_FAST_NP = PTHREAD_MUTEX_TIMED_NP
};

#define PTHREAD_MUTEX_PRIO_CEILING_SHIFT        19
#define PTHREAD_MUTEX_PRIO_CEILING_MASK                0xfff80000

/* Flags in mutex attr.  */
#define PTHREAD_MUTEXATTR_PROTOCOL_SHIFT        28
#define PTHREAD_MUTEXATTR_PROTOCOL_MASK                0x30000000
#define PTHREAD_MUTEXATTR_PRIO_CEILING_SHIFT        12
#define PTHREAD_MUTEXATTR_PRIO_CEILING_MASK        0x00fff000
#define PTHREAD_MUTEXATTR_FLAG_ROBUST                0x40000000
#define PTHREAD_MUTEXATTR_FLAG_PSHARED                0x80000000
#define PTHREAD_MUTEXATTR_FLAG_BITS \
  (PTHREAD_MUTEXATTR_FLAG_ROBUST | PTHREAD_MUTEXATTR_FLAG_PSHARED \
   | PTHREAD_MUTEXATTR_PROTOCOL_MASK | PTHREAD_MUTEXATTR_PRIO_CEILING_MASK)

#define __PTHREAD_COND_SHARED_MASK 1
#define PTHREAD_MUTEX_PSHARED_BIT 128


  
#endif