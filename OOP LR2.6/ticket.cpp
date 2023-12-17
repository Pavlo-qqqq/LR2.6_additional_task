#include "ticket.h"

Ticket::Ticket(const std::string& dest, const std::string& date, const std::string& name)
    : destination(dest), departureDate(date), passengerName(name) {}