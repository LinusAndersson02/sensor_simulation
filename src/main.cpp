#include "Sensor.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

int main() {
    std::ofstream log("events.log", std::ios::app);
    if (!log) { std::cerr << "Cannot open logfile\n"; return 1; }

    // TODO: create concrete sensor objects and loop
    double value = 42.0;
    double ts = std::chrono::duration<double>(
        std::chrono::system_clock::now().time_since_epoch()).count();

    log << R"({"ts":)" << ts << R"(,"type":"demo","value":)" << value << "}\n";
    std::cout << "Wrote one demo event.\n";
}
