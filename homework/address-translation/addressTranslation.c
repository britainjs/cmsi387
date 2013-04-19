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

    if ( (logical < 0) || (logical >= 256) ) {
        return -1;
    }

    int page = logical >> 4;
    int offset = logical & 15;

    if (ptr[page].valid == 0) {
        return -2;
    }

    int physicalPage = (ptr[page].frame<<4) | offset;
    
    return physicalPage;

}
