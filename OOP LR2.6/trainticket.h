#pragma once
#include "Ticket.h"
#include <iostream>

class TrainTicket : public Ticket {
public:
    std::string trainNumber;

    TrainTicket(const std::string& dest, const std::string& trainNum, const std::string& name, const std::string& date);
    void display() const override;
    std::string getType() const override;
    std::string getTicketNumber() const override;
};
