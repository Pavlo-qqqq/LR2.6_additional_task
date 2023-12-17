#pragma once
#include "Ticket.h"
#include <list>
#include <memory>

class TicketManager {
private:
    std::list<std::unique_ptr<Ticket>> ticketList;

public:
    void addTicket(std::unique_ptr<Ticket> ticket);
    bool removeTicket(const std::string& ticketNumber, const std::string& departureDate);
    void displayTicketByTicketNumberAndDate(const std::string& ticketNumber, const std::string& departureDate) const;
    void displayAllTickets() const;
    void displayAirTickets() const;
    void displayTrainTickets() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
