#pragma once
#include <string>

class Ticket {
public:
    std::string destination;
    std::string departureDate;
    std::string passengerName;

    Ticket(const std::string& dest, const std::string& date, const std::string& name);
    virtual ~Ticket() = default;
    virtual void display() const = 0;
    virtual std::string getType() const = 0;
    virtual std::string getTicketNumber() const = 0;
};
