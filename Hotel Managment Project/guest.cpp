#include "Guest.h"

Guest::Guest() : guestName(""), checkinDate(Date()), checkoutDate(Date()), starRate(0), hotelName(""), roomType(""), extraBed(false), view(""), suiteSize("") {}

Guest::Guest(std::string name, Date checkin, Date checkout, int star, std::string hotel, std::string room, bool bed, std::string vw, std::string size)
    : guestName(name), checkinDate(checkin), checkoutDate(checkout), starRate(star), hotelName(hotel), roomType(room), extraBed(bed), view(vw), suiteSize(size) {}

std::string Guest::getGuestName() const { return guestName; }
Date Guest::getCheckinDate() const { return checkinDate; }
Date Guest::getCheckoutDate() const { return checkoutDate; }
int Guest::getStarRate() const { return starRate; }
std::string Guest::getHotelName() const { return hotelName; }
std::string Guest::getRoomType() const { return roomType; }
bool Guest::getExtraBed() const { return extraBed; }
std::string Guest::getView() const { return view; }
std::string Guest::getSuiteSize() const { return suiteSize; }

void Guest::setGuestName(std::string name) { guestName = name; }
void Guest::setCheckinDate(Date checkin) { checkinDate = checkin; }
void Guest::setCheckoutDate(Date checkout) { checkoutDate = checkout; }
void Guest::setStarRate(int star) { starRate = star; }
void Guest::setHotelName(std::string hotel) { hotelName = hotel; }
void Guest::setRoomType(std::string room) { roomType = room; }
void Guest::setExtraBed(bool bed) { extraBed = bed; }
void Guest::setView(std::string vw) { view = vw; }
void Guest::setSuiteSize(std::string size) { suiteSize = size; }

std::ostream& operator<<(std::ostream& os, const Guest& guest) {
    os << "Guest Name: " << guest.guestName << "\nCheck-in Date: " << guest.checkinDate << "\nCheck-out Date: " << guest.checkoutDate 
       << "\nStar Rate: " << guest.starRate << "\nHotel Name: " << guest.hotelName << "\nRoom Type: " << guest.roomType 
       << "\nExtra Bed: " << (guest.extraBed ? "Yes" : "No") << "\nView: " << guest.view << "\nSuite Size: " << guest.suiteSize;
    return os;
}
