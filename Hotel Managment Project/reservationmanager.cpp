#include "ReservationManager.h"
#include <iostream>

ReservationManager::ReservationManager() : noReservation(0) {
    for (int i = 0; i < 200; ++i) hotelArray[i] = nullptr;
    for (int i = 0; i < 1000; ++i) reservationArray[i] = nullptr;
}

bool ReservationManager::insertHotel(Hotel* hotel) {
    for (int i = 0; i < 200; ++i) {
        if (hotelArray[i] == nullptr) {
            hotelArray[i] = hotel;
            return true;
        }
    }
    return false;
}

int ReservationManager::makeReservation(Guest& guest) {
    for (int i = 0; i < 200; ++i) {
        if (hotelArray[i] && hotelArray[i]->getHotelName() == guest.getHotelName()) {
            for (int j = 0; j < hotelArray[i]->getRoomCapacity(); ++j) {
                Room* room = hotelArray[i]->getRoomArray()[j];
                bool* availability = room->getAvailabilityArray();
                bool isAvailable = true;
                for (int k = guest.getCheckinDate().getDay(); k < guest.getCheckoutDate().getDay(); ++k) {
                    if (!availability[k]) {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable) {
                    for (int k = guest.getCheckinDate().getDay(); k < guest.getCheckoutDate().getDay(); ++k) {
                        availability[k] = false;
                    }
                    double perdayCost = 100; // Simplified cost calculation
                    double totalCost = perdayCost * (guest.getCheckoutDate().getDay() - guest.getCheckinDate().getDay());
                    if (guest.getRoomType() == "stdRoom" && guest.getExtraBed()) {
                        perdayCost *= 1.1; // Adding extra bed cost
                    }
                    if (guest.getRoomType() == "suite") {
                        if (guest.getSuiteSize() == "medium") {
                            perdayCost *= 1.5;
                        } else if (guest.getSuiteSize() == "large") {
                            perdayCost *= 2.0;
                        }
                    }
                    Reservation* res = new Reservation(guest, room->getRoomNo(), perdayCost, totalCost);
                    insert(res);
                    return res->getReservationNo();
                }
            }
        }
    }
    return 0; // No available room found
}

bool ReservationManager::insert(Reservation* reservation) {
    if (noReservation < 1000) {
        reservationArray[noReservation++] = reservation;
        return true;
    }
    return false;
}

void ReservationManager::search(int reservationNo) {
    for (int i = 0; i < noReservation; ++i) {
        if (reservationArray[i]->getReservationNo() == reservationNo) {
            std::cout << *reservationArray[i] << std::endl;
            return;
        }
    }
    std::cout << "Reservation not found." << std::endl;
}

bool ReservationManager::cancelReservation(int reservationNo) {
    for (int i = 0; i < noReservation; ++i) {
        if (reservationArray[i]->getReservationNo() == reservationNo) {
            delete reservationArray[i];
            reservationArray[i] = reservationArray[--noReservation];
            reservationArray[noReservation] = nullptr;
            return true;
        }
    }
    return false;
}

void ReservationManager::save(const std::string& archive, const Date& date) {
    std::ofstream outFile(archive, std::ios::app);
    if (!outFile) {
        throw std::runtime_error("File cannot be opened");
    }

    for (int i = 0; i < noReservation; ++i) {
        if (date > reservationArray[i]->getGuest().getCheckoutDate()) {
            outFile << *reservationArray[i] << std::endl;
        }
    }
}

bool ReservationManager::searchReservation(const std::string& archive, int reservationNo) {
    std::ifstream inFile(archive);
    if (!inFile) {
        throw std::runtime_error("File cannot be opened");
    }

    int no;
    while (inFile >> no) {
        if (no == reservationNo) {
            std::cout << "Reservation No: " << no << " found in archive." << std::endl;
            return true;
        }
    }
    return false;
}
