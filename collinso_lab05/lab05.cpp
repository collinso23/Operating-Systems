/*
 *  Orion Collins
 *  Lab05
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

void print_array(int inArr[],int size){
    //printf("Here is the array:\n");
    for (int i = 0; i < size; i++) {
        cout << inArr[i] << " ";
    }
    printf("\n\n");
}

int main(int argc, char* argv[]) {
    // check for correct numbers of args if not then prompt user for n
    int *arr;
    //int len = sizeof(arr)/sizeof(arr[0]);
    bool fromconsole = true;
    int len;
    //gets user input and stores it in an array
    if (argc < 4){
        arr = new int[3];
        len = 3;
        fromconsole = false;
        printf ("Please enter 3 space(' ') sperated values: \n");
        for (int i=0; i < len; i++){
            scanf ("%d",&arr[i]);
        }
        printf("\nArray from User Input\n");
        print_array(arr,len);
    }
    else if(argc >= 4) {   //store argv into int array for manipulation
        len = argc-1;
        arr = new int[len];
        printf("Array from Console Input\n");
        for (int i = 0; i < len; i++) {
            arr[i] = atoi(argv[i+1]);
        }
        print_array(arr,len);
    }

    //sort and print out sorted array
    cout << "Sorting" << endl;
    sort(arr,arr+len);
    print_array(arr,len);
    return 0;
}
