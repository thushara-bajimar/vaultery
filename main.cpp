#include<iostream>
#include<fstream>
using namespace std;

string title;

int accountEntry();
int login();
int menu();
int notesEntry();
int viewAll();
int search();
int modify();
int deleteEntry();
int exitProg();

int menu(){
    int choice;

   while(true){

        cout<<"\nWhat do you want to do?\n";

        cout<<"1. Notes Entry\n";
        cout<<"2. View All Entries\n";
        cout<<"3. Search Entry\n";
        cout<<"4. Modify Entry\n";
        cout<<"5. Delete Entry\n";
        cout<<"6. Exit\n";

        cin>>choice;

        if(choice == 1){
            notesEntry();
        }else if(choice == 2){
            viewAll();
        }else if(choice == 3){
            search();
        }else if(choice == 4){
            modify();
        }else if(choice == 5){
            deleteEntry();
        }else if(choice == 6){
            exitProg();
        }else{
            cout<<"Please Enter Proper Option: (1 to 6)\n";
        }
    }
    return 0;
}

int notesEntry(){
    string title, content;

    cin.ignore();

    cout<<"Title: ";
    getline(cin, title);

    cout<<"Content:\n";
    getline(cin, content);
    cout<<"\n";

    ofstream file("vault_notes.txt", ios::app);

    //file<<"***NOTES***\n";
    file<<"Title: "<<title<<endl;
    file<<"Content: "<<content<<endl;
    file<<"---"<<endl;

    file.close();

    cout<<"File Created Successfully!!\n\n";
}

int accountEntry(){
    string username, password;

    cin.ignore();

    cout<<"Username: ";
    getline(cin, username);

    cout<<"Password: ";
    getline(cin, password);

    ofstream file("vault_account.txt", ios::app);

    file<<username<<endl;
    file<<password<<endl;

    file.close();

    cout<<"Username and Password Saved Successfully!!\n\n";
    cout<<"Please press enter\n";

    login();
}

int login(){
    string username, password;

    cin.ignore();
   
    cout<<"Username: ";
    getline(cin, username);
    
    cout<<"Password: ";
    getline(cin, password);

    //open file
    ifstream file("vault_account.txt");

    //get 2 lines as stored username and password
    string user, pass;

    bool found = false;

    while(getline(file, user) && getline(file, pass)){
        if(user == username && pass == password){
            found = true;
            break;
        }
    }

    file.close();

    /*cout<<user;
    cout<<pass;
    cout<<username;
    cout<<password;*/

    //compare both
    //if(user == username && pass == password){
        //menu;
    if(found){
        cout<<"Login Successful!\n";
        menu();

    }else{
        cout<<"You don't have any such account. Please create an account.\n";
        accountEntry();
    }
    //if true, show the menu 
    //else dialogue
}

int viewAll(){
    string line;

    ifstream file("vault_notes.txt");

    while(getline(file, line)){
        cout<<line<<endl;
    }

    file.close();
}

int search(){
    string searchTitle;
    string line;

    cout<<"Enter the title of the entry you want to search: ";
    getline(cin, searchTitle);

    ifstream file("vault_notes.txt");

    getline(file, line);

    do{
        if(searchTitle == title){
            cout<<line<<endl;
        }
    }while(line == title)
}

int modify(){
    cout<<"coming soon...\n\n";
}

int deleteEntry(){
    cout<<"coming soon...\n\n";
}

int exitProg(){
    cout<<"coming soon...thank u\n\n";

    exit(0);
}

int main(){
    int choice;
    int opt;

    cout<<" NAMASTE!!\n\nWELCOME TO VAULTERY!!"<<endl;

    cout<<"Already have an account?\n";
    cout<<"1. Login\n";
    cout<<"Don't have an account?\n";
    cout<<"2. Create account\n\n";

    cout<<"Enter your choice: ";
    cin>>opt;

    if(opt == 1){
        login();
    }else if(opt == 2){
        accountEntry();
    }else{
        cout<<"Please Enter Either 1 or 2\n\n";
    }

    //this menu will be written in login...

    /*while(true){
        choice = menu();

        if(choice == 1){
            notesEntry();
        }else if(choice == 2){
            viewAll();
        }else if(choice == 3){
            search();
        }else if(choice == 4){
            modify();
        }else if(choice == 5){
            deleteEntry();
        }else if(choice == 6){
            exit();
        }else{
            cout<<"Please Enter Proper Option: (1 to 6)\n";
        }
    }*/

    return 0;
}