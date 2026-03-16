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

        cout<<"\n=================================================\n";
        cout<<"                 MAIN MENU\n";
        cout<<"=================================================\n";
    

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
    cout<<"\n=================================================\n";
    cout<<"                 ENTRY\n";
    cout<<"=================================================\n";
    
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

    cout<<"\n$===$ File Created Successfully!! $===$\n\n";

    return 0;
}

int accountEntry(){
    cout<<"\n=================================================\n";
    cout<<"                 CREATE ACCOUNT\n";
    cout<<"=================================================\n";
    
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

    cout<<"$===$ Username and Password Saved Successfully!! $===$\n\n";
    cout<<"Please press enter\n";

    login();

    return 0;
}

int login(){
    cout<<"\n=================================================\n";
    cout<<"                 LOGIN\n";
    cout<<"=================================================\n";
    
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
        cout<<"\n$===$ Login Successful! $===$\n";
        menu();

    }else{
        cout<<"You don't have any such account. Please create an account.\n";
        accountEntry();
    }
    //if true, show the menu 
    //else dialogue
}

int viewAll(){
    cout<<"\n=================================================\n";
    cout<<"                 ALL SAVED NOTES\n";
    cout<<"=================================================\n";
    string line;

    ifstream file("vault_notes.txt");

    while(getline(file, line)){
        cout<<line<<endl;
    }

    file.close();

    return 0;
}

int search(){
    cout<<"\n=================================================\n";
    cout<<"                 SEARCH\n";
    cout<<"=================================================\n";
    
    string searchTitle;
    string line;

    cin.ignore();

    cout<<"\nEnter the title of the entry you want to search: ";
    getline(cin, searchTitle);

    ifstream file("vault_notes.txt");

    bool found = false;

    while(getline(file, line)){
        if(line == "Title: " + searchTitle){
            cout<<"\nEntry Found!\n\n";

            cout<<line<<endl;

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

    return 0;

}

int modify(){
    cout<<"\n=================================================\n";
    cout<<"                 MODIFICATION\n";
    cout<<"=================================================\n";
    
    string modTitle;
    string line;

    cin.ignore();

    cout<<"\nEnter the entry you want to modify: ";
    getline(cin, modTitle);
    cout<<endl;

    ifstream file("vault_notes.txt");
    ofstream temp("temp_notes.txt");

    bool found = false;

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

    remove("vault_notes.txt");
    rename("temp_notes.txt", "vault_notes.txt");

    if(found){
        cout<<"\n$===$ Entry modified successfully! $===$\n";
    }else{
        cout<<"Entry not found!\n";
    }

    return 0;
}

int deleteEntry(){
    cout<<"\n=================================================\n";
    cout<<"                 DELETION\n";
    cout<<"=================================================\n";
    
    string delTitle;
    string line;

    cin.ignore();

    cout<<"\nEnter the entry you want to delete: ";
    getline(cin, delTitle);

    ifstream file("vault_notes.txt");
    ofstream temp("temp_notes.txt");

    bool found = false;

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

    remove("vault_notes.txt");
    rename("temp_notes.txt", "vault_notes.txt");

    if(found){
        cout<<"\n$===$ Entry deleted successfully! $===$\n";
    }else{
        cout<<"Entry not found!\n";
    }

    return 0;
}

int exitProg(){
    cout<<"\n\n\t====##**EXITING.....**##====\n\n====##**Thank you!!. Let's meet next time....**##====\n\n";

    exit(0);
}

int main(){
    int choice;
    int opt;

    cout<<"\t# = # = # = # = # = # = # = # = # = # = # = #\n";
    cout<<"\t\t\t* NAMASTE!! *\n\n\t\t* WELCOME TO VAULTERY!! *"<<endl;
    cout<<"\t# = # = # = # = # = # = # = # = # = # = #\n";

    cout<<"\n=  ===  =  ===  =  ===  =  ===  =  ===  =  ===  =  ===   =\n\n";

    cout<<"Already have an account?\n";
    cout<<"1. Login\n";
    cout<<"Don't have an account?\n";
    cout<<"2. Create account\n\n";

    cout<<"Enter your choice: ";
    cin>>opt;
    cout<<endl;

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