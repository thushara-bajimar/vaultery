#include<iostream>
using namespace std;

int menu();
int createEntry();
int notesEntry();
int passwordEntry();
int viewAll();
int search();
int modify();
int deleteEntry();
int exit();

int menu(){
    int choose;

    cout<<"1. Create Entry\n";
    cout<<"2. View All Entries\n";
    cout<<"3. Search Entry\n";
    cout<<"4. Modify Entry\n";
    cout<<"5. Delete Entry\n";
    cout<<"6. Exit\n";

    cout<<"What do you want to do?\n";
    cin>>choose;

    return choose;
}

int notesEntry(){
    
}

int createEntry(){
    int entry;

    cout<<"What do you want to enter?\n\n";
    cout<<"1. Enter Notes\n";
    cout<<"2. Enter Password\n\n";

    cin>>entry;

    if(entry == 1){
        notesEntry();
    }else if(entry == 2){
        passwordEntry();
    }else{
        cout<<"Please Enter Either 1 or 2\n\n";
    }
}

int viewAll(){
    cout<<"coming soon...\n\n";
}

int search(){
    cout<<"coming soon...\n\n";
}

int modify(){
    cout<<"coming soon...\n\n";
}

int deleteEntry(){
    cout<<"coming soon...\n\n";
}

int exit(){
    cout<<"coming soon...\n\n";
}

int main(){
    int choice;

    cout<<" NAMASTE!!\n\nWELCOME TO VAULTERY!!"<<endl;

    while(true){
        choice = menu();

        if(choice == 1){
            createEntry();
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
    }

    return 0;
}