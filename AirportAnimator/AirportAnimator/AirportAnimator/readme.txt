Name: Lance Cole
Developed on Mac/Linux VM

Compile Instructions: It is very important that you include the -lncurses flag when compiling. If this is not included, then compilation will fail.
Run Instructions: Run using the following format: ./executableName passengerNum toursNum.

Solution: 
My solution for this is pretty straightforward. I set up a function that each thread would run, because each plane does the exact same thing.
Once that was done, it was primarily figuring out what information needed to be available to each thread at the same time (that being total tours needed,
total tours done, as well as semaphore pointers). I also used semaphores as a way to control threads with the boarding step and the takeoff/return step.

Answers:
1.Try running your program with only 11 passengers. What happens? Why? 
When you run with only 11 passengers, the run will deadlock pretty quickly as all the threads try to subtract a passenger from the total.
None of the planes fill up, so none of them actually tour.

2.Try running your program with 12 passengers. What happens? Why?
Similar to what happened in problem 1, 12 passengers is not enough to fill any planes and get them to tour. They all get stuck trying to
fill up.

3.Try running your program with 50 passengers and 100 tours. What happens? why?
When running with 50 passengers and 100 tours, one of the planes gets very close to filling up but unfortunately does not completely fill. 
Therefore, the program deadlocks with no planes running a single tour because no plane takes offs due to not being full.

4.Try running your program with 100 passengers and 20 tours. What happens? Why?
When running the program with 100 passengers and 20 tours, the program does a normal run through until the tours done is greater than 
the number of tours we want. It may go over depending on if we still have planes out on tours when we hit 20 tours. This one runs correctly, 
because multiple plains are able fill up completely and tour. Once those come back, the ones that were not full are able to fill up completely and tour.

5.What is the minimum number of passengers that will guarantee avoidance of
deadlock? Why?
The minimum number of passengers that will guarantee avoidance of deadlock is the number of planes * passengers per planes, in this case 8 planes * 12 passengers / plane = 96
passengers. This guarantees that at least one plane will be able to fill to capacity, tour, and return allowing the next not full plane to go.