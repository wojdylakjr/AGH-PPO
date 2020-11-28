#include "MapPoint.h"

void MapPoint::set_latitude(double lat) { _latitude = lat; }


void MapPoint::set_longitude(double lon) { _longitude = lon; }


void MapPoint::print() {
  std::cout << "Point: (" << _latitude << ", " << _longitude << ")"
            << std::endl;
}


void MapPoint::set_coordinates(double lat, double lon) {
  _latitude = lat;
  _longitude = lon;
}


MapDistance MapPoint::distance(MapPoint city) {
  MapDistance distance;
  double lonDistance =
      sqrt((_longitude - city._longitude) * (_longitude - city._longitude));
  double latDistance =
      sqrt((_latitude - city._latitude) * (_latitude - city._latitude));
  distance.set_longitudeDistance(lonDistance);
  distance.set_latitudeDistance(latDistance);
  // double r=sqrt(lonDistance*lonDistance + latDistance*latDistance);

  return distance;
}


MapPoint MapPoint::closest(MapPoint city1, MapPoint city2) {

  MapDistance distance1 = distance(city1);

  MapDistance distance2 = distance(city2);

  double distance11 = sqrt((distance1.get_longitudeDistance()) *
                               (distance1.get_longitudeDistance()) +
                           (distance1.get_latitudeDistance()) *
                               (distance1.get_latitudeDistance()));

  double distance22 = sqrt((distance2.get_longitudeDistance()) *
                               (distance2.get_longitudeDistance()) +
                           (distance2.get_latitudeDistance()) *
                               (distance2.get_latitudeDistance()));

  if (distance11 > distance22) {
    return city2;
  } else {
    return city1;
  }
}


MapPoint MapPoint::half_way_to(MapPoint city) {
  MapPoint half;
  half._longitude = (_longitude + city._longitude) / 2;
  half._latitude = (_latitude + city._latitude) / 2;
  return half;
}