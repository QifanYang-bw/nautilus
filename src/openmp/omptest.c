#include <nautilus/nautilus.h>
#include <nautilus/shell.h>
#include "libomp.h"
#ifndef NAUT_CONFIG_DEBUG_GPUDEV
#undef DEBUG_PRINT
#define DEBUG_PRINT(fmt, args...) 
#endif

#define ERROR(fmt, args...) ERROR_PRINT("gpudev: " fmt, ##args)
#define DEBUG(fmt, args...) DEBUG_PRINT("gpudev: " fmt, ##args)
#define INFO(fmt, args...) INFO_PRINT("gpudev: " fmt, ##args)


static int handle_gputest (char * buf, void * priv)
{
    char name[32], rw[16];
    struct nk_gpu_dev *d;
    struct nk_gpu_dev_characteristics c;

    #pragma parallel
    {
    for(int i=0;i<5;i++){
      nk_vc_printf("%d",i);
    }

    }

}


static struct shell_cmd_impl omptest_impl = {
    .cmd      = "omptest",
    .help_str = "openmp test",
    .handler  = handle_gputest,
};
nk_register_shell_cmd(omptest_impl);

