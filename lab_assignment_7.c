//Cristian McGee COP3502C Lab Assignment 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bubbleSortCount(int* arr, int* arrCounter);
int selectionSortCount(int* arr, int* arrCounter);
//in this code I don't make a variable to represent 9 just because 9 is always 9

int main(){
    int array1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    int arr1BubbleSort, arr1SelectionSort, arr2BubbleSort, arr2SelectionSort;
    int array1BubbleSortCount[9], array1SelectionSortCount[9], array2BubbleSortCount[9], array2SelectionSortCount[9];
    
    arr1BubbleSort = bubbleSortCount(array1, array1BubbleSortCount);
    arr1SelectionSort = selectionSortCount(array1, array1SelectionSortCount);
    arr2BubbleSort = bubbleSortCount(array2, array2BubbleSortCount);
    arr2SelectionSort = selectionSortCount(array2, array2SelectionSortCount);
    

    for(int i = 0; i < 4; i++){
        char name[30], name2[30];
        int int3;
        if(i % 2 == 0){
            strcpy(name, "Bubble Sort");
            int3 = i < 2 ? arr1BubbleSort : arr2BubbleSort;
        } else {
            strcpy(name, "Selection Sort");
            int3 = i < 2 ? arr1SelectionSort : arr2SelectionSort;
        }
        if(i < 2){
            strcpy(name2, "Array 1");
        } else {
            strcpy(name2, "Array 2");
        }
        printf("\n%s %s:\n", name2, name);
        for(int j = 0; j < 9; j++){
            int int1, int2;
            if(i == 0){
                int1 = array1[j];
                int2 = array1BubbleSortCount[j];
            } else if(i == 1){
                int1 = array1[j];
                int2 = array1SelectionSortCount[j];
            } else if(i == 2){
                int1 = array2[j];
                int2 = array2BubbleSortCount[j];
            } else {
                int1 = array2[j];
                int2 = array2SelectionSortCount[j];
            }
            printf("%d: %d is the number of times %d is swapped\n", int1, int2, int1);
        }
        printf("The total amount of swaps is %d\n\n", int3);
    }

    return 0;
}

int bubbleSortCount(int* arr, int* arrCounter){
    int totalSwaps = 0;
    int* tempArr = (int*)malloc(9 * sizeof(int));
    
    for(int i = 0; i < 9; i++){
        tempArr[i] = arr[i];
    }

    for (int i = 0; i < 9; i++) {
        arrCounter[i] = 0;
    }

    for (int i = 0; i < 9 - 1; i++) {
        for (int j = 0; j < 9 - i - 1; j++) {
            if (tempArr[j] > tempArr[j + 1]) {
                int temp = tempArr[j];
                tempArr[j] = tempArr[j + 1];
                tempArr[j + 1] = temp;

                arrCounter[j]++;
                arrCounter[j + 1]++;
                totalSwaps++;
            }
        }
    }

    free(tempArr);
    return totalSwaps;
}

int selectionSortCount(int* arr, int* arrCounter){
    int totalSwaps = 0;
    int* tempArr = (int*)malloc(9 * sizeof(int));

    for(int i = 0; i < 9; i++){
        tempArr[i] = arr[i];
    }

    for (int i = 0; i < 9; i++) {
        arrCounter[i] = 0;
    }

    for (int i = 0; i < 9 - 1; i++) {
        int n = i;
        for (int j = i + 1; j < 9; j++) {
            if (tempArr[j] < tempArr[n]) {
                n = j;
            }
        }
        if (n != i) {
            int temp = tempArr[i];
            tempArr[i] = tempArr[n];
            tempArr[n] = temp;

            arrCounter[i]++;
            arrCounter[n]++;
            totalSwaps++;
        }
    }

    free(tempArr); 
    return totalSwaps;
}