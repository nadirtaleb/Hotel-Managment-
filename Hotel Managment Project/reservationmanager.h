#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include "Hotel.h"
#include "Reservation.h"
#include <stdexcept>
#include <fstream>

class ReservationManager {
private:
    Hotel* hotelArray[200];
    Reservation* reservationArray[1000];
    int noReservation;
public:
    ReservationManager();

    bool insertHotel(Hotel* hotel);
    int makeReservation(Guest& guest);
    bool insert(Reservation* reservation);
    void search(int reservationNo);
    bool cancelReservation(int reservationNo);
    void save(const std::string& archive, const Date& date);
    bool searchReservation(const std::string& archive, int reservationNo);
};

#endif
