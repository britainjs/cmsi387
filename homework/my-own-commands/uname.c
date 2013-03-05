#include <linux/types.h>
#include <linux/unistd.h>
#include <string.h>
#include <sys/utsname.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    //Demonstrates the uname system call, which returns information about the system
    //It takes in a pointer to a type of struct called utsname, and fills it with 
    //the system information.
    
    //A struct to hold the results of the system call.
    struct utsname systemInfo;
    //Now we invoke the system call.
    // JD: You need a *pointer* to systemInfo here!
    int result = syscall(122, systemInfo);
    
    if(result == -1){
        //we hit an error
        char *error = "Invalid destination\n";
        syscall(4, 2, error, strlen(error) );
    }else{
        //No we will print out the info
        //First is the os name
        printf("%s\n", systemInfo.sysname);
        
        //Next is the host name
        printf("%s\n", systemInfo.nodename);
        
        //The os release version
        // JD: ???? Missing semicolon below.
        printf("%s\n", systemInfo.release)
        
        //The os version number
        // JD: Double ???? Now a missing rparen *and* semicolon!
        printf("%s\n", systemInfo.version
        
        //A hardware identifier
        printf("%s\n", systemInfo.machine);
        
        //And the domain name
        printf("%s\n", systemInfo.domainname);
    }
}
