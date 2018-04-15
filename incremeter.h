#ifndef _INCREMETER_H_INCLUDED_
#define _INCREMETER_H_INCLUDED_

#include <atomic>
#include <limits>
#include <type_traits>

using namespace std;


/** @class Incrementer
 * @brief thread-safe class for autoincrement
 */
template <typename T>
class Incrementer
{
public:
    Incrementer();
    Incrementer(const T& value, const T& max_value);
    T get_current() const;
    void next();
    T get_next();
    void set_value(const T& value);
    void set_max(const T& maximum);
private:
    atomic<T> val {0};
    atomic<T> max_val {std::numeric_limits<T>::max()};
};

template <typename T>
Incrementer<T>::Incrementer():val {0}
{
    static_assert(std::is_integral<T>::value, "unsigned integral type required.");
    static_assert(std::is_unsigned<T>::value, "unsigned integral type required.");
}

template <typename T>
Incrementer<T>::Incrementer(const T& value, const T& max_value): val {value}, max_val {max_value}
{
    static_assert(std::is_integral<T>::value, "unsigned integral type required.");
    static_assert(std::is_unsigned<T>::value, "unsigned integral type required.");
}


template <typename T>
T Incrementer<T>::get_current() const
{
    return val;
}

template <typename T>
void Incrementer<T>::next()
{
    T v = val;
    if(v >= max_val || val == numeric_limits<T>::max())
        val = static_cast<T>(0);
    else ++val;
}

template <typename T>
T Incrementer<T>::get_next()
{
    next();
    return get_current();
}

template <typename T>
void Incrementer<T>::set_value(const T& value)
{
    val = value;
}

template <typename T>
void Incrementer<T>::set_max(const T& maximum)
{
    max_val = maximum;
    if(val > maximum)
        val = maximum;
}

#endif // _INCREMETER_H_INCLUDED_
