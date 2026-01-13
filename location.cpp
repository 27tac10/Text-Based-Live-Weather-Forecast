#include "location.h"
#include "httplib.h"
#include <iostream>

using namespace std;

Location::Location(double lat, double lon)
{
    latitude = lat;
    longitude = lon;

    httplib::Client cli(base_url);
    auto res = cli.Get("/geo/1.0/reverse?lat=" + to_string(latitude) + "&lon=" + to_string(longitude) + "&limit=1&appid=" + api_key);
    if (res && res->status == 200) 
    {
        locationData = nlohmann::json::parse(res->body);
        valid_location = true;
    } 
    else 
    {
        cerr << "Error fetching location data" << endl;
    }
}
Location::Location(string city)
{
    city_name = city;
    httplib::Client cli(base_url);
    auto res = cli.Get("/geo/1.0/direct?q=" + city_name + "&limit=1&appid=" + api_key);
    if (res && res->status == 200) 
    {
        locationData = nlohmann::json::parse(res->body);
        valid_location = true;
    } 
    else 
    {
        cerr << "Error: fetching location data" << endl;
    }
}

Location::Location(string city, string country)
{
    city_name = city;
    country_name = country;
    httplib::Client cli(base_url);
    auto res = cli.Get("/geo/1.0/direct?q=" + city_name + "," + country_name + "&limit=1&appid=" + api_key);
    if (res && res->status == 200) 
    {
        locationData = nlohmann::json::parse(res->body);
        valid_location = true;
    } 
    else 
    {
        cerr << "Error: fetching location data" << endl;
    }
}

Location::Location(string city, string country, string state)
{
    city_name = city;
    country_name = country;
    state_name = state;
    httplib::Client cli(base_url);
    auto res = cli.Get("/geo/1.0/direct?q=" + city_name + "," + state_name + "," + country_name + "&limit=1&appid=" + api_key);
    if (res && res->status == 200) 
    {
        locationData = nlohmann::json::parse(res->body);
        valid_location = true;
    } 
    else 
    {
        cerr << "Error: fetching location data" << endl;
    }
}

bool Location::isValidLocation()
{
    return valid_location;
}
