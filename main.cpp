#include <iostream>
#include <string>
using namespace std;

class AbsractPoint
{
public:
    virtual AbsractPoint* Clone() = 0;
    virtual string ToString() = 0;
};

class Point : AbsractPoint
{
protected:
    int x, y;
public:
    Point(int x_, int y_ ) : x(x_), y(y_) {}
    Point(Point& p)
    {
        x = p.x;
        y = p.y;
    }
    Point* Clone() {return new Point(this->x, this->y);}
    string ToString()
    {
        string str;
        str.append("Point (");
        str += to_string(this->x);
        str +="; ";
        str += to_string(this->y);
        str +=")\n";
        return str;
    }

    int GetX() {return this->x;}
    int GetY()  {return this->y;}
};

class ColorPoint : public Point
{
protected:
    string color;
public:
    ColorPoint(int x_, int y_, string color_) : Point(x_, y_), color(color_){}
    ColorPoint(ColorPoint& p) : Point(p.x, p.y), color(p.color){}
    ColorPoint* Clone(){return new ColorPoint(this->x, this->y, this->color);}
    string ToString()
    {
        string str;
        str.append("ColorPoint (");
        str += to_string(this->x);
        str +="; ";
        str += to_string(this->y);
        str +="; ";
        str += this->color;
        str +=")\n";
        return str;
    }
};

int main()
{
    Point* pointDonor = new Point(1, 1);
    Point* pointClone = pointDonor->Clone();

    cout << pointDonor->ToString();
    cout << pointClone->ToString();

    ColorPoint* colorPDonor = new ColorPoint(pointDonor->GetX(),
                                             pointDonor->GetY(),
                                             "Red");

    ColorPoint* colorPClone = colorPDonor->Clone();

    cout << colorPDonor->ToString();
    cout << colorPClone->ToString();

//    delete pointDonor;
//    delete pointClone;

//    delete colorPDonor;
//    delete colorPClone;
    cout << "Hello World!" << endl;
    return 0;
}
