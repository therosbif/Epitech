
#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

class NasaError : public std::exception
{
    public:
        NasaError(std::string const &message,
                std::string const &component = "Unknown");

        const std::string &getComponent() const { return _component; };
        const char *what() const noexcept override { return _message.data(); };

    private:
        std::string _message;
        std::string _component;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message,
                std::string const &component = "Unknown") : NasaError(message, component) {};

};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message,
                std::string const &component = "Unknown") : NasaError(message, component) {};
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message,
                std::string const &component = "Unknown") : NasaError(message, component) {};
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message) : NasaError(message, "CommunicationDevice") {};
};

#endif
