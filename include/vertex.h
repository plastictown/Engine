/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#ifndef __VERTEX_H_INCLUDED__
#define __VERTEX_H_INCLUDED__

#include <type_traits>
#include <initializer_list>
#include <array>
#include <exception>

template <typename T, size_t n_coords>
class vertex {
  public:
    /// default ctor
    vertex<T, n_coords>();
    /// ctor with n_coords values in il
    vertex<T, n_coords>(const std::initializer_list<T>&);
    /// set value val by index vnum
    void setAt(size_t vnum, const T& val);
    /// get value by index vnum
    T& getAt(size_t vnum);
  protected:
    std::array<T, n_coords> coords;
};

template <typename T, size_t n_coords>
vertex<T, n_coords>::vertex() {
    static_assert( n_coords > 1, "too few coordinates! should be 2 or more");
    static_assert(std::is_arithmetic
                  <typename std::remove_cv
                  < typename std::remove_reference
                  <T>::type>::type>::value,
                  "values must have an arithmetic type!");
    coords.fill(0);
}

template <typename T, size_t n_coords>
vertex<T, n_coords>::vertex(const std::initializer_list<T>& il)
    : vertex<T, n_coords>() {
    if(il.size() != n_coords)
        throw std::invalid_argument("vertex::ctor(): incorrect number of vertex coordinates");
    size_t ctr = 0u;
    for(auto& i : il)
        coords[ctr++] = i;
}

template <typename T, size_t n_coords>
void vertex<T, n_coords>::setAt(size_t vnum, const T& val) {
    if(vnum >= n_coords)
        throw std::invalid_argument("vertex::setv(): invalid index");
    coords[vnum] = val;
}

template <typename T, size_t n_coords>
T& vertex<T, n_coords>::getAt(size_t vnum) {
    if(vnum >= n_coords)
        throw std::invalid_argument("vertex::getv(): invalid index");
    return coords[vnum];
}

#endif // __VERTEX_H_INCLUDED__
