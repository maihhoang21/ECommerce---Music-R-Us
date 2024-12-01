#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>
#include "Merchandise.h"

class Event {
private:
    std::string event_id;
    std::string artist;
    std::string venue;
    std::string date;
    std::string time;
    double ticket_price;
    int ticket_availability;
    std::vector<Merchandise> related_merchandise;

public:
    Event(const std::string& id, const std::string& artist, const std::string& venue,
          const std::string& date, const std::string& time, double price, int availability);

    // Methods
    std::string getEventDetails() const;
    bool checkTicketAvailability(int requested_tickets) const;
    void updateTicketAvailability(int tickets_sold);
    void addRelatedMerchandise(const Merchandise& merchandise);
    void viewRelatedMerchandise() const;
};

#endif 
