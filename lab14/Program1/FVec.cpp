#include "FVec.h"

FVec::FVec(int start, int end) {
  _size = abs(end - start);
  _arr = new int[_size];
  _begin = start;
  _end = end;
}

FVec::FVec(std::function<int(int)> gen, int size) {
  _size = size;
  _arr = new int[_size];
  for (int i = 0; i < _size; i++) {
    _arr[i] = gen(i + 1);
  }
  _begin = 0;
  _end = _size;
}

FVec::FVec(const FVec &copiedObject) { copy(copiedObject); }

FVec::FVec(FVec &&movedObject) { move(std::move(movedObject)); }

FVec::~FVec() { delete[] _arr; }



FVec &FVec::set(int index, int value) {
  _arr[index] = value;
  return *this;
}

int FVec::begin() const { return _begin; }
int FVec::end() const { return _end; }




std::ostream &operator<<(std::ostream &stream, const FVec &fvec) {
  stream << "idx[" << fvec._begin << "," << fvec._end << "] ";
  for (int i = 0; i < fvec._size; i++) {
    stream << fvec._arr[i] << " "; // valgrind error
  }
  return stream;
}

int &FVec::operator[](int n) { return _arr[n - _begin]; }

FVec &FVec::operator=(const FVec &copiedObject) {
  delete[] _arr;
  copy(copiedObject);
  return *this;
}

FVec &FVec::operator=(FVec &&movedObject) {
  // if(this != &movedObject){
  delete[] _arr;
  move(std::move(movedObject));
  // }
  return *this;
}




FVec FVec::create(int size) { return FVec(0, size); }


void FVec::move(FVec &&movedObject) {
  _size = std::__exchange(movedObject._size, 0);
  _arr = std::__exchange(movedObject._arr, nullptr);
  _begin = std::__exchange(movedObject._begin, 0);
  _end = std::__exchange(movedObject._end, 0);
}

void FVec::copy(const FVec &copiedObject) {
  _size = copiedObject._size;
  _arr = new int[_size];

  for (int i = 0; i < _size; i++) {
    _arr[i] = copiedObject._arr[i];
  }

  _begin = copiedObject._begin;
  _end = copiedObject._end;
}