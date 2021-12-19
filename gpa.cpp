/**
 * Name: Anupriya Dubey
 * Date: December 19th, 2021
 * Description: The following program is calculates the final gpa for the current 
 * semester utlizing a student's final grades in each course. It was written in C++ 11. It 
 * incorporates data structures such a vectors and arrays to store, access and manipulate values to compute the final gpa.
 * This program follows a 4.3 grading scale and utilizes the gpa calculation used by Ontario Tech University.
 * 
*/
 

#include <iostream>
#include<string>
#include <vector>

using namespace std;

void calc_gpa(string grades[], int n);

int main(){

    cout << " " << endl;
    int n = 0; //the number of subjects
    cout<<"How many subjects did you take this semester?: ";
    cin >> n;

    string grades[n];

    string grade = ""; //examples: "A+", A", A-"
    for (int i = 0; i < n; i++){
        cout << "Enter grade for subject " << i+1 << ": ";
        cin >> grade;
        grades[i] = grade;
        cout << endl;
    }

    calc_gpa(grades, n);

    
    return 0;
}

void calc_gpa(string grades[], int n){
    vector <string> letter_grades = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "D", "F"};
    vector <double> grades_weight = {4.3, 4, 3.7, 3.3, 3, 2.7, 2.3, 2, 1, 0};
    double sum_scores = 0.0;

    for (int i = 0; i < n; i++){

        //find index of each letter grade
        auto it = find(letter_grades.begin(), letter_grades.end(), grades[i]);
        if(it != letter_grades.end()){
            int index = it - letter_grades.begin();
            cout << "Index: " << index << endl;
            cout << "grade weight: " << grades_weight[index] << endl;
            sum_scores += grades_weight[index];
        }
        else{
            cout << -1 << endl;
        }
        
    }

    double sem_gpa = sum_scores/n;
    cout << " "  << endl;
    cout <<" The final gpa for this semester: " << sem_gpa << endl;
    
}

 //* USE : g++ -std=c++11 gpa.cpp TO RUN