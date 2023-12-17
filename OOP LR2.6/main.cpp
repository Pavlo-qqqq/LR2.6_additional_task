#include <iostream>
#include "TicketManager.h"
#include "AirTicket.h"
#include "TrainTicket.h"

int main() {
    TicketManager ticketManager;
    std::string filename = "ticket_data.txt";

    ticketManager.loadFromFile(filename);

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add Ticket\n";
        std::cout << "2. Remove Ticket\n";
        std::cout << "3. Display Ticket by Ticket Number and Date\n";
        std::cout << "4. Display All Tickets\n";
        std::cout << "5. Display Air Tickets\n";
        std::cout << "6. Display Train Tickets\n";
        std::cout << "7. Save Data to File\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string dest, ticketNum, name, date;
            std::cin.ignore();
            std::cout << "Choose ticket type:\n1.Air Ticket \n2.Train Ticket\n";
            int ticketType;
            std::cin >> ticketType;
            if (ticketType != 1 && ticketType != 2)
            {
                std::cout << "Error. Wrong ticket type choose.";
                break;
            }
            std::cin.ignore();
            std::cout << "Enter Destination: ";
            getline(std::cin, dest);
            std::cout << "Enter Ticket Number: ";
            getline(std::cin, ticketNum);
            std::cout << "Enter Passenger Name: ";
            getline(std::cin, name);
            std::cout << "Enter Departure Date: ";
            getline(std::cin, date);
            if (ticketType == 1)
            {
                ticketNum = "FL" + ticketNum;
                std::unique_ptr<Ticket> ticket = std::make_unique<AirTicket>(dest, ticketNum, name, date);
                ticketManager.addTicket(std::move(ticket));
            }
            else
            {
                ticketNum = "TN" + ticketNum;
                std::unique_ptr<Ticket> ticket = std::make_unique<TrainTicket>(dest, ticketNum, name, date);
                ticketManager.addTicket(std::move(ticket));
            }
            break;
        }
        case 2: {
            std::string ticketNum, date;
            std::cout << "Enter Ticket Number: ";
            std::cin >> ticketNum;
            std::cout << "Enter Departure Date: ";
            std::cin >> date;
            bool removed = ticketManager.removeTicket(ticketNum, date);
            if (removed) {
                std::cout << "Ticket successfully removed.\n";
            }
            else {
                std::cout << "Ticket not found or couldn't be removed.\n";
            }
            break;
        }
        case 3: {
            std::string ticketNum, date;
            std::cout << "Enter Ticket Number: ";
            std::cin >> ticketNum;
            std::cout << "Enter Departure Date: ";
            std::cin >> date;
            ticketManager.displayTicketByTicketNumberAndDate(ticketNum, date);
            break;
        }
        case 4:
            ticketManager.displayAllTickets();
            break;
        case 5:
            ticketManager.displayAirTickets();
            break;
        case 6:
            ticketManager.displayTrainTickets();
            break;
        case 7:
            ticketManager.saveToFile(filename);
            break;
        case 8:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 8);

    return 0;
}