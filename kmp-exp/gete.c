#include <stdio.h>
#include <stdlib.h>

int main () {
   printf("LANG : %s\n", getenv("LANG"));
  printf("HOME : %s\n", getenv("HOME"));
printf("ROOT : %s\n",	getenv("ROOT"));

   return(0);
}
