// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Link from stack overflow on cin buffer :https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer
// Login page from: https://www.youtube.com/watch?v=m1uPsXeDp-Q&list=WL&index=2&t=171s



#include<iostream>
#include<istream>
#include <sstream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <set>
#include <regex>

using namespace std; // 
void login();
void registr();
void forgot();
void book();
void Admin();
void Intsructor_available();
void pay();
void lesson();
void cancel();
void availability();



void student_login() // function for student login
{
    cout << "\t\t\tStudent Login Page\n";

    int count = 0;
    string user_name, password, u, pass;
    system("cls");
    cout << "please enter the following details" << endl;
    cout << "USERNAME :";
    cin >> user_name;
    cout << "PASSWORD :";
    cin >> password;

    ifstream input("StudentRegister.txt");
    while (input >> u >> pass)
    {
        if (u == user_name && pass == password)

        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << "\nHello!\n" << user_name << " Login successful!\n";
        cin.get();
        cin.get();
        
    }
    else
    {
        cout << "\n Try again!\n Please Enter usernaem and password\n";
      
    }


}



void instructor_login() //function for instructor login
{
    cout << "\t\t\tInstructor Login Page\n";
    int count = 0;
    string user_name, password, u, pass;
    system("cls");
    cout << "please enter the following details" << endl;
    cout << "USERNAME :";
    cin >> user_name;
    cout << "PASSWORD :";
    cin >> password;

    ifstream input("InstructorRegister.txt"); // check if the stored  username and password is the same as the username and password inputed
    while (input >> u >> pass)
    {
        if (u == user_name && pass == password)

        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << "\nHello!\n" << user_name << " Login successful!\n"; // 
        cin.get();
        cin.get();
  
    }
    else
    {
        cout << "\n Try again!\n Please Enter user name and password\n";
       
    }


}



void student_registration() // Function to register the student
{

    cout << "\t\t\t Student Registration Form\n" << endl;

    cout << "Please enter your first name:\n ";
    string name;
    cin.ignore();//  It is used to flush cin  buffer. I was having problems when I ran the program so I used thi.
    cin >> name;

    cout << "Please enter your last name:\n ";
    string last_name;
    cin.ignore();//  It is used to flush cin  buffer.
    cin >> last_name;

    cout << "Please enter your age:\n";
    int age;
    cin.ignore();
    cin >> age;


    cout << "Please enter your email address:\n";
    string email;;
    cin >> email;
    

  
    string Vehicle;
 
    while (true)
    {
        cout << "Please enter what type of car do you want to drive? ( Manual/Automatic):\n";
        cin >> Vehicle;
        if (Vehicle == "Manual" || Vehicle == "Automatic")
        {
            
            break; // exit loop if car type is valid

        }
        else
        {
            cout << "Car type unavailable." << endl;

        }

    }

    // Get Student Username and Password
    cout << "Pls enter your preffered user name and password" << endl;
    string reguser, regpass, ru, rp;
    system("cls");
    cout << "Enter the username :";
    cin >> reguser;
    cout << "\nEnter the password :";
    cin >> regpass;

    ofstream reg("StudentRegister.txt", ios::app); //
    reg << reguser << ' ' << regpass << endl;
    system("cls");
    cout << "\nRegistration Sucessful\n";
    //main();


}
// Function to register Instructor



void Instructor_registration()
{

    cout << "\t\t\t Instruction Registration Form\n" << endl;

    cout << "Please enter your first name:\n ";
    string name;
    cin.ignore();//  It is used to flush cin  buffer.
    cin >> name;

    cout << "Please enter your last name:\n ";
    string last_name;
    cin.ignore();//  It is used to flush cin  buffer.
    cin >> last_name;

    cout << "Please enter your age:\n";
    int age;
    cin.ignore();
    cin >> age;

    cout << "Please enter your email address:\n";
    string email;
    cin.ignore();
    cin >> email;
    cout << endl;

    string Vehicle;
    
    while (true)
    {
        cout << "Please enter what type of car do you want to drive? ( Manual/Automatic):\n";

        cin >> Vehicle;
        if (Vehicle == "Manual" || Vehicle == "Automatic")
        {
            cout << "\nOkay , car type chosen\n";
            break; // exit loop if car type is valid

        }
        else
        {
            cout << "Car type unavailable." << endl;

        }

    }

  

    // Get Student Username and Password
    cout << "Pls enter your preffered user name and password" << endl;
    string reguser, regpass, ru, rp;
    system("cls");
    cout << "Enter the username :";
    cin >> reguser;
    cout << "\nEnter the password :";
    cin >> regpass;

    ofstream reg("InstructorRegister.txt");
    reg << reguser << ' ' << regpass << endl;
    system("cls");
    cout << "\nRegistration Sucessful\n";
    //main(); 

}






// A class representing a date, that has day,month and year properties.
class Date {
public:
    int day, month, year;

    // Constructors
    Date(int day = 0, int month = 0, int year = 0) : day(day), month(month), year(year) {}

    // Parse a date string in the format "DD/MM/YYYY"
    static Date parseDate(const string& dateStr) {
        stringstream ss(dateStr);
        string day, month, year;
        getline(ss, day, '/');
        getline(ss, month, '/');
        getline(ss, year);
        return Date(stoi(day), stoi(month), stoi(year));
    }

    // Comparison operators
    friend bool operator==(const Date& d1, const Date& d2) {
        return (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year);
    }

    friend bool operator!=(const Date& d1, const Date& d2) {
        return !(d1 == d2);
    }

    friend bool operator<(const Date& d1, const Date& d2) {
        if (d1.year < d2.year) return true;
        if (d1.year > d2.year) return false;
        if (d1.month < d2.month) return true;
        if (d1.month > d2.month) return false;
        return d1.day < d2.day;
    }

    friend bool operator<=(const Date& d1, const Date& d2) {
        return (d1 < d2 || d1 == d2);
    }

    friend bool operator>(const Date& d1, const Date& d2) {
        return !(d1 <= d2);
    }

    friend bool operator>=(const Date& d1, const Date& d2) {
        return !(d1 < d2);
    }
};

bool isValidDate(const string& date) {
    // Regex for date format DD/MM/YYYY
    regex dateFormat(R"((0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/([0-9]{4}))");
    return regex_match(date, dateFormat);
}

bool isValidTime(const string& time) {
    // Regex for 24-hour time format HH:MM
    regex timeFormat(R"((^[0-1][0-9]|2[0-3]):([0-5][0-9]$))");
    return regex_match(time, timeFormat);
}

bool isValidUserName(const string& user_name) {
    // Check if the username is not empty and consists of alphanumeric characters
    regex userNameFormat(R"(^\w+$)");
    return regex_match(user_name, userNameFormat);
}

struct Booking // A struct for Booking it contains the date,start and end time and also the username that would be used for booking.  
{
    string date;
    string  start_time;
    string end_time;
    string user_name;

};

vector<Booking> bookings;

bool RegisteredUser(const string& username)
{
    ifstream file("StudentRegister.txt");
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string file_username;
        ss >> file_username;
        if (file_username == username) {
            return true;
        }
    }
    return false;
}

void bookLesson() {
    string date, start_time, end_time, user_name;

    cout << "\nPlease enter your username: ";
    cin.ignore();
    getline(cin, user_name);

    while (!RegisteredUser(user_name))
    {
        cout << "Invalid username. Please use only registered usernames." << endl;
        cout << "\nPlease enter your username: ";
        getline(cin, user_name);
    }

    cout << "Enter the date of the lesson (DD/MM/YYYY): ";
    getline(cin, date);

    if (!isValidDate(date)) {
        cout << "Invalid date format. Please enter the date in DD/MM/YYYY format." << endl;
        return;
    }

    cout << "Enter the time you wish to start (In 24-hour format HH:MM): ";
    getline(cin, start_time);

    if (!isValidTime(start_time)) {
        cout << "Invalid time format. Please enter the time in HH:MM format." << endl;
        return;
    }

    cout << "Enter the time you wish to finish (In 24-hour format HH:MM): ";
    getline(cin, end_time);

    if (!isValidTime(end_time)) {
        cout << "Invalid time format. Please enter the time in HH:MM format." << endl;
        return;
    }


    for (const Booking& b : bookings) {
        if (b.date == date && b.start_time == start_time && b.end_time == end_time) {
            cout << "The selected date and time slot is booked by another user." << endl;
            return;
        }
    }

    // If no double booking, proceed with the booking
    Booking booking;
    booking.user_name = user_name;
    booking.date = date;
    booking.start_time = start_time;
    booking.end_time = end_time;

    bookings.push_back(booking); // Add the booking to the end of the bookings vector

    // Save the booking to a file
    ofstream file("bookings.txt", ios::app);
    file << booking.date << " " << booking.start_time << " " << booking.end_time << " " << booking.user_name << endl;
    file.close();

    cout << "Lesson booked successfully!" << endl;
}


  



void displayBookings() // function used to display the booking.
{
    ifstream file("bookings.txt");
    string line;
// Error messsage should be displayed  if file does not open
    if (!file.is_open())
    {
        cout << "Error: Unable to open the file" << endl;
        return;
    }
    // If there are no bookings in the "bookings" vector, display this message 
    if (bookings.empty()) {
        cout << "No bookings have been made yet." << endl;
        return;
    }
    
    cout << "Here are the current bookings:" << endl;
    // Loop through each line in the "bookings.txt" file.
    while (getline(file, line)) 
    {
        stringstream ss(line);
        string date, start_time, end_time;
        getline(ss, date, ' ');
        getline(ss, start_time, ' ');
        getline(ss, end_time);

        cout << "Date: " << date << ", Start Time: " << start_time << ", End Time: " << end_time << endl;
    }

}  






// class for student to make payment contains the card number , amount to ba paid, cvc and expiry date.
// Now I didnt put an error message to check if the characters are correct aas I ran out of time
class Payment 
{
private:
    string card_number;
    float amount=0;
    int cvc =0;
    string expiry_date;
public:
    Payment(string card_number, float amount, int cvc, string expiry_date)
    {
        card_number = card_number;
        amount = amount;
        cvc = cvc;
        expiry_date = expiry_date;
    }

    string getcard_number() 
    {
        return card_number;
    }
    float getamount()
    {
        return amount;

    }
    int getCVC()
    {
        return cvc;
    }

    string getexpiry_date()
    {
        return expiry_date;

    }


};



bool isValidDay(const string& day) {
    static const set<string> validDays = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    return validDays.find(day) != validDays.end();
}

void availability()
{
    int days;
    vector<string> workDays;
    string weekDays[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

    cout << "How many days do you want to work? (Enter three or more days) ";
    cin >> days;

    if (days < 3) {
        cout << "Invalid input. You must choose to work at least 3 days." << endl;
        return;
    }

    cout << "Enter the days of the week you want to work from the following options:" << endl;
    for (const auto& day : weekDays) {
        cout << day << " ";
    }
    cout << endl;

    string selectedDay;
    for (int i = 0; i < days; ++i) {
        cout << "Enter day " << (i + 1) << ": ";
        cin >> selectedDay;

        if (!isValidDay(selectedDay)) {
            cout << "Invalid day entered. Please enter a valid day of the week (e.g., Monday, Tuesday, etc.)." << endl;
            --i; // Decrement i to retry this iteration
        }
        else {
            workDays.push_back(selectedDay);
        }
    }

    string startTime, endTime;
    cout << "Enter the start time for the days (in 24-hour format, e.g., 13:30): ";
    cin >> startTime;
    cout << "Enter the end time for the days (in 24-hour format, e.g., 17:45): ";
    cin >> endTime;

    int hours;
    cout << "Enter the number of hours you want to work per day: ";
    cin >> hours;

    if (hours < 6) {
        cout << "Invalid input. You must work at least 6 hours per day." << endl;
        return;
    }

    cout << "You will work " << hours << " hours on ";
    for (size_t i = 0; i < workDays.size(); ++i) {
        cout << workDays[i];
        if (i != workDays.size() - 1) {
            cout << ", ";
        }
    }
    cout << " from " << startTime << " to " << endTime << "." << endl;
}






int main()
{
    int choice;
    cout << "********************MONCLARE DRIVING SCHOOL******************************************\n\n\n";
    cout << "************************ LOGIN PAGE ************************\n\n";
    cout << "*******************        MENU        *******************************\n\n";
    cout << "1.Login" << endl;
    cout << "2.Register" << endl;
    cout << "3.Forgotten Username or Password?" << endl;
    cout << "4.Make a Booking" << endl;
    cout << "5.Fill in Instructor availability" << endl;
    cout << "6.Administration" << endl;
    cout << "7.Exit" << endl;
    cout << "\nEnter your choice :";
    cin >> choice;

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registr();
        break;
    case 3:
        forgot();
        break;
    case 4:
        book();
        break;
    case 5:
        Intsructor_available();
        break;
    case 6:
        Admin();
        break;
    case 7:
        cout << "\tThanks for using the login page\n";
        break;
    
    default:
        system("cls");
        cout << "Wrong choice selected. Select from the menu\n" << endl;
        main();
    }

}


void login()
{
    char userType;

    // Prompt the user for their user types
    cout << "Are you a student or an instructor? (S/I): ";
    cin >> userType;

    // Display the appropriate registration form based on user type
    if (userType == 'S' || userType == 's')
    {
        student_login();
    }
    else if (userType == 'I' || userType == 'i') 
    {
        instructor_login();
    }
    else 
    {
        cout << "Invalid user type." << endl;
    }

}

void registr()// registerUser
{
    char userType;

    // Prompt the user for their user type
    cout << "Are you a student or an instructor? (S/I): ";
    cin >> userType;

    // Display the appropriate registration form based on user type
    if (userType == 'S' || userType == 's')
    {
        student_registration();
    }
    else if (userType == 'I' || userType == 'i')
    {
        Instructor_registration();
    }
    else 
    {
        cout << "Invalid user type." << endl;
    }


}


void forgot() {
    int choice;
    system("cls"); // clear console screen
    cout << "Forgotten? We're here for help\n";
    cout << "1. Search your ID by username" << endl;
    cout << "2. Search your ID by password" << endl;
    cout << "3. Main menu" << endl;
    cout << "Enter your choice: ";
    cin >> choice; // user inputs their choice with a number

    do {
        cout << "Enter your choice (1-3): ";
        cin >> choice; // user inputs their choice with a number

        if (cin.fail() || choice < 1 || choice > 3) {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        }
    } while (choice < 1 || choice > 3);

    switch (choice) {
    case 1: { // search by username
        int count = 0; // initialize counter to 0
        string searchuser, su, sp; // string variables for user input, username, and password
        cout << "\nEnter your remembered username: ";
        cin >> searchuser;

        // Search in StudentRegister.txt
        ifstream searchu("StudentRegister.txt");
        while (searchu >> su >> sp) { // reads each line from the file
            if (su == searchuser) { // if the username is found
                count = 1; // set count to 1
                break;
            }
        }
        searchu.close();

        // If not found in StudentRegister, search in InstructorRegister.txt
        if (count == 0) {
            ifstream searchu("InstructorRegister.txt");
            while (searchu >> su >> sp) { // reads each line from the file
                if (su == searchuser) { // if the username is found
                    count = 1; // set count to 1
                    break;
                }
            }
            searchu.close();
        }

        if (count == 1) { // if username is found
            cout << "\n\nHurray, account found\n";
            cout << "\nYour password is: " << sp << endl; // display the recovered password
            cin.ignore();
            cin.get();
            system("cls");
            main(); // return to main menu
        }
        else { // if username is not found
            cout << "\nSorry, your username is not found in our database\n";
            cout << "Please kindly contact your system administrator for more details\n";
            cin.ignore();
            cin.get();
            main(); // return to main menu
        }
        break;
    }
    case 2: { // search by password
        int count = 0;
        string searchpass, su2, sp2;
        cout << "\nEnter the remembered password: ";
        cin >> searchpass;

        // Search in StudentRegister.txt
        ifstream searchp("StudentRegister.txt");
        while (searchp >> su2 >> sp2) { // reads each line from the file
            if (sp2 == searchpass) { // if the password is found
                count = 1; // set count to 1
                break;
            }
        }
        searchp.close();

        // If not found in StudentRegister, search in InstructorRegister.txt
        if (count == 0) {
            ifstream searchp("InstructorRegister.txt");
            while (searchp >> su2 >> sp2) { // reads each line from the file
                if (sp2 == searchpass) { // if the password is found
                    count = 1; // set count to 1
                    break;
                }
            }
            searchp.close();
        }

        if (count == 1) { // if password is found
            cout << "\nYour password is found in the database\n";
            cout << "\nYour username is: " << su2 << endl;
            cin.ignore();
            cin.get();
            system("cls");
            main();
        }
        else { // if password is not found
            cout << "Sorry, we cannot find your password in our database\n";
            cout << "Kindly contact your administrator for more information\n";
            cin.ignore();
            cin.get();
            main(); // return to main menu
        }
        break;
    }
    case 3: { // takes user to main menu after pressing enter
        cin.ignore();
        main();
        break;
    }
    default: { // if user inputs wrong number display error message below
        cout << "Sorry, you entered the wrong choice. Kindly try again" << endl;
        forgot();
        break;
    }
    }


}


 



           
void book() // This function is actoing as the main memnu for booking
{
    int choice;
    system("cls");

    cout << "Enter your choice:\n\n";
    cout << "\nThis is meant for students only\n\n";

    cout << "1. Book a Lesson\n\n";
        cout << "2.Pay for lesson\n\n";
        cout << "3 Cancel your booking\n";
        cout << "\n4.Exit to main menu\n";

    cin >> choice;


    switch (choice)
    {
    case 1:
        lesson();
        break;
    case 2:
        pay();
        break;
    case 3:
        cancel();
        break;
    case 4:
        cout << "\tThanks for using the login page\n";
        cin.get();
        main();
        break;
    default:
        system("cls");
        cout << "Wrong choice selected. Select from the menu\n" << endl;
        book();
    }
}


void lesson()
{
    cout << "\t\t\tWelcome, Book a Lesson\n" << endl; // 
    bookLesson(); // calls the booklesson function to book a lesson when number 1 is inputted.
    displayBookings(); // displays the booking
}

void pay() // The user is expected to pay after the lesson 
// the user would have thier fees communicated to them on the website
// the fees would be per hour so all they have to do pay.
// I as thinking of adding some sort of condition that would  make them pay at an hourly rate but I dont have time. 

{
    cout << "\t\t\t Wellcome to the Payment Page\n" << endl;
    cout << "\t\t\tPlease Enter your account details\n\n";
    cout << "Enter your card number\n\n";
    string card_number;
    cin >> card_number;

    cout << "\nEnter Amount to be paid\n" << endl;
    float amount;
    cin >> amount;

    cout << "\nEnter your cvc\n" << endl;
    int cvc;
    cin >> cvc;

    cout << "\nEnter the expiry date\n" << endl;
    string expiry_date;
    cin >> expiry_date;

    cout << "Thank yoo payment accepted" << endl;

    Payment payment(card_number, amount, cvc, expiry_date);

    book();


}


void cancel() // function to cancel a booking

{
    cout << "\t\t\tWelcome to the Cancel Booking Page\n";

    cout << "\nPlease enter your username\n"; // prompt user for user name
    string user_name;
    cin >> user_name;

    

    cout << "\n Enter the start time you booked the lesson\n";
    string start_time; // prompt user for start time
    cin >> start_time;

    cout << "\n Enter the finish time you booked the lesson\n";
    string finish_time; // promt user for end time
    cin >> finish_time;


    // Find and remove the booking
    bool found_booking = false;
    for (auto it = bookings.begin(); it != bookings.end(); ++it)
    {
        if (it->user_name == user_name && it->start_time == start_time && it->end_time == finish_time)
        {
            found_booking = true;
            bookings.erase(it);
            break;
        }
    }

    if (found_booking) // if booking is found cancel booking
    {
        // Save the updated bookings to file
        ofstream file("bookings.txt");
        for (const auto& booking : bookings)
        {
            file << booking.user_name << " " << booking.date << " " << booking.start_time << " " << booking.end_time << endl;
        }
        file.close();

        cout << "\n Your booking has been cancelled\n";
    }


    else
    {
        cout << "\nSorry, we could not find a booking matching the details you provided.\n";
    }


}

void Admin()
{
    cout<< "\t\t\tWelcome to the  Reviews Page\n";
    // It is for both students and instructors so they have access to it.
    cout<< "Kindly Leave us a review of our services \n"; // prompt user for  feedbakc
    string feedback;
    cout << " My thoughts on the system is:"<< feedback << endl;
    cin >> feedback;

    cout << "\nThank you for your feedback!";


}
void Intsructor_available()
{
    availability();
}

        





/*
* void forgot()
{
    int choice;
    system("cls"); // clear console screen
    cout << "Forgotten ? We're here for help\n";
    cout << "1.Search your id by username" << endl;
    cout << "2.Search your id by password" << endl;
    cout << "3.Main menu" << endl;
    cout << "Enter your choice :";
    cin >> choice; // user inputs thier choice with a number

    switch (choice)
    {
    case 1: //search by username
    {
        int count = 0; // initialize counter to 0
        string searchuser, su, sp; // string variables for user input, username, and password
        cout << "\nEnter your remembered username :";
        cin >> searchuser;

        ifstream searchu("database.txt");  // opens the file "database.txt" for input
        while (searchu >> su >> sp)  // reads each line from the file
        {
            if (su == searchuser)  // // if the username is found
            {
                count = 1;  // set count to 1
            }
        }
        searchu.close(); // close the file
        if (count == 1)   // if username is found
        {
            cout << "\n\nHurray, account found\n";
            cout << "\nYour password is " << sp;   // display the recovered password
            cin.get();
            cin.get();
            cin.get();
            system("cls");
            main();  // return to main menu
        }
        else  // if username is not found
        {
            cout << "\nSorry, Your username is not found in our database\n";
            cout << "\nPlease kindly contact your system administrator for more details \n";
            cin.get();
            cin.get();
            main();   // return to main menu
        }
        break;
    }
    case 2: // search by password
    {
        int count = 0;
        string searchpass, su2, sp2;
        cout << "\nEnter the remembered password :";
        cin >> searchpass;

        ifstream searchp("database.txt"); // opens the file "database.txt" for input
        while (searchp >> su2 >> sp2)  // reads each line from the file
        {
            if (sp2 == searchpass)  // if the password is found
            {
                count = 1;  // set count to 1
            }
        }
        searchp.close(); // close the file
        if (count == 1)   // if password is found
        {
            cout << "\nYour password is found in the database \n";
            cout << "\nYour password is : " << su2;
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else // if password is not found
        {
            cout << "Sorry, We cannot find your password in our database \n";
            cout << "\nkindly contact your administrator for more information\n";
            cin.get();
            cin.get();
            main(); // return to main menu
        
        }

        break;
    }

    case 3: // takes user to main menu after pressing enter
    {
        cin.get();
        main();
    }

    default: // if user inputs wrong number display error message below
    {
        cout << "Sorry, You entered wrong choice. Kindly try again" << endl;
        forgot();
    }



    }
}

*/