//
//  helper.c
//  Sorting Algorithm Fun
//
//  Created by Thomas Ring on 9/23/14.
//  Copyright (c) 2014 Euler Pi. All rights reserved.
//

#include "helper.h"

void fillFloatArrayWithRandom(float* array) {
    printf("Unimplemented function called. Void.");
}

void printArray(float array[], int size) {
    printf("[");
    float current;
    for (int count=0; count < size; count++) {
        current = array[count];
        printf("%f", current);
        if (count + 1 < size) {
            printf(", ");
        }
    }
    printf("]\n");
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