#include <time.h>
#include <linux/unistd.h>
#include <linux/types.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv []) {
    //Demonstrates the time system call, which returns the time since 00:00:00,
    //January 1, 1970. The returned value is in seconds. Takes in an optional
    // pointer, in which it stores the results.
    long int* result;
    printf("%d\n", syscall(13, result) );
    
    //To show the use of the parameter
    printf("%ld\n", *result);
}