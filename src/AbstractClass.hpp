// an enum class is like an enum, but strongly typed
enum class Success
{
    success = 0
};


// AbstractClass is an abstract class; abstract classes are interfaces. They only have pure virtual
// functions. You can't use an abstract class to instantiate an object of that abstract class; you
// have to first implement the virtual functions inside of the abstract class.
class AbstractClass
{
    public:
        // This is a pure virtual function; it has no implementation in this class.
        virtual void message(Success s);
};
