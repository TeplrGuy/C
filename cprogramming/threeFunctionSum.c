//
//  main.c
//  cprogramming
//
//  Created by Gilbert Appiah on 5/19/17.
//  Copyright © 2017 gilbertappiah.com All rights reserved.
//

/*
 *
 * Write three functions that compute the sum of the numbers in a given an array of elements
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum(int size, int *arr);
void userInput();
void *append(int size, int *arr);

int sum( int size, int *arr){
    int summ =0;
    size -=1;
    
    while (size >=0 ) {
        summ =  summ+ arr[size];
        size--;
    }
    
    return summ;
}

void *append(int size,int *arr){
    int count=0, r;
    srand((unsigned)time(NULL));
    
    for (count =0; count <= size ; count++) {
        r = rand() %100;
        arr[count] = r;
    }
    
    return 0;
}

void userInput(){
    int *arr = malloc(sizeof(int)), input = 0, size=0, count=0;
    while (1) {
        printf("0 to quit \n");
        printf("1 fill array given size \n");
        printf("2 to sum elements \n");
        printf("Enter: \n");
        scanf("%d", &input);
        switch (input) {
            case 0:
                free(arr);
                exit(1);
            case 1:
                printf("Enter size: \n");
                scanf("%d", &size);
                append(size, arr);
                printf("\n[ ");
                for (count =0; count< size; count++) {
                    printf("%d ", arr[count]);
                }
                printf(" ]\n\n");
                break;
            case 2:
                printf("\nSum:%d \n\n", sum(size, arr));
                break;
            default:
                break;
        }
    }
}

int main(int argc, const char * argv[]) {
    userInput();
    return 0;
}
