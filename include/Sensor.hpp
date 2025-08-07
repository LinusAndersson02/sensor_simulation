#pragma once
#include <string>
#include <nlohmann/json.hpp>

class Sensor {
public:
    virtual ~Sensor() = default;
    virtual std::string type() const = 0;
    virtual double read() = 0;                     // return simulated value
    nlohmann::json to_json(double value, double ts) const;
};
