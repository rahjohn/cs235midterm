# cs235midterm
Red Rover
The purpose of this midterm is to simulate the game Red Rover, in part by implementing a
double-linked list data structure. If a double-linked list is not used, you will be subject to a 50% penalty
in any section of the midterm where other than a double-linked list is used. Your linked list structure
will consist of Player nodes. A Player node will consist of a name, strength, speed, and pointers to the
nodes on either side of the Player node. Do not use any predefined data structures in your program.
Here is how our version of Red Rover is played:
1. There are two teams consisting of the same number of Players, Team A and Team B. Each
team forms a straight line, holding hands. The two teams face each other.
2. Team A decides whom to “call over” from Team B.
3. Once Team A has decided, they chant, “Red Rover, Red Rover, send (name) right over!”
4. The player from Team B who is called must run toward Team A and try to break through the
arms of two Team A players.
5. If the player from Team B fails to break through, he becomes a member of Team A. But if he
breaks through, he goes back to his original team, Team B, and takes a member of Team A with
him. The player he takes back is the stronger of the Players whose connection he broke.
6. Now it is Team B's turn to decide whom to “call over” from Team A.
7. Play continues back and forth until one team only has one Player left. The game ends and the
larger team wins.
