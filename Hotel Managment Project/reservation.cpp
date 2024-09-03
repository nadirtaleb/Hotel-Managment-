#include "Reservation.h"

int Reservation::counter = 1;

Reservation::Reservation() : guest(Guest()), reservationNo(counter++), roomNo(0), perdayCost(0.0), totalCost(0.0) {}

Reservation::Reservation(Guest g, int room, double perday, double total)
    : guest(g), reservationNo(counter++), roomNo(room), perdayCost(perday), totalCost(total) {}

int Reservation::getReservationNo() const { return reservationNo; }
int Reservation::getRoomNo() const { return roomNo; }
double Reservation::getPerdayCost() const { return perdayCost; }
double Reservation::getTotalCost() const { return totalCost; }

void Reservation::setReservationNo(int no) { reservationNo = no; }
void Reservation::setRoomNo(int room) { roomNo = room; }
void Reservation::setPerdayCost(double cost) { perdayCost = cost; }
void Reservation::setTotalCost(double cost) { totalCost = cost; }

Guest Reservation::getGuest() const { return guest; }

std::ostream& operator<<(std::ostream& os, const Reservation& reservation) {
    os << "Reservation No: " << reservation.reservationNo << "\nGuest: " << reservation.guest << "\nRoom No: " << reservation.roomNo 
       << "\nPer Day Cost: " << reservation.perdayCost << "\nTotal Cost: " << reservation.totalCost;
    return os;
}
