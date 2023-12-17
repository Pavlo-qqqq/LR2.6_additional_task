#pragma once
#include "Ticket.h"
#include <iostream>

class AirTicket : public Ticket {
public:
    std::string flightNumber;

    AirTicket(const std::string& dest, const std::string& flightNum, const std::string& name, const std::string& date);
    void display() const override;
    std::string getType() const override;
    std::string getTicketNumber() const override;
};