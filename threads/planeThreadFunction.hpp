#include "airport.hpp"

void planeBehaviour(Plane plane, bool &stop_thread){
    while(!stop_thread){
        std::this_thread::sleep_for(0.032s);
        if(plane.isTraveling()){
            planeCoordsMutex.lock();
            plane.updateCoordinates();
            planeCoordsMutex.unlock();
            plane.speedController();

        }
        else{
            cout << plane.identification <<  " is at destination, distanceFromDestination :" << endl;
            this_thread::sleep_for(chrono::seconds(2s));
            cout << plane.identification << "Taking off to new destination" << endl;
            srand((plane.planeIndex + 1)*time(nullptr));
            int index = rand()%10;
            plane.updateDestination(airport_List.at(index).coordinates());
            airport_List.at(index).printCoords();
            cout << "New trajectory is :";
            plane.printTrajectory();
        }
    }
}

