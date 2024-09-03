#include "Room.h"

Room::Room(int no) : roomNo(no) {
    for (int i = 0; i < 360; ++i) {
        availabilityArray[i] = true;
    }
}

Room::~Room() {
    std::cout << "Room " << roomNo << " deleted." << std::endl;
}

int Room::getRoomNo() const { return roomNo; }
void Room::setRoomNo(int no) { roomNo = no; }
bool* Room::getAvailabilityArray() { return availabilityArray; }
void Room::setAvailabilityArray(const bool availability[]) {
    for (int i = 0; i < 360; ++i) {
        availabilityArray[i] = availability[i];
    }
}

StdRoom::StdRoom(int no) : Room(no), extraBed(false) {}

bool StdRoom::getExtraBed() const { return extraBed; }
void StdRoom::setExtraBed(bool bed) { extraBed = bed; }

void StdRoom::print() const {
    std::cout << "StdRoom No: " << roomNo << ", Extra Bed: " << (extraBed ? "Yes" : "No") << std::endl;
}

DeluxRoom::DeluxRoom(int no, const std::string& vw) : Room(no), view(vw) {}

std::string DeluxRoom::getView() const { return view; }
void DeluxRoom::setView(const std::string& vw) { view = vw; }

void DeluxRoom::print() const {
    std::cout << "DeluxRoom No: " << roomNo << ", View: " << view << std::endl;
}

Suite::Suite(int no, const std::string& size) : Room(no), suiteSize(size) {}

std::string Suite::getSuiteSize() const { return suiteSize; }
void Suite::setSuiteSize(const std::string& size) { suiteSize = size; }

void Suite::print() const {
    std::cout << "Suite No: " << roomNo << ", Size: " << suiteSize << std::endl;
}
