#include "Event.h"
#include <iostream>


Event::Event(const std::string& id, const std::string& artist, const std::string& venue,
             const std::string& date, const std::string& time, double price, int availability)
    : event_id(id), artist(artist), venue(venue), date(date), time(time),
      ticket_price(price), ticket_availability(availability) {}

std::string Event::getEventDetails() const {
    return "Event ID: " + event_id + "\nArtist: " + artist + "\nVenue: " + venue +
           "\nDate: " + date + "\nTime: " + time + "\nTicket Price: $" +
           std::to_string(ticket_price) + "\nTickets Available: " + std::to_string(ticket_availability) + "\n";
}

bool Event::checkTicketAvailability(int requested_tickets) const {
    return ticket_availability >= requested_tickets;
}


void Event::updateTicketAvailability(int tickets_sold) {
    if (tickets_sold <= ticket_availability) {
        ticket_availability -= tickets_sold;
        std::cout << "Tickets sold: " << tickets_sold << ". Tickets remaining: " << ticket_availability << "\n";
    } else {
        std::cout << "Error: Not enough tickets available.\n";
    }
}


void Event::addRelatedMerchandise(const Merchandise& merchandise) {
    related_merchandise.push_back(merchandise);
    std::cout << "Related merchandise added: " << merchandise.getMerchandiseDetails() << "\n";
}


void Event::viewRelatedMerchandise() const {
    std::cout << "Related Merchandise for Event \"" << artist << "\":\n";
    for (const auto& item : related_merchandise) {
        std::cout << item.getMerchandiseDetails();
    }
}
