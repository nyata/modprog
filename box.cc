#include <iostream>
using namespace std;
class Box {
private:
	double length;
	double width;
	double height;
	static int objectCount;
public:
	Box(double l = 2.0, double b = 2.0, double h = 2.0); ~Box() { --objectCount; }
          // returns the volume of the box
double volume() const { return length * width * height; }
// returns the footprint (area on the floor) of the box 
double footprint() const { return length * width; }
// returns number of existing boxes
static int getCount() { return objectCount; }
friend ostream& operator<<(ostream& os, const Box& b); };
int Box::objectCount = 0;
Box::Box(double l, double b, double h) {
	length = l;
	width = b;
	height = h;
	if (length < 0.0 || width < 0.0 || height < 0.0) {
		cout << "Error: No negative values allowed in box!" << endl;
		length = width = height = 0.0;
	}
	++objectCount;
}
ostream& operator<<(ostream& os, const Box& b) {
	os << b.length << " * "<< b.width << " * "<< b.height;
	return os;
}
int main(void) {
	Box boxes[4];
	cout << "Inital box count: " << Box::getCount() << endl;
	Box b1(2.0, 3.0, 1.0);
	const Box b2(1.0, 2.0, 3.0);
	Box b3(2.0, 3.0, -1.0);
	Box* b4 = new Box();
	cout << "Current box count: " << Box::getCount() << endl;
	boxes[0] = b1;
	boxes[1] = b2;
	boxes[2] = *b4;
	boxes[3] = b3;
	for(int i = 0; i < 4; ++i)
		cout << "Box " << i + 1 << " (" << boxes[i] << ") has a footprint of "	
			 << boxes[i].footprint() << " and a volume of "
		     << boxes[i].volume() << "." << endl;
	delete b4;

	cout << "Final box count: " << Box::getCount() << endl;
	return 0;
}