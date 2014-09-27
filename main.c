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
    // insert code here...
    float testArray[] = {0.5, 1.0, 0.1, 0.7, 0.4, 0.3, 0.6};
    int size = sizeof(testArray)/sizeof(float);
    
    printArray(testArray, size);
    
    mergeSortArray(testArray, size);
    
    printf("THE FINAL ARRAY VALUE: ");
    printArray(testArray, size);
    
    return 0;
}

