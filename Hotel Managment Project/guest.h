#ifndef GUEST_H
#define GUEST_H

#include "Date.h"
#include <string>
#include <iostream>

class Guest {
private:
    std::string guestName;
    Date checkinDate;
    Date checkoutDate;
    int starRate;
    std::string hotelName;
    std::string roomType;
    bool extraBed;
    std::string view;
    std::string suiteSize;
public:
    Guest();
    Guest(std::string name, Date checkin, Date checkout, int star, std::string hotel, std::string room, bool bed, std::string vw, std::string size);

    std::string getGuestName() const;
    Date getCheckinDate() const;
    Date getCheckoutDate() const;
    int getStarRate() const;
    std::string getHotelName() const;
    std::string getRoomType() const;
    bool getExtraBed() const;
    std::string getView() const;
    std::string getSuiteSize() const;

    void setGuestName(std::string name);
    void setCheckinDate(Date checkin);
    void setCheckoutDate(Date checkout);
    void setStarRate(int star);
    void setHotelName(std::string hotel);
    void setRoomType(std::string room);
    void setExtraBed(bool bed);
    void setView(std::string vw);
    void setSuiteSize(std::string size);

    friend std::ostream& operator<<(std::ostream& os, const Guest& guest);
};

#endif
