# Hotel Management Project

## Overview
This C++ Hotel Management Project demonstrates object-oriented programming principles and dynamic memory management using pointers. The program creates instances of different types of hotels and guest reservations using hardcoded data to ensure a clear demonstration of the core features.

## Features
- **Multiple Hotel Types**: The program simulates Three-Star, Four-Star, and Five-Star hotels.
- **Room Types**: Supports standard rooms, deluxe rooms, and suites.
- **Reservations**: The program creates and manages reservations for predefined guests.

## Getting Started

### 1. Clone the RepositoryAAA
```bash
git clone https://github.com/nadirtaleb/Hotel-Managment-.git
cd Hotel-Managment-


2. Compile the Project
To compile the project, use the following command in your terminal:
g++ -o hotel_management main.cpp Date.cpp Room.cpp Hotel.cpp Guest.cpp Reservation.cpp ReservationManager.cpp
This will produce an executable named hotel_management.

3. Run the Program
After compiling, run the executable with:
./hotel_management


4. What the Program Does
Hotel Initialization: The program initializes three types of hotels: Three-Star, Four-Star, and Five-Star.
Guest Creation: Two guests are created with predefined check-in and check-out dates.
Reservation Management: Reservations are automatically made for the guests in the appropriate hotels.
Output: The program outputs reservation details, searches for specific reservations, and demonstrates cancellation.


5. Key Concepts Demonstrated
Polymorphism: Different types of rooms are managed using a base Room pointer.
Dynamic Memory Management: Hotels and reservations are dynamically allocated and deallocated.
Encapsulation: The program encapsulates hotel and guest management logic within classes.
