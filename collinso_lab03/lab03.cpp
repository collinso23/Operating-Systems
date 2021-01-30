/**
 * Orion Collins 
 *  Lab03
 */

#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

int main() 
{
    
    ifstream inFile;
    int line, min;
    int fileDataArray[10];
    string fileName;
    
    //Ask user for file and open it
    cout << "Enter input file: ";
    cin >> fileName;
    inFile.open (fileName, ios::in);
    
    // if(file was opened) {read the data into array}; else {print an error}
    if (inFile.is_open()){
        while (!inFile.eof()) {
            inFile >> fileDataArray[line++];
        }

        //print out values stored in the array along with keeping track of the minimum
        for (int i = 0; i < line; i++){
            if (fileDataArray[i] < min){
                min = fileDataArray[i];
            }
            printf ("%i ",fileDataArray[i]);
        }
        
        printf ("\nThe minimum value from the file is %i\n",min);
    }    
    else {
        printf ("FAILED TO OPEN\n");
        exit(-1);
    }
    inFile.close();
    return 0;
}