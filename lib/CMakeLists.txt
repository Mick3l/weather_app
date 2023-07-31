add_library(weather weather.cpp weather.h)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG e65e685fa907492fc5f337e97a7e9713758cc9e7)
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(hash GIT_REPOSITORY https://github.com/Mick3l/fast-cpp-hash-table.git
        GIT_TAG 950e8a8156ec843965a5a8d904e175e970ef16f3) #replace with the latest commit in main branch
FetchContent_MakeAvailable(hash)

target_link_libraries(weather PUBLIC nlohmann_json::nlohmann_json)

target_link_libraries(weather PUBLIC cpr::cpr)

target_include_directories(weather PUBLIC "${HASH}")
