#include "AbstractClass.hpp"

class Base
{
    public:
        // The virtual keyword enables dynamic dispatch (usually implemented by a vtable)
        virtual void message(Success s);
        
        // Default constructor
        Base();
    
    // protected functions are only accessible to classes that inherit from this class with public
    // or protected access
    protected:
        std::string info;
        
    // friend functions can access anything inside the class, even if it's protected or private
    friend std::string getInfo(const Base* b);
    friend void setInfo(Base* b, std::string information);
};

