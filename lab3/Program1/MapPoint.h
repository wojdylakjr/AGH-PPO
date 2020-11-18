#ifndef MAP_POINT_H
#define MAP_POINT_H
#include <iostream>

typedef struct MapPoint{
  char *name;
  double longitude;
  double latitude;
}MapPoint;

MapPoint constructMP(const char* ,const double, const double );
void print(MapPoint);
double distance(MapPoint, MapPoint);
void movePoint(MapPoint& ,const double, const double);
MapPoint inTheMiddle(MapPoint, MapPoint, const char*);
void clear(int, MapPoint**);
void clear( MapPoint);

#endif