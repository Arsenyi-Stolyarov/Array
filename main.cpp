template <typename = void, int ...>

class Array;


template <>

class Array <>
{
    template <typename, int ...> friend class Array;
    template <int, typename ...>        class Heart;
};


template <typename X, int I, int ... L>

class Array <X, I, L ...> : public Array <Array <X, L ...>, I>
{
    using Array <Array <X, L ...>, I> :: Array;
};


template <typename X, int I>

class Array <X, I> : public Array <> :: Heart <I, X>
{
    using Array <> :: Heart <I, X> :: Heart;
};


template <int I, typename X, typename ... L>

struct Array <> :: Heart <I, X, L ...> : public Heart <I - 1, X, X, L ...>
{
    using Heart <I - 1, X, X, L ...> :: Heart;
};


template <typename X, typename ... L>

class Array <> :: Heart <0, X, L ...>
{

    X x [sizeof ... (L)];

public:

    Heart () = default;

    Heart (L ... l) : x {l ...} {}


    operator const X * () const { return x; }

    operator       X * ()       { return x; }

};


int main ()
{
    Array <double, 3> a_1 = { 1.0, 2.0, 3.0 };

    Array <double, 2, 3> a_2 = { { 4.0, 5.0, 6.0 },
                                 { 7.0, 8.0, 9.0 } };

    a_2[0] = a_1;

    a_2[1] = { 0.1, 1.1, 2.1 };

    return 0;
}
