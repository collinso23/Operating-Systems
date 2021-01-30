/*
 * Orion Collins
 * Problem 7: grade exams
 */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctype.h>
#include <string>
#include <stdio.h>
#include <limits>

using namespace std;
	struct Node{
	double data;
	struct Node *next;
};

//grades the exams
double grade_exam(string correct_answers,string answers){
	double counter = 0;
	for(int i = 0 ; i < 9;i++){
		if(answers[i] == correct_answers[i]){
			counter+=1;
		}
	}

	return counter/9;
}

//push data to struct
void push(struct Node *head, double data){
	Node *curr = head;

	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = (Node*)malloc(sizeof(Node));
	curr->next->data = data;
	curr->next->next = NULL;
}

//calculate average score
string average(Node *head,int exams_graded){
	Node *curr = head;
	double total = 0;
	while(curr != NULL){
		total+= curr->data;
		curr = curr->next;
	}
	string r_string = "Average grade was " + to_string(total/exams_graded);
	return r_string;
}

//calculate lowest score
string lowest(Node *head){
	int occurences = 0;
	double lowest = numeric_limits<double>::max();

	Node *curr =head;
	while(curr != NULL){
		double c_data = curr->data;
		if(c_data < lowest){
			lowest = c_data;
			occurences = 0;
		}
		if(c_data == lowest){
			occurences++;
		}
		curr = curr->next;
	}

	string r_string = "Grade is " + to_string(lowest) + " with " + to_string(occurences) + " occurences\n";
	return r_string;
}

//calulate highest score
string highest(Node *head){
	int occurences = 0;
	double highest = numeric_limits<double>::min();

	Node *curr =head;
	while(curr != NULL){
		double c_data = curr->data;
		if(c_data > highest){
			highest = c_data;
			occurences = 0;
		}
		if(c_data == highest){
			occurences++;
		}
		curr = curr->next;
	}

	string r_string = "Highest Grade is " + to_string(highest) + " with " + to_string(occurences) + " occurences\n";
	return r_string;
}

//calulate who passed the exam
string passed(Node *head){
	int occurences = 0;

	Node *curr = head;
	while(curr != NULL){
		double c_data = curr->data;
		if(c_data >= .70){
			occurences++;
		}
		curr = curr->next;
	}

	string r_string = to_string(occurences) + " students passed\n";
	return r_string;
}


//print out exam results formated
void print_exam(Node *head,int exams_graded){
	Node *curr = head;
	cout << "Number of Exams Graded: " << exams_graded << endl;
	cout << average(head,exams_graded) << endl;
	cout << lowest(head);
	cout << highest(head);
	cout << passed(head);
}


//get infile, init struct, and call grading routines
int main(int argc, char *argv[]){

	ifstream in_stream;
	string correct_answers;
	bool first_line = true;
	int exams_graded = 0;
	in_stream.open("problem7.dat");
	string line;
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));

	if(in_stream.fail()){
		cout << "error trying to open data file." << endl;
	}
	else{
		while(getline(in_stream,line)){
			if(first_line){
				correct_answers = line;
				first_line = false;
			}else{
				double grade = grade_exam(correct_answers,line);
				exams_graded++;
				push(head,grade);
			}
		}
	}

	head = head->next; 
	print_exam(head,exams_graded);

	return 0;
}
