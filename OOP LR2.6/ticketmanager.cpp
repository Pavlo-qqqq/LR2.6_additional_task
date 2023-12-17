#include "TicketManager.h"
#include "AirTicket.h"
#include "TrainTicket.h"
#include <iostream>
#include <fstream>

void TicketManager::addTicket(std::unique_ptr<Ticket> ticket) {
    ticketList.push_back(std::move(ticket));
}

bool TicketManager::removeTicket(const std::string& ticketNumber, const std::string& departureDate) {
    size_t initialSize = ticketList.size();

    ticketList.remove_if([ticketNumber, departureDate](const std::unique_ptr<Ticket>& ticket) {
        return ticket->getTicketNumber() == ticketNumber && ticket->departureDate == departureDate;
        });

    return (ticketList.size() < initialSize);
}

void TicketManager::displayTicketByTicketNumberAndDate(const std::string& ticketNumber, const std::string& departureDate) const {
    std::cout << "Ticket " << ticketNumber << " on " << departureDate << ":\n";
    for (const auto& ticket : ticketList) {
        if (ticket->getTicketNumber() == ticketNumber && ticket->departureDate == departureDate) {
            std::cout << "Destination: " << ticket->destination << "\n";
            std::cout << "Passenger: " << ticket->passengerName << "\n\n";
        }
    }
}

void TicketManager::displayAllTickets() const {
    std::cout << "All Air Tickets:\n\n";
    for (const auto& tickets : ticketList) {
        std::cout << "Ticket Type: " << tickets->getType() << "\n";
        std::cout << "Destination: " << tickets->destination << "\n";
        std::cout << "Ticket Number: " << tickets->getTicketNumber() << "\n";
        std::cout << "Passenger: " << tickets->passengerName << "\n";
        std::cout << "Departure Date: " << tickets->departureDate << "\n\n";
    }
}

void TicketManager::displayAirTickets() const {
    for (const auto& ticket : ticketList) {
        // Перевіряємо, чи квиток є типу AirTicket перед викликом display()
        if (dynamic_cast<AirTicket*>(ticket.get())) {
            // Виклик методу display() для AirTicket
            ticket->display(); 
        }
    }
}

void TicketManager::displayTrainTickets() const {
    for (const auto& ticket : ticketList) {
        // Перевіряємо, чи квиток є типу TrainTicket перед викликом display()
        if (dynamic_cast<TrainTicket*>(ticket.get())) {
            // Виклик методу display() для TrainTicket
            ticket->display(); 
        }
    }
}

void TicketManager::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    for (const auto& tickets : ticketList) {
        outFile << tickets->destination << "," << tickets->getTicketNumber() << ","
            << tickets->passengerName << "," << tickets->departureDate << "\n";
    }
    outFile.close();
    std::cout << "Data saved to " << filename << std::endl;
}

void TicketManager::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cout << "Open file Error: " << filename << std::endl;
        return;
    }

    std::string dest, ticketNum, name, date;
    while (getline(inFile, dest, ',') && getline(inFile, ticketNum, ',') &&
        getline(inFile, name, ',') && getline(inFile, date)) {
        // Створюємо авіаквиток чи квиток на потяг залежно від типу запису в файлі
        if (ticketNum.substr(0, 2) == "FL") {
            ticketList.emplace_back(std::make_unique<AirTicket>(dest, ticketNum, name, date));
        }
        else if (ticketNum.substr(0, 2) == "TN") {
            ticketList.emplace_back(std::make_unique<TrainTicket>(dest, ticketNum, name, date));
        }
    }

    inFile.close();
    std::cout << "Data loaded from: " << filename << std::endl;
}
