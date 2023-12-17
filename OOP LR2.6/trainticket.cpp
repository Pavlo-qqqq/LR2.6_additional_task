#include "TrainTicket.h"

TrainTicket::TrainTicket(const std::string& dest, const std::string& trainNum, const std::string& name, const std::string& date)
    : Ticket(dest, date, name), trainNumber(trainNum) {}

void TrainTicket::display() const {
    std::cout << "Train Ticket Details:\n";
    std::cout << "Destination: " << destination << "\n";
    std::cout << "Train Number: " << trainNumber << "\n";
    std::cout << "Passenger: " << passengerName << "\n";
    std::cout << "Departure Date: " << departureDate << "\n\n";
}

std::string TrainTicket::getType() const {
    return "Train";
}

std::string TrainTicket::getTicketNumber() const {
    return trainNumber;
}