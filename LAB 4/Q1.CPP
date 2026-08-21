
#include <iostream>
using namespace std;

class Weather {
private:
    string cityName;
    float temperature;
    string weatherCondition;

public:
    // Constructor
    Weather(string city, float temp, string condition) {
        cityName = city;
        temperature = temp;
        weatherCondition = condition;
    }

    // Friend function declaration
    friend void generateReport(Weather w);
};

// Friend function can access private members
void generateReport(Weather w) {
    cout << "----- Weather Report -----" << endl;
    cout << "City: " << w.cityName << endl;
    cout << "Temperature: " << w.temperature << " C" << endl;
    cout << "Condition: " << w.weatherCondition << endl;

    // Classify temperature
    if (w.temperature > 35)
        cout << "Category: Very Hot" << endl;
    else if (w.temperature >= 20)
        cout << "Category: Pleasant" << endl;
    else
        cout << "Category: Cool" << endl;
}

int main() {
    string city;
    float temp;
    string weather;
    cout<<"enter city: "<< endl;
    cin>>city;
    cout<<"enter temp: "<<endl;
    cin>>temp;
    cout<<"enter type of weather: "<<endl;
    cin>>weather;
    Weather w(city, temp, weather);

    generateReport(w);

    return 0;
}

