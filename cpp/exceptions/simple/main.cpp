#include "stdio.h"
#include <exception>

int main()
{
  try
  {
    printf("Hello!!!\n");
    throw(1);
  }
  catch(int err)
  {
    printf("Error:%d\n", err);
  }

  return 0;
}
