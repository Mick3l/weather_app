#include "weather.h"

uint8_t mtl::GetDay(Date date) {
    uint32_t days = JAN_1_2023 + (date.year - START_YEAR) * YEAR /* for leap years */ +
                    (date.year - 2020) / 4 - (date.year - 2020) / 100 + (date.year - 2020) / 400;
    for (int i = JANUARY; i < date.month; ++i) {
        days += months_length[i];
    }
    days += date.day - 1;
    return days % 7;
}

std::string mtl::WeatherGetter::DayTimeForecast::GetPicture(uint8_t string_number) const {
    switch (weather_code) {
        case 0: {
            if (string_number == 0) {
                return "Clear";
            }
            std::string picture[] = {
                    "    \\   /    ",
                    "     .-.     ",
                    "  - (   ) -  ",
                    "      -'     ",
                    "    /   \\    "};
            return picture[string_number - 1];
            break;
        }
        case 1: {
            if (string_number == 0) {
                return "Mainly Clear";
            }

            std::string picture[] = {
                    "    \\   /    ",
                    "     .-.     ",
                    "  - (   ) -  ",
                    "      -'     ",
                    "    /   \\    "};
            return picture[string_number - 1];
        }
        case 2: {
            if (string_number == 0) {
                return "Partly Cloudy";
            }
            std::string picture[] = {
                    "   \\  /      ",
                    " _ /\"\".-.    ",
                    "   \\_(   ).  ",
                    "   /(___(__) ",
                    "             "};
            return picture[string_number - 1];
        }
        case 3: {
            if (string_number == 0) {
                return "Cloudy";
            }

            std::string picture[] = {"             ",
                                     "     .--.    ",
                                     "  .-(    ).  ",
                                     " (___.__)__) ",
                                     "             "};
            return picture[string_number - 1];
        }
        case 45: {
            if (string_number == 0) {
                return "Foggy";
            }

            std::string picture[] = {"             ",
                                     " _ - _ - _ - ",
                                     "  _ - _ - _  ",
                                     " _ - _ - _ - ",
                                     "             "};
            return picture[string_number - 1];
        }
        case 48: {
            if (string_number == 0) {
                return "Rime Fog";
            }

            std::string picture[] = {"             ",
                                     " _ - _ - _ - ",
                                     "  _ - _ - _  ",
                                     " _ - _ - _ - ",
                                     "             "};
            return picture[string_number - 1];
        }
        case 51:
        case 55:
        case 53: {
            if (string_number == 0) {
                return "Drizzle";
            }

            std::string picture[] = {"     .-.    ",
                                     "    (   ).  ",
                                     "   ((    ) ",
                                     "   '   ' ' ",
                                     "    '   '  "};
            return picture[string_number - 1];
        }
        case 56:
        case 57: {
            if (string_number == 0) {
                return "Freezing drizzle";
            }

            std::string picture[] = {"     .-.    ",
                                     "    (   ).  ",
                                     "   ((    ) ",
                                     "   *   ' ' ",
                                     "    '   *  "};
            return picture[string_number - 1];
        }
        case 61: {
            if (string_number == 0) {
                return "Light Rain";
            }

            std::string picture[] = {"     .-.    ",
                                     "    (   ).  ",
                                     "   ((    ) ",
                                     "   '   ' ' ",
                                     "    '   '  "};
            return picture[string_number - 1];
        }
        case 63: {
            if (string_number == 0) {
                return "Rain";
            }

            std::string picture[] = {"     .-.    ",
                                     "    (   ).  ",
                                     "   ((    ) ",
                                     "   ' ' ' ' ",
                                     "  ' ' ' '  "};
            return picture[string_number - 1];
        }
        case 65: {
            if (string_number == 0) {
                return "Heavy Rain";
            }

            const std::string picture[] = {"     .-.    ",
                                           "    (   ).  ",
                                           "   ((    ) ",
                                           "  ' ''' ''' ",
                                           " ''' ' ''' '  "};
            return picture[string_number - 1];
        }
        case 71: {
            if (string_number == 0) {
                return "Light Snow";
            }

            std::string picture[] = {"     .-.    ",
                                     "    (   ).  ",
                                     "   ((    ) ",
                                     "   *   * * ",
                                     "    *   *  "};
            return picture[string_number - 1];
        }
        case 73: {
            if (string_number == 0) {
                return "Snow";
            }

            std::string picture[] = {"     .-.    ",
                                     "    (   ).  ",
                                     "   ((    ) ",
                                     "   * * * * ",
                                     "  * * * *  "};
            return picture[string_number - 1];
        }
        case 75: {
            if (string_number == 0) {
                return "Heavy Snow";
            }

            std::string picture[] = {"     .-.    ",
                                     "    (   ).  ",
                                     "   ((    ) ",
                                     "   * *** * ",
                                     "  *** ***  "};
            return picture[string_number - 1];
        }
        case 80: {
            if (string_number == 0) {
                return "Light Showers";
            }

            std::string picture[] = {"     .-.    ",
                                     "    (   ).  ",
                                     "   ((    ) ",
                                     "   '   ' ' ",
                                     "    '   '  "};
            return picture[string_number - 1];
        }
        case 81: {
            if (string_number == 0) {
                return "Showers";
            }

            std::string picture[] = {"     .-.    ",
                                     "    (   ).  ",
                                     "   ((    ) ",
                                     "   ' ' ' ' ",
                                     "  ' ' ' '  "};
            return picture[string_number - 1];
        }
        case 82: {
            if (string_number == 0) {
                return "Heavy Showers";
            }

            std::string picture[] = {"     .-.    ",
                                     "    (   ).  ",
                                     "   ((    ) ",
                                     "   ' * ' * ",
                                     "  * ' * '  "};
            return picture[string_number - 1];
        }
        case 85:
        case 86: {
            if (string_number == 0) {
                return "Snow Showers";
            }
            std::string picture[] = {"     .-.    ",
                                     "    (   ).  ",
                                     "   ((    ) ",
                                     "   ' * ' * ",
                                     "  * *** *  "};
            return picture[string_number - 1];
        }
        case 95:
        case 96:
        case 97: {
            if (string_number == 0) {
                return "Thunderstorm";
            }
            std::string picture[] = {"     .-.    ",
                                     "    (   ).  ",
                                     "   ((    ) ",
                                     "   /' \\* / * ",
                                     "  *\\ '/  \\'"};
            return picture[string_number - 1];
        }
    }
}

std::string DayOfWeek(uint8_t day) {
    switch (day) {
        case MONDAY:
            return "Monday";
        case TUESDAY:
            return "Tuesday";
        case WEDNESDAY:
            return "Wednesday";
        case THURSDAY:
            return "Thursday";
        case FRIDAY:
            return "Friday";
        case SATURDAY:
            return "Saturday";
        case SUNDAY:
            return "Sunday";
    }
}


mtl::Date::Date(
        const std::string& date) :
        year(std::stoi(date.substr(0, 4))),
        month(std::stoi(date.substr(5, 2))),
        day(std::stoi(date.substr(8, 2))) {
}

std::ostream& mtl::operator<<(std::ostream& stream, mtl::Date& date) {
    stream << std::setw(2) << static_cast<int32_t>(date.day) << ' ';
    switch (date.month) {
        case JANUARY:
            std::cout << std::setw(9) << "January";
            break;
        case FEBRUARY:
            std::cout << std::setw(9) << "February";
            break;
        case MARCH:
            std::cout << std::setw(9) << "March";
            break;
        case APRIL:
            std::cout << std::setw(9) << "April";
            break;
        case MAY:
            std::cout << std::setw(9) << "May";
            break;
        case JUNE:
            std::cout << std::setw(9) << "June";
            break;
        case JULY:
            std::cout << std::setw(9) << "July";
            break;
        case AUGUST:
            std::cout << std::setw(9) << "August";
            break;
        case SEPTEMBER:
            std::cout << std::setw(9) << "September";
            break;
        case OCTOBER:
            std::cout << std::setw(9) << "October";
            break;
        case NOVEMBER:
            std::cout << std::setw(9) << "November";
            break;
        case DECEMBER:
            std::cout << std::setw(9) << "December";
            break;
    }
    return stream;
}


mtl::WeatherGetter::WeatherGetter(
        const std::string& config_filepath) :
        cities_forecast(),
        config_info(),
        stored_days_number() {
    nlohmann::json parsed_config = nlohmann::json::parse(std::ifstream(config_filepath));
    config_info = {parsed_config["refresh"], parsed_config["days"]};
    if (config_info.refresh_rate < 1) {
        std::cerr << "wrong refresh number";
    }
    if (config_info.days_number < 1) {
        std::cerr << "wrong days number";
    }
    stored_days_number = config_info.days_number;
    for (const auto& i: parsed_config["names"]) {
        cities_forecast.Insert(i,
                               std::move(Forecast(
                                       GetForecast(GetCoordinatesByName(i)))));
    }
}

mtl::Coordinates mtl::WeatherGetter::GetCoordinatesByName(const std::string& name) {
    cpr::Response response = cpr::Get(cpr::Url{"https://api.api-ninjas.com/v1/city"},
                                      cpr::Header{{"X-Api-Key", "e8hvtk+YOTUg/8cHm469XA==M5oSRuLnfmr1eBwd"}},
                                      cpr::Parameters{{"name", name}});
    if (response.status_code != 200) {
        return {-91.f, -91.f};
    }
    nlohmann::json parsed_response = nlohmann::json::parse(response.text);
    return mtl::Coordinates{parsed_response[0]["latitude"], parsed_response[0]["longitude"]};
}

nlohmann::json mtl::WeatherGetter::GetForecast(mtl::Coordinates coordinates) {
    if (coordinates.latitude == -91.f && coordinates.longitude == -91.f) {
        return nlohmann::json{};
    }
    cpr::Response response = cpr::Get(cpr::Url{"https://api.open-meteo.com/v1/forecast"},
                                      cpr::Parameters{{"latitude",      std::to_string(coordinates.latitude)},
                                                      {"longitude",     std::to_string(coordinates.longitude)},
                                                      {"hourly",        "temperature_2m,relativehumidity_2m,windspeed_10m,winddirection_10m,pressure_msl,weathercode"},
                                                      {"forecast_days", std::to_string(config_info.days_number)}});
    nlohmann::json parsed_response = nlohmann::json::parse(response.text);
    return parsed_response;
}

mtl::WeatherGetter::Forecast::Forecast(nlohmann::json&& parsed_json) : days() {
    if (parsed_json.empty()) {
        return;
    }
    //for every day
    for (size_t i = 0; i < parsed_json["hourly"]["time"].size(); i += 24) {
        days.emplace_back(parsed_json, i);
    }
}

void mtl::WeatherGetter::Forecast::show(uint8_t days_number) {
    if (days.empty()) {
        std::cout << "connection error" << std::endl;
        return;
    }
    for (int i = 0; i < days_number; ++i) {
        std::cout << std::string(4 * (cell_width + 1), '-') << std::endl;
        std::cout << days[i] << std::endl;
    }
    std::cout << std::string(4 * (cell_width + 1), '-') << std::endl;
}

mtl::WeatherGetter::DayForecast::DayForecast(nlohmann::json& parsed_json, size_t
day_start_time_idx) :
        date(parsed_json["hourly"]["time"][day_start_time_idx]),
        night(parsed_json, day_start_time_idx + NIGHT),
        morning(parsed_json, day_start_time_idx + MORNING),
        day(parsed_json, day_start_time_idx + DAY),
        evening(parsed_json, day_start_time_idx + EVENING) {
}

mtl::WeatherGetter::DayTimeForecast::DayTimeForecast(nlohmann::json& parsed_json, size_t
daytime_start_idx) :
        temperature_max(std::accumulate(parsed_json["hourly"]["temperature_2m"].begin() + daytime_start_idx,
                                        parsed_json["hourly"]["temperature_2m"].begin() + daytime_start_idx +
                                        DAYTIME_LENGTH, INT16_MIN,
                                        [](int16_t a, int16_t b) { return std::max(a, b); })),
        temperature_min(std::accumulate(parsed_json["hourly"]["temperature_2m"].begin() + daytime_start_idx,
                                        parsed_json["hourly"]["temperature_2m"].begin() + daytime_start_idx +
                                        DAYTIME_LENGTH, INT16_MAX,
                                        [](int16_t a, int16_t b) { return std::min(a, b); })),
        pressure(std::accumulate(parsed_json["hourly"]["pressure_msl"].begin() + daytime_start_idx,
                                 parsed_json["hourly"]["pressure_msl"].begin() + daytime_start_idx +
                                 DAYTIME_LENGTH, 0,
                                 [](int16_t a, int16_t b) { return a + b; }) * 0.75f / DAYTIME_LENGTH),
        wind_direction(std::accumulate(parsed_json["hourly"]["winddirection_10m"].begin() + daytime_start_idx,
                                       parsed_json["hourly"]["winddirection_10m"].begin() + daytime_start_idx +
                                       DAYTIME_LENGTH, 0, [](int16_t a, int16_t b) { return a + b; }) /
                       DAYTIME_LENGTH / WIND_DIRECTION_ANGLE),
        wind_velocity(std::accumulate(parsed_json["hourly"]["windspeed_10m"].begin() + daytime_start_idx,
                                      parsed_json["hourly"]["windspeed_10m"].begin() + daytime_start_idx +
                                      DAYTIME_LENGTH, 0.f,
                                      [](float a, float b) { return std::max(a, b); }) / DAYTIME_LENGTH),
        humidity(std::accumulate(parsed_json["hourly"]["relativehumidity_2m"].begin() + daytime_start_idx,
                                 parsed_json["hourly"]["relativehumidity_2m"].begin() + daytime_start_idx +
                                 DAYTIME_LENGTH, 0,
                                 [](int16_t a, int16_t b) { return a + b; }) / DAYTIME_LENGTH),
        weather_code() {
    std::vector<uint16_t> weather_codes{
            parsed_json["hourly"]["weathercode"].begin() + daytime_start_idx,
            parsed_json["hourly"]["weathercode"].begin() + daytime_start_idx + DAYTIME_LENGTH
    };
    std::sort(weather_codes.begin(), weather_codes.end());
    weather_code = weather_codes[3];//weather code = median from all weather codes
}

std::ostream& mtl::operator<<(std::ostream& stream, mtl::WeatherGetter::DayForecast& dayForecast) {
    stream << "| " << dayForecast.date << ' '
           << std::setw(strlen("Wednesday")) << std::left << DayOfWeek(GetDay(dayForecast.date))
           << std::string(4 * (cell_width) - offset - strlen("Wednesday"), ' ') << " |" << std::right
           << std::endl; // Wednesday because it's the longest day name
    stream << std::string(4 * (cell_width + 1), '-') << std::endl;
    stream << "| "
           << std::setw(offset) << std::left << "night" << std::right << std::setw(cell_width - offset + 1)
           << "  | "
           << std::setw(offset) << std::left << "morning" << std::right << std::setw(cell_width - offset + 1)
           << "  | "
           << std::setw(offset) << std::left << "day" << std::right << std::setw(cell_width - offset + 1) << "  | "
           << std::setw(offset) << std::left << "evening" << std::right << std::setw(cell_width - offset + 1)
           << "  | "
           << std::endl;
    stream << "| " << dayForecast.night << " | "
           << dayForecast.morning << " | "
           << dayForecast.day << " | "
           << dayForecast.evening << " |" << std::endl;
    for (int i = 0; i < 6; ++i) {
        stream << std::left << "| " << std::setw(cell_width - 1) << dayForecast.night.GetPicture(i) << "|"
               << std::setw(cell_width) << dayForecast.morning.GetPicture(i) << "|"
               << std::setw(cell_width) << dayForecast.day.GetPicture(i) << "|"
               << std::setw(cell_width) << dayForecast.evening.GetPicture(i) << "|" << std::endl;
    }
    stream << std::right;

    return stream;
}

std::ostream& mtl::operator<<(std::ostream& stream, mtl::WeatherGetter::DayTimeForecast& dayForecast) {
    stream << std::showpos << std::setw(3) << dayForecast.temperature_min << ".."
           << std::setw(3) << dayForecast.temperature_max << ' ' << std::noshowpos;
    stream << dayForecast.pressure << ' ' << std::setw(3) << static_cast<int32_t>(dayForecast.humidity) << '%'
           << ' ';
    stream << std::fixed << std::setprecision(1) << std::setw(5) << dayForecast.wind_velocity << ' ';
    switch (dayForecast.wind_direction) {
        case NORTH:
            stream << "N ";
            break;
        case NORTH_EAST:
            stream << "NE";
            break;
        case EAST:
            stream << "E ";
            break;
        case SOUTH_EAST:
            stream << "SE";
            break;
        case SOUTH:
            stream << "S ";
            break;
        case SOUTH_WEST:
            stream << "SW";
            break;
        case WEST:
            stream << "W ";
            break;
        case NORTH_WEST:
            stream << "NW";
            break;
    }

    return stream;
}

void mtl::WeatherGetter::ShowForecast() {
    auto current_city_iterator = cities_forecast.begin();
    std::cout << current_city_iterator->first << std::endl;
    current_city_iterator->second.show(config_info.days_number);
    for (char i = getch(); i != ESC; i = getch()) {
        switch (i) {
            case '+':
                ++config_info.days_number;
                if (config_info.days_number > stored_days_number) {
                    UpdateForecast();
                    ++stored_days_number;
                }
                break;
            case '-':
                if (config_info.days_number > 0) {
                    --config_info.days_number;
                }
                break;
            case 'n':
                ++current_city_iterator;
                if (current_city_iterator == cities_forecast.end()) {
                    current_city_iterator = cities_forecast.begin();
                }
                break;
            case 'p':
                if (current_city_iterator == cities_forecast.begin()) {
                    current_city_iterator = cities_forecast.end();
                }
                --current_city_iterator;
                break;
            default:
                continue;
        }
        system("cls");
        std::cout << current_city_iterator->first << std::endl;
        (*current_city_iterator).second.show(config_info.days_number);
    }
}

void mtl::WeatherGetter::UpdateForecast() {
    for (auto& city: cities_forecast) {
        city.second = Forecast(GetForecast(GetCoordinatesByName(city.first)));
    }
}
