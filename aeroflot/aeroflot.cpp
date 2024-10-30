#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

struct AEROFLOT {
    string destination;     // Название пункта назначения
    int flightNumber;      // Номер рейса
    string planeType;      // Тип самолета
    string departureTime;   // Время вылета
};

// Функция для чтения рейсов из файла
void loadFlightsFromFile(AEROFLOT flights[], int& count, int maxFlights, const string& filename) {
    ifstream infile(filename);
    if (infile.is_open()) {
        while (infile >> flights[count].destination >> flights[count].flightNumber
            >> flights[count].planeType >> flights[count].departureTime) {
            count++;
            if (count >= maxFlights) break;
        }
        infile.close();
    }
}

// Функция для сохранения рейсов в файл
void saveFlightsToFile(AEROFLOT flights[], int count, const string& filename) {
    ofstream outfile(filename);
    for (int i = 0; i < count; i++) {
        outfile << flights[i].destination << " "
            << flights[i].flightNumber << " "
            << flights[i].planeType << " "
            << flights[i].departureTime << endl;
    }
    outfile.close();
}

// Функция для отображения рейсов с форматированным выводом
void displayFlights(AEROFLOT flights[], int count) {
    cout << "\nCurrent flight list:\n";
    cout << left << setw(15) << "Destination"
        << setw(15) << "Flight Number"
        << setw(15) << "Plane Type"
        << setw(15) << "Departure Time" << endl;
    for (int i = 0; i < count; i++) {
        cout << left << setw(15) << flights[i].destination
            << setw(15) << flights[i].flightNumber
            << setw(15) << flights[i].planeType
            << setw(15) << flights[i].departureTime << endl;
    }
}

// Функция для добавления нового рейса
void addFlight(AEROFLOT flights[], int& count, int maxFlights) {
    if (count >= maxFlights) {
        cout << "The flight list is full." << endl;
        return;
    }

    cout << "Enter destination: ";
    cin >> flights[count].destination;
    cout << "Enter flight number: ";
    cin >> flights[count].flightNumber;
    cout << "Enter plane type: ";
    cin >> flights[count].planeType;
    cout << "Enter departure time (HH:MM): ";
    cin >> flights[count].departureTime;

    count++;
    cout << "Flight added successfully!" << endl;
}

// Функция для редактирования существующего рейса
void editFlight(AEROFLOT flights[], int count) {
    int flightNumber;
    cout << "Enter the flight number to edit: ";
    cin >> flightNumber;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (flights[i].flightNumber == flightNumber) {
            cout << "Editing flight to " << flights[i].destination << endl;
            cout << "Enter new destination: ";
            cin >> flights[i].destination;
            cout << "Enter new plane type: ";
            cin >> flights[i].planeType;
            cout << "Enter new departure time (HH:MM): ";
            cin >> flights[i].departureTime;
            cout << "Flight updated!" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Flight not found." << endl;
    }
}

// Функция для сортировки рейсов по пункту назначения
void sortFlightsByDestination(AEROFLOT flights[], int count) {
    sort(flights, flights + count, [](AEROFLOT a, AEROFLOT b) {
        return a.destination < b.destination;
        });
}

// Функция для сортировки рейсов по времени вылета
void sortFlightsByDepartureTime(AEROFLOT flights[], int count) {
    sort(flights, flights + count, [](AEROFLOT a, AEROFLOT b) {
        return a.departureTime < b.departureTime;
        });
}

// Функция для поиска рейсов по типу самолета
void searchByPlaneType(AEROFLOT flights[], int count, const string& planeType) {
    bool found = false;
    cout << left << setw(15) << "Destination" << setw(15) << "Flight Number" << endl;
    for (int i = 0; i < count; i++) {
        if (flights[i].planeType == planeType) {
            cout << left << setw(15) << flights[i].destination
                << setw(15) << flights[i].flightNumber << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No flights found for this plane type." << endl;
    }
}

// Функция для поиска рейсов по пункту назначения
void searchByDestination(AEROFLOT flights[], int count, const string& destination) {
    bool found = false;
    cout << left << setw(15) << "Destination" << setw(15) << "Flight Number"
        << setw(15) << "Plane Type" << setw(15) << "Departure Time" << endl;
    for (int i = 0; i < count; i++) {
        if (flights[i].destination == destination) {
            cout << left << setw(15) << flights[i].destination
                << setw(15) << flights[i].flightNumber
                << setw(15) << flights[i].planeType
                << setw(15) << flights[i].departureTime << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No flights found for this destination." << endl;
    }
}

// Основная функция для запуска системы управления рейсами
void start(AEROFLOT flights[], int& count, int maxFlights, const string& filename) {
    int choice;
    bool running = true;

    while (running) {
        cout << "\n===== Flight Management System =====\n";
        cout << "1. Add flight\n";
        cout << "2. Edit flight\n";
        cout << "3. Sort flights by destination\n";
        cout << "4. Sort flights by departure time\n";
        cout << "5. Search by plane type\n";
        cout << "6. Search by destination\n";
        cout << "7. Display all flights\n";
        cout << "8. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addFlight(flights, count, maxFlights);
            sortFlightsByDestination(flights, count); // Сортируем после добавления нового рейса
            saveFlightsToFile(flights, count, filename);
            break;
        case 2:
            editFlight(flights, count);
            sortFlightsByDestination(flights, count); // Сортируем после редактирования рейса
            saveFlightsToFile(flights, count, filename);
            break;
        case 3:
            sortFlightsByDestination(flights, count);
            cout << "Flights sorted by destination!" << endl;
            displayFlights(flights, count);
            break;
        case 4:
            sortFlightsByDepartureTime(flights, count);
            cout << "Flights sorted by departure time!" << endl;
            displayFlights(flights, count);
            break;
        case 5: {
            string planeType;
            cout << "Enter plane type to search: ";
            cin >> planeType;
            searchByPlaneType(flights, count, planeType);
            break;
        }
        case 6: {
            string destination;
            cout << "Enter destination to search: ";
            cin >> destination;
            searchByDestination(flights, count, destination);
            break;
        }
        case 7:
            displayFlights(flights, count);
            break;
        case 8:
            cout << "Saving and exiting..." << endl;
            saveFlightsToFile(flights, count, filename);
            running = false;
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }
    }
}

int main() {
    const int maxFlights = 7; // Максимальное количество рейсов
    AEROFLOT flights[maxFlights]; // Массив рейсов
    int flightCount = 0; // Счетчик рейсов
    string filename = "flights.txt"; // Имя файла для сохранения данных

    loadFlightsFromFile(flights, flightCount, maxFlights, filename); // Загрузка рейсов из файла

    start(flights, flightCount, maxFlights, filename); // Запуск системы управления рейсами

    return 0;
}
