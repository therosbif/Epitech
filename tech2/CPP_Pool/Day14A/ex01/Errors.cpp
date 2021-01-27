/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD14A-jack.goodall
** File description:
** Errors
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message,
    std::string const &component) : _message(message), _component(component)
{
}
