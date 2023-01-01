#include<iostream>
using namespace std;
class PersonalInfo{
    protected:
        int totalamount=0;
        string name;
        string phonenumber;
        string gender;
        string place;

    public:
        void setPinfo(string name1,string phonenumber1,string gender1,string place1,int totalamount1){
            name=name1;
            phonenumber=phonenumber1;
            gender=gender1;
            place=place1;
            totalamount=totalamount1;
        }
        void getPinfo(){
            cout << "Name: " << name << endl;
            cout << "Total Amount: " << totalamount << endl;
            cout << "Phone Number: " << phonenumber << endl;
            cout << "Gender: " << gender << endl;
            cout << "Place: " << place << endl;
        }
};
class Deposit : public PersonalInfo{
    protected:
        int depositedamount=0;
    public:
        void setDepositamt(int depositamount1){
            depositedamount=depositamount1;
        }   
        void getDepositamt(){
            cout << "Deposited Amount: " << depositedamount << endl;
            totalamount=totalamount+depositedamount;
            cout << "Total Amount after deposition: " << totalamount << endl;
            depositedamount=0;
        }
};
class Withdrawl : public Deposit{
    protected:
        int withdrawlamount=0;
    public:
        void setWithdrawlamt(int withdrawlamount1){
            withdrawlamount=withdrawlamount1;
        }   
        void getWithdrawlamt(){
            cout << "Withdrawl Amount: " << withdrawlamount << endl;
            totalamount=totalamount-withdrawlamount;
            cout << "Total Amount after withdrawl: " << totalamount << endl;
            withdrawlamount=0;
        }
};
class Changes : public Withdrawl{
    public:
        void setChanges(string new_name,string new_phonenumber){
            name=new_name;
            phonenumber=new_phonenumber;
        }
};
class DisplayPinfo : public Changes{
    public:
        void display1(){
            getPinfo();
        }
};
class Displaydep : public DisplayPinfo{
    public:
    void display2(){
        getDepositamt();
    }
};
class Displaywithdrawl : public Displaydep{
    public:
    void display3(){
        getWithdrawlamt();
    }
};
int main(){
    Displaywithdrawl d;
    int choice;
    string name2;
    int totalamount;
    string phno;
    int wamount;
    int damount;
    string gender2;
    string place2;
    string newname;
    string newphno;
    do
    {
        cout << "******************************************************" << endl;
        cout << "*                 1.Account Information              *" << endl;
        cout << "*                 2.Deposit                          *" << endl;
        cout << "*                 3.Withdraw                         *" << endl;
        cout << "*                 4.Changes                          *" << endl;
        cout << "*                 5.Display Personal Info            *" << endl;
        cout << "*                 6.Display After Deposit            *" << endl;
        cout << "*                 7.Display After Withdrawl          *" << endl;
        cout << "*                 8.Exit                             *" << endl;
        cout << "******************************************************" << endl;
        cout << "Enter the choice: " << endl;
        cin >> choice;
        switch (choice)
        {
            case 1: cout << "Enter the name: " << endl;
                    cin >> name2;
                    cout << "Enter the phone number: " << endl;
                    cin >> phno;
                    cout << "Enter the gender: " << endl;
                    cin >> gender2;
                    cout << "Enter the place: " << endl;
                    cin >> place2;
                    cout << "Enter the total amount: " << endl;
                    cin >> totalamount;
                    d.setPinfo(name2,phno,gender2,place2,totalamount);
                    break;
            case 2: cout << "Enter the amount to be deposited: " << endl;
                    cin >> damount;
                    d.setDepositamt(damount);
                    break;
            case 3: cout << "Enter the amount to be withdraw: " << endl;
                    cin >> wamount;
                    d.setWithdrawlamt(wamount);
                    break;
            case 4: cout << "Enter the new name: " << endl;
                    cin >> newname;
                    cout << "Enter new phone number: " << endl;
                    cin >> newphno;
                    d.setChanges(newname,newphno);
                    break;
            case 5: d.display1();
                    break;
            case 6: d.display2();
                    break;
            case 7: d.display3();
                    break;
            case 8: exit(0);
                    break;
        }
    } while (1);
}