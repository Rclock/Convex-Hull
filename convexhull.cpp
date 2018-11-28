/*
 * Ryan Clocker
 * Tony White
 * Dr. Anderson
 * COSC 320
 * Project 3 Source Code
 * **Please see README for compile instructions**
 */

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include "matplotlibcpp.h"
using namespace std;
namespace plt = matplotlibcpp;
void clear();
struct point
{
  int x,y;
  point(){}
  point(int a, int b)
  {
    x = a; y = b;
  }
};

int distance(point u, point v)
{
  return sqrt((v.x - u.x)*(v.x - u.x) + (v.y - u.y)*(v.y - u.y));
 
}
int formAngle(point x, point y, point z)
{
 return ((y.x - x.x) * (z.y - x.y) - (y.y - x.y) * (z.x - x.x)); //cross product of vectors p1p2 and p1p3
}
 point origin;
int operator^(point u, point v)//cross product operator
{
 return u.x*v.y - v.x*u.y;
}
int main()
{
    vector<point> points; 
    int tempx = 0;
    while (tempx <= 15)//while loop to initialize vector with data
    {
        int tempx, tempy = 0;
    cout << "Enter x and y values for a new point, pressing enter after each integer. Enter above 15 to stop. " << endl;
    cin >> tempx;
    if (tempx > 15)
        break;
    cin >> tempy;
    points.push_back(point(tempx, tempy));//adds each point to the vector
    } 
    clear();
    
 cout << "\033[1;33m Here are the points given. \033[0m\n" << endl;
 
 for(point p : points)//displays each point
  {
    
    printf("(%d,%d) ", p.x, p.y);
  }
  std::cout << std::endl;

  std::sort(points.begin(), points.end(), [](point u, point v)//uses std::sort to sort the points, based on y coordinate
  {
    return u.y < v.y;
  });
 cout << "\033[1;33m The following points are sorted by y-coordinate to find the origin: \033[0m\n" << endl;
 for(point p : points){//displays all of the points now sorted by y-coordinate
   
    printf("(%d,%d) ", p.x, p.y);
  }
  std::cout << std::endl;
    cout << "\033[1;33m The origin is the left-most point above. \033[0m\n" << endl;
  //set p0 to be the left most y-least coordinate in the sorted y value array.
  origin = points[0];//since points array is sorted by y value, this takes left most smallest y value as the origin
  cout << endl;
 

  //sorts by comparing cross products
  std::sort(points.begin()+1, points.end(), [](point u, point v)
  {
    //before checking for angles, we must subtract the origin's coordinates
    u.x = u.x - origin.x;
    u.y = u.y - origin.y;
    v.x = v.x - origin.x;
     v.y = v.y - origin.y;
     
    if (u.y == 0 && u.x > 0)//the angle is u is 0
      return true;
    if (v.y == 0 && v.x > 0)//the angle of v is 0
      return false;
    if (u.y > 0 && v.y < 0)//v is between 0 and 180
      return true;
    if (u.y < 0 && v.y > 0)//
      return false;
    
    return (u^v) > 0;//this returns true if u is clockwise from v(how we want to sort)
  });
 
   cout << "\033[1;33m The points are now sorted by polar coordinate using cross products: \033[0m\n" << endl;
   for (point p : points)//displays points sorted by polar coordinates
  {
   printf("(%d, %d) ", p.x, p.y);
    
  }
  cout << endl << endl;
 vector<point> originalpoints;
 for (auto i = 0; i < points.size(); i++)
 {
  originalpoints.push_back(points[i]);
 }
 
 
  //can put the below code either before or after the sort. this checks for the same angle and deletes if so
   
   for (auto i = points.begin(); i <= points.end()-1;)//.begin +1 to make it work
     {//for loop deletes all points that are co-linear
   
    
    point p1 = *i;
    point p2 = *(i+1);
    
   p1.x = p1.x - origin.x;
   p1.y = p1.y - origin.y;
   p2.x = p2.x - origin.x;
   p2.y = p2.y - origin.y;
    

    int temp = origin^(p1);
   
    int temp2 = origin^(p2);
   
    
    if (temp == temp2)
    {
        point p3 = *i;
        point p4 = *(i+1);
  
       if (p3.x >= 0 && p4.x <= 0)
       {
           i++;
        continue;
       }
       if (p3.x <= 0 && p4.x >= 0)
       {
           i++;
        continue;
       }
       if (p3.x >= 0 && p4.x >= 0)
       {
           
           i++;
           
           continue;
       }
       if (p3.x <= 0 && p3.x <= 0)
       {
           i++;
           continue;
       }
       
     int d1 = distance(origin, p3);
     int d2 = distance(origin, p4);
    
     if (d1 > d2)
     {
       cout << "here" << endl;
       i = points.erase(i+1);
     }
     if (d2 > d1)
     {
         cout << "here" << endl;
      i = points.erase(i);
     }
     
    }
    else
    {
        i++;
    }
 
  }
  
  cout << endl << endl;
  stack<point> S;
 
  S.push(points[0]);
  S.push(points[1]);
  S.push(points[2]);
 
 for (int i = 3; i < points.size(); i++)
 {
   point top = S.top();
   S.pop();
   while (formAngle(top, S.top(), points[i]) >= 0)//gets rid of a point if it is on the same line in the hull
   {
     top = S.top();
     S.pop();
   }
   S.push(top);
   S.push(points[i]);
   
 }
  //now get the points off the stack that form the convex hull in counterclockwise order
  cout << "\033[1;33m The following points form the Convex Hull (points with the same cross product have been deleted): \033[0m\n" << endl;
  vector<point> hullpoints;
  int i = 0;
  while (!S.empty())
  {
    point current = S.top();
    S.pop();
    printf("(%d, %d) ", current.x, current.y);
    hullpoints.push_back(current);
    i++;
  }
 cout << endl;
 vector<int> x(hullpoints.size()+1), y(hullpoints.size()+1);

for (int i = 0; i < x.size(); i++)
{
 x[i] = hullpoints[i].x;   
}
for (int i = 0; i < y.size(); i++)
{
 y[i] = hullpoints[i].y;   
}
//the following code is used strictly for graphical output
 std::vector<int> x_axis_x(21);
 for(int i=0; i<21; i++){
   x_axis_x.at(i) = i-10;
 }
 std::vector<int> x_axis_y(21,0);
 std::vector<int> y_axis_y(21);
 for(int i=0; i<21; i++){
   y_axis_y.at(i) = i-10;
 }
 std::vector<int> y_axis_x(21,0);
 vector<int> x_orig(originalpoints.size()), y_orig(originalpoints.size());
 
 for (int i = 0; i < x_orig.size(); i++)
{
 x_orig[i] = originalpoints[i].x;   
}
for (int i = 0; i < y_orig.size(); i++)
{
 y_orig[i] = originalpoints[i].y;   
}

 x[x.size()-1] = x[0];
 y[y.size()-1] = y[0];
 plt::xlim(-10,10);
 plt::ylim(-10,10);
 plt::grid(1);
 
 
 plt::plot(x_axis_x, x_axis_y, "k-");
 plt::plot(y_axis_x, y_axis_y, "k-");
 plt::plot(x_orig, y_orig, "o");
 plt::plot(x, y);
 plt::title("Convex Hull");
plt::show(); 

 return 0;
}



void clear()
{
    cout << "\n\n\n\n\n\n\n";   
}
