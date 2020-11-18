#include <string.h>
#include "MapPoint.h"


MapPoint constructMP(const char* name, const double width, const double longA ){
MapPoint location;
location.latitude=width;
location.longitude=longA;
location.name= new char[strlen(name)+1];
strcpy(location.name, name);
return location;
}


void print(MapPoint location){
  if(location.longitude<0 && location.latitude>0){
    std:: cout<<"Punkt na mapie <"<<location.name<<"> ma wspolrzedne [ "<<location.latitude<<
    " N, "<<location.longitude<<" W ]\n";
  }
  else if(location.longitude<0 && location.latitude<0){
     std:: cout<<"Punkt na mapie <"<<location.name<<"> ma wspolrzedne [ "<<location.latitude<<
    " S, "<<location.longitude<<" W ]\n";
  }
  else if(location.longitude>0 && location.latitude<0){
     std:: cout<<"Punkt na mapie <"<<location.name<<"> ma wspolrzedne [ "<<location.latitude<<
    " S, "<<location.longitude<<" E ]\n";
  }
  else{
     std:: cout<<"Punkt na mapie <"<<location.name<<"> ma wspolrzedne [ "<<location.latitude<<
    " N, "<<location.longitude<<" E ]\n";
  }
}


double distance(MapPoint firstLocation, MapPoint secondLocation){
  double distance = firstLocation.longitude - secondLocation.longitude;
  if(distance > 0) return distance;
  else return -distance;
return 0;
}


void movePoint(MapPoint& location, const double widthShift, const double longShift){
 location.latitude += widthShift;
 location.longitude +=longShift;
}


MapPoint inTheMiddle(MapPoint firstLocation, MapPoint secondLocation, const char* xyz){
MapPoint test;
test.name = (char*)malloc((strlen(xyz)+1)*sizeof(char));
test.latitude=(firstLocation.latitude + secondLocation.latitude)/2;
test.longitude=(firstLocation.longitude + secondLocation.longitude)/2;
strcpy(test.name, xyz);
return test;
}


void clear(int n, MapPoint** locationsArray){
for(int i=0;i<n;i++){
  free(locationsArray[i]->name);
}
}

void clear( MapPoint location){
  free(location.name);
}
