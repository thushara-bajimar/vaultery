/* 
  VAULTERY - Personal CLI Vault
    - User login system
    - create, view, search, modify and delete notes
    - file-based storage

    Author - thushara-bajimar
*/

#include<iostream>
#include<fstream>
#include<limits>
#include<cstdlib>
using namespace std;

void createAccount();
void login();
void menu();
void createNote();
void viewAllNotes();
void searchNote();
void modifyNote();
void deleteNote();
void exitProgram();

// Creates an account with username and password; stores it in the file
void createAccount(){
    cout<<"\n=================================================\n";
    cout<<"                 CREATE ACCOUNT\n";
    cout<<"=================================================\n";
    
    string username, password;

    cout<<"\nPlease create your account by entering the following details:\n\n";

    cout<<"Username: ";
    getline(cin, username);

    cout<<"Password: ";
    getline(cin, password);

    ofstream file("vault_account.txt", ios::app);

    file<<username<<endl;
    file<<password<<endl;

    file.close();

    cout<<"===== Username and Password Saved Successfully!! =====\n\n";

    login();
    
}

// Handles user login by checking credentials from the file
void login(){
    cout<<"\n=================================================\n";
    cout<<"                 LOGIN\n";
    cout<<"=================================================\n";
    
    string username, password;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
   
    cout<<"Username: ";
    getline(cin, username);
    
    cout<<"Password: ";
    getline(cin, password);

    ifstream file("vault_account.txt");

    string user, pass;

    bool found = false;

    while(getline(file, user) && getline(file, pass)){
        if(user == username && pass == password){
            found = true;
            break;
        }
    }

    file.close();

    if(found){
        cout<<"\n===== Login Successful! =====\n";
        cout<<"\nWelcome back, "<<username<<"!\n";
        menu();
        return;

    }else{
        cout<<"You don't have any such account. Please create an account.\n";
        createAccount();
        return;
    }
}

// Displays main menu and handles user choices
void menu(){
    int choice;

   while(true){

        cout<<"\nWhat do you want to do?\nChoose any option from the menu below:\n";

        cout<<"\n=================================================\n";
        cout<<"                 MAIN MENU\n";
        cout<<"=================================================\n";
    

        cout<<"1. Create Note\n";
        cout<<"2. View All Notes\n";
        cout<<"3. Search Note\n";
        cout<<"4. Modify Note\n";
        cout<<"5. Delete Note\n";
        cout<<"6. Exit\n";

        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(choice == 1){
            createNote();
        }else if(choice == 2){
            viewAllNotes();
        }else if(choice == 3){
            searchNote();
        }else if(choice == 4){
            modifyNote();
        }else if(choice == 5){
            deleteNote();
        }else if(choice == 6){
            exitProgram();
        }else{
            cout<<"Please Enter Proper Option: (1 to 6)\n";
        }
    }
}

// Creates notes with title and content; stores it in the file
void createNote(){
    cout<<"\n=================================================\n";
    cout<<"                 CREATE NOTE\n";
    cout<<"=================================================\n";
    
    string title, content;

    cout<<"Title: ";
    getline(cin, title);

    cout<<"Content:\n";
    getline(cin, content);
    cout<<"\n";

    ofstream file("vault_notes.txt", ios::app);

    if(!file){
        cout<<"Error opening file for writing!\n";
        return;
    }

    //file<<"***NOTES***\n";
    file<<"Title: "<<title<<endl;
    file<<"Content: "<<content<<endl;
    file<<"---"<<endl;

    file.close();

    cout<<"\n===== File Created Successfully!! =====\n\n";

    cout<<"\nPlease press enter to return to the main menu...\n";
    cin.get();

}

// Displays all the saved notes
void viewAllNotes(){
    cout<<"\n=================================================\n";
    cout<<"                 ALL SAVED NOTES\n";
    cout<<"=================================================\n";
    string line;

    ifstream file("vault_notes.txt");

    if(!file){
        cout<<"No entries found!!\n\n";
        return;
    }

    bool isEmpty = true;

    while(getline(file, line)){
    cout<<line<<endl;
    isEmpty = false;
    }

    if(isEmpty){
        cout<<"No entries available!\n";
    }

    file.close();

    cout<<"\nPlease press enter to return to the main menu...\n";
    cin.get();

}

// Search by title
void searchNote(){
    cout<<"\n=================================================\n";
    cout<<"                 SEARCH\n";
    cout<<"=================================================\n";
    
    string searchTitle;
    string line;

    cout<<"\nEnter the title of the entry you want to search: ";
    getline(cin, searchTitle);

    ifstream file("vault_notes.txt");

    if(!file){
        cout<<"No entries found!!\n\n";
        return;
    }

    bool found = false;

    while(getline(file, line)){
        if(line == "Title: " + searchTitle){
            cout<<"\nEntry Found!\n\n";

            cout<<line<<endl;

            // Print content until separator is reached
            while(getline(file, line) && line != "---"){
                cout<<line<<endl;
            }
            found = true;
            break;
        }
    }
    if(!found){
        cout<<"Entry with this title is not found!!\n";
    }

    file.close();

    cout<<"\nPlease press enter to return to the main menu...\n";
    cin.get();

}

// Modify the existing notes
void modifyNote(){
    cout<<"\n=================================================\n";
    cout<<"                 MODIFICATION\n";
    cout<<"=================================================\n";
    
    string modTitle;
    string line;

    cout<<"\nEnter the entry you want to modify: ";
    getline(cin, modTitle);
    cout<<endl;

    ifstream file("vault_notes.txt");

    if(!file){
        cout<<"No entries found!!\n\n";
        return;
    }

    ofstream temp("temp_notes.txt"); // New file to store updates

    bool found = false;

    // If title matches, get new title and content from user
    while(getline(file, line)){
        if(line == "Title: " + modTitle){
            string newTitle, newContent;

            cout<<"Enter the new title: ";
            getline(cin, newTitle);

            cout<<"Enter the new content:\n";
            getline(cin, newContent);

            temp<<"Title: "<<newTitle<<endl;
            temp<<"Content: "<<newContent<<endl;
            temp<<"---"<<endl;

            found = true;

            while(getline(file, line) && line != "---");
        }else{
            temp<<line<<endl;
        }
    }
    file.close();
    temp.close();

    // Replace original file with the updated one 
    if(remove("vault_notes.txt") != 0){
        cout<<"Error modifying old file!\n";
    }

    if(rename("temp_notes.txt", "vault_notes.txt") != 0){
        cout<<"Error updating file!\n";
    }

    if(found){
        cout<<"\n===== Entry modified successfully! =====\n";
    }else{
        cout<<"Entry not found!\n";
    }

    cout<<"\nPlease press enter to return to the main menu...\n";
    cin.get();
}

// Delete title and content
void deleteNote(){
    cout<<"\n=================================================\n";
    cout<<"                 DELETION\n";
    cout<<"=================================================\n";
    
    string delTitle;
    string line;

    cout<<"\nEnter the entry you want to delete: ";
    getline(cin, delTitle);

    ifstream file("vault_notes.txt");

    if(!file){
        cout<<"No entries found!!\n\n";
        return;
    }
    
    ofstream temp("temp_notes.txt"); // New file to store updates

    bool found = false;

    // Copy all entries except the one to be deleted
    while(getline(file, line)){
        if(line == "Title: " + delTitle){

            found = true;

            while(getline(file, line) && line != "---");
        }else{
            temp<<line<<endl;
        }
    }
    file.close();
    temp.close();

    // Replace original file with the updated one 
    if(remove("vault_notes.txt") != 0){
        cout<<"Error deleting old file!\n";
    }

    if(rename("temp_notes.txt", "vault_notes.txt") != 0){
        cout<<"Error updating file!\n";
    }

    if(found){
        cout<<"\n===== Entry deleted successfully! =====\n";
    }else{
        cout<<"\nEntry not found!\n";
    }

    cout<<"\nPlease press enter to return to the main menu...\n";
    cin.get();

}

// Terminate the program
void exitProgram(){
    cout<<"\n\n\t========...EXITING...========\n\n========...Thank you!!. Let's meet next time...========\n\n";

    exit(0);

}

// Display welcome screen and initial user options
int main(){
    int choice;
    int opt;

    cout<<"Please press Enter to continue...\n\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<"=============================================================\n";
    cout<<"\t# = # = # = # = # = # = # = # = # = # = # = #\n";
    cout<<"\t\t\t* NAMASTE!! *\n\n\t\t* WELCOME TO VAULTERY!! *"<<endl;
    cout<<"\t# = # = # = # = # = # = # = # = # = # = #\n";
    cout<<"=============================================================\n\n";


    cout<<"Already have an account?\n";
    cout<<"1. Login\n";
    cout<<"Don't have an account?\n";
    cout<<"2. Create account\n\n";

    cout<<"Enter your choice: ";
    cin>>opt;
    cout<<endl;

    while(opt != 1 && opt != 2){
        cout<<"Please Enter Either 1 or 2\n\n";
        cout<<"Enter your choice: ";
        cin>>opt;
        cout<<endl;
    }

    if(opt == 1){
        login();
    }else if(opt == 2){
        createAccount();
    }

    return 0;
}