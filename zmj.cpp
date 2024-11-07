#include<iostream>
#include<cmath>

class Vector{
public:
    double x;
    double y;
    Vector(){x=0;y=0;}
    Vector(double xVal, double yVal) : x(xVal), y(yVal) {}

    Vector& add(Vector other){
        this->x+=other.x;
        this->y+=other.y;
        return *this;
    }
    
    void print(){
        std::cout<<"x:"<<this->x<<" ";
        std::cout<<"y:"<<this->y<<std::endl;
    }

    double dir(){
        double X=this->x;
        double Y=this->y;
        double rel = sqrt(X*X+Y*Y);
        return rel;
    }

    double dir_print(){
        double X=this->x;
        double Y=this->y;
        double rel = sqrt(X*X+Y*Y);
        std::cout<<"this_dir:"<<rel<<std::endl;
        return rel;
    }



   //------------------------------------------------
    Vector& operator=(Vector& other) {
    if (this!= &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
    }

    Vector& operator+=(Vector& other) {
    x += other.x;
    y += other.y;
    return *this;
    }

    Vector& operator-=(Vector& other) {
    x -= other.x;
    y -= other.y;
    return *this;
    }

    Vector& operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
    }

    bool operator==( Vector& other) {
    return x == other.x && y == other.y;
    }
};

void ceshi(){
    Vector a(1,1.5);
    Vector b(2,2.5);
    a.print();
    b.print();

    b.add(a);
    b.dir_print();
}
int main()
{
    ceshi();
    return 0;
}