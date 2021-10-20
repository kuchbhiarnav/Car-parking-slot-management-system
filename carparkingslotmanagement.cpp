// parking slot area
//car parking-->19(C1-C19)
//1 entrance , 2 exits

#include <iostream> //header file for standard input-output//
#include <string>
#include <conio.h>
#include <fstream> //Used to create files, write information to files, and read information from files//
#include <stdlib.h>
#include <chrono> //header file to sync system time//
#include <ctime>  //header file to show time//
using namespace std;

class CAR //CAR class created//
{

public:
     string phone_num, cust_name; //string variables initialized//
     int vehicle_num;
     char slot[50], a;
     float stay_hrs;

     void input() //Input Function to take user input//
     {
          system("CLS"); //CLS - Clearing the Screen: system("CLS");//
          int the_car;
          cout << endl
               << "\t Enter the name of the customer: ";
          cin >> cust_name;
          cout << endl
               << "\tEnter the phone number: ";
          cin >> phone_num;
          cout << endl
               << "\tEnter the vehicle number: ";
          cin >> vehicle_num;
          cout << endl
               << "\tEnter the time duration of the stay: ";
          cin >> stay_hrs;
          cout << endl
               << "\tEnter the time slot: ";
          cin >> slot;
          if (the_car < 20 && stay_hrs < 8) //if condition to display parking spaces//
          {
               cout << "\tParking Space Available!\n";
               cout<<"\tBooking Confirmed!";
               auto givemetime = chrono::system_clock::to_time_t(chrono::system_clock::now()); //Used to sync system time and date//
               cout << "\n\n\t\tCar got parked!! at:- "<< ctime(&givemetime)<<endl; //Used to display current system time//
               cout<<"\n\n\t\tPlease select option 5. to print your parking ticket"<<endl;
          }
     }

     void calculate() // calculate function calculates the charge = stay hours * cost
     {

          system("CLS");
          cout << "\n\n\t\tGST CHARGED = Rs. 2.73" << endl; //GST() - Taxes
          cout << "\n\n\t\tThe total parking charge is:  "; //regular charges
          cout << stay_hrs * 30 + 2.73 << " rupees";        //Total = stay hours * cost + 2.73//
     }

     void output() // output function will display the details of the user//
     {
          cout << "\n\n\t\t Customer's Name : " << cust_name << endl;
          cout << "\n\n\t\t Phone number : " << phone_num << endl;
          cout << "\n\n\t\t Car Number : " << vehicle_num << endl;
          cout << "\n\n\t\t Hours Of Stay : " << stay_hrs << endl;
          cout << "\n\n\t\t Time Slot Of Parking : " << slot << endl;
          cout << "\n\n";
     }
} d0;

void delete_my_record() //Delete Function used to delete the stored data in the file//
{
     int num;
     system("CLS");
     cout << "\n\n\t Enter the car number you want to remove from the slot: ";
     cin >> num;
     ifstream inFile;
     inFile.open("cardata.dat", ios::binary); //To open the file//
     ofstream outFile;
     outFile.open("temp.dat", ios::out | ios::binary); //To open a temporary file//
     while (inFile.read((char *)&d0, sizeof(d0)))
     {
          if (d0.vehicle_num != num) //If the vehicle_num = num, then we write into the temp file//
          {
               outFile.write((char *)&d0, sizeof(d0));
          }
     }
     auto givemetime = chrono::system_clock::to_time_t(chrono::system_clock::now());
     cout<<"\n\n\t\t Booking Cancelled!\n";
     cout << "\n\n\t\t Parking Record Deleted at \n"<< ctime(&givemetime) << endl;

     inFile.close();  //To close the cardata file//
     outFile.close(); //To close the temporary file//

     remove("cardata.dat");             //Remove function to delete the cardata//
     rename("temp.dat", "cardata.dat"); //Rename Function to change the temp file name back to caradata//
}

int main() //driver code//
{
     system("Color E4 "); //changes the colour for the output terminal

     int login(), option, the_car, vehicle_num; //variables initialized//
     login();                                   //login function called//
     while (1)
     {
          system("CLS");
          cout << R"(
                                       __   _                     __      __                                                                 __ 
  _________ ______   ____  ____ ______/ /__(_)___  ____ _   _____/ /___  / /_   ____ ___  ____ _____  ____ _____ ____  ____ ___  ___  ____  / /_
 / ___/ __ `/ ___/  / __ \/ __ `/ ___/ //_/ / __ \/ __ `/  / ___/ / __ \/ __/  / __ `__ \/ __ `/ __ \/ __ `/ __ `/ _ \/ __ `__ \/ _ \/ __ \/ __/
/ /__/ /_/ / /     / /_/ / /_/ / /  / ,< / / / / / /_/ /  (__  ) / /_/ / /_   / / / / / / /_/ / / / / /_/ / /_/ /  __/ / / / / /  __/ / / / /_  
\___/\__,_/_/     / .___/\__,_/_/  /_/|_/_/_/ /_/\__, /  /____/_/\____/\__/  /_/ /_/ /_/\__,_/_/ /_/\__,_/\__, /\___/_/ /_/ /_/\___/_/ /_/\__/  
                 /_/                            /____/                                                   /____/                                 

)" << '\n';

          cout << R"(
                                                                                    ____                     _____________         _____________
                                                                               ____//_]|________        ____//__][__][___|    ____//__][______||
                                                                              (o _ |  -|   _  o|       (o  _|  -|     _ o|   (o _ |  -|   _   o|
                                                                              `(_)-------(_)--'        `-(_)--------(_)-'    `(_)-------(_)---'
          )" << '\n';
          cout << endl;
          cout << endl
               << "\t========================================";
          cout << endl
               << "\t  1. Book a slot for the vehicle: ";
          cout << endl
               << "\t  2. Total number of vehicles Parked: ";
          cout << endl
               << "\t  3. Total parking charges of all vehicles with details: ";
          cout << endl
               << "\t  4. To Cancel the booking: ";
          cout << endl
               << "\t  5. To Print the Ticket: ";
          cout << endl
               << "\t  6. To View the Parking Record: ";
          cout << endl
               << "\t  7. Exit the Program ";
          cout << endl
               << "\t========================================";
          cout << endl;
          cout << "\tSelect Your Option--> ";
          cin >> option;

          switch (option) //switch cases initialized//
          {

          case 1: //This switch case is used to book a parking slot//
          {
               char b;
               cout << "\n\n\t\t==Do You Want to continue further== ";
               cout << "(\n\n\t\t |y=yes| |n=no| )";
               cin >> b;
               if (b == 'y') //if loop here used to take user input if choice (b) = y//
               {

                    ofstream f1("cardata.dat", ios::binary | ios::out | ios::app); //to read and write inside the file//
                    d0.input();                                                    //void input() function called//
                    f1.write((char *)&d0, sizeof(d0));
               }
               break; // Used to terminate a statement sequence.
          }
          case 2: //Switch case used to the see the total no.of cars parked//
          {
               system("CLS");
               cout << "\n\n\t\t=== View the Records in the Parking Database ===";
               cout << endl;
               ifstream infile("cardata.dat", ios::binary | ios::in);
               int the_car = 1;                             //To initialize the the_car as 1 to start the while loop//
               while (infile.read((char *)&d0, sizeof(d0))) //while loop initialized//
               {
                    system("CLS");
                    cout << endl;
                    cout << "\n\n\tThe Car position is in parking lot : " << the_car;
                    the_car++;   //increment operator used to increment from 1//
                    d0.output(); //void output() called//
                    cout << endl;
                    cout << "\n\n\n";
                    system("PAUSE"); // PAUSE function pauses the program and waits for that to terminate before it continues execution of the program//
                    cout << endl;
               }

               break;
          }
          case 3: //This switch case is used to show all the parking charges//
          {
               ifstream infile("cardata.dat", ios::binary | ios::in);
               int the_car = 1;
               while (infile.read((char *)&d0, sizeof(d0)))
               {
                    cout << "\n";
                    d0.calculate(); //Void calculate() function called//
                    the_car++;
                    d0.output(); //void output() called//
                    system("PAUSE");
                    cout << "\n";
                    cout << endl;
               }
               break;
          }
          case 4:
          {

               delete_my_record(); //void delete_my_record function called//
               break;
          }

          case 5:
          {
               system("CLS");
               ifstream infile("cardata.dat", ios::binary | ios::in);
               int the_car;
               while (infile.read((char *)&d0, sizeof(d0)))
               {
                    cout << "\n";
                    d0.calculate();
                    auto givemetime = chrono::system_clock::to_time_t(chrono::system_clock::now());
                    cout << "\n\n\t\t\t^^^^ HERE IS YOUR PARKING TICKET ^^^^\n\n\tDate/Time:-\t" << ctime(&givemetime) << endl;
                    system("PAUSE");
                    the_car++;
                    cout << "\n";
                    cout << endl;
               }

               break;
          }

          case 6:
          {

               cout << "\n\n\t\t\t ****PARKING RECORD****";
               ifstream infile("cardata.dat", ios::binary | ios::in);
               while (infile.read((char *)&d0, sizeof(d0)))
               {
                    cout << "\n\n*************************************************************";
                    d0.output();
                    the_car++;
                    cout << "Prepared by - admin \t\t Approved by - Manager";
                    cout << "\n\n*************************************************************";
                    cout << endl;
                    system("PAUSE");
               }
          }
          break;

          case 7:
          {
               system("CLS");
               exit(0); //to exit the program//
               break;
          }
          default: // default values for function parameters//
          {
               cout << "\n\n\t\t Invalid input" << endl;
               cout << "\t\t Please choose from the given options above!!" << endl;
               cout << "\n\n\t\tPress Enter to continue";
          }
          }
          getch();
     }
}

int login() //login() function initialized//
{

     string pass = ""; // making a string for user input//
     string uid = "";  // making a string for user input//
     char ch;
     cout << "\n\n\n\n\n\n\n\t\t\t\t\tCar Parking Reservation System Login Portal";
     cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter User ID:- ";
     uid = _getch();
     while (ch != 13)
     { //character 13 is entered//
          uid.push_back(ch);
          cout << '*';
          ch = _getch();
     }
     if (uid == "20bcs6658") //if loop executes if str uid = "20bcs6658"//
     {
          system("");
     }

     cout << "\n\n\t\t\t\t\t\tPlease Enter Password: ";
     ch = _getch();
     while (ch != 13)         //while loop initialized takes input upto 13 characters//
     {                        //character 13 is enter
          pass.push_back(ch); //push_back() function is used to push elements into a vector from the back.//
          cout << '*';
          ch = _getch();
     }
     if (pass == "123") //if loop executes if str pass = "pass"//
     {
          cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
          system("PAUSE");
     }
     else //else this access will be denied//
     {
          cout << "\n\n\n\n\t\t\t\t\t Access Denied...Please Try Again!!\n";
          system("PAUSE");
          system("CLS");
          login();
     }
     return 0;
}
