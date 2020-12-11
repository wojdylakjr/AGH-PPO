#include"Vector2D.h"

int Vector2D::count = 0;


Vector2D::Vector2D() : _x(0), _y(0) {
  count++;
}


Vector2D::Vector2D(double x,double y) : _x(x), _y(y) {
  count++;
}


Vector2D::Vector2D(const Vector2D& copiedVec) : _x(copiedVec._x), _y(copiedVec._y) {
  std::cout<<"copying ";
  print();
  count++;
}


Vector2D::Vector2D(Vector2D&& movedVec){
  _x = std::__exchange(movedVec._x,0);
  _y = std::__exchange(movedVec._y,0);
  //_y = std::move(movedVec._y);
//   _x = movedVec._x;
//   _y = movedVec._y;
//   movedVec._x = 0;
//   movedVec._y = 0;
  std::cout<<"moving ";
  print();
  count++;
}


Vector2D::~Vector2D(){
  count--;
}


Vector2D Vector2D::add(const Vector2D& vec) const{
  return Vector2D(_x + vec._x, _y + vec._y);
}


double Vector2D::dot(const Vector2D& vec) const{
  return _x * vec._x + _y * vec._y;
}


void Vector2D::print(const std::string& text) const{
  std::cout<<text<<"("<<_x<<", "<<_y<<")"<<std::endl;
}


Vector2D Vector2D::fromCarthesian(double x, double y){
  return Vector2D(x,y);
}


Vector2D Vector2D::fromPolar(double r, double phi){
  return Vector2D(r*cos(phi * M_PI/180), r*sin(phi * M_PI/180));
}