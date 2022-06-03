#include "coordinatesXY.hpp"

class trajectory{
private:
    float coeffX;
    float coeffY;
public:
    void calculateTrajectory(coordinatesXY origin, coordinatesXY destination);
    void printTrajectory() const;
    [[nodiscard]] float getCoeffX() const;
    [[nodiscard]] float getCoeffY() const;
};

void trajectory::calculateTrajectory(coordinatesXY origin, coordinatesXY destination) {
    float totalX = destination.getX() - origin.getX();
    float totalY = destination.getY() - origin.getY();
    float total = abs(totalX) + abs(totalY);
    coeffX = totalX/std::abs(total);
    coeffY = totalY/std::abs(total);
}

void trajectory::printTrajectory() const {
    std::cout << "X :" << coeffX << " Y :" << coeffY << std::endl;
}

float trajectory::getCoeffX() const {
    return coeffX;
}
float trajectory::getCoeffY() const {
    return coeffY;
}

