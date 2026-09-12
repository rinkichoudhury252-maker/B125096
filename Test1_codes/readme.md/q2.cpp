#include <iostream>
using namespace std;

class Borrower
{
private:
    int borrowerID;
    int overdueDays;
    float fineAmount;

public:
    Borrower(int id, int days)
    {
        borrowerID = id;
        overdueDays = days;
        fineAmount = 0;
    }

    
    void calculateFine()
    {
        fineAmount = overdueDays * 5;
    }

    
    void calculateFine(float specialRate)
    {
        fineAmount = overdueDays * specialRate;
    }

    
    void display()
    {
        cout << "Borrower ID: " << borrowerID << endl;
        cout << "Overdue Days: " << overdueDays << endl;
        cout << "Fine Amount: Rs. " << fineAmount << endl;
    }

    
    friend void compareFine(Borrower &, Borrower &);
};


void compareFine(Borrower &b1, Borrower &b2)
{
    if (b1.fineAmount > b2.fineAmount)
    {
        cout << "\nBorrower " << b1.borrowerID
             << " has the higher fine: Rs. "
             << b1.fineAmount << endl;
    }
    else if (b2.fineAmount > b1.fineAmount)
    {
        cout << "\nBorrower " << b2.borrowerID
             << " has the higher fine: Rs. "
             << b2.fineAmount << endl;
    }
    else
    {
        cout << "\nBoth borrowers have the same fine: Rs. "
             << b1.fineAmount << endl;
    }
}

int main()
{
    int id1, id2;
    int days1, days2;
    float specialRate;

    cout << "Enter Borrower 1 ID: ";
    cin >> id1;

    cout << "Enter overdue days: ";
    cin >> days1;

    cout << "\nEnter Borrower 2 ID: ";
    cin >> id2;

    cout << "Enter overdue days: ";
    cin >> days2;

    
    Borrower *b1 = new Borrower(id1, days1);
    Borrower *b2 = new Borrower(id2, days2);


    b1->calculateFine();

  
    cout << "\nEnter special fine rate for Borrower 2: ";
    cin >> specialRate;

    b2->calculateFine(specialRate);

  
    cout << "\n--- Borrower Details ---\n";

    b1->display();

    cout << endl;

    b2->display();

    
    compareFine(*b1, *b2);

    
    delete b1;
    b1=nullptr;

    delete b2;
    b2=nullptr;


    return 0;
}