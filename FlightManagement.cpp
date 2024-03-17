#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to represent a flight
struct Flight {
    string flightNumber;
    string destination;
    string arrivalTime;
    string departureTime;
};

// Function to add a new flight to the system
void addFlight(vector<Flight>& flights) {
    Flight newFlight;
    
    cout << "Enter flight number: ";
    cin >> newFlight.flightNumber;
    cout << "Enter destination: ";
    cin >> newFlight.destination;
    cout << "Enter arrival time: ";
    cin >> newFlight.arrivalTime;
    cout << "Enter departure time: ";
    cin >> newFlight.departureTime;
    
    flights.push_back(newFlight);
    cout << "Flight added successfully." << endl;
}

// Function to remove a flight from the system
void removeFlight(vector<Flight>& flights, const string& flightNumber) {
    for (auto it = flights.begin(); it != flights.end(); ++it) {
        if (it->flightNumber == flightNumber) {
            flights.erase(it);
            cout << "Flight removed successfully." << endl;
            return;
        }
    }
    cout << "Flight not found." << endl;
}

// Function to display all flights in the system
void displayFlights(const vector<Flight>& flights) {
    cout << setw(15) << "Flight Number" << setw(15) << "Destination" << setw(15) << "Arrival Time" << setw(15) << "Departure Time" << endl;
    for (const Flight& flight : flights) {
        cout << setw(15) << flight.flightNumber << setw(15) << flight.destination << setw(15) << flight.arrivalTime << setw(15) << flight.departureTime << endl;
    }
}

int main() {
    vector<Flight> flights;
    int choice;
    
    do {
        cout << "\nFlight Management System" << endl;
        cout << "1. Add Flight" << endl;
        cout << "2. Remove Flight" << endl;
        cout << "3. Display Flights" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addFlight(flights);
                break;
            case 2: {
                string flightNumber;
                cout << "Enter flight number to remove: ";
                cin >> flightNumber;
                removeFlight(flights, flightNumber);
                break;
            }
            case 3:
                displayFlights(flights);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}
