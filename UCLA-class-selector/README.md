This program is a proof of concept for a future web app focused on making it easier to know which classes a student can currently take.

To run, simply put both files in a development environment of your choice, and compile them.
The resultant .exe takes in user input in a very specific manner, the program has not been written to accept whitespace.

Some notes:
1. This program at the moment only spits out absolutely required courses in CS, Math, and Physics specifically for CS students.
2. User input should consist of only course numbers with letters and commas, any typos might result in an error.
3. For courses labeled with both a number and a letter (e.g. CS35L), include both (input "35L")
4. The program does not differentiate between courses you have completed and have credit for. So, input them as if you completed the course.
5. There is currently no functionality for electives or tech breadths or other GE's.
6. The program does not take into account corequisites or recommended(rather than enforced) rerequisites.

Here's an example, using classes that a freshman CS student might have taken:
"Hello CS UCLA goer!
Loading Classes... All classes loaded!
Please Enter all CS Courses you have taken (In format "31,M51,33" etc., or NONE)
31

Let's see... so far you have taken 1 CS class(es), the following:
CS31

Please Enter all MATH Courses you have taken (In format "31,M51,33" etc., or NONE)
31A,31B,32A

Let's see... so far you have taken 3 MATH class(es), the following:
MATH31A
MATH31B
MATH32A

Please Enter all PHYSICS Courses you have taken (In format "31,M51,33" etc., or NONE)
1A

Let's see... so far you have taken 1 PHYSICS class(es), the following:
PHYSICS1A

Classes you can take are:
CS32
CS35L
PHYSICS1B
PHYSICS4AL
MATH32B
MATH33A
MATH33B
MATH61"

As mentioned above, current supported classes are only CS, Math, and Physics classes ABSOLUTELY required to get a CS degree, listed below:
CS: 1, 31, 32, 33, 35L, M51A, 97, 111, 118, 130, 131, 132, M151B, M152A, 180, 181
Math: 31A, 31B, 32A, 32B, 33A, 33B, 61
Physics: 1A, 1B, 1C, 4AL
