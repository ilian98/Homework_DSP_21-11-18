#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main () {
    long long int fn,grade,input; // variables for storing faculty number, grade and faculty number in searching respectively
    string command,name1,name2; // variables for storing command and the first and last name respectively
    fstream file; // variable for the file
    for (;;) {
        cin >> command ;
        if (command=="exit") break; // if command is exit, the program has to finish
        else if (command=="create") { // if command is create, we input data for a person and store it in the file
                if (file.is_open()==0) { // we check if the file is already open
                   file.open("StudentsGrades.db",ios::in|ios::out); // if the file is not open, we open it
                   if (file.is_open()==0) { // if the file is still not open, this means that it does not exist and we create it
                      file.open("StudentsGrades.db",ios::in|ios::out|ios::trunc);
                      }
                   }
                cin >> fn >> name1 >> name2 >> grade ; // we input the data for some student
                file.clear(); // we clear the flags
                file.seekg(0,ios_base::end); // we position the stream at the end of the file
                file << fn << " " << name1 << " " << name2 << " " << grade << "\n"; // we save the data in the file
                cout << "Record saved!\n";
                }
        else if (command=="sequentialSearch") { // if command is sequentialSearch we search for a person in the file
                if (file.is_open()==0) { // if the file is not open, we open it
                   file.open("StudentsGrades.db",ios::in|ios::out);
                   if (file.is_open()==0) continue; // if the file is still not open, this means it does not exist and we cannot search
                   }
                cin >> input ; // we input a faculty number for the search
                file.clear(); // we clear the flags
                file.seekg(0,ios_base::beg); // we position the stream at the beginning of the file
                for (;;) {
                    if (!(file >> fn >> name1 >> name2 >> grade)) break; // this statement checks if we are at the end of the file
                    if (input==fn) { // if the current faculty number is the same as the input faculty number, we found the student
                       cout << fn << " " << name1 << " " << name2 << " " << grade << "\n";
                       break;
                       }
                    }
                }
        }
    file.close(); // we close the file because we finished the work with it
    cout << endl ;
    return 0;
}
