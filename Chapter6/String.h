#ifndef STRING_H
#define STRING_H

#include <cassert>
#include <cstring>
#include <iostream>

class String
{
private:
    class StringBody
    {
        friend class String;
        StringBody(const char* str_)
        {
            std::cout << "Creating new body" << std::endl;
            count = 1;
            str = new char[strlen(str_) + 1];
            strcpy(str, str_);
        }
        ~StringBody()
        {
            std::cout << "Deleting body" << std::endl;
            delete str;
        }
        
        char*   str;
        int     count;
    };
    
    StringBody* body;
    
public:
    String()
    {
        body = new StringBody("");
    }
    
    String(const String& other)
    {
        body = other.body;
        body->count++;
    }
    
    String(const char* str)
    {
        body = new StringBody(str);
    }
    
    ~String()
    {
        body->count--;
        assert(body->count >= 0);
        if (body->count == 0)
            delete body;
    }
    
    String& operator=(const String& other)
    {
        body->count--;
        assert(body->count >= 0);
        if (body->count == 0)
            delete body;
        body = other.body;
        body->count++;
        return *this;
    }

    String& operator=(const char* str)
    {
        body->count--;
        assert(body->count >= 0);
        if (body->count == 0)
            delete body;
        body = new StringBody(str);
        return *this;
    }
};

#endif
