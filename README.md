# CS335-Project2-Part1 
by Yu Tong Chen
HashTable Implementation

### Aril 7, 2019
Started working on the project, successfully implemented all functions within the GPS class. One thing I'm not sure about is how 
throwing a struct works, specifically, GPS::GPS(double lon, double lat) throw(BadPoint). Did some research and still not sure. The struct
is empty so does that mean I have to add stuff in there? 

### April 8, 2019
Continued on the project by working on _hash_item.h and _hash_item.cpp. So far so good, was able to successfully implement all the functions
one again. 

### April 9, 2019
Last part of the project was to derive the hash_table from abstract class and implement the functions. Blanked out intially and had to
do alot of studying/research in order to fully grasp the concept of hash tables. Started the day slow by writing constructors, destructors,
and adding in some private variables. Decided to do a linear probing to resolve collisions. One thing I wasn't sure about is the
size of the table. We are given a default INITIAL_SIZE but in main, a HashTable object is created with 2000, which I'm assuming is also
a size. What I did was create a default constructor and set the table size to Initial Size and another constructor that takes a parameter
and have that parameter be set to whatever parameter is provided in main when creating a HashTable object. I think this approach made sense.
Another idea I had to differentiate bewteen INITIAL_SIZE and the parameter HashTable object had was for maybe resizing. If the provided n
approached INITIAL_SIZE, calculated through the load factor, resizing would be done. I follow through with this approach.

### April 12, 2019
Started the day by working on the find function, was able to successfully implement it. Then started working on the rest of the functions,
starting with insert then remove, size, and lastly listall. Insert function worked and so continued to Remove. The tricky thing with remove 
is that you don't want to actually remove the node but rather mark the index with a marker to signify it has been removed. Both ways 
will and might cause issues in the long run when searching causing the runtime to go from O(1) to O(n) when using open addressing and solving 
collisions through linear probing. Nevertheless, remove was implemented and so was the size function. Lastly, listall was implemented, 
tested all the functions and so far, everything works as it should. No errors. Just hoping that when Professor Weiss runs the code, it will
be error free as well.
