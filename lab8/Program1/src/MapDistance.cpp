#include"MapDistance.h"
void MapDistance::set_latitudeDistance(double lat){
_latitudeDistance=lat;
}
void MapDistance::set_longitudeDistance(double lon){
_longitudeDistance=lon;
}

void MapDistance:: print(){
std::cout<<"Distance: ("<<_latitudeDistance<<", "<<_longitudeDistance<<")"<<std::endl;
}

  double MapDistance::get_latitudeDistance(){
    return _latitudeDistance;

  }
 double MapDistance::get_longitudeDistance(){
   return _longitudeDistance;

 }