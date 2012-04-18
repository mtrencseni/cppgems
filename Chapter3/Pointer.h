#ifndef POINTER_H
#define POINTER_H

#include <stddef.h>
#include <cassert>

template<class T>
class Pointer
{
public:
    Pointer()
    {
        rc = NULL;
    }
    
    Pointer(T* t)
    {
        rc = new RefCount(t);
    }

    Pointer(const Pointer& other)
    {
        rc = other.rc;
        if (rc)
            rc->count++;
    }
    
    const Pointer& operator=(const Pointer& other)
    {
        if (other.rc)
            other.rc->count++;
        Free();
        rc = other.rc;
        return *this;
    }
    
    ~Pointer()
    {
        Free();
    }
    
    T* operator->()
    {
        assert(rc);
        return rc->obj;
    }
    
    const T* operator-> () const
    {
        assert(rc);
        return rc->obj;        
    }
    
    T& operator*()
    {
        assert(rc);
        return rc->obj;        
    }
    
    const T& operator*() const
    {
        assert(rc);
        return rc->obj;        
    }
    
    operator const void*() const
    {
        if (rc)
            return this;
        else
            return NULL;
    }
        
private:
        
    struct RefCount
    {
        T*  obj;
        int count;
        
        RefCount(T* obj_)
        {
            assert(obj_);
            obj = obj_;
            count = 1;
        }
        
        ~RefCount()
        {
            assert(count == 0);
            delete obj;
        }
    };
    
    RefCount* rc;

    void Free()
    {
        if (rc)
        {
            rc->count--;
            if (rc->count == 0)
                delete rc;
        }
    }
};

#endif
