#ifndef  ARRAY_H
#define  ARRAY_H


template <typename = void, int ...>

class Array; // Class declaration


template <>

class Array <> // Specialization that acts like private namespace with auxiliary classes
{

    template <typename, int ...> friend class Array; // Grants access to all class definitions

    template <int, typename ...>        class Heart; // Core class declaration

};


template <typename X, int I, int ... L>

class Array <X, I, L ...> : public Array <Array <X, L ...>, I> // n - dimensional array is an array of n-1 - dimensional arrays
{
    using Array <Array <X, L ...>, I> :: Array; // Inherits base constructor
};


template <typename X, int I>

class Array <X, I> : public Array <> :: Heart <I, X> // one - dimensional array inherits from private core class
{
    using Array <> :: Heart <I, X> :: Heart; // Inherits base constructor
};


template <int I, typename X, typename ... L>

class Array <> :: Heart <I, X, L ...> : public Array <> :: Heart <I - 1, X, X, L ...> // Core class that has a constructor with number of arguments equal to the size of the array
{
    using Array <> :: Heart <I - 1, X, X, L ...> :: Heart; // Inherits base constructor
};


template <typename X, typename ... L>

class Array <> :: Heart <0, X, L ...> // Core class that acts like pointer to static array.
{

    X x [sizeof ... (L)];

public:

    Heart () = default;

    Heart (L ... l) : x {l ...} {}


    operator const X * () const { return x; }

    operator       X * ()       { return x; }

};


#endif //ARRAY_H
