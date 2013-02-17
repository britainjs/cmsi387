#include <linux/unistd.h>
#include <linux/reboot.h>

int main(int argc, char *argv []) {
    //This program invokes the reboot system call, which instantly restarts the system
    //Does not save any data, so make sure make sure everything is saved and nothing
    //important is running. Note the program must be run as a superuser, i.e. sudo ./a.out
    
    //The call takes in 3 ints. The first two must be the constants LINUX_REBOOT_MAGIC1
    //and LINUX_REBOOT_MAGIC2, constants defined int linux/reboot.h. The third int
    //can be a variety of constants to restart, power off, turn on or off the 
    // ctrl-alt-delete hotkey, or halt the system. For this instance, we are using
    //LINUX_REBOOT_CMD_RESTART, which prints "Restarting System," and then immediately
    //restarts.
    
    syscall(88, LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_RESTART);
    
    
}