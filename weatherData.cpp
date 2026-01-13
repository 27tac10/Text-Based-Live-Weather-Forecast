#include "weatherData.h"
#include "httplib.h"

using namespace std;

WeatherData::WeatherData(double lat, double lon)
{
    latitude = lat;
    longitude = lon;
    httplib::Client cli(base_url);
    auto res = cli.Get("/data/2.5/weather?lat=" + to_string(latitude) + "&lon=" + to_string(longitude) + "&appid=" + apiKey+"&units=metric");
    if (res && res->status == 200) 
    {
        weatherJson = nlohmann::json::parse(res->body);
    } 
    else 
    {
        cerr << "Error fetching weather data" << endl;
    }
}

WeatherData::WeatherData(string cityName)
{
    httplib::Client cli(base_url);
    auto res = cli.Get("/data/2.5/weather?q=" + cityName + "&appid=" + apiKey+"&units=metric");
    if (res && res->status == 200) 
    {
        weatherJson = nlohmann::json::parse(res->body);
    } 
    else 
    {
        cerr << "Error fetching weather data" << endl;
    }
}  

WeatherData::WeatherData(string cityName, string countryCode)
{
    httplib::Client cli(base_url);
    auto res = cli.Get("/data/2.5/weather?q=" + cityName + "," + countryCode + "&appid=" + apiKey+"&units=metric");
    if (res && res->status == 200) 
    {
        weatherJson = nlohmann::json::parse(res->body);
    } 
    else 
    {
        cerr << "Error fetching weather data" << endl;
    }
}

WeatherData::WeatherData(string cityName, string countryCode, string stateName)
{
    httplib::Client cli(base_url);
    auto res = cli.Get("/data/2.5/weather?q=" + cityName + "," + stateName + "," + countryCode + "&appid=" + apiKey+"&units=metric");
    if (res && res->status == 200) 
    {
        weatherJson = nlohmann::json::parse(res->body);
    } 
    else 
    {
        cerr << "Error fetching weather data" << endl;
    }
}

void WeatherData::readLatitude()
{
    latitude = static_cast<double>(weatherJson["coord"]["lat"]);
}

void WeatherData::readLongitude()
{
    longitude = static_cast<double>(weatherJson["coord"]["lon"]);
}

void WeatherData::readWeatherID()
{
    weather_id = static_cast<int>(weatherJson["weather"][0]["id"]);
}

void WeatherData::readWeatherMain()
{
    weather_main = weatherJson["weather"][0]["main"];
}

void WeatherData::readWeatherDescription()
{
    weather_description = weatherJson["weather"][0]["description"];
}

void WeatherData::readWeatherIcon()
{
    weather_icon = weatherJson["weather"][0]["icon"];
}

void WeatherData::readBase()
{
    base = weatherJson["base"];
}

void WeatherData::readTemperature()
{
    temperature = static_cast<double>(weatherJson["main"]["temp"]);
}

void WeatherData::readFeelsLike()
{
    temperature_feels_like = static_cast<double>(weatherJson["main"]["feels_like"]);
}

void WeatherData::readMinTemperature()
{
    temperature_min = static_cast<double>(weatherJson["main"]["temp_min"]);
}

void WeatherData::readMaxTemperature()
{
    temperature_max = static_cast<double>(weatherJson["main"]["temp_max"]);
}

void WeatherData::readPressure()
{
    pressure = static_cast<int>(weatherJson["main"]["pressure"]);
}

void WeatherData::readHumidity()
{
    humidity = static_cast<int>(weatherJson["main"]["humidity"]);
}

void WeatherData::readSeaLevel()
{
    sea_level = static_cast<int>(weatherJson["main"]["sea_level"]);
}

void WeatherData::readGroundLevel()
{
    ground_level = static_cast<int>(weatherJson["main"]["grnd_level"]);
}

void WeatherData::readVisibility()
{
    visibility = static_cast<int>(weatherJson["visibility"]);
}

void WeatherData::readWindSpeed()
{
    wind_speed = static_cast<double>(weatherJson["wind"]["speed"]);
}

void WeatherData::readWindDeg()
{
    wind_deg = static_cast<int>(weatherJson["wind"]["deg"]);
}

void WeatherData::readWindGust()
{
    wind_gust = static_cast<double>(weatherJson["wind"]["gust"]);
}

void WeatherData::readRain1h()
{
    rain_1h = static_cast<double>(weatherJson["rain"]["1h"]);
}

void WeatherData::readCloudsAll()
{
    clouds_all = static_cast<int>(weatherJson["clouds"]["all"]);
}

void WeatherData::readSnow1h()
{
    snow_1h = static_cast<double>(weatherJson["snow"]["1h"]);
}

void WeatherData::readDt()
{
    dt = static_cast<int>(weatherJson["dt"]);
}

void WeatherData::readSysType()
{
    sys_type = static_cast<int>(weatherJson["sys"]["type"]);
}

void WeatherData::readSysId()
{
    sys_id = static_cast<int>(weatherJson["sys"]["id"]);
}

void WeatherData::readSysCountry()
{
    sys_country = weatherJson["sys"]["country"];
}

void WeatherData::readSysSunrise()
{
    sys_sunrise = static_cast<int>(weatherJson["sys"]["sunrise"]);
}

void WeatherData::readSysSunset()
{
    sys_sunset = static_cast<int>(weatherJson["sys"]["sunset"]);
}

void WeatherData::readTimezone()
{
    timezone = static_cast<int>(weatherJson["timezone"]);
}

void WeatherData::readId()
{
    id = static_cast<int>(weatherJson["id"]);
}

void WeatherData::readName()
{
    name = weatherJson["name"];
}

void WeatherData::readCod()
{
    cod = static_cast<int>(weatherJson["cod"]);
}

void WeatherData::readAll()
{
     readLatitude();
     readLongitude();
     readWeatherID();
     readWeatherMain();
     readWeatherDescription();
     readWeatherIcon();
     readBase();
     readTemperature();
     readFeelsLike();
     readMinTemperature();
     readMaxTemperature();
     readPressure();
     readHumidity();
     readSeaLevel();
     readGroundLevel();
    // readVisibility();
    // readWindSpeed();
    // readWindDeg();
    // readWindGust();
    // //readRain1h();
    // readCloudsAll();
    // //readSnow1h();
    // readDt();
    // readSysType();
    // readSysId();
    // readSysCountry();
    // readSysSunrise();
    // readSysSunset();
    // readTimezone();
     readId();
     readName();
     readCod();

    if(weather_main == "Rain")
    {
        readRain1h();
    }

    if(weather_main == "Snow")
    {
        readSnow1h();
    }
}

double WeatherData::getLatitude()
{
    return latitude;
}

double WeatherData::getLongitude()
{
    return longitude;
}

int WeatherData::getWeatherID()
{
    return weather_id;
}

string WeatherData::getWeatherMain()
{
    return weather_main;
}

string WeatherData::getWeatherDescription()
{
    return weather_description;
}

string WeatherData::getWeatherIcon()
{
    return weather_icon;
}

string WeatherData::getBase()
{
    return base;
}

double WeatherData::getTemperature()
{
    return temperature;
}

double WeatherData::getTemperatureFeelsLike()
{
    return temperature_feels_like;
}

double WeatherData::getTemperatureMin()
{
    return temperature_min;
}

double WeatherData::getTemperatureMax()
{
    return temperature_max;
}

int WeatherData::getPressure()
{
    return pressure;
}

int WeatherData::getHumidity()
{
    return humidity;
}

int WeatherData::getSeaLevel()
{
    return sea_level;
}

int WeatherData::getGroundLevel()
{
    return ground_level;
}

int WeatherData::getVisibility()
{
    return visibility;
}

double WeatherData::getWindSpeed()
{
    return wind_speed;
}

int WeatherData::getWindDeg()
{
    return wind_deg;
}

double WeatherData::getWindGust()
{
    return wind_gust;
}

double WeatherData::getRain1h()
{
    return rain_1h;
}

int WeatherData::getCloudsAll()
{
    return clouds_all;
}

double WeatherData::getSnow1h()
{
    return snow_1h;
}

int WeatherData::getDt()
{
    return dt;
}

int WeatherData::getSysType()
{
    return sys_type;
}

int WeatherData::getSysId()
{
    return sys_id;
}

string WeatherData::getSysCountry()
{
    return sys_country;
}

int WeatherData::getSysSunrise()
{
    return sys_sunrise;
}

int WeatherData::getSysSunset()
{
    return sys_sunset;
}

int WeatherData::getTimezone()
{
    return timezone;
}

int WeatherData::getId()
{
    return id;
}

string WeatherData::getName()
{
    return name;
}

int WeatherData::getCod()
{
    return cod;
}