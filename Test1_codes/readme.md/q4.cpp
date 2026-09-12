#include <iostream>
using namespace std;

class GameController;   

class Inventory
{
private:
    int playerID;
    int numberOfItems;
    int *quantity;

public:
    
    Inventory(int id, int items)
    {
        playerID = id;
        numberOfItems = items;

        quantity = new int[numberOfItems];

        for (int i = 0; i < numberOfItems; i++)
        {
            quantity[i] = 0;
        }
    }

    void enterInventory()
    {
        cout << "Enter quantity of " << numberOfItems << " items:\n";

        for (int i = 0; i < numberOfItems; i++)
        {
            cout << "Item " << i + 1 << ": ";
            cin >> quantity[i];
        }
    }

    void displayInventory()
    {
        cout << "\nPlayer ID: " << playerID << endl;

        cout << "Item quantities: ";
        for (int i = 0; i < numberOfItems; i++)
        {
            cout << quantity[i] << " ";
        }

        cout << endl;
    }

    
    friend class GameController;

    
    ~Inventory()
    {
        delete[] quantity;
    }
};

class GameController
{
public:

    
    void inspectInventory(Inventory &inv)
    {
        cout << "\n--- Inventory Inspection ---\n";
        cout << "Player ID: " << inv.playerID << endl;
        cout << "Number of Items: " << inv.numberOfItems << endl;

        cout << "Quantities: ";
        for (int i = 0; i < inv.numberOfItems; i++)
        {
            cout << inv.quantity[i] << " ";
        }

        cout << endl;
    }

    
    void changeQuantity(Inventory &inv, int position, int newQuantity)
    {
        if (position >= 1 && position <= inv.numberOfItems)
        {
            inv.quantity[position - 1] = newQuantity;

            cout << "Quantity changed successfully.\n";
        }
        else
        {
            cout << "Invalid item position!\n";
        }
    }
};

int main()
{
    int id, items;

    cout << "Enter Player ID: ";
    cin >> id;

    cout << "Enter number of items: ";
    cin >> items;

    
    Inventory *inv = new Inventory(id, items);

    inv->enterInventory();

    GameController controller;

    controller.inspectInventory(*inv);

    int position, newQuantity;

    cout << "\nEnter item position to modify: ";
    cin >> position;

    cout << "Enter new quantity: ";
    cin >> newQuantity;

    controller.changeQuantity(*inv, position, newQuantity);

    cout << "\n--- Updated Inventory ---\n";
    inv->displayInventory();

    
    delete inv;

    return 0;
}