// an enum class is like an enum, but strongly typed
enum class Success
{
    success = 0
};


class Base
{
    public:
        // The virtual keyword enables dynamic dispatch (usually implemented by a vtable)
        virtual void message(Success s);
        
        // Default constructor
        Base();
    
    protected:
        std::string info;
        
        
    friend std::string getInfo(const Base* b);
    friend void setInfo(Base* b, std::string information);
};

