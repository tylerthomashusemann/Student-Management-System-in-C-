#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int main();
void show_data(int searchkey);          // function used to show data to the end user
void get_data(int i);                   // function used to obtain data from end user
void search_student(int searchkey);     
void add_student();                     // function used to add record of a new student
void edit_student(int idnumber);        // function used to edit existing records
void fullscreen();
int ts;

struct student                          // struture student is made to store students info
{
    int rollno;
    string name;
    string fname;
    string cell;
    string dob;
    string address;
};

student rec[50];                        // this is a basic arrar of defined structure to store data
int main()
{
    system("CLS");
    system("color B1");
    int choice;                         // int var used to determine which operation the user would like to do
    int idnumber;                       // int var used to record the ID numbr which the user wants to edit
    int searchkey;                      // int var to store the students roll num by which the user can search for

    cout << "Please, Enter the total number of Students - Max 50: ";
    cin >> ts;

    while(ts--)
    {
        cout << "\n\t\tWhat would you like to do today?" << endl;
        cout << "\n\t---------------------------------"  << endl;
        cout << "\t\t1: Add Student " << endl;
        cout << "\t\t2: Edit Student Info " << endl;
        cout << "\t\t3: Search for a Student " << endl;
        cout << "\t\t4: Exit Program " << endl;
        cout << "\t\t---------------------------------"  << endl;
        cout << "Please, Enter an option from above " << endl;

        cin >> choice;
        switch(choice)
        {
            case 1:                     // if the user enters 1, then the student adding module will be displayed
            add_student();
            break;
            case 2:                     // if there are no records in the array, then the program will ask the user to input records first
            if(rec[0].rollno==0)
            {
                cout << "Please Add in Students first." << endl;
                system("pause");
                main();
            }
            else                        // if records are present in the array, then it will show in table
            {
                cout << endl;
                cout << "------------------------------------------------------------------------------" << endl;
                cout << "-------------------------------Student Records Table--------------------------" << endl;
                cout << "------------------------------------------------------------------------------" << endl;
                cout << "ID   "<<"Roll   "<<"Name   "<<"Parentr\tCell No.   "<<"D.O.B   "<<"Address\n\n";
                cout << "-------------------------------------------------------------------------------" << endl;

                for(int i=0;i<=ts;i++)
                {
                    show_data(i);       // function is called wiht the index value to show data
                }

                cout << "-------------------------------------------------------------------------------" << endl;
                cout << "Which Student ID Number will you like to edit: ";

                cin >> idnumber;         // asking the user for which ID they would want to make a change to

                if(idnumber>ts || idnumber<0)   // validatin the ID number
                {
                    cout << "\nThat is an Invalid ID Number, please try again." << endl;
                }
                else
                {
                    edit_student(idnumber);     // valid ID is entered to edit the function
                }
            }
            break;

            case 3:
                if(rec[0].rollno==0)            // if there is not existing record, then ask the user to input records first
                {
                    cout << "Please Add in Students first." << endl;
                    system("pause");
                    main();                      // return to main so the user can input thier new records
                }
                else 
                {
                    cout << "Enter Roll Number of the student you want to search for: ";
                    cin >> searchkey;           // roll number as the search key can be inputed by the user
                    search_student(searchkey);
                    break;
                    case 4:
                    return 0;                   // terminating the records
                    break;
                    default:                    // default value for an invalid input
                     cout << "That is an Invalid Number." << endl;
                     system("pause");
                    main();
                }
            }
            return 0;
        }
    }


void get_data(int i)
{       // fucntion for receiving data from user
    cout << "Enter student roll number in format (1XXX): ";
    cin >> rec[i].rollno;
    cout << "Enter the Student's Name: ";
    cin >> rec[i].name;
    cout << "Enter Student's Parents Name: ";
    cin >> rec[i].fname;
    cout << "Enter Student's Cell Phone #: ";
    cin >> rec[i].cell;
    cout << "Enter Student's Date of Birth in format (mm/dd/yyyy): ";
    cin >> rec
[i].dob;
    cout << "Enter Student's Address: ";
    cin >> rec[i].address;
}

void show_data(int searchkey)               // function for showing data on the screen
{
    int i=searchkey;
    cout <<i<< "  ";
    cout << rec[i].rollno << "     ";
    cout << rec[i].name << "       ";
    cout << rec[i].fname << "      ";
    cout << rec[i].cell << "       ";
    cout << rec[i].dob <<  "       ";
    cout << rec[i].address << "    ";
}

void search_student(int searchkey)
{
    for(int i=0; i <=ts; i++)               // loop through complete array
    {
        if(rec[i].rollno == searchkey)      // if roll number matches to search term
        {
            cout <<"ID  "<<"Roll    "<<"Name    "<<"Parent\tCell No.    "<<"D.O.B   "<<"Address\n\n";
            show_data(i);                   // function is used insdie another function 
        }
    }
}

void add_student()                               // function is used to add record of a new student
{
    for(int i=0; i <=ts; i++)
    {
        get_data(i);                                // loop was processed 5 times to get input for 5 students
    }
    system("CLS");
    cout << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "-------------------------------Student Records Table--------------------------" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "ID   "<<"Roll   "<<"Name   "<<"Parentr\tCell No.   "<<"D.O.B   "<<"Address\n\n";
    cout << "-------------------------------------------------------------------------------" << endl;

    for(int i = 0; i <= ts; i++)
    {
        show_data(i);                                // loop was processed for 5 times to show obtained records
    }
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------FINISHED--------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    system("pause");

    main();                                         // return to main function to show manu again
} 

void edit_student(int idnumber)                  // function is used to edit existing student records
{
    for(int i = 0; i <= ts; i++)                    // loop is started
    {
        if(idnumber == i)                           // though loop ever value is compared with the search term
        {
            cout << "\nExisting information about this record.\n\n";
            cout << "----------------------------------------------------------------------------" << endl;
            cout << "ID   "<<"Roll   "<<"Name   "<<"Parentr\tCell No.   "<<"D.O.B   "<<"Address\n\n"; 
            cout << "------------------------------------------------------------------------------" << endl;
            show_data(i);                               // load info for existing record
            cout << "\n\nEnter new data for the record show above.\n\n";
            get_data(i);                                // input data for that specific record
            cout << "\n\nRecord updated successfully." << endl;
            system("pause");
            main();          // return to main function
        }
    }
}