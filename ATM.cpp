//ATM Machine

#include <iostream> //For basic functions
#include <iomanip> //For setw
#include <cstdlib> //For random
#include <ctime> //For time
#include <vector> //For vector
using namespace std;

//Pin Check Function
bool pinCheck(string pin)
{
    string userPin;
    int chance = 3;
    while (chance > 0)
    {
        cout<<"Enter your pin: ";
        cin>>userPin;
        if (userPin == pin)
        {
            break;
            return true;
        }
        else
        {
            chance -=1;
            cout<<"Sorry! Wrong Pin, You have "<<chance<<" chances left."<<endl;
        }
    }
    if (chance == 0)
    {
        cout<<"Your card is frozen! Visit our nearest branch for further assistance."<<endl;
        return false;
    }
}

//Show menu function
void showMenu()
{
    cout<<"\nType '1' to show your balance.\nType '2' to withdraw money. \nType '3' to deposit money. \nType '4' to show recent transactions. \nType '5' to change your pin. \nType '6' to quit."<<endl;
}

//Main Function
int main()
{
    srand(time(0));
    string pin = "102030"; //Pin initialization
    int balance = rand()%100000; //Initial Balance
    bool check; //For pin check status;
    string tran; //Transaction line
    string tempoPin, confirmTempoPin; //For changing the pin
    int action, withdraw, deposit;
    cout<<setw(70)<<"Welcome to Starling Bank! How can I help you?"<<endl; //Greeting line
    vector<string> transactions; //A vector to store the transactions
    tran = "Your initial balance = " + to_string(balance);
    transactions.push_back(tran); //1st initial balance line
start:
    check = pinCheck(pin); //check the pin
    if (check == true) //Everything will work only if the pin is true
    {
        showMenu();        //Showing the menu
        do
        {
            cout<<endl<<"Enter your action number: ";
            cin>>action;
            switch (action)
            {
            case 1: //Show your balance
                cout<<"Your balance = "<< balance<<endl;
                break;

            case 2: //Withdraw Money
                while (true)
                {
                    cout<<"Enter amount to withdraw: ";
                    cin>>withdraw;
                    if (withdraw > balance)
                    {
                        cout<<"There is no sufficient amount to withdraw. Try again!"<<endl;
                    }
                    else
                    {
                        balance -= withdraw;
                        cout<<"Successfully withdrawn! You have "<<balance<<" left."<<endl;
                        tran = "Withdrawn : ";
                        tran += to_string(withdraw);
                        transactions.push_back(tran);
                        break;
                    }
                }
                break;

            case 3: //Deposit Money
                cout<<"Enter amount to deposit: ";
                cin>>deposit;
                balance +=deposit;
                cout<<"Successfully deposited! You have "<<balance<<" left."<<endl;
                tran = "Deposited : ";
                tran += to_string(deposit);
                transactions.push_back(tran);
                break;

            case 4: //Show transactions
                system("cls");
                tran = "Final balance = ";
                tran += to_string(balance);
                transactions.push_back(tran);
                cout<<"Transaction History"<<endl<<endl;
                for (int i=0; i<transactions.size(); ++i)
                {
                    cout<<transactions[i]<<endl;
                }
                showMenu();
                break;

            case 5: //Pin change
pinChange:
                cout<<"Enter a new pin: ";
                cin>>tempoPin;
                if (pin != tempoPin)
                {
                    cout<<"Confirm your new pin: ";
                    cin>>confirmTempoPin;
                    if (tempoPin == confirmTempoPin)
                    {
                        system("cls");
                        cout<<"Pin Successfully Changed! Activate your card with your new pin!"<<endl;
                        system("pause");
                        pin = confirmTempoPin;
                        goto start;
                    }
                    else
                    {
                        cout<<"Two pins are not the same. Try again."<<endl;
                        goto pinChange;
                    }
                }
                else
                {
                    cout<<"Your new pin is invalid. Try a new one."<<endl;
                    goto pinChange;
                }
                break;

            case 6: //Stop the service
                cout<<"Thanks for using our services! Have a nice day!"<<endl;
                break;

            default: //Default
                cout<<"Invalid Number. Type again!"<<endl;

            }
        }
        while (action != 6);   //Ends when the user types 6.
    }
    return 0;
}
