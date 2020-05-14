/* Declaration of common pthread types for all architectures.
   Copyright (C) 2017-2019 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef _PTHREAD_TYPE_H
#define _PTHREAD_TYPE__H        1
/* For internal mutex and condition variable definitions.  */
#define __SIZEOF_PTHREAD_MUTEX_T 40
#define __SIZEOF_PTHREAD_ATTR_T 56
#define __SIZEOF_PTHREAD_MUTEX_T 40
#define __SIZEOF_PTHREAD_RWLOCK_T 56
#define __SIZEOF_PTHREAD_BARRIER_T 32

#define __SIZEOF_PTHREAD_MUTEXATTR_T 4
#define __SIZEOF_PTHREAD_COND_T 48
#define __SIZEOF_PTHREAD_CONDATTR_T 4
#define __SIZEOF_PTHREAD_RWLOCKATTR_T 8
#define __SIZEOF_PTHREAD_BARRIERATTR_T 4

/* Definitions for internal mutex struct.  */
#define __PTHREAD_COMPAT_PADDING_MID
#define __PTHREAD_COMPAT_PADDING_END
#define __PTHREAD_MUTEX_LOCK_ELISION    1
#ifdef __x86_64__
# define __PTHREAD_MUTEX_NUSERS_AFTER_KIND  0
# define __PTHREAD_MUTEX_USE_UNION          0
#else
# define __PTHREAD_MUTEX_NUSERS_AFTER_KIND  1
# define __PTHREAD_MUTEX_USE_UNION          1
#endif
#define __LOCK_ALIGNMENT
#define __ONCE_ALIGNMENT

/* Thread identifiers.  The structure of the attribute type is not
   exposed on purpose.  */
typedef unsigned long int pthread_t;
/* Data structures for mutex handling.  The structure of the attribute
   type is not exposed on purpose.  */

struct pthread_mutexattr
{
  /* Identifier for the kind of mutex.
     Bit 31 is set if the mutex is to be shared between processes.
     Bit 0 to 30 contain one of the PTHREAD_MUTEX_ values to identify
     the type of the mutex.  */
  int mutexkind;
};


typedef union
{
  char __size[__SIZEOF_PTHREAD_MUTEXATTR_T];
  int __align;
} pthread_mutexattr_t;
/* Data structure for condition variable handling.  The structure of
   the attribute type is not exposed on purpose.  */
typedef union
{
  char __size[__SIZEOF_PTHREAD_CONDATTR_T];
  int __align;
} pthread_condattr_t;
/* Keys for thread-specific data */
typedef unsigned int pthread_key_t;
/* Once-only execution */
typedef int __ONCE_ALIGNMENT pthread_once_t;
union pthread_attr_t
{
  char __size[__SIZEOF_PTHREAD_ATTR_T];
  long int __align;
};
#ifndef __have_pthread_attr_t
typedef union pthread_attr_t pthread_attr_t;
# define __have_pthread_attr_t 1
#endif
struct __pthread_mutex_s
{
unsigned int __count;
int __kind;

};


struct __pthread_cond_s
{
  __extension__ union
  {
    __extension__ unsigned long long int __wseq;
    struct
    {
      unsigned int __low;
      unsigned int __high;
    } __wseq32;
  };
  __extension__ union
  {
    __extension__ unsigned long long int __g1_start;
    struct
    {
      unsigned int __low;
      unsigned int __high;
    } __g1_start32;
  };
  unsigned int __g_refs[2] __LOCK_ALIGNMENT;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};

struct pthread_condattr
{
  /* Combination of values:
     Bit 0                : flag whether conditional variable will be
                            sharable between processes.
     Bit 1-COND_CLOCK_BITS: Clock ID.  COND_CLOCK_BITS is the number of bits
                            needed to represent the ID of the clock.  */
  int value;
};

typedef union
{
  struct __pthread_mutex_s __data;
  char __size[__SIZEOF_PTHREAD_MUTEX_T];
  long int __align;
} pthread_mutex_t;

typedef union
{
  struct __pthread_cond_s __data;
  char __size[__SIZEOF_PTHREAD_COND_T];
  __extension__ long long int __align;
} pthread_cond_t;

/* typedef union */
/* { */
/*   struct __pthread_rwlock_arch_t __data; */
/*   char __size[__SIZEOF_PTHREAD_RWLOCK_T]; */
/*   long int __align; */
/* } pthread_rwlock_t; */
/* typedef union */
/* { */
/*   char __size[__SIZEOF_PTHREAD_RWLOCKATTR_T]; */
/*   long int __align; */
/* } pthread_rwlockattr_t; */
#ifdef __USE_XOPEN2K
/* POSIX spinlock data type.  */
typedef volatile int pthread_spinlock_t;
/* POSIX barriers data type.  The structure of the type is
   deliberately not exposed.  */
typedef union
{
  char __size[__SIZEOF_PTHREAD_BARRIER_T];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[__SIZEOF_PTHREAD_BARRIERATTR_T];
  int __align;
} pthread_barrierattr_t;



/* struct __pthread_mutex_s */
/* { */
/*   int __lock __LOCK_ALIGNMENT; */
/*   unsigned int __count; */
/* /\*   int __owner; *\/ */
/* /\* #if !__PTHREAD_MUTEX_NUSERS_AFTER_KIND *\/ */
/* /\*   unsigned int __nusers; *\/ */
/* /\* #endif *\/ */
/*   /\* KIND must stay at this position in the structure to maintain */
/*      binary compatibility with static initializers. */
/*      Concurrency notes: */
/*      The __kind of a mutex is initialized either by the static */
/*      PTHREAD_MUTEX_INITIALIZER or by a call to pthread_mutex_init. */
/*      After a mutex has been initialized, the __kind of a mutex is usually not */
/*      changed.  BUT it can be set to -1 in pthread_mutex_destroy or elision can */
/*      be enabled.  This is done concurrently in the pthread_mutex_*lock functions */
/*      by using the macro FORCE_ELISION. This macro is only defined for */
/*      architectures which supports lock elision. */
/*      For elision, there are the flags PTHREAD_MUTEX_ELISION_NP and */
/*      PTHREAD_MUTEX_NO_ELISION_NP which can be set in addition to the already set */
/*      type of a mutex. */
/*      Before a mutex is initialized, only PTHREAD_MUTEX_NO_ELISION_NP can be set */
/*      with pthread_mutexattr_settype. */
/*      After a mutex has been initialized, the functions pthread_mutex_*lock can */
/*      enable elision - if the mutex-type and the machine supports it - by setting */
/*      the flag PTHREAD_MUTEX_ELISION_NP. This is done concurrently. Afterwards */
/*      the lock / unlock functions are using specific elision code-paths.  *\/ */
/*   int __kind; */
/* /\*   __PTHREAD_COMPAT_PADDING_MID *\/ */
/* /\* /\\* #if __PTHREAD_MUTEX_NUSERS_AFTER_KIND *\\/ *\/ */
/* /\* /\\*   unsigned int __nusers; *\\/ *\/ */
/* /\* /\\* #endif *\\/ *\/ */
/* /\* #if !__PTHREAD_MUTEX_USE_UNION *\/ */
/* /\*   __PTHREAD_SPINS_DATA; *\/ */
/* /\*   __pthread_list_t __list; *\/ */
/* /\* # define __PTHREAD_MUTEX_HAVE_PREV      1 *\/ */
/* /\* #else *\/ */
/* /\*   __extension__ union *\/ */
/* /\*   { *\/ */
/* /\*     __PTHREAD_SPINS_DATA; *\/ */
/* /\*     __pthread_slist_t __list; *\/ */
/* /\*   }; *\/ */
/* /\* # define __PTHREAD_MUTEX_HAVE_PREV      0 *\/ */
/* /\* #endif *\/ */
/* /\*   __PTHREAD_COMPAT_PADDING_END *\/ */
/* }; */



#endif
#endif
