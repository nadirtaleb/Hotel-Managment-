#ifndef HOTEL_H
#define HOTEL_H

#include "Room.h"
#include <string>

class Hotel {
protected:
    std::string hotelName;
    int roomCapacity;
    Room** roomArray;
public:
    Hotel(const std::string& name, int capacity);
    virtual void initializeRooms() = 0;
    virtual ~Hotel();

    std::string getHotelName() const;
    int getRoomCapacity() const;
    Room** getRoomArray() const;
};

class ThreeStarHotel : public Hotel {
private:
    double stdroomRate;
    double breakfastRate;
public:
    ThreeStarHotel(const std::string& nm, int capacity, double stdRate, double brkRate);
    void initializeRooms() override;

    double getStdRoomRate() const;
    double getBreakfastRate() const;
};

class FourStarHotel : public Hotel {
private:
    double stdroomRate;
    double deluxroomRate;
public:
    FourStarHotel(const std::string& nm, int capacity, double stdRate, double dlxRate);
    void initializeRooms() override;

    double getStdRoomRate() const;
    double getDeluxRoomRate() const;
};

class FiveStarHotel : public Hotel {
private:
    double stdroomRate;
    double deluxroomRate;
    double suiteRate;
public:
    FiveStarHotel(const std::string& nm, int capacity, double stdRate, double dlxRate, double steRate);
    void initializeRooms() override;

    double getStdRoomRate() const;
    double getDeluxRoomRate() const;
    double getSuiteRate() const;
};

#endif
