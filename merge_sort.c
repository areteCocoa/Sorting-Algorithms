//
//  merge_sort.c
//  Sorting Algorithm Fun
//
//  Created by Thomas Ring on 9/23/14.
//  Copyright (c) 2014 Euler Pi. All rights reserved.
//

#include "merge_sort.h"
#include "helper.h"

void appendArrayWithArray(float origin[], float addition[], int entryIndex, int additionSize, int additionEntryIndex) {
    float nextValue;
    for (int count = additionEntryIndex; count < additionSize; count ++) {
        nextValue = addition[count];
        origin[count - additionEntryIndex + entryIndex] = nextValue;
    }
}

void mergeArrays(float * first, float * second, const int firstSize, const int secondSize, float* destination) {
    printf("\nMerging arrays: %p %p ===== ", first, second);
    printArray(first, firstSize);
    printf(" and ");
    printArrayLine(second, secondSize);
    
    int resultCount = 0;
    
    int firstCount = 0, secondCount = 0;
    float firstFloat = first[firstCount];
    float secondFloat = second[secondCount];
    
    while (resultCount < firstSize + secondSize) {
        if (firstCount < firstSize && secondCount < secondSize) {
            printf("Comparing values %.1f and %.1f: ", firstFloat, secondFloat);
            
            ComparisonResult comparison = compareFloats(firstFloat, secondFloat);
            if (comparison == Ascending || comparison == Equal) {
                destination[resultCount] = firstFloat;
                
                firstCount++;
                firstFloat = first[firstCount];
            } else if (comparison == Descendding) {
                destination[resultCount] = secondFloat;
                
                secondCount++;
                secondFloat = second[secondCount];
            }
            printf("%.1f inserted.\n", destination[resultCount]);
        } else if (firstCount >= firstSize) {
            appendArrayWithArray(destination, second, resultCount, secondSize, secondCount);
            secondCount = secondSize;
            
        } else if (secondCount >= secondSize) {
            appendArrayWithArray(destination, first, resultCount, firstSize, firstCount);
            firstCount = firstSize;
        }
        resultCount = firstCount + secondCount;
        printArrayLine(destination, firstSize + secondSize);
    }
    
    printf("Arrays merged to %p ===== ", destination); printArrayLine(destination, firstSize + secondSize);
}

void mergeSortArray(float array[], int size) {
    if (size == 1) {
        return;
    }
    
    printf("\nMerge sorting array of size %d.\n", size);
    
    int firstSize = size/2;
    int secondSize = size - firstSize;
    
    float first[firstSize];
    float second[secondSize];
    
    for (int count = 0; count < firstSize; count+=1) {
        first[count] = array[count];
    }
    for (int count = firstSize; count < size; count++) {
        second[count-firstSize] = array[count];
    }
    
    printf("Array split into two:\n");
    printArrayLine(first, firstSize);
    printArrayLine(second, secondSize);
    
    mergeSortArray(first, firstSize);
    mergeSortArray(second, secondSize);
    
    mergeArrays(first, second, firstSize, secondSize, array);
    
    printf("Merge sorted array: ");
    
    //array = &sortedArray;
    
    printArrayLine(array, size);
}