#include "Base.hpp"

class Subclass : public Base
{
    public:
        // The override keyword explicitly confirms that the message function is overriding a
        // virtual function from the Base class.
        void message(Success s) override;
        
        Subclass();
        
        // Make this class non-copyable by deleting the copy constructor and the assignment operator.
        Subclass(const Subclass& other) = delete;
        Subclass& operator=(const Subclass& other) = delete;
};

