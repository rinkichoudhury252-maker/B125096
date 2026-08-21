
#include <iostream>
using namespace std;

class WalletManager;  // Forward declaration

class DigitalWallet {
private:
    string userName;
    double walletBalance;
    string walletStatus;

public:
    // Constructor
    DigitalWallet(string name, double balance, string status) {
        userName = name;
        walletBalance = balance;
        walletStatus = status;
    }

    // Declare WalletManager as friend class
    friend class WalletManager;
};

class WalletManager {
public:

    // Display wallet details
    void displayDetails(DigitalWallet &w) {
        cout << "----- Wallet Details -----" << endl;
        cout << "User Name: " << w.userName << endl;
        cout << "Wallet Balance: Rs. " << w.walletBalance << endl;
        cout << "Wallet Status: " << w.walletStatus << endl;
    }

    // Add money
    void addMoney(DigitalWallet &w, double amount) {
        if (w.walletStatus == "Active") {
            w.walletBalance += amount;
            cout << "Rs. " << amount << " added successfully." << endl;
        } else {
            cout << "Wallet is disabled." << endl;
        }
    }

    // Deduct money if sufficient balance exists
    void deductMoney(DigitalWallet &w, double amount) {
        if (w.walletStatus != "Active") {
            cout << "Wallet is disabled." << endl;
        }
        else if (w.walletBalance >= amount) {
            w.walletBalance -= amount;
            cout << "Rs. " << amount << " deducted successfully." << endl;
        }
        else {
            cout << "Insufficient balance." << endl;
        }
    }

    // Disable wallet
    void disableWallet(DigitalWallet &w) {
        w.walletStatus = "Disabled";
        cout << "Wallet disabled." << endl;
    }

    // Display wallet status
    void displayStatus(DigitalWallet &w) {
        cout << "Current Wallet Status: "
             << w.walletStatus << endl;
    }
};

int main() {
    DigitalWallet wallet("Rinki", 5000, "Active");
    WalletManager manager;

    manager.displayDetails(wallet);

    manager.addMoney(wallet, 1000);
    manager.deductMoney(wallet, 10000);

    manager.displayDetails(wallet);

    manager.disableWallet(wallet);
    manager.displayStatus(wallet);

    return 0;
}
