#include <thread>
#include <iostream>
#include <string>
#include "threads/planeThreadFunction.hpp"



using namespace  sf;
using namespace std;

#ifdef _MSC_VER
//#define _PATH_IMG_ "../../../../../img/"
//#else
#define _PATH_IMG_ "../img/"
#endif



const string path_image(_PATH_IMG_);
Plane planeTab[15];//Tableau de 15 avions

int main()
{
    sf::err().rdbuf(nullptr);


    vector<Text> AirportNamesVector;

    Font font;
    if (!font.loadFromFile("../arial.ttf")) cout<< "erreur police"<<endl;

    for(int i = 0; i < 10 ; i++){
        Text tmp;
        tmp.setFont(font);
        tmp.setCharacterSize(20);
        AirportNamesVector.push_back(tmp);
    }


    bool stop_thread = false;
    RenderWindow app(VideoMode(1002, 1024, 32), "Air traffic simulation - Aurelien Roge et Guillaume Leroy");


    Sprite backgroundSprite;
    Sprite Airport_logoSprite[10];
    Texture planeImage, backgroundImage, Airport_logoImage;
    backgroundSprite.setScale(sf::Vector2f(1.0, 1.0));
    Sprite PlaneTabSprite[15];



    if (!backgroundImage.loadFromFile(path_image+"background.jpg") ||
        !planeImage.loadFromFile(path_image+"plane.png")||!Airport_logoImage.loadFromFile(path_image+"airport_logo.png")) {
        cerr << "Erreur pendant le chargement des images" << endl;
        return EXIT_FAILURE; // On ferme le programme
    }

    backgroundSprite.setTexture(backgroundImage);

    for (int i = 0; i < 10; ++i) {
        Airport_logoSprite[i].setTexture(Airport_logoImage);
        Airport_logoSprite[i].setScale(sf::Vector2f(0.01,0.01));
    }


    for (int i = 0; i < 15; ++i) {
        PlaneTabSprite[i].setTexture(planeImage);
        PlaneTabSprite[i].setScale(sf::Vector2f(0.008, 0.008));
    }

    Airport airport(285, 631);
    Airport_logoSprite[0].setPosition(280, 631);
    airport.identification = "Paris";
    airport_List.push_back(airport);
    airport_List.at(0).printCoords();
    AirportNamesVector[0].setString("Paris");
    AirportNamesVector[0].setPosition(281, 666);
    AirportNamesVector[0].setFillColor(Color::Black);


    Airport airport1(149, 476);
    Airport_logoSprite[1].setPosition(144, 476);
    airport1.identification = "Dublin";
    airport_List.push_back(airport1);
    airport_List.at(1).printCoords();
    AirportNamesVector[1].setString("Dublin");
    AirportNamesVector[1].setPosition(134, 511);
    AirportNamesVector[1].setFillColor(Color::Black);

    Airport airport2(135, 841);
    Airport_logoSprite[2].setPosition(130, 841);
    airport2.identification = "Madrid";
    airport_List.push_back(airport2);
    airport_List.at(2).printCoords();
    AirportNamesVector[2].setString("Madrid");
    AirportNamesVector[2].setPosition(120, 876);
    AirportNamesVector[2].setFillColor(Color::Black);

    Airport airport3(10, 860);
    Airport_logoSprite[3].setPosition(5, 860);
    airport3.identification = "Lisbonne";
    airport_List.push_back(airport3);
    airport_List.at(3).printCoords();
    AirportNamesVector[3].setString("Lisbonne");
    AirportNamesVector[3].setPosition(0, 895);
    AirportNamesVector[3].setFillColor(Color::Black);

    Airport airport4(479, 825);
    Airport_logoSprite[4].setPosition(474, 825);
    airport4.identification = "Rome";
    airport_List.push_back(airport4);
    airport_List.at(4).printCoords();
    AirportNamesVector[4].setString("Rome");
    AirportNamesVector[4].setPosition(459, 860);
    AirportNamesVector[4].setFillColor(Color::Black);

    Airport airport5(624, 731);
    Airport_logoSprite[5].setPosition(619, 731);
    airport5.identification = "Belgrade";
    airport_List.push_back(airport5);
    airport_List.at(5).printCoords();
    AirportNamesVector[5].setString("Belgrade");
    AirportNamesVector[5].setPosition(604, 766);
    AirportNamesVector[5].setFillColor(Color::Black);

    Airport airport6(519, 330);
    Airport_logoSprite[6].setPosition(514, 330);
    airport6.identification = "Stockholm";
    airport_List.push_back(airport6);
    airport_List.at(6).printCoords();
    AirportNamesVector[6].setString("Stockholm");
    AirportNamesVector[6].setPosition(495, 365);
    AirportNamesVector[6].setFillColor(Color::Black);

    Airport airport7(830, 345);
    Airport_logoSprite[7].setPosition(825, 345);
    airport7.identification = "Moscou";
    airport_List.push_back(airport7);
    airport_List.at(7).printCoords();
    AirportNamesVector[7].setString("Moscou");
    AirportNamesVector[7].setPosition(815, 375);
    AirportNamesVector[7].setFillColor(Color::Black);

    Airport airport8(464, 514);
    Airport_logoSprite[8].setPosition(459, 514);
    airport8.identification = "Berlin";
    airport_List.push_back(airport8);
    airport_List.at(8).printCoords();
    AirportNamesVector[8].setString("Berlin");
    AirportNamesVector[8].setPosition(454, 549);
    AirportNamesVector[8].setFillColor(Color::Black);

    Airport airport9(829, 807);
    Airport_logoSprite[9].setPosition(824, 807);
    airport9.identification = "Istanbul";
    airport_List.push_back(airport9);
    airport_List.at(9).printCoords();
    AirportNamesVector[9].setString("Istanbul");
    AirportNamesVector[9].setPosition(814, 842);
    AirportNamesVector[9].setFillColor(Color::Black);


    srand(time(nullptr));
    for(int i = 0; i < 15; i++){
        Plane plane;

        plane.identification = "AF" + to_string(101+i);
        plane.planeIndex = i;
        planeTab[i] = plane;
        planeTab[i].setCoords(airport_List.at(rand()%10).coordinates());
        planeTab[i].updateDestination(airport_List.at(rand()%10).coordinates());

    }




    vector<Text> PlanesNamesVector;

    for(int i = 0; i < 15; i++){
        Text text;
        text.setFont(font);
        text.setCharacterSize(15);
        text.setString(planeTab[i].identification);
        text.setFillColor(Color::Black);
        PlanesNamesVector.push_back(text);
    }

    vector <thread> planeThreads;
    for(int i = 0; i  < 15; i++){
        planeThreads.emplace_back(planeBehaviour, ref(planeTab[i]), ref(stop_thread));

    }



    while (app.isOpen()){
        Event event;

        while (app.pollEvent(event))
        {
            if ((event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Escape) || event.type == Event::Closed)
            {
                app.close();
            }
        }



        app.clear();
        app.draw(backgroundSprite);
        for(int i = 0; i < 10; i++){
            app.draw(Airport_logoSprite[i]);
        }

        for (int i = 0; i < 15; ++i) {
            PlaneTabSprite[i].setPosition(allPlanesCoordinates[i].getX(),allPlanesCoordinates[i].getY());
            PlanesNamesVector[i].setPosition(allPlanesCoordinates[i].getX() + 20,allPlanesCoordinates[i].getY() - 8);
            app.draw(PlaneTabSprite[i]);
            app.draw(PlanesNamesVector[i]);
        }


        for(int i = 0; i < 10; i++){
            app.draw(AirportNamesVector[i]);
        }


        app.display();
    }


}
