#include <time.h>
#include <linux/unistd.h>
#include <linux/types.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv []) {
    //Demonstrates the time system call, which returns the time since 00:00:00,
    //January 1, 1970. The returned value is in seconds. Takes in an optional
    // pointer, in which it stores the results.
    // JD: Watch your data types and pointers!
    //     (i.e., know when to use pointers and when not to do so)
    //     (hint: You made the wrong choices below)
    long int* result;
    // JD: Well, your types *are* right but you aren't quite there
    //     yet.  Answer this...so result is now a pointer to an int.
    //     Which int?
    //
    //     (Hint: Look at how you fixed uname.c)
    printf("%d\n", syscall(13, result) );

    //To show the use of the parameter
    printf("%ld\n", *result);
}
