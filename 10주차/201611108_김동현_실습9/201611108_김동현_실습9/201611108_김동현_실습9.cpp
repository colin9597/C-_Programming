#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Point {
	float x, y;
public:
	Point(float _x = 0.0F, float _y = 0.0F) { this->x = _x; this->y = _y; }
	float getX() const { return x; }
	float getY() const { return y; }
	float getDistance(const Point& other)const {
		return sqrt((x - other.x) * (x - other.x) - (y - other.y) * (y - other.y));
	}
	friend ostream& operator << (ostream& os, const Point& pt);
};
ostream& operator << (ostream& os, const Point& pt) {
	os << "(" << pt.x << ", " << pt.y << ")";
	return os;
}

enum Color { RED, BLUE, YELLOW };

class Shape {
	Color lineColor;
public:
	Color getLineColor() const { return lineColor; }
	virtual Shape* clone() const = 0;
	virtual void print() const = 0;
	virtual float getLength() const = 0;
};

class ClosedShape : public Shape {
	Color fillColor;
public:
	Color getFillColor() const { return fillColor; }
	virtual float getArea() const = 0;
};

class Polygon : public ClosedShape {
protected:
	vector<Point> Points;
public:
	void addPoint(const Point& p) {Points.push_back(p);}
	virtual Shape* clone()const {
		Polygon* newPolygon = new Polygon(*this);
		return newPolygon;
	}
	virtual void print()const {
		typedef vector<Point>::const_iterator iterator;
		for (iterator it = Points.begin(); it != Points.end(); it++) {
			const Point& pt = *it;
			cout << pt;
		}
		cout << endl;
	}
	virtual float getLength()const {
		float length = 0.0F;
		for (int i = 0; i < Points.size(); i++) {
			int j = (i + 1) % Points.size();
			const Point& pt1 = Points[i];
			const Point& pt2 = Points[j];
			length += pt1.getDistance(pt2);
		}
		return length;
	}
	virtual float getArea()const {
		float area=0.0F;
		for (int i = 0; i < Points.size(); i++) {
			float area2 = 0.0F;
			int j = (i + 1) % Points.size();
			const Point& pt1 = Points[i];
			const Point& pt2 = Points[j];
			area2 = (pt1.getX() * pt2.getY()) - (pt2.getX() * pt1.getY());
			area += abs(area2);
		}
		return area / 2;
	}
};

class Rectangle : public Polygon {
public:
	Rectangle() {}
	Rectangle(Point _p1, Point _p2, Point _p3, Point _p4) {
		addPoint(_p1);
		addPoint(_p2);
		addPoint(_p3);
		addPoint(_p4);
	}
	~Rectangle() {}
	virtual Shape* clone()const {
		Rectangle* newRectangle = new Rectangle(*this);
		return newRectangle;
	}
	virtual void print()const {
		cout << "Rectangle: ";
		Polygon::print();
	}
};

class Triangle : public Polygon {
public:
	Triangle() {}
	Triangle(Point _p1, Point _p2, Point _p3) {
		addPoint(_p1);
		addPoint(_p2);
		addPoint(_p3);
	}
	~Triangle() {}
	virtual Shape* clone()const {
		Triangle* newTriangle = new Triangle(*this);
		return newTriangle;
	}
	virtual void print()const {
		cout << "Triangle: ";
		Polygon::print();
	}
};

class ShapeList {
	vector<Shape*> shapes;
public:
	ShapeList() : shapes() {}
	void addShape(const Shape* const _shape) {
		Shape* const newShape = _shape->clone();
		shapes.push_back(newShape);
	}
	void print()const {
		typedef vector<Shape*>::const_iterator iterator;
		for (iterator it = shapes.begin(); it != shapes.end(); it++) {
			const Shape* const shape = *it;
			shape->print();
		}
	}
	float getTotalArea()const {
		float totalArea = 0.0F;
		for (const auto shape : shapes) {
			float area = 0.0F;
			const auto p = dynamic_cast<const Polygon*> (shape);
			area = p->getArea();
			totalArea += area;
		}
		return totalArea;
	}
};

int main() {
	Point p1(0, 0), p2(0, 10), p3(20, 20), p4(20, 30);
	Shape* const r = new Rectangle(p1, p2, p3, p4);
	Shape* const t = new Triangle(p1, p2, p3);
	ShapeList list{};
	list.addShape(r);
	list.addShape(t);
	delete r;
	delete t;
	list.print();
	cout << list.getTotalArea() << endl;
}