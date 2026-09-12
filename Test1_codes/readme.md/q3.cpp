#include <iostream>
using namespace std;

class SensorGrid
{
private:
    int n;
    float *temperature;

public:
    
    SensorGrid(int size)
    {
        n = size;
        temperature = new float[n];
    }

    void enterReadings()
    {
        cout << "Enter " << n << " temperature readings:\n";

        for (int i = 0; i < n; i++)
        {
            cout << "Reading " << i + 1 << ": ";
            cin >> temperature[i];
        }
    }

   
    void displayReadings()
    {
        cout << "Temperature readings:\n";

        for (int i = 0; i < n; i++)
        {
            cout << temperature[i] << " ";
        }

        cout << endl;
    }

    
    void replaceReading(int position, float newTemperature)
    {
        if (position >= 1 && position <= n)
        {
            temperature[position - 1] = newTemperature;
            cout << "Reading replaced successfully.\n";
        }
        else
        {
            cout << "Invalid position!\n";
        }
    }


    friend void compareAverage(SensorGrid &, SensorGrid &);

   
    ~SensorGrid()
    {
        delete[] temperature;
    }
};


void compareAverage(SensorGrid &s1, SensorGrid &s2)
{
    float sum1 = 0, sum2 = 0;

    for (int i = 0; i < s1.n; i++)
    {
        sum1 += s1.temperature[i];
    }

    for (int i = 0; i < s2.n; i++)
    {
        sum2 += s2.temperature[i];
    }

    float average1 = sum1 / s1.n;
    float average2 = sum2 / s2.n;

    cout << "\nAverage temperature of Grid 1: "
         << average1 << endl;

    cout << "Average temperature of Grid 2: "
         << average2 << endl;

    if (average1 > average2)
    {
        cout << "Grid 1 has the greater average temperature."
             << endl;
    }
    else if (average2 > average1)
    {
        cout << "Grid 2 has the greater average temperature."
             << endl;
    }
    else
    {
        cout << "Both grids have the same average temperature."
             << endl;
    }
}

int main()
{
    int n1, n2;

    cout << "Enter number of readings for Grid 1: ";
    cin >> n1;

    cout << "Enter number of readings for Grid 2: ";
    cin >> n2;

    
    SensorGrid *grid1 = new SensorGrid(n1);
    SensorGrid *grid2 = new SensorGrid(n2);

    
    cout << "\n--- Grid 1 ---\n";
    grid1->enterReadings();

    cout << "\n--- Grid 2 ---\n";
    grid2->enterReadings();

    cout << "\n--- Sensor Readings ---\n";

    grid1->displayReadings();
    grid2->displayReadings();

    int position;
    float newTemperature;

    cout << "\nEnter position to replace in Grid 1: ";
    cin >> position;

    cout << "Enter new temperature: ";
    cin >> newTemperature;

    grid1->replaceReading(position, newTemperature);

    cout << "\nGrid 1 after replacement:\n";
    grid1->displayReadings();

    
    compareAverage(*grid1, *grid2);

    
    delete grid1;
    delete grid2;

    return 0;
}