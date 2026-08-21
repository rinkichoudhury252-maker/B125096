
#include <iostream>
using namespace std;

class UserAccount {
private:
    string username;
    int loginAttempts;
    string accountStatus;

public:
    // Constructor
    UserAccount(string user, int attempts, string status) {
        username = user;
        loginAttempts = attempts;
        accountStatus = status;
    }

    // Friend function
    friend void checkAccount(UserAccount u);
};

void checkAccount(UserAccount u) {
    cout << "----- Account Details -----" << endl;
    cout << "Username: " << u.username << endl;
    cout << "Login Attempts: " << u.loginAttempts << endl;

    // Check number of unsuccessful attempts
    if (u.loginAttempts >= 3)
        cout << "Account Status: Account Locked" << endl;
    else
        cout << "Account Status: Account Active" << endl;
}

int main() {
    string name;
    int attempt;
    string status;
    cout<<"enter user name: "<<endl;
    cin>>name;
    cout<<"enter number of attempts: "<<endl;
    cin>>attempt;
    cout<<"enter the status of account: "<<endl;
    cin>>status;
    UserAccount user(name,attempt,status);

    checkAccount(user);

    return 0;
}

