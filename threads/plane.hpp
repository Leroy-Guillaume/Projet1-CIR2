#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <string>
#include <optional>
#include <cstdio>
#include <cstdlib>
#include "../tools/trajectory.h++"


using namespace std;
mutex planeCoordsMutex;

coordinatesXY allPlanesCoordinates[30];
class Plane
{

private:
    coordinatesXY coords;
    coordinatesXY destination;
    float speed = 0.1;
    bool atDestination = true;
    trajectory trajectoire;
public:

    int planeIndex = 0;
    string identification;
    void updateDestination(coordinatesXY newDestination);
    void printTrajectory();
    void speedController();
    void setCoords(coordinatesXY newCoords);
    void updateCoordinates();
    [[nodiscard]] bool isTraveling() const;

    friend ostream &operator<<(ostream &os, const Plane &plane);
};


ostream &operator<<(ostream &os, const Plane &plane){
    os << "Plane " << plane.identification << " at coordinates :" << "X : " << plane.coords.getX()<< " Y :" << plane.coords.getY();

    return os;
}

void Plane::updateDestination(coordinatesXY newDestination) {

    atDestination = false;
    destination = newDestination;
    trajectoire.calculateTrajectory(coords,destination);
}

void Plane::printTrajectory(){
    trajectoire.printTrajectory();
}

void Plane::updateCoordinates() {
    //On vérifie que l'avion n'est pas déjà à destination (avec une petite marge d'erreur)
    if(coords.distanceFrom(destination) > 1){
        float newX = this->coords.getX() + speed * trajectoire.getCoeffX();
        float newY = this->coords.getY() + speed * trajectoire.getCoeffY();
        coords.setX(newX);
        coords.setY(newY);
        allPlanesCoordinates[planeIndex] = coords;
    }
    else{
        atDestination = true;
        speed = 0;
    }
}

void Plane::speedController() {
    float defaultSpeed = 1;
    if(coords.distanceFrom(destination) > 100){
        if(speed < 6*defaultSpeed){
            speed += 0.5;
        }
    }
    else if(coords.distanceFrom(destination) > 30 && coords.distanceFrom(destination) < 100){
        if (speed > 3*defaultSpeed){
            speed -= 0.3;
        }
        else{
            speed += 0.3;
        }
    }
    else if((coords.distanceFrom(destination) < 30) && speed > 2*defaultSpeed){
        speed -= 0.3;
    }
    else if(coords.distanceFrom(destination) < 15){
        speed = defaultSpeed;
    }
    else if(coords.distanceFrom(destination) < 5){
        speed = 0.4;
    }
    else if(coords.distanceFrom(destination) < 2){
        speed = 0.1;
    }
}

void Plane::setCoords(coordinatesXY newCoords){
    coords = newCoords;
}

bool Plane::isTraveling() const{
    return !atDestination;
}

