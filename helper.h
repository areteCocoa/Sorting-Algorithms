//
//  helper.h
//  Sorting Algorithm Fun
//
//  Created by Thomas Ring on 9/23/14.
//  Copyright (c) 2014 Euler Pi. All rights reserved.
//

#ifndef __Sorting_Algorithm_Fun__helper__
#define __Sorting_Algorithm_Fun__helper__

#include <stdio.h>

typedef enum {
    Ascending,
    Descendding,
    Equal
} ComparisonResult;

void fillFloatArrayWithRandom(float array[]);
void printArray(float array[], int size);
ComparisonResult compareFloats(float first, float second);

#endif /* defined(__Sorting_Algorithm_Fun__helper__) */
