#include <stdlib.h>
#include <stdio.h>
#include "malloc.h"

int main(int argc, char const *argv[])
{
   int i;
   int *ptr[500];

   for (i = 0; i < 500; i++)
   {
      ptr[i] = (int *)malloc(2);
   }

   for (i = 0; i < 500; i++)
   {
      if (i % 2)
      {
         free(ptr[i]);
         ptr[i] = NULL; // set pointer to NULL after freeing memory
      }
   }
   
   for (i = 0; i < 500; i++)
   {
      if (ptr[i] != NULL) {
         *ptr[i] = 1;
      }
   }
   
   for (i = 0; i < 500; i++)
   {
      if (ptr[i] != NULL) {
         free(ptr[i]);
         ptr[i] = NULL;
      }
   }

   return 0;
}
