#include "AirTicket.h"

AirTicket::AirTicket(const std::string& dest, const std::string& flightNum, const std::string& name, const std::string& date)
    : Ticket(dest, date, name), flightNumber(flightNum) {}

void AirTicket::display() const {
    std::cout << "Air Ticket Details:\n";
    std::cout << "Destination: " << destination << "\n";
    std::cout << "Flight Number: " << flightNumber << "\n";
    std::cout << "Passenger: " << passengerName << "\n";
    std::cout << "Departure Date: " << departureDate << "\n\n";
}

std::string AirTicket::getType() const {
    return "Air";
}

std::string AirTicket::getTicketNumber() const {
    return flightNumber;
}