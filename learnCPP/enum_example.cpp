#include<iostream>

enum class TrafficLight { red, green, blue };

TrafficLight operator++(TrafficLight& light) {
    switch (light) {
    case TrafficLight::red: return TrafficLight::green;
    case TrafficLight::green: return TrafficLight::blue;
    case TrafficLight::blue: return TrafficLight::red;
    }
}

TrafficLight tr = TrafficLight::blue;

int main() {
    TrafficLight next = ++tr;
    if(tr == TrafficLight::blue) std::cout << "blue" << std::endl;
    if(next == TrafficLight::red) std::cout << "red" << std::endl;

    return 0;
}