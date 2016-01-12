#include <math.h>
#include <iostream>
#include <fstream>
#include "random_generator.h"
using namespace std;

/*
Author: Eric Froese
Student Number: 5029954
Description: This program approximates Pi by shooting at random locations
inside a 1x1 square. If the distance between the shot and the center point of 
the square (0.5,0.5) is less than or equal to 0.5, then it hit inside the circle.
The ratio between the number of shots that hit inside the circle and that miss
are used to calculate Pi. The resuts are printed to "ApproximatePi.txt"
Course: COSC 4F00
Due Date: October 30, 2015
Assignment: 1
*/

float getCartDistance(float x1, float y1, float x2, float y2){
	float xdiff = pow((x2 - x1), 2);
	float ydiff = pow((y2 - y1), 2);
	return sqrt(xdiff + ydiff);
}

int main(int argc, char const *argv[]) {
	ofstream outdata;
	outdata.open("ApproximatePi.txt", std::ofstream::out | std::ofstream::trunc);
	random_generator randy(5, 10000, 3000);	//seeds
	float totalshots = 0;
	float numhits = 0;
	float cart_distance;
	float x1 = 0.5;
	float y1 = 0.5;
	float x2, y2;
	outdata << "Approximate Pi!" << endl << endl;
	cout << "Approximate Pi! Look at ApproximatePi.txt for results" << endl;
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 1000; ++j) {
			x2 = randy.nextDouble();
			y2 = randy.nextDouble();
			cart_distance = getCartDistance(x1, y1, x2, y2);
			if (cart_distance < 0.5) {
				numhits ++;
				totalshots ++;
			} else {
				totalshots ++;
			}
		}
		outdata << "Number of Shots: " << totalshots << "   Approximate Pi: " << 4.0*(numhits/totalshots) << endl;
	}
	outdata.close();
}