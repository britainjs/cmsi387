/**
 * Implementation of the software paging unit.
 */
#include "addressTranslation.h"

#include <stdio.h>
#include <stdlib.h>

static pagetable *ptr = NULL; // ptr = "page table register"

void setPageTable(pagetable *pt) {
    ptr = pt;
}

int getPhysical(int logical) {
    // JD: This is right, but better to use the PAGESIZE,
    //     PAGEBITS, and PAGEMASK macros defined in the .h
    //     file---if you do it that way, changing those
    //     will automatically adapt your code to different
    //     address register and page size settings.
    //
    //     Not to mention ERR_OUT_OF_RANGE and ERR_INVALID!
    if ( (logical < 0) || (logical >= 256) ) {
        return -1;
    }

    int page = logical >> 4;
    int offset = logical & 15;

    if (ptr[page].valid == 0) {
        // JD: ^^^ !ptr[page].valid works in C also :)
        return -2;
    }

    int physicalPage = (ptr[page].frame<<4) | offset;
    
    return physicalPage;

}
