#include "Hotel.h"
#include <iostream>
#include <cstdlib>

Hotel::Hotel(const std::string& name, int capacity) : hotelName(name), roomCapacity(capacity) {
    roomArray = new Room*[roomCapacity];
}

Hotel::~Hotel() {
    for (int i = 0; i < roomCapacity; ++i) {
        delete roomArray[i];
    }
    delete[] roomArray;
    std::cout << "Hotel " << hotelName << " deleted." << std::endl;
}

std::string Hotel::getHotelName() const { return hotelName; }
int Hotel::getRoomCapacity() const { return roomCapacity; }
Room** Hotel::getRoomArray() const { return roomArray; }

ThreeStarHotel::ThreeStarHotel(const std::string& nm, int capacity, double stdRate, double brkRate)
    : Hotel(nm, capacity), stdroomRate(stdRate), breakfastRate(brkRate) {}

void ThreeStarHotel::initializeRooms() {
    for (int i = 0; i < roomCapacity; ++i) {
        roomArray[i] = new StdRoom(i + 1);
    }
}

double ThreeStarHotel::getStdRoomRate() const { return stdroomRate; }
double ThreeStarHotel::getBreakfastRate() const { return breakfastRate; }

FourStarHotel::FourStarHotel(const std::string& nm, int capacity, double stdRate, double dlxRate)
    : Hotel(nm, capacity), stdroomRate(stdRate), deluxroomRate(dlxRate) {}

void FourStarHotel::initializeRooms() {
    for (int i = 0; i < roomCapacity; ++i) {
        double u = static_cast<double>(rand()) / RAND_MAX;
        if (u < 0.6) {
            roomArray[i] = new StdRoom(i + 1);
        } else {
            roomArray[i] = new DeluxRoom(i + 1, u < 0.8 ? "mountain" : "lake");
        }
    }
}

double FourStarHotel::getStdRoomRate() const { return stdroomRate; }
double FourStarHotel::getDeluxRoomRate() const { return deluxroomRate; }

FiveStarHotel::FiveStarHotel(const std::string& nm, int capacity, double stdRate, double dlxRate, double steRate)
    : Hotel(nm, capacity), stdroomRate(stdRate), deluxroomRate(dlxRate), suiteRate(steRate) {}

void FiveStarHotel::initializeRooms() {
    for (int i = 0; i < roomCapacity; ++i) {
        double u = static_cast<double>(rand()) / RAND_MAX;
        if (u < 0.5) {
            roomArray[i] = new StdRoom(i + 1);
        } else if (u < 0.8) {
            roomArray[i] = new DeluxRoom(i + 1, u < 0.65 ? "mountain" : "lake");
        } else {
            roomArray[i] = new Suite(i + 1, u < 0.9 ? "small" : u < 0.95 ? "medium" : "large");
        }
    }
}

double FiveStarHotel::getStdRoomRate() const { return stdroomRate; }
double FiveStarHotel::getDeluxRoomRate() const { return deluxroomRate; }
double FiveStarHotel::getSuiteRate() const { return suiteRate; }
