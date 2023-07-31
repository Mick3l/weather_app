#include <iostream>

#include "lib/weather.h"

using namespace std;

#define line std::cout << std::endl;

int main() {
    mtl::WeatherGetter w(R"(I:\weather\bin\config.json)");
    w.ShowForecast();
    system("pause");
    return 0;
}
