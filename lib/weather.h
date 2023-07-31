#pragma once

#include <iostream>
#include <vector>
#include <conio.h>

#include "cpr/cpr.h"
#include "nlohmann/json.hpp"
#include "hash.h"

#define HOURS_PER_DAY 24

//days of week
#define MONDAY 0
#define TUESDAY 1
#define WEDNESDAY 2
#define THURSDAY 3
#define FRIDAY 4
#define SATURDAY 5
#define SUNDAY 6
#define JAN_1_2023 6
#define START_YEAR 2023
#define START_MONTH 1
#define START_DATE 1
#define YEAR 365

//wind directions
#define NORTH 0
#define NORTH_EAST 1
#define EAST 2
#define SOUTH_EAST 3
#define SOUTH 4
#define SOUTH_WEST 5
#define WEST 6
#define NORTH_WEST 7
#define WIND_DIRECTION_ANGLE 45

//day times
#define NIGHT 0
#define MORNING 6
#define DAY 12
#define EVENING 18

#define DAYTIME_LENGTH 6

//months
#define JANUARY 1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12
const uint8_t months_length[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//button code
#define ESC 27

//table properties
#define cell_width 28
#define offset 12

namespace mtl {

    struct Coordinates {
        double latitude;
        double longitude;
    };

    struct Date {
        uint8_t day;
        uint8_t month;
        uint16_t year;

        //date in iso8601 format
        explicit Date(const std::string& date);
    };

    uint8_t GetDay(Date date);

    struct Info {
        int32_t refresh_rate;
        int32_t days_number;
    };

    std::ostream& operator<<(std::ostream& stream, Date& date);


    class WeatherGetter {
    public:
        explicit WeatherGetter(const std::string& config_filepath);

        ~WeatherGetter() = default;

        WeatherGetter(const WeatherGetter& other) = delete;

        WeatherGetter& operator=(const WeatherGetter& other) = delete;

        void ShowForecast();

    private:
        class DayTimeForecast {
        public:
            DayTimeForecast(nlohmann::json& parsed_json, size_t daytime_start_idx);

            DayTimeForecast(const DayTimeForecast& other) = default;

            DayTimeForecast& operator=(const DayTimeForecast& other) = default;

            ~DayTimeForecast() = default;

            friend std::ostream& operator<<(std::ostream& stream, DayTimeForecast& dayForecast);

            [[nodiscard]] std::string GetPicture(uint8_t string_number) const;

        private:
            int16_t temperature_max;
            int16_t temperature_min;
            //average in 6 hours
            uint16_t pressure;
            uint8_t humidity;
            uint8_t wind_direction;
            float wind_velocity;
            int8_t weather_code;
        };

        class DayForecast {
        public:
            DayForecast(nlohmann::json& parsed_json, size_t day_start_time_idx);

            DayForecast(const DayForecast& other) = default;

            DayForecast& operator=(const DayForecast& other) = default;

            ~DayForecast() = default;

            friend std::ostream& operator<<(std::ostream& stream, DayForecast& dayForecast);

        private:
            Date date;
            DayTimeForecast morning;
            DayTimeForecast day;
            DayTimeForecast evening;
            DayTimeForecast night;
        };

        class Forecast {
        public:
            Forecast() = default;

            explicit Forecast(nlohmann::json&& parsed_json);

            Forecast(Forecast& other) = delete;

            Forecast& operator=(const Forecast& other) = delete;

            Forecast(Forecast&& other) noexcept: days(std::move(other.days)) {}

            Forecast& operator=(Forecast&& other) noexcept {
                days = std::move(other.days);
                return *this;
            }

            ~Forecast() = default;

            void show(uint8_t days_number);

        private:
            std::vector<DayForecast> days;
        };

        friend std::ostream& operator<<(std::ostream& stream, DayForecast& dayForecast);

        friend std::ostream& operator<<(std::ostream& stream, DayTimeForecast& dayForecast);

        mtl::hash_map<std::string, Forecast> cities_forecast;

        Info config_info;

        size_t stored_days_number;

        Coordinates GetCoordinatesByName(const std::string& name);

        nlohmann::json GetForecast(Coordinates coordinates);

        void UpdateForecast();

    };

    std::ostream& operator<<(std::ostream& stream, WeatherGetter::DayForecast& dayForecast);

    std::ostream& operator<<(std::ostream& stream, WeatherGetter::DayTimeForecast& dayForecast);
}