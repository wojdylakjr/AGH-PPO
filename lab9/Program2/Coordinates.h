#pragma once

class Coordinates{
    public:
    friend class MapPoint;//opcjonalnie
    void Set(double,double);
    void Latitude(double);
    void Longitude(double);
    double Latitude() const;
    double Longitude() const;
    private:
    double _latitude;
    double _longitude;

};