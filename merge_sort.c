//
//  merge_sort.c
//  Sorting Algorithm Fun
//
//  Created by Thomas Ring on 9/23/14.
//  Copyright (c) 2014 Euler Pi. All rights reserved.
//

#include "merge_sort.h"
#include "helper.h"

void appendArrayWithArray(float origin[], float addition[], int entryIndex, int additionSize) {
    for (int count = 0; count < additionSize; count ++) {
        origin[count + entryIndex] = addition[count];
    }
}

void mergeArrays(float * first, float * second, const int firstSize, const int secondSize, float* destination) {
    printf("\nMerging arrays: ");
    printArray(first, firstSize);
    printf("\t\t\t and ");
    printArray(second, secondSize);
    
    int resultCount = 0;
    
    int firstCount = 0, secondCount = 0;
    float firstFloat = first[firstCount];
    float secondFloat = second[secondCount];
    
    while (resultCount < firstSize + secondSize) {
        if (firstCount < firstSize && secondCount < secondSize) {
            printf("Comparing values %f and %f.\n", firstFloat, secondFloat);
            
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
        } else if (firstCount >= firstSize) {
            appendArrayWithArray(destination, second, resultCount, secondSize);
            secondCount = secondSize;
            
        } else if (secondCount >= secondSize) {
            appendArrayWithArray(destination, first, resultCount, firstSize);
            firstCount = firstSize;
        }
        resultCount = firstCount + secondCount;
        printArray(destination, firstSize + secondSize);
    }
    
    printf("Arrays merged to "); printArray(destination, firstSize + secondSize);
}

void mergeSortArray(float array[], int size) {
    if (size == 1) {
        return;
    }
    
    printf("Merge sorting array of size %d.\n", size);
    
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
    printArray(first, firstSize);
    printArray(second, secondSize);
    
    mergeSortArray(first, firstSize);
    mergeSortArray(second, secondSize);
    
    float sortedArray[size];
    mergeArrays(first, second, firstSize, secondSize, sortedArray);
    
    printf("Merge sorted array: ");
    
    array = sortedArray;
    
    printArray(array, size);
}