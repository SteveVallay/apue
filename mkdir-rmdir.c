#include "apue.h"
#include <sys/stat.h>
#include <sys/types.h>


int main(int argc, char*argv[]){

    const char* dir_name  = "test_dir";
   if (mkdir(dir_name, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) < 0 ){
       err_ret("%s: mkdir error", dir_name);
   }

   sleep(5);
   if (rmdir(dir_name) < 0){
       err_ret("%s: rmdir error", dir_name);
   }
   return 0;

}
