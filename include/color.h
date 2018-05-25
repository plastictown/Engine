#ifndef __COLOR_H__
#define __COLOR_H__

#include <type_traits>
#include <initializer_list>
#include <array>
#include <exception>


template <typename T, size_t n_colorCount>
class color {
  public:
    /// defaut ctor
    color<T, n_colorCount>();
    color<T, n_colorCount> (const std::initializer_list<T> &);

  private:

};

#endif  //__COLOR_H__
