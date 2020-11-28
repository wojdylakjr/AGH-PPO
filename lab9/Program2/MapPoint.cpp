#include"MapPoint.h"
int MapPoint::numberOfPoints=0;

MapPoint::MapPoint (const std::string& name,double lat,double lon){
   _name=name;
   _coord.Longitude(lon);
   //_coord.Latitude(lat);
   _coord._latitude=lat;//jesli Coordinates zrobie jako friend class
//    _latitude=lat;
//    _longitude=lon;
// _coord.Set(_latitude, _longitude);
   MapPoint::numberOfPoints++;
}

MapPoint::MapPoint (const std::string& name){
    _name = name;
    MapPoint::numberOfPoints++;

}

MapPoint::MapPoint(){
   MapPoint::numberOfPoints++;
}

MapPoint::~MapPoint(){}

 Coordinates MapPoint::GetCoordinates()const {
   return _coord;
 }

Coordinates& MapPoint::GetCoordinates(){
    return _coord;
}

Coordinates* MapPoint::GetCoordinatesPtr(){
    return &_coord;
}

void MapPoint::SetId(const std::string& name){
    _name=name;
}

void MapPoint::Print()const{
    std::cout<< "Point: "<<_name
    << " ("<< _coord.Latitude()
    << ","<< _coord.Longitude()
    << ")"<<std::endl;
}

unsigned MapPoint::NumberOfPoints(){
    return MapPoint::numberOfPoints;
}

double surfaceTriangleArea(const MapPoint* city1, const MapPoint* city2 , const MapPoint* city3){
    // pole = 1/2 * ((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))
    double x_21 = city2->_coord.Longitude() - city1->_coord.Longitude();
    double y_31 = city3->_coord.Latitude() - city1->_coord.Latitude();
    double x_31 = city3->_coord.Longitude() - city1->_coord.Longitude();
    double y_21 = city2->_coord.Latitude() - city1->_coord.Latitude();

    double field = 0.5 * (x_21 * y_31 - x_31 * y_21);
    if (field > 0) return field;
    else return -field;
}