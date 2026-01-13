#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include "json.hpp"

using namespace std;

class Location
{
    public:
        Location(double lat, double lon);
        Location(string city);
        Location(string city, string country);
        Location(string city, string country, string state);
        bool isValidLocation();


    private:
    nlohmann::json locationData;
    const string base_url = "http://api.openweathermap.org";
    const string api_key = "26f282ea7b9c93f7bc565a1acac6a412";
    bool valid_location = false;


    double latitude;
    double longitude;
    string city_name;
    string country_name;
    string state_name;
};

#endif // LOCATION_H