#include <linux/module.h>  /* Needed by all modules */
#include <linux/kernel.h>  /* Needed for KERN_ALERT */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("test");
MODULE_DESCRIPTION("Android ko test");

int init_module(void)
{
   pr_err("Denis: Hello world\n");

   // A non 0 return means init_module failed; module can't be loaded.
   return 0;
}

void cleanup_module(void)
{
  pr_err("Goodbye world 1.\n");
}
