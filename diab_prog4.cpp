/*
Leila Diab
Due Date: 2/24/20
Course:  C0P3014
Assignment:  Program 4
Professor: Sorgente

Description: This program calculates the perimeter and semiperimeter 
of a triangle with side lengths that are entered by the user.

*/
#include <iostream>
#include <string>
#include <cmath>
void areaPerimeter(int, int, int, double&, int&);
/**********************
Precondition: The user's side lengths of triangle are valid and are passed by value.  
Postcondition: the area, semiperimeter, and perimeter are calculated from 
user data which will be passed by reference throughout program. 
Description: calculates area, semiperimeter, and perimeter from values entered by user. 

******************************/
void results(int, int, int, double&, int&);
/***********************************
Precondition: All of the values are valid and area/perimeter are calculated properly.
Postcondition: The area, perimeter, and all three side values
will be printed in organized style so all are displayed for user. The side lengths are
passed by value and the area and perimeter are passed by reference.  
Description: This displays all of the data taken and calculated to the user. 
***********************************/
using namespace std;




int main()
{

    //declaring variables
    int side1, side2, side3, perimeter;
    double area;
    
    //Asking user for name, and if they want to calculate
    string name;
    string userAnswer = "y";
    cout << "Welcome to the triangle calculator! Enter your name here: ";
    cin >> name;
    cout << "\n\nHello, " << name << ". Would you like to calculate the area and perimeter of a triangle?";
    cout << "\n\nYou will have to enter 3 integer values for each side of the triangle. After entering, I will then calculate \nthe perimeter and area of the triangle. ";
    cout << "\nEnter Y or N to continue (y for yes and n for no): ";
    cin >> userAnswer;


    while (userAnswer == "y" || userAnswer == "Y") {
        cout << "Enter a side length for side 1: ";
        cin >> side1;
        cout << "Enter a side length for side 2: ";
        cin >> side2;
        cout << "Enter a side length for side 3: ";
        cin >> side3;
        if ( (side1 + side2 > side3) && (side2 + side3 > side1) && (side3 + side1 > side2) ) {
            areaPerimeter(side1, side2, side3, area, perimeter);
            results(side1, side2, side3, area, perimeter);
        }
        else {
            cout << endl << "invalid entry. try new lengths" << endl;
            area = false;
            perimeter = false;
            results(side1, side2, side3, area, perimeter);
            
 }
        
           
       

        cout << endl << name << ", Would you like to do another calculation (y or n): " << endl;
        cin >> userAnswer;
        

    }

    cout << name << ", Have a good day!";
    return 0;
}
    
   
  




//Description: finds the area, semiperimeter, and perimeter based on lengths that the user entered
void areaPerimeter(int side1, int side2, int side3, double& area, int& perimeter) {
   
    double semiPerimeter = static_cast <double>  ( (side1 + side2 + side3) / 2.0); //static casting variable to get right calculation value 
    //double insideSquare= (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3);//variable so math is easier to read
    //cout << "inside square: " << insideSquare; //testing for calculation error

    perimeter = (side1 + side2 + side3);
    cout << "The semiperimeter is: "<< semiPerimeter << endl; 
    // cout << endl << "The perimeter is: " << perimeter; for testing purposes
    area = sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3));
 
  }
    
    
//displays results for function
void results(int side1, int side2, int side3, double& area, int& perimeter) {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1); //setting decimal place to tenths place for double value (area)
    if ((side1 + side2 < side3) || (side3 + side2 < side1) || (side3 + side1 < side2)) {
        cout << "Side 1: \t Side 2:\t Side 3: \t Area: \t Perimeter:" << endl;
        cout << side1 << "\t\t" << side2 << "\t\t" << side3 << "\t\t" << area << "\t" << perimeter << endl;
    }
    else {

        cout << "Side 1: \t Side 2:\t Side 3: \t Area: \t Perimeter:" << endl;
        cout << side1 << "\t\t" << side2 << "\t\t" << side3 << "\t\t" << area << "\t" << perimeter << endl;
    }

}