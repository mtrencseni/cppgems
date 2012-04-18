#include "Pointer.h"
#include <iostream>

/*

 Based on C++ Gems Chapter 3 by Cay S. Horstmann.
 Typed up and sanified by Marton Trencseni (mtrencseni@gmail.com).
 Doesn't work with derived pointers.
 Not thread-safe.
 
 */

class X
{
public:
    X()
    {
        std::cout << "Creating an X." << std::endl;
    }
    
    ~X()
    {
        std::cout << "Destroying an X." << std::endl;
    }
};

class Y : public X
{
public:
    Y()
    {
        std::cout << "Creating an Y." << std::endl;
    }
    
    ~Y()
    {
        std::cout << "Destroying an Y." << std::endl;
    }
};

int main()
{
    {
        Pointer<X> p = new X();
        Pointer<X> q = p;
        Pointer<X> r = q;
        p = new X();

        Pointer<Y> v = new Y();
//        r = v; // no
        std::cout << "At block end." << std::endl;
    } // pointers are destroyed as they go out of scope
    std::cout << "Exiting." << std::endl;
}
