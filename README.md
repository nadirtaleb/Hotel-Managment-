# Hotel Management Project

## Overview
This C++ Hotel Management Project demonstrates object-oriented programming principles and dynamic memory management using pointers. The program creates instances of different types of hotels and guest reservations using hardcoded data to ensure a clear demonstration of the core features.

## Features
- **Multiple Hotel Types**: The program simulates Three-Star, Four-Star, and Five-Star hotels.
- **Room Types**: Supports standard rooms, deluxe rooms, and suites.
- **Reservations**: The program creates and manages reservations for predefined guests.

## How to Run
- Clone the repository Using Git
- Compile using this command g++ -o hotel_management main.cpp Date.cpp Room.cpp Hotel.cpp Guest.cpp Reservation.cpp ReservationManager.cpp
- After compiling, run the executable with ./hotel_management


## Key Concepts Demonstrated
- **Polymorphism:**: Different types of rooms are managed using a base Room pointer.
- **Dynamic Memory Management**: Hotels and reservations are dynamically allocated and deallocated.
- **Encapsulation**: The program encapsulates hotel and guest management logic within classes..
