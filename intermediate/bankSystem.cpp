#include <iostream>
#include <iostream>
#include <cmath>
#include <istream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class account_query
{
private:
    char account_number[20];
    char firstName[20];
    char lastName[20];
    float total_Balance;

public:
    void read_data();
    void show_data();
    void write_rec();
    void read_rec();
    void search_record();
    void delete_data();
    void edit_record();
};

void account_query ::read_data()
{
    cout << "\nEnter the Account Number";
    cin >> account_number;
    cout << "\nEnter the first name :  ";
    cin >> firstName;
    cout << "\nEnter the lasr name : ";
    cin >> lastName;
    cout << "\nEnter Balance :  ";
    cin >> total_Balance;
}
 
void account_query ::show_data()
{
    cout << "Account Name" << account_number << endl;
    cout << "First Name" << firstName << endl;
    cout << "Last Name" << lastName << endl;
    cout << "Current Balance : Rs." << total_Balance << endl;
    cout << ".......................\n";
}

void account_query ::write_rec()
{
    fstream file;
    file.open("record", ios ::binary | ios ::app);
    read_data();

    file.write(reinterpret_cast<char *>(this), sizeof(*this));

    file.close();
};

void account_query ::read_rec()
{
    fstream ifile;
    ifile.open("record", ios ::binary | ios ::in);
    if (!ifile)
    {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    };
    cout << "\n****Data from file****" << endl;

    while (!ifile.eof())
    {
        if (ifile.read(reinterpret_cast<char *>(this), sizeof(*this)))
        {
            show_data();
        }
    }
    ifile.close();
};
void account_query ::search_record()
{
    int n;
    ifstream infile;
    infile.open("record", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Search: ";
    cin>>n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    show_data();
    infile.close();
}  
void account_query ::edit_record(){
    int n;
  fstream ifile;
    ifile.open("record", ios ::binary | ios ::in);
    if (!ifile)
    {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    };
    ifile.seekg(0 ,ios::end );
    int count = ifile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to edit: ";
    cin>>n;
     ifile.seekg((n-1)*sizeof(*this));
     ifile.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout<<"Record "<<n<<" has following data"<<endl;
    show_data();
    ifile.close();
    ifile.open("record.bank", ios::out|ios::in|ios::binary);
    ifile.seekp((n-1)*sizeof(*this));
    cout<<"\nEnter data to Modify "<<endl;
    read_data();
    ifile.write(reinterpret_cast<char*>(this), sizeof(*this));

}
int main()
{
    account_query A;
    int choice;
    cout << "account information system";
    while (true)
    {
        cout << "Select one of application";
        cout << "\n\t1-->Add record to file";
        cout << "\n\t2-->Show  record from file";
        cout << "\n\t3-->Search record from file";
        cout << "\n\t5-->Edit record from file ";
		cout << "\n Quit \n  ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            A.write_rec();
            break;
        case 2:
            A.read_rec();

            break;
        case 3:
            A.search_record();
            break;
        case 4:
            A.edit_record();
            break;    
        default:
            cout << "\nEnter corret choice : ";

            exit(0);
        }
    }

    system("pause");
    return 0;
}