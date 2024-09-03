#ifndef RESERVATION_H
#define RESERVATION_H

#include "Guest.h"

class Reservation {
private:
    static int counter;
    Guest guest;
    int reservationNo;
    int roomNo;
    double perdayCost;
    double totalCost;
public:
    Reservation();
    Reservation(Guest g, int room, double perday, double total);

    int getReservationNo() const;
    int getRoomNo() const;
    double getPerdayCost() const;
    double getTotalCost() const;

    void setReservationNo(int no);
    void setRoomNo(int room);
    void setPerdayCost(double cost);
    void setTotalCost(double cost);

    Guest getGuest() const;

    friend std::ostream& operator<<(std::ostream& os, const Reservation& reservation);
};

#endif
