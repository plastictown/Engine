#ifndef __COLOR_H__
#define __COLOR_H__

#include <type_traits>
#include <initializer_list>
#include <array>
#include <vector>
#include <exception>

typedef unsigned char uchar;

template <typename T, size_t N>
class color {
  public:
    /// defaut ctor
    color<T, N>();
    color<T, N> (const std::initializer_list<T> & col);
    void set(const std::initializer_list<T>& col );
    void setAt(const size_t index, T&value);
    T& get(const size_t index);

  protected:
    std::array<T, N> colors;


  private:

};

#endif  //__COLOR_H__
