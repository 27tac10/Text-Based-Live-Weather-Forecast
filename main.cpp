#include <iostream>
#include <string>
#include "weatherData.h"
#include "location.h"
#include "httplib.h"

using namespace std;

void printMenu();
int userChoice();
string getCityName();
string getCountryCode();
bool isValidInput(string, string);

int main()
{
    bool close_app = false;
    
    while(!close_app)
    {
        printMenu();
        int choice = userChoice();

        switch(choice)
        {
            case 1:
            {
                // Get weather by city name
                string city_name;
                string country_name;
                city_name = getCityName();
                country_name = getCountryCode();
                
                if(isValidInput(city_name, country_name) == false)
                {
                    cout << "Invalid input. Please try again." << endl;
                    break;
                }
                WeatherData weather(city_name, country_name);
                weather.readAll();
                cout << "City: " << weather.getName() << endl;
                cout << "Temperature: " << weather.getTemperature() << endl;
                cout << "Condition: " << weather.getWeatherMain() << endl;
                break;
            }
            case 2:
            {
                // Get weather by geographic coordinates
                double latitude, longitude;
                cout << "Enter latitude: ";
                cin >> latitude;
                cout << "Enter longitude: ";
                cin >> longitude;
                WeatherData weather(latitude, longitude);
                weather.readAll();
                cout << "City: " << weather.getName() << endl;
                cout << "Temperature: " << weather.getTemperature() << endl;
                cout << "Condition: " << weather.getWeatherMain() << endl;
                break;
            }
            case 3:
                close_app = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        cout << endl;
    }

    return 0;
};

void printMenu()
{
    cout << "Weather App Menu:" << endl;
    cout << "1. Get weather by city and country name" << endl;
    cout << "2. Get weather by geographic coordinates" << endl;
    cout << "3. Exit" << endl;
}

int userChoice()
{
    string line;
    cout << "Enter your choice (1-3): ";
    if (!getline(cin, line)) return 0;
    try {
        return std::stoi(line);
    } catch (...) {
        return 0; // invalid -> will hit default case
    }
}

string getCityName()
{
    string city;
    cout << "Enter city name: ";
    getline(cin, city);
    return city;
}

string getCountryCode()
{
    string country;
    cout << "Enter country name (e.g. United States): ";
    getline(cin, country);
    return country;
}

bool isValidInput(string city, string country)
{
    Location location(city, country);
    return location.isValidLocation();
}