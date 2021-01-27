/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD17-jack.goodall
** File description:
** Container
*/

#ifndef CONTAINER_HPP_
#define CONTAINER_HPP_

template<typename contained, class stl_container>
class contain {
    public:
        contain() = default;
        ~contain() = default;

        void push(contained const &data) {
            _container << data;
        }

    protected:
    private:
        stl_container _container;
};

#endif /* !CONTAINER_HPP_ */
