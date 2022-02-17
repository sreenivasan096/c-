#include <iostream>
#include <cmath>
#include <istream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void login();
void registr();
void forget();
main()
{

  int choice;
  cout << "*********************  LOGIN *********************\n";
  cout << "1.Login";
  cout << "\n2.Register";
  cout << "\n3.Forget Password : ";
  cout << "\nEnter your Choise : ";
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
    forget();
    break;
  case 4:
    cout << "\nThanka for using .. ";
    break;
  default:

    cout << "\nSorry,wrongChoise : ";
    system("CLS");
    main();
  }
  // return 0;9
}
void registr()
{
  string user, pass;
  system("CLS");
  cout << "Enter the username : ";
  cin >> user;
  cout << "Enter the password : ";
  cin >> pass;

  ofstream reg("database.txt", ios ::app);
  reg << user << " " << pass << endl;
  ifstream readFile("database.txt");
  string mtext;
  while (getline(readFile, mtext))
  {
    // cout << mtext ;
  }
  main();
}

void login()
{
  int exists;
  string user, pass, u, p;
  system("CLS");
  cout << "Enter username  :";
  cin >> user;
  cout << "Enter password  :";
  cin >> pass;

  ifstream input("database.txt");
  while (input >> u >> p)
  {

    if (u == user && p == pass)
    {
      exists = 1;
    }
  }

  input.close();

  if (exists == 1)
  {
    cout << "hello" << user << "\n Thanks for comming again";
    cin.get();
    cin.get();
    main();
  }
  else
  {
    cout << "Invalid user ";
    cin.get();
    cin.get();
    main();
  }
}

void forget()
{
  int exist = 0;
  string searchuser, user, pass;
  system("CLS");
  cout << "Enter username  : ";
  cin >> searchuser;

  ifstream searchu("database.txt");

  while (searchu >> user >> pass)
  {
    if (user == searchuser)
    {
      exist = 1;
      break;
    }
  }

  searchu.close();
  if (exist == 1)
  {
    cout << "Your user name  is " << pass;
    cin.get();
    cin.get();
    main();
  }
  else
  {
    cout << "\n  No user found ";
    cin.get();
    cin.get();

    main();
  }
}