#include <iostream>
#include <string>

using namespace std;

class ATM
{
private:

    string username;
    string pincode;
    int amount;
    bool registered = false;
    static bool registeredusers;
    int recovery;
    int tries = 1;

public:
    static void registeruser(ATM arr[], int &limit, int Size)
    {
        cin.ignore();

        string name;
        cout << "Enter Username: ";
        getline(cin, name);

        bool already = false;
        if (limit < Size)
        {
            for (int i = 0; i < limit; i++)
            {
                if (arr[i].username == name)
                {
                    already = true;
                    break;
                }
            }
            if (already)
            {
                cerr << "Username has already been taken!" << endl;
                return;
            }
        }
        else if (limit >= Size)
        {
            cerr << "Users Limit Reached!" << endl;
            return;
        }

        string pin;
        cout << "Enter Pincode: ";
        getline(cin, pin);

        string confirmpin;
        cout << "Confirm Pincode: ";
        getline(cin, confirmpin);

        while (confirmpin != pin)
        {
            cerr << "Wrong Confirmation PIN Entered!" << endl;
            cout << "Re-Confirm PIN: ";
            cin >> confirmpin;
        }

        int recovery;
        cout << "Enter the Recovery Key(Must be integer): ";
        cin >>  recovery;
        cout << "\n\nRegistration Successful! " << endl;
        cout << "Rs.1000 Have Been Given To You As Registration bonus!" << endl;
        cout << endl;
        arr[limit].amount = 1000;
        arr[limit].username = name;
        arr[limit].registered = true;
        arr[limit].pincode = pin;       // Assigning pincode
        arr[limit].recovery = recovery; // Assigning recovery key
        registeredusers = true;
        limit++;
    }

static bool login(ATM arr[], int Count)
{
        if (!registeredusers)
        {
            cerr << "Please register first!" << endl;
            return false;
        }

        cin.ignore();
        string name;
        cout << "Enter Username: ";
        getline(cin, name);

        int index = -1; // Initialize index for the user being logged in

        // Find the user in the array
        for (int i = 0; i < Count; i++)
        {
            if (arr[i].username == name)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cerr << "Username not found!" << endl;
            return false;
        }

        string pin;
        cout << "Enter Pincode: ";
        getline(cin, pin);

        // Check if the pin is correct
        if (arr[index].pincode == pin)
        {
            cout << "Login Successful! " << endl;
            cout << "------Account details------ " << endl;
            cout << "Username: " << arr[index].username << endl;
            cout << "Pincode: " << arr[index].pincode << endl;
            cout << "Amount: " << arr[index].amount << endl;
            return true;
        }
        else
        {
            cerr << "Invalid Pincode!" << endl;

            if (arr[index].tries >= 3)
            {
                cout << "====Recovery Key====" << endl;
                cout << arr[index].recovery << endl;
                cout << "==========================" << endl;
                arr[index].tries = 1;
            }
            else
            {
                arr[index].tries++;
            }
            return false;
        }
}

static void withdraw(ATM arr[], int usercount)
{
        if (!registeredusers)
        {
            cerr << "Please register first!" << endl;
            return;
        }

        cin.ignore();

        string name;
        cout << "Enter Username: " << endl;
        getline(cin, name);

        int index = -1;
        for (int i = 0; i < usercount; i++)
        {
            if (arr[i].username == name)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cerr << "User not found!" << endl;
            return;
        }

        string pin;
        cout << "Enter Pincode: " << endl;
        getline(cin, pin);

        if (arr[index].pincode != pin)
        {
            cerr << "Invalid Pincode!" << endl;
            return;
        }

        int amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > arr[index].amount)
        {
            cerr << "Insufficient balance!" << endl;
            return;
        }

        arr[index].amount -= amount;
        cout << "Withdrawal of " << amount << " successful." << endl;
        cout << "Current balance: " << arr[index].amount << endl;
}

void deposit(ATM arr[], int noofusers)
{
        if (!registeredusers)
        {
            cerr << "Please register first!" << endl;
            return;
        }

        cin.ignore();

        string name;
        cout << "Enter Username: " << endl;
        getline(cin, name);

        int index = -1;
        for (int i = 0; i < noofusers; i++)
        {
            if (arr[i].username == name)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cerr << "User not found!" << endl;
            return;
        }

        string pin;
        cout << "Enter Pincode: " << endl;
        getline(cin, pin);

        if (arr[index].pincode != pin)
        {
            cerr << "Invalid Pincode!" << endl;
            return;
        }

        int amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        arr[index].amount += amount;
        cout << "Deposit of " << amount << " successful." << endl;
        cout << "Current balance: " << arr[index].amount << endl;
}

static void transfer(ATM arr[], int usercount)
{
        if (!registeredusers)
        {
            cerr << "Please register first!" << endl;
            return;
        }

        string senderName;
        cout << "Enter sender's Username: ";
        cin.ignore();
        getline(cin, senderName);

        int senderIndex = -1;
        for (int i = 0; i < usercount; i++)
        {
            if (arr[i].username == senderName)
            {
                senderIndex = i;
                break;
            }
        }

        if (senderIndex == -1)
        {
            cerr << "Sender not found!" << endl;
            return;
        }

        string pin;
        cout << "Enter Sender's Pincode: ";
        getline(cin, pin);

        if (arr[senderIndex].pincode != pin)
        {
            cerr << "Invalid Pincode!" << endl;
            return;
        }

        string receiverName;
        cout << "Enter receiver's Username: ";
        getline(cin, receiverName);

        int receiverIndex = -1;
        for (int i = 0; i < usercount; i++)
        {
            if (arr[i].username == receiverName)
            {
                receiverIndex = i;
                break;
            }
        }

        if (receiverIndex == -1)
        {
            cerr << "Receiver not found!" << endl;
            return;
        }

        int amount;
        cout << "Enter amount to transfer: ";
        cin >> amount;

        if (amount > arr[senderIndex].amount)
        {
            cerr << "Insufficient balance!" << endl;
            return;
        }

        arr[senderIndex].amount -= amount;
        arr[receiverIndex].amount += amount;
        cout << "Transfer of " << amount << " successful." << endl;
        cout << "Current balance of " << arr[senderIndex].username << ": " << arr[senderIndex].amount << endl;
        cout << "Current balance of " << arr[receiverIndex].username << ": " << arr[receiverIndex].amount << endl;
}
};
bool ATM::registeredusers = false;

void Displaymenu()
{
    cout << "Welcome to Habib Bank Limited!" << endl;
    cout << "--------------MENU--------------" << endl;
    cout << "1.Register \n2.Login \n3.Withdraw \n4.Deposit \n5.Transfer \n6.Exit" << endl;
    cout << "-------------------------------- " << endl;
}

int main()
{
    system("cls");

    int choice{};
    int capacity{};
    cout << "Enter the Number of users: ";
    cin >> capacity;
    cin.ignore();

    ATM arr[capacity];
    int usercount = 0;
    do
    {
        system("cls");
        Displaymenu();

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            ATM::registeruser(arr, usercount, capacity);
            system("pause");
            break;
        case 2:
            ATM::login(arr, usercount);
            system("pause");
            break;
        case 3:
            ATM::withdraw(arr, usercount);
            system("pause");
            break;
        case 4:
            arr[usercount].deposit(arr, usercount);
            system("pause");
            break;
        case 5:
            ATM::transfer(arr, usercount);
            system("pause");
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid Choice!" << endl;
            break;
        }

    } while (choice != 6);
    return 0;
}