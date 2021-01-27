
#ifndef REF_PTR_HPP_
#define REF_PTR_HPP_

#include <cstddef>
#include "BaseComponent.hpp"

class RefPtr
{
    public:
        RefPtr(BaseComponent *rawPtr = nullptr);
        RefPtr(RefPtr const &other);
        RefPtr &operator=(RefPtr const &other);
        ~RefPtr() = default;

        RefPtr &operator=(BaseComponent *other);

        BaseComponent *get() const { return _rawPtr; };

    private:
        BaseComponent *_rawPtr;
};

#endif // REF_PTR_HPP_
