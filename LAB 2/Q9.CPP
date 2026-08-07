#include <iostream>
#include <string> // Allowed because it's part of iostream standard usage
using namespace std;

class CricketPlayer {
private:
    string playerName;
    int matchesPlayed;
    int totalRuns;

    // Helper function to classify performance
    string classifyPerformance(double avg) {
        if (avg >= 50.0) return "Excellent";
        else if (avg >= 35.0) return "Good";
        else if (avg >= 20.0) return "Average";
        else return "Poor";
    }

public:
    // Accept player details with validation
    void acceptDetails() {
        cout << "Enter player name: ";
        getline(cin, playerName);

        cout << "Enter matches played: ";
        while (!(cin >> matchesPlayed) || matchesPlayed < 0) {
            cout << "Invalid input. Enter a non-negative integer: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter total runs scored: ";
        while (!(cin >> totalRuns) || totalRuns < 0) {
            cout << "Invalid input. Enter a non-negative integer: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore(); // Clear newline from buffer
    }

    // Calculate batting average
    double calculateAverage() {
        if (matchesPlayed == 0) return 0.0; // Avoid division by zero
        return static_cast<double>(totalRuns) / matchesPlayed;
    }

    // Display complete player report
    void displayReport() {
        double avg = calculateAverage();
        cout << "\n----- Player Report -----\n";
        cout << "Name: " << playerName << "\n";
        cout << "Matches Played: " << matchesPlayed << "\n";
        cout << "Total Runs: " << totalRuns << "\n";
        cout << "Batting Average: " << avg << "\n";
        cout << "Performance: " << classifyPerformance(avg) << "\n";
    }
};

int main() {
    CricketPlayer player;
    player.acceptDetails();
    player.displayReport();
    return 0;
}
