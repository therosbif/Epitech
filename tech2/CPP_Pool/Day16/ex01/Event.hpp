/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-jack.goodall
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <list>
#include <string>

class Event {
    public:
        Event() = default;
        Event(unsigned int time, const std::string &event);
        ~Event() = default;
        Event(const Event &);
        Event &operator=(const Event &) = default;

        unsigned int getTime() const { return _time; };
        const std::string &getEvent() const { return _event; };
        void setTime(unsigned int time) { _time = time; };
        void setEvent(const std::string &event) { _event = event; };

    protected:
    private:
        unsigned int _time;
        std::string _event;
};

#endif /* !EVENT_HPP_ */
