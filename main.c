//
//  main.c
//  Sorting Algorithm Fun
//
//  Created by Thomas Ring on 9/23/14.
//  Copyright (c) 2014 Euler Pi. All rights reserved.
//

#include <stdio.h>
#include "merge_sort.h"
#include "helper.h"

void swapFloatingElements(float *first, float *second) {
    float copy = *first; // first value
    
    *first = *second;
    *second = copy;
}

/* main */
int main(int argc, const char * argv[]) {
    
    int size = 100;
    float array[size];
    
    fillFloatArrayWithRandom(array, size);
    
    printArrayLine(array, size);
    
    mergeSortArray(array, size);
    
    printf("\n");
    printf("THE FINAL ARRAY VALUE: ");
    printArrayLine(array, size);
    
    return 0;
}

