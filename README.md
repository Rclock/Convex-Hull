# Convex-Hull
Convex Hull algorithm with visual representation and user-input. 



This code uses c++ in a single main function to take user-input of point coordinates to display a proper Convex Hull graphically. IT uses the Graham's Scan method and the cross product method for sorting by polar angle. The code uses Python 2.7 to enable graphing functions within a new namespace in c++. If you do not know what a CH is, here is a brief description: 
A CH is basically used to find a perimeter of any set of points. It has absolutely no concavities, and is always some type of polygon. There is no restriction on the number of edges, it could just be a simple triangle or it could have 30 edges. CH is widely used in geometric problems and other geometric algorithms today. 

To run the code, you'll need Python 2.7 installed on your system and you must include the below statement in your makefile. You must use the matplotlibcpp.h header file and download it. All of these things accomplished, it should compile and run. 
"-I/usr/include/python2.7 -lpython2.7" at the end of your makefile code.

How to run code: 
After executing, enter two integers, each followed by an enter key, to specify points to be used. When you are done adding points, enter anything above the integer 15 to stop entering points and the code will give output informaiton on the CH and show it in a pop-up graph. 
