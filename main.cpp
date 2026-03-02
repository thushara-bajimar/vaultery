#include<iostream>
using namespace std;

int createFile();
int viewAll();
int search();
int modify();
int deleteF();
int exit();

int menu(){
    int choose;

    cout<<" NAMASTE!!\n\nWELCOME TO VAULTERY!!"<<endl;
    cout<<"1. Create File\n";
    cout<<"2. View All Files\n";
    cout<<"3. Search File\n";
    cout<<"4. Modify File\n";
    cout<<"5. Delete File\n";
    cout<<"6. Exit\n";

    cout<<"What do you want to do?\n";
    cin>>choose;

    return choose;
}

int main(){
    int choice;

    while(true){
        choice = menu();

        if(choice == 1){
            createFile();
        }else if(choice == 2){
            viewAll();
        }else if(choice == 3){
            search();
        }else if(choice == 4){
            modify();
        }else if(choice == 5){
            deleteF();
        }else if(choice == 6){
            exit();
        }else{
            cout<<"Please Enter Proper Option: (1 to 6)\n";
        }
    }

    return 0;
}