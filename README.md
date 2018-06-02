# Convex-Hull
A Convex Hull algorithm with visual representation and user-input. 



This code uses c++ in a single main function to take user-input of point coordinates to display a proper Convex Hull graphically. It uses the Graham's Scan method and the cross product method for sorting by polar angle. The code uses Python 2.7 to enable graphing functions within a new namespace in c++. If you do not know what a CH is, here is a brief description: 
A CH is basically used to find a perimeter of any set of points. It has absolutely no concavities, and is always some type of polygon. There is no restriction on the number of edges, it could just be a simple triangle or it could have 30 edges. CH is widely used in geometric problems and other geometric algorithms today. 

To run the code, you'll need Python 2.7 installed on your system and you must include the below statement in your makefile. You must use the matplotlibcpp.h header file and download it. All of these things accomplished, it should compile and run. 
Add "-I/usr/include/python2.7 -lpython2.7" to the end of whatever your makefile code is. 

How to run code: 
After executing, enter two integers, each followed by an enter key, to specify points to be used. When you are done adding points, enter anything above the integer 15 to stop entering points and the code will give output information on the CH and show it in a pop-up graph. 



As for future goals for this project, we'd like to try to get it to work for 100% of cases. Currently, it works for probably 90% of cases that we've thrown at it. There exists an issue with > or >= operators for cases of co-linearity, but we are not sure which one is the best to use. We have seen cases where it works using > and not >=, vice versa. It currently uses >= in the while loop in step 8 of the Graham's Scan algorithm. This way, if you throw a lot of points with the same co-linearity at it, it will have issues. If you change it back to >, it will do fine with co-linearity but might have a concavity if you throw 20-25 points at it. We are not sure why. We will continue researching and running it until hopefully one day it works for every case we can think of. This project was truly challenging to work on, but it's been worth it. We hope to get it fully working in the near future. 
