#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <string>
#include <optional>
#include <SFML/Graphics.hpp>
#include "plane.hpp"

using namespace std;
using namespace  sf;

class Airport
{
    vector<Plane> planes;
    coordinatesXY coords;


public:
    string identification;
    Airport(float x, float y){
        coords.setX(x);
        coords.setY(y);
    }

    void printCoords(){
        cout << identification << " X : " << coords.getX() << " Y : " << coords.getY() << endl;
    }
    coordinatesXY coordinates(){
        return coords;
    }
    friend ostream &operator<<(ostream &os, const Airport &airport);
};
vector <Airport> airport_List;

ostream &operator<<(ostream &os, const Airport &airport)
{
    os << "Available planes\n";
    for (auto &plane : airport.planes)
    {
        os << plane.identification << endl;
    }
    return os;
}




