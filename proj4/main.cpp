#include "bst.h"

//Client program makes use of an object Course, allowing the user to create new
//courses and save them for later. The program gives the user the ability to
//save courses, search for courses, search for courses in a range, display
//courses, delete courses from the saved list and delete the entire list.
int main()
{
    Table myTable;
    char response = '\n';
    bool running = true;
    Course course;
    
    //Welcome screen for the user
    cout << "This program allows you to search for classes by course number."
         << " You may also search for a course within a range of numbers that"
         << " You may define. You are able to add courses to the list of "
         << "available courses. You may also remove a course by number from "
         << "the list or if you like, you can get rid of the entire list "
         << "itself.";

    //Loop the running program is contained within to give the user continued
    //choices
    while(running)
    {
        //Display for choices available to the user
        cout << "What would you like to do?" << endl
             << "(1) Add a course to the list of available courses?" << endl
             << "(2) Find courses matching a course number?" << endl
             << "(3) Find courses within a range of numbers?" << endl
             << "(4) Remove a course from the list?" << endl
             << "(5) Remove all the courses from the list?" << endl
             << "(6) Display all the courses?" << endl
             << "(q) Enter 'q' to quit the program" << endl;
        cout << endl << "Enter your choice now: ";
        cin >> response;
        cin.ignore(100, '\n');
        cout << endl;
        
        //response 1: creates a course and then inserts it into the BST
        if(response == '1')
        {
            course.create_course();
            if(myTable.insert_course(course) == 0)
            {
                cout << "The course could not be saved." << endl;
            }
        }
    
        //Choice 2: Has the user enter their search term. Finds all matches in
        //the BST. prompts the user to choose if they would like to see all 
        //the matches. if choosen, all matches are displayed
        if(response == '2')
        {
            int size;
            char response = '\n';
            char * number = new char[50];
            Course ** courses;
            cout << "Enter a course number to search for: ";
            cin.getline(number, 50, '\n');
            cin.clear();
            cout << endl;
            size = myTable.retrieve_num(number, courses);
            if(size > 0)
            {
                cout << "Matching course(s) found. Would you like to display"
                     << " the courses? (y/n): " << endl;
                cin >> response;
                cin.ignore(100, '\n');
                
                if(tolower(response) == 'y')
                {
                    for(int i = 0; i < size; ++i)
                    {
                        courses[i]->display_course();
                    }
                }
            }
        }
        
        //Choice 3: Has the user enter their search terms, an upper and a lower
        //bound to search for Finds all matches in the BST. prompts the user to 
        //choose if they would like to see all the matches. if choosen, all 
        //matches are displayed
        if(response == '3')
        {
        
            int size;
            char response = '\n';
            char * lBound = new char[50];
            char * uBound = new char[50];
            Course ** courses;
            
            cout << "Enter the lowest course number to search for: ";
            cin.getline(lBound, 50, '\n');
            cin.clear();
            cout << "Enter the highest course number to search for: ";
            cin.getline(uBound, 50, '\n');
            cin.clear();
            
            size = myTable.retrieve_range(lBound, uBound, courses);
            if(size > 0)
            {
                cout << "Matching course(s) found. Would you like to display"
                     << " the courses? (y/n): " << endl;
                cin >> response;
                cin.ignore(100, '\n');
                
                if(tolower(response) == 'y')
                {
                    for(int i = 0; i < size; ++i)
                    {
                        courses[i]->display_course();
                    }
                }
            }

            delete [] lBound;
            delete [] uBound;
        }
        
        //Choice 4: Allows the user to enter a course number to delete from
        //the list. 
        if(response == '4')
        {
            char * temp = new char[50];
            cout << "Enter a course number to delete: ";
            cin.getline(temp, 50, '\n');
            cin.clear();

            if(myTable.remove(temp) == 0)
            {
                cout << endl << "The course you entered was not found." << endl;
            }

            else
            {
                cout << endl << "The course was deleted." << endl;
            }
            
            delete [] temp;
        }
        
        //Choice 5: wipes all data from the BST
        if(response == '5')
        {
            cout << endl << "All courses will now be wiped from the list" << endl;
            myTable.remove_all();
        }
        
        //Choice 6: displays all data within the BST to the user
        if(response == '6')
        {
            myTable.display_all();
        }
        
        //Choice q: terminates the loop. allows the program to end.
        if(response == 'q')
        {
            running = false;
        }
    }
    
    cout << "The program will now close" << endl;
    return 0;
}
