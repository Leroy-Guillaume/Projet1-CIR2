class coordinatesXY{
private:
    float X = 0,Y = 0;
public:
    [[nodiscard]] float getX() const{
        return X;
    }
    [[nodiscard]] float getY() const{
        return Y;
    }
    void setX(float newX){
        this->X = newX;
    }
    void setY(float newY){
        this->Y = newY;
    }
    [[nodiscard]] float distanceFrom(coordinatesXY point) const;
    coordinatesXY();
};

coordinatesXY::coordinatesXY() {
    X = 0;
    Y = 0;
}

float coordinatesXY::distanceFrom(coordinatesXY point) const{
    return std::abs(abs(point.getX() - this->X) + abs(point.getY() - this->Y));
}