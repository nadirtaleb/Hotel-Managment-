#include <iostream>
#include "ReservationManager.h"

int main() {
    srand(time(0));

    ReservationManager manager;

    // Create some hotels
    Hotel* hotel1 = new ThreeStarHotel("Three Star Hotel", 100, 100.0, 10.0);
    Hotel* hotel2 = new FourStarHotel("Four Star Hotel", 200, 150.0, 200.0);
    Hotel* hotel3 = new FiveStarHotel("Five Star Hotel", 300, 200.0, 250.0, 300.0);
    manager.insertHotel(hotel1);
    manager.insertHotel(hotel2);
    manager.insertHotel(hotel3);

    // Initialize rooms for hotels
    hotel1->initializeRooms();
    hotel2->initializeRooms();
    hotel3->initializeRooms();

    // Create some guests
    Guest guest1("John Doe", Date(7, 26, 2024), Date(8, 3, 2024), 3, "Three Star Hotel", "stdRoom", false, "", "");
    Guest guest2("Jane Smith", Date(7, 26, 2024), Date(8, 3, 2024), 5, "Five Star Hotel", "suite", false, "", "large");

    // Make reservations
    int resNo1 = manager.makeReservation(guest1);
    int resNo2 = manager.makeReservation(guest2);

    // Search reservations
    manager.search(resNo1);
    manager.search(resNo2);

    // Cancel a reservation
    manager.cancelReservation(resNo1);

    // Save expired reservations
    try {
        manager.save("archive.txt", Date(9, 1, 2024));
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Search in the archive
    try {
        manager.searchReservation("archive.txt", resNo1);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Clean up
    delete hotel1;
    delete hotel2;
    delete hotel3;

    return 0;
}
