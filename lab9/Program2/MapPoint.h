#pragma once
#include<iostream>
#include"Coordinates.h"

class MapPoint{
    public:
    
    static int numberOfPoints;
    MapPoint(const std::string&,double,double);
    MapPoint(const std::string&);
    MapPoint();
    ~MapPoint();
    Coordinates GetCoordinates()const;
    Coordinates& GetCoordinates();
    Coordinates* GetCoordinatesPtr();
    void SetId(const std::string&);
    void Print()const;
    static unsigned NumberOfPoints();
    friend double surfaceTriangleArea(const MapPoint*, const MapPoint* , const MapPoint*);

    private:
    std::string _name;
    Coordinates _coord;
};

