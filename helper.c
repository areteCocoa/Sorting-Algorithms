//
//  helper.c
//  Sorting Algorithm Fun
//
//  Created by Thomas Ring on 9/23/14.
//  Copyright (c) 2014 Euler Pi. All rights reserved.
//

#include "helper.h"
#include <time.h>
#include <stdlib.h>

const int verbose = 1;

float randomFloat() {
    float random;
    
    random = (float)rand()/(float)rand();
    return random;
}

void fillFloatArrayWithRandom(float* array, int size) {
    srand((int)time(NULL));
    
    for (int index = 0; index < size; index++) {
        array[index] = randomFloat();
    }
    
}

void printArray(float array[], int size) {
    if (verbose != 0) {
        printf("[");
        float current;
        for (int count=0; count < size; count++) {
            current = array[count];
            printf("%.2f", current);
            if (count + 1 < size) {
                printf(", ");
            }
        }
        printf("]");
    }
}

void printArrayLine(float array[], int size) {
    printArray(array, size);
    printf("\n");
}

ComparisonResult compareFloats(float first, float second) {
    if (first > second) {
        return Descendding;
    } else if (first < second) {
        return Ascending;
    } else {
        return Equal;
    }
}