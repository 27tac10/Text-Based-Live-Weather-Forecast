#ifndef WEATHER_DATA_H
#define WEATHER_DATA_H

#include <string>
#include "json.hpp"

using namespace std;

class WeatherData {
    public:
        WeatherData(double, double);
        WeatherData(string);
        WeatherData(string, string);
        WeatherData(string, string, string);

        void readAll();

        double getLatitude();
        double getLongitude();
        int getWeatherID();
        string getWeatherMain();
        string getWeatherDescription();
        string getWeatherIcon();
        string getBase();
        double getTemperature();
        double getTemperatureFeelsLike();
        double getTemperatureMin();
        double getTemperatureMax();
        int getPressure();
        int getHumidity();
        int getSeaLevel();
        int getGroundLevel();
        int getVisibility();
        double getWindSpeed();
        int getWindDeg();
        double getWindGust();
        double getRain1h();
        int getCloudsAll();
        double getSnow1h();
        int getDt();
        int getSysType();
        int getSysId();
        string getSysCountry();
        int getSysSunrise();
        int getSysSunset();
        int getTimezone();
        int getId();
        string getName();
        int getCod();

    private:
        nlohmann::json weatherJson;
        const string apiKey = "26f282ea7b9c93f7bc565a1acac6a412";
        const string base_url = "api.openweathermap.org";
        double latitude;
        double longitude;
        int weather_id;
        string weather_main;
        string weather_description;
        string weather_icon; // ???
        string base;
        double temperature;
        double temperature_feels_like;
        double temperature_min;
        double temperature_max;
        int pressure;
        int humidity;
        int sea_level;
        int ground_level;
        int visibility;
        double wind_speed;
        int wind_deg;
        double wind_gust;
        double rain_1h;
        int clouds_all;
        double snow_1h;
        int dt;
        int sys_type;
        int sys_id;
        string sys_country;
        int sys_sunrise;
        int sys_sunset;
        int timezone; // Timezone
        int id; // City ID
        string name; // City name
        int cod; // Response code

        void readLatitude();
        void readLongitude();
        void readWeatherID();
        void readWeatherMain();
        void readWeatherDescription();
        void readWeatherIcon();
        void readBase();
        void readTemperature();
        void readFeelsLike();
        void readMinTemperature();
        void readMaxTemperature();
        void readPressure();
        void readHumidity();
        void readSeaLevel();
        void readGroundLevel();
        void readVisibility();
        void readWindSpeed();
        void readWindDeg();
        void readWindGust();
        void readRain1h();
        void readCloudsAll();
        void readSnow1h();
        void readDt();
        void readSysType();
        void readSysId();
        void readSysCountry();
        void readSysSunrise();
        void readSysSunset();
        void readTimezone();
        void readId();
        void readName();
        void readCod();
};

#endif // WEATHER_DATA_H