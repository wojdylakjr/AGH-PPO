#include "Coordinates.h"
void Coordinates::Set(double lat,double lon){
    _latitude=lat;
    _longitude=lon;
}

void Coordinates::Latitude(double lat){
    _latitude=lat;
}

void Coordinates::Longitude(double lon){
    _longitude=lon;
}

double Coordinates::Latitude() const{
    return _latitude;
}

double Coordinates::Longitude() const{
    return _longitude;
}