// This file is part of The New Aspell
// Copyright (C) 2001-2003 by Kevin Atkinson under the GNU LGPL license
// version 2.0 or 2.1.  You should have received a copy of the LGPL
// license along with this library if you did not you can find
// it at http://www.gnu.org/.

#ifndef ASPELL_VECTOR__HPP
#define ASPELL_VECTOR__HPP

#include <vector>

namespace acommon
{
  template <typename T>
  class Vector : public std::vector<T>
  {
  public:

    Vector() {}
    Vector(unsigned int s) : std::vector<T>(s) {}
    Vector(unsigned int s, const T & val) : std::vector<T>(s, val) {}

    void append(T t) {
      this->push_back(t);
    }
    void append(const T * begin, unsigned int size) {
      this->insert(this->end(), begin, begin+size);
    }
    void append(const T * begin, const T * end) {
      this->insert(this->end(), begin, end);
    }
    int alloc(int s) {
      int pos = this->size();
      this->resize(pos + s);
      return pos;
    }
    T * data()
    {
      #if __cplusplus >= 201103L
        return this->data();
      #else
        return &*this->begin();
      #endif
    }
    T * data(int pos)
    {
      #if __cplusplus >= 201103L
        return this->data() + pos;
      #else
        return &*this->begin() + pos;
      #endif
    }
    T * data_end()
    {
      #if __cplusplus >= 201103L
        return this->data() + this->size();
      #else
        return &*this->begin() + this->size();
      #endif
    }

    T * pbegin()
    {
      #if __cplusplus >= 201103L
        return this->data();
      #else
        return &*this->begin();
      #endif
    }
    T * pend()
    {
      #if __cplusplus >= 201103L
        return this->data() + this->size();
      #else
        return &*this->begin() + this->size();
      #endif
    }

    const T * pbegin() const
    {
      #if __cplusplus >= 201103L
        return this->data();
      #else
        return &*this->begin();
      #endif
    }
    const T * pend()   const
    {
      #if __cplusplus >= 201103L
        return this->data() + this->size();
      #else
        return &*this->begin() + this->size();
      #endif
    }

    template <typename U>
    U * datap() { 
      return reinterpret_cast<U * >(&this->front());
    }
    template <typename U>
    U * datap(int pos) {
      return reinterpret_cast<U * >(&this->front() + pos);
    }

    void pop_front() {this->erase(this->begin());}
    void push_front(const T & v) {this->insert(this->begin(), v);}
  };
}

#endif
