/*
 Colin McDaniel
 February 14, 2013
 
 This program prompts the user to enter points with various attributes, and then prints these points in a sorted order.
 */


#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>


using namespace std;


class Point2D {
public:
    
	// Constructors
	Point2D();
	Point2D(double a, double b);
    
	// Gets-rs
	double getx() const;
	double gety() const;
    virtual int getSelection() const;
	virtual string getc() const;
	virtual double getw() const;
    
	// Set-rs
	void setx(double a);
	void sety(double b);
    
	// Print functions
	virtual void print();
	virtual void print(int a);
    
private:
    
    // Point consists of (x,y)
	double x;
	double y;
};


class ColorPoint2D : public Point2D {
public:
    
	// Constructors
	ColorPoint2D();
	ColorPoint2D(double a, double b, string col);
	ColorPoint2D(Point2D p, string col);
    
	// Get-r
	virtual string getc() const;
    virtual int getSelection() const;
    
	// Set-r
	void setc(string col);
    
	// Print functions
	virtual void print();
    
private:
    
    //Point consists of color(x,y)
	string color;
};


class WeightedPoint2D : public Point2D {
public:
    
	// Constructors
	WeightedPoint2D();
	WeightedPoint2D(double a, double b, double wt);
    
    // Get-r
    virtual double getw() const;
    virtual int getSelection() const;
    
	// Print functions
	virtual void print();
    
private:
    
    // Point consists of weight(x,y)
	double weight;
};


// Overloaded operator
bool operator< (const Point2D &a, const Point2D &b);


// Compare function for Sort function
bool compare(Point2D* a, Point2D* b);


int main() {
    
    // Print introduction and instructions to screen
    cout << "Welcome to Point Printer! You can create three different kinds of points:\n\n";
    cout << "1. Point2D, e.g., (2,6.5)\n2. ColorPoint2D, e.g., blue(-4.5,3.5)\n3. WeightedPoint2D, e.g., .12(3.6,8.7)\n\n";
    cout << "Enter 0 when you are finished. (Please use only lowercase letters!)\n\n";
    
    // Variables necessary for user inputting
    int selection = 1;
    double x;
    double y;
    string color;
    double weight;
    vector<Point2D*> points;
    
    // Loops selection inputting until the user inputs 0
    while(selection != 0) {
        
        // Prompts user to input selection
        cout << "Selection: ";
        cin >> selection;
        
        // Prompts user for appropriate variables depending on user's selection, creates appropriate object with variables, and directs a vector to point to these objects
        if(selection != 0) {
            switch(selection){
                case 1:
                    cout << "x = ";
                    cin >> x;
                    cout << "y = ";
                    cin >> y;
                    points.push_back(new Point2D(x,y));
                    break;
                case 2:
                    cout << "x = ";
                    cin >> x;
                    cout << "y = ";
                    cin >> y;
                    cout << "color = ";
                    cin.ignore();
                    getline(cin, color);
                    points.push_back(new ColorPoint2D(x,y,color));
                    break;
                case 3:
                    cout << "x = ";
                    cin >> x;
                    cout << "y = ";
                    cin >> y;
                    cout << "weight = ";
                    cin >> weight;
                    points.push_back(new WeightedPoint2D(x,y,weight));
                    break;
                default:
                    cout << "Not a valid selection. Please try again.\n";
                    break;
            }
        }
    }
    
    cout << endl << "Your points in sorted order are\n\n";
    
    // Sorts points
    sort(points.begin(), points.end(), compare);
    
    // Prints points
    for(int i = 0; i < points.size(); i++){
        cout << (i + 1) << ": ";
        (*points[i]).print();
        cout << endl;
    }
    
    // Delete dynamically allocated memory
    for(int i = 0; i < points.size(); i++)
        delete points[i];
    
    cout << endl;
    
    return 0;
}


/** Point2D default constructor definition, sets point as (0,0) */
Point2D::Point2D() {
    x = 0;
    y = 0;
    return;
}


/** Point 2D constructor with parameters
 @param a Set as x value
 @param b Set as y value
 */
Point2D::Point2D(double a, double b) {
    x = a;
    y = b;
    return;
}


/** Point2D get-r function definition
 @return x value
 */
double Point2D::getx() const {
    return x;
}


/** Point 2D get-r function definition
 @return y value
 */
double Point2D::gety() const {
    return y;
}


/** Point2D member function that returns an integer related to the program's user selection
 @return 1 selection
 */
int Point2D::getSelection() const{
    return 1;
}


/** Point2D get-r function in place for polymorphism to occur in boolean operator < overload when inputting a dereferenced object pointer
 @return empty string
 */
string Point2D::getc() const{
	return "";
}


/** Point2D get-r function in place for polymorphism to occur in boolean operator < overload when inputting a dereferenced object pointer
 @return 0
 */
double Point2D::getw() const{
	return 0;
}


/** Point2D set-r function definition
 @param a Sets the value of x
 */
void Point2D::setx(double a) {
    x = a; return;
}


/** Point2D set-r function definition
 @param b Sets the value of y
 */
void Point2D::sety(double b) {
    y = b;
    return;
}


/** Point2D function definition, prints point (x,y) */
void Point2D::print() {
	cout<<"("<<x<<","<<y<<")";
	return;
}


/** Point2D function definition, prints point and creates a newline
 @param a Differentiates function from regular print function
 */
void Point2D::print(int a) {
	print(); cout<<endl;
	return;
}


/** ColorPoint2D default constructor, gives color an empty string value */
ColorPoint2D::ColorPoint2D() {
    color = "";
    return;
}


/** ColorPoint2D constructor with parameters
 @param a Sets x value
 @param b Sets y value
 @param col Sets color
 */
ColorPoint2D::ColorPoint2D(double a, double b, string col): Point2D(a,b) {
    color = col;
	return;
}


/** ColorPoint2D constructor with parameters
 @param p Functions as (x,y)
 @param col Sets color
 */
ColorPoint2D::ColorPoint2D(Point2D p, string col) {
	setx(p.getx());
	sety(p.gety());
    
	color = col;
	return;
}


/** ColorPoint2D get-r function definition
 @return color
 */
string ColorPoint2D::getc() const {
    return color;
}


/** ColorPoint2D that gets the number of the user's selection corresponding to this class
 @return 2 selection
 */
int ColorPoint2D::getSelection() const{
    return 2;
}


/** ColorPoint2D set-r function definition
 @param col Sets color
 */
void ColorPoint2D::setc(string col) {
    color = col;
    return;
}


/** ColorPoint2D function definition, prints point color(x,y) */
void ColorPoint2D::print() {
	cout << color;
	Point2D::print();
	return;
}


/** WeightedPoint2D default constructor, sets weight to 0 */
WeightedPoint2D::WeightedPoint2D(){
    weight = 0;
    return;
}


/** WeightedPoint2D constructor with parameters
 @param a Gets set to x
 @param b Gets set to y
 @param wt Gets set as weight
 */
WeightedPoint2D::WeightedPoint2D(double a, double b, double wt) : Point2D(a,b) {
	weight = wt;
    return;
}


/** WeightedPoint2D member function that returns weight
 @return weight
 */
double WeightedPoint2D::getw() const{
    return weight;
}


/** WeightedPoint2D member function that returns an integer corresponding to the user's selection
 @return 3 selection
 */
int WeightedPoint2D::getSelection() const{
    return 3;
}


/** WeightedPoint2D function definition, prints point weight(x,y) */
void WeightedPoint2D::print() {
	cout << weight;
	Point2D::print();
	return;
}


/** < operator overloading for two Point2D objects using ordering definitions; designed for polymorphism, input a dereferenced object pointer
 @param a Left side dereferenced Point2D object pointer
 @param b Right side dereferenced Point2D object pointer
 @return val Boolean value
 */
bool operator< (const Point2D &a, const Point2D &b){
    bool val = 0;
    
	// If class is less than another, val = true
	if(a.getSelection() < b.getSelection())
		val = 1;
    
	// Else if they are from same class...
	else if(a.getSelection() == b.getSelection()){
        
		// If first object is closer to the origin than second object, val = true
		if(sqrt(pow(a.getx(), 2) + pow(a.gety(), 2)) < sqrt(pow(b.getx(), 2) + pow(b.gety(), 2)))
			val = 1;
        
		// Else if the two objects are the same distance from the origin...
		else if(sqrt(pow(a.getx(), 2) + pow(a.gety(), 2)) == sqrt(pow(b.getx(), 2) + pow(b.gety(), 2))){
            
			// If the two points are not at the origin...
			if(a.getx() != 0 || a.gety() != 0){
				double angle_a = atan2(a.gety(), a.getx());
				double angle_b = atan2(b.gety(), b.getx());
                
				// If first angle is in first two quadrants and second angle in is third or fourth quadrant, val = true
				if(angle_a > 0 && angle_b < 0)
					val = 1;
                
				// Else if both angles are in first two quadrants...
				else if(angle_a > 0 && angle_b > 0){
                    
					// If first angle is smaller than second angle, val = true
					if(angle_a < angle_b)
						val = 1;
				}
                
				// Else if both angles are in second two quadrants...
				else if(angle_b < 0 && angle_b < 0){
                    
					// If first angle is smaller than second angle, val = true
					if(angle_a < angle_b)
						val = 1;
				}
			}
		}
        
		// If the two coordinates are equal and they are both ColorPoint2Ds, compare the colors
		if(a.getSelection() == 2 && (a.getx() == b.getx() && a.gety() == b.gety())){
			string a_color = a.getc();
			string b_color = b.getc();
            
			if(a_color.length() < b_color.length()){
				int counter = 0;
				for(int i = 0; i < a_color.length(); i++){
					if(counter == i){
						if(static_cast<int>(a_color[i]) < static_cast<int>(b_color[i]))
							val = 1;
						else if(static_cast<int>(a_color[i]) == static_cast<int>(b_color[i]))
							++counter;
					}
					if(counter == a_color.length())
						val = 1;
				}
			}
			else{
				int counter = 0;
				for(int i = 0; i < b_color.length(); i++){
					if(counter == i){
						if(static_cast<int>(a_color[i]) < static_cast<int>(b_color[i]))
							val = 1;
						else if(static_cast<int>(a_color[i]) == static_cast<int>(b_color[i]))
							++counter;
					}
				}
			}
		}
        
		// If the two coordinates are equal and they are both WeightedPoint2Ds, compare the weights
		if(a.getSelection() == 3 && (a.getx() == b.getx() && a.gety() == b.gety())){
			double a_weight = a.getw();
			double b_weight = b.getw();
            
			if(a_weight < b_weight)
				val = 1;
		}
	}
    
    return val;
}


/** compare function to be inputted as a parameter for the Sort function, takes two object pointers and returns true if the first is 'less' than the second
 @return (*a < *b)
 */
bool compare(Point2D* a, Point2D* b){
    return ((*a) < (*b));
    
}