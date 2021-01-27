/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** ConveyorBelt
*/

#ifndef CONVEYORBELT_HPP_
#define CONVEYORBELT_HPP_

#include "../Toys/Object.hpp"
#include "../Wrap/Wrap.hpp"

class IConveyorBelt {
    public:
        virtual void in(const std::string &) = 0;
        virtual void out() = 0;
        virtual Object *take() = 0;
        virtual bool put(Object *) = 0;
    protected:
    private:
};

class PapaXmasConveyorBelt : public IConveyorBelt {
    public:
        PapaXmasConveyorBelt();
        ~PapaXmasConveyorBelt();
        void in(const std::string &);
        void out();
        Object *take();
        bool put(Object *);
    protected:
        Object *_object;
        int _input;
        int _output;
    private:
};

class ConveyorBeltRand : public PapaXmasConveyorBelt {
    public:
        ConveyorBeltRand();
        ~ConveyorBeltRand();
        void in(const std::string &);
        void out() override;
};

#endif /* !CONVEYORBELT_HPP_ */
