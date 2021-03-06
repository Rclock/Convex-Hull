# Convex-Hull
A Convex Hull algorithm with visual representation and user-input. 



This project will ask for user-input of point coordinates to graphically display a matching Convex Hull. It uses the Graham's Scan method and the cross product method for sorting by polar angle. The code uses Python 2.7 to enable graphing functions within a new namespace in c++. If you do not know what a CH is, here is a brief description: 
A CH is basically used to find a perimeter of any set of points. It has absolutely no concavities, and is always some type of polygon. There is no restriction on the number of edges, it could just be a simple triangle or it could have 30 edges. CH is widely used in geometric problems and other geometric algorithms today. 


To run the code, you'll need Python 2.7 installed on your system and you will have to include its location when you compile. 

To install python 2.7 on your system in Ubuntu Linux: 

sudo apt-get install python-matplotlib python-numpy python2.7-dev

You also have to download the "matplotlibcpp.h" file and have it located in the local directory that the project is running in. This is used for the visual plotting. The header file is located above in the files for this repository. the All of these things accomplished, it should compile and run. 

Assuming python2.7 is installed in "/usr/include/", Add "-I/usr/include/python2.7 -lpython2.7" to the end of whatever your makefile/compile code is. 

For example, this is one way to compile the project with debug info:  

g++ -o convex convexhull.cpp -std=c++11 -I/usr/include/python2.7 -lpython2.7 -g



How to run code: ./convex
After executing, enter two integers, each followed by an enter key, to specify points to be used. When you are done adding points, enter anything above the integer 15 to stop entering points and the code will give output information on the CH and show it in a pop-up graph. 



As for future goals for this project, I'd like to try to get it to work for 100% of cases. Currently, it works for probably 95% of cases that I've thrown at it. There exists an issue with > or >= operators for cases of co-linearity, but I am not sure which one is the best to use. I have seen cases where it works using > and not >=, vice versa.  Currently, if you throw maybe 25 points at it, it will sometimes have a single concavity. I'm not sure if this happens because of the total number of points I am using or if those points had a lot of co-linear pairs or what. I will continue researching and running it until hopefully one day it works for every case we can think of. This project was truly challenging to work on, but it's been worth it. I hope to get it fully working in the near future.  
