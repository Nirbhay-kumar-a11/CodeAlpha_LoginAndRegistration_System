#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>
using namespace std;

class Login{
    private:
    string LoginID, password;
    public:
    Login():LoginID(""),password(""){}

    void setID(string id){
        LoginID = id;
    }

    void setPW(string pw){
        password = pw;
    }

    string getID(){
        return LoginID;
    }

    string getPW(){
        return password;
    }
};

registration(Login log){
    system("cls");
    string id, pw;
    cout<<"\tEnter Login ID:";
    cin>>id;
    log.setID(id);

    start:
    cout<<"\tEnter A Strong Password: ";
    cin>>pw;
    if(pw.length()>=8){
    log.setPW(pw);
    }
    else{
        cout<<"\tEnter Minimum 8 characters!"<<endl;
        goto start;
    }
    ofstream outfile("E:\LoginAndRegistration.txt, ",ios::app);
    if(!outfile){
        cout<<"\tError: File can't Open!"<<endl;
    }
    else{
        outfile<<"\t"<<log.getID()<<":"<<log.getPW()<<endl<<endl;
        cout<<"\tUser Registered Successfully!"<<endl;
    }
    outfile.close();
    Sleep(3000);
    }

    login(){
        system("cls");
        string id, pw;
        cout<<"\tEnter Login ID:";
        cin>>id;

       cout<<"\tEnter password: ";
       cin>>pw;

       ifstream infile("E:\LoginAndRegistration.txt");
       if(!infile){
        cout<<"\tError: File Can't Open!"<<endl;
       }
       else{
        string line;
        bool found = false;
        while(getline(infile,line)){
            stringstream ss;
            ss<<line;
            string userId, userPW;
            char delimiter;
            ss>>userId>>delimiter>>userPW;

            if(id==userId && pw==userPW ){
              found = true;

              cout<<"\tPlease Wait";
              for(int i=0;i<3;i++){
                cout<<".";
                Sleep(800);
            }
            system("cls");
              cout<<"\twelcome to This page!"<<endl;  
            }
        }
        if(!found){
            cout<<"\tError : Incorrect Login ID Or Password!"<<endl;
        }
       }
       infile.close();
        Sleep(5000);   
    }

int main(){
    Login log;

    bool exit = false;
    while(!exit){
    system("cls");
    int val;
    cout<<"\tWelcome To Registration & Login Form"<<endl;
    cout<<"\t************************************"<<endl;
    cout<<"\t1.Register"<<endl;
    cout<<"\t2.Login."<<endl;
    cout<<"\t3.Exit."<<endl;
    cout<<"\tEnter Choice: ";
    cin>>val;

    if(val==1){
        registration(log);
    }

    else if(val==2){
     login();   
    }

    else if(val==3){
       system("cls");
       exit=true;
       cout<<"\tGood Luck!"<<endl;
       Sleep(3000); 
    }
    Sleep(3000);    
    }
}