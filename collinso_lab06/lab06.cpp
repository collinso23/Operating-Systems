/*
 * Orion Collins
 * Lab 6: analyze college enrollment data
 */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctype.h>
#include <string>
#include <stdio.h>

using namespace std;


//Checks if string contains only positive integers
bool true_integer(string w){
	int pos = 0;
	if(w[pos] == '-'){
		pos++;
	}
	for(int i = 0 + pos; i < (int)w.length(); i++){
		if(isdigit(w[i]) == false){
			return false;
		}
	}

	return true;
}

//Splits line from file by spaces
int *split_String(string line){
	int *arr = new int[7];
	int pos = 0;
	string s_number = "";
	line += " ";
	for(auto x : line){
		if(x == ' '){
			if(true_integer(s_number)){
				arr[pos] = stoi(s_number);
				pos++;
				if(pos > 6){
					break;
				}
				s_number = "";
			}else{
				return NULL;
			}
		}else{
			s_number += x;
		}
	}

	return arr;
}


/*
 * Reads data from specified .dat file, and if file values inputted correctly,
 * return true, else return false.
 */
bool read_data(int total_enrollments[7][7]){
	unsigned int row = 0;
	ifstream in_stream;
	in_stream.open("problem6.dat");
	string line;

	if(in_stream.fail()){
		printf("error trying to open data file.\n");
	}
	else{
		while(getline(in_stream,line)){
			int *curr_college = split_String(line);

			if(curr_college == NULL){
				cout << "including characters besides whole number characters" << endl;
				in_stream.close();
				return false;
			}


			for(int i = 0 ; i < 7 ;i++){
				total_enrollments[row][i] = curr_college[i];
			}
			row++;
		}
		in_stream.close();
	}
	return true;
}


//Prints each (row,column) value, and sums each column and row
void print_data(int school_data[7][7]){
	int college_counter;
	int total_counter = 0;
	int per_year[7];
	for(int i = 0 ; i < 7; i++){
		per_year[i] = 0;
	}

	for(int i = 0 ; i < 7;i++){
		printf("College %i : ",i+1);
		college_counter = 0;
		for(int j = 0; j < 7; j++){
			printf("	%i	",school_data[i][j]);
			college_counter += school_data[i][j];
			per_year[j] += school_data[i][j];
		}
		printf("| Total College %i : %i \n", i+1,college_counter);
	    total_counter += college_counter;
	}
	
	//print total for each year
	printf("Per Year:");
	for(int i = 0 ; i < 7;i++){
		printf("	%i	",per_year[i]);
	}
	printf("| Total enrollment across all colleges: %i\n", total_counter);
}

int main(int agrc, char* argv[]){

	int total_enrollments[7][7]; // seven colleges 2010-2016. Rows = college, columns = years.
	bool read = read_data(total_enrollments);
	if(read)
		print_data(total_enrollments);

	return 0;
}
