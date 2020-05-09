#ifndef _NK_446_HEADER_H_
#define _NK_446_HEADER_H_
#include "nl_types.h"
#include <nautilus/libccompat.h>

#define pid_t uint64_t
#define locale_t uint64_t
nl_catd catopen(const char *name, int flag);

char *catgets(nl_catd catalog, int set_number,
                     int message_number,
                     const char *message);

nl_catd catopen(const char *name, int flag);

int catclose(nl_catd catalog);

char *strerror_r (int errnum);

#endif