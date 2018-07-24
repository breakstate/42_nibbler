# Nibbler
Nibbler is yet another snake video game written in C++ including a major twist: dynamic libraries.
Through this project, you will discover the power and usefullness of dynamic
libraries used at runtime. Your goal is splitted in 4 parts : a main executable and 3
dynamic libraries that your main executable will load and use at runtime. Each library
will embed everything your main executable might need to display the game and to get
the player’s inputs. The main executable will only focus on the game logic and interact
with your dynamic libraries. The main executable must interact in a identical way with
any of your libraries.

## Mandatory.

You must create a Snake game made of 4 parts : a main program and 3 dynamic libraries.
Each dynamic library "embeds" a graphical interface and input handling routines for your
game. Let’s state this in another way: each available GUI and input handler for your
game must only exist in a dynamic library that will be loaded and used dynamically by
the main program at runtime. It is strictly FORBIDDEN to do any reference to any
graphic library that you want to use in your main program. Only your dynamic libraries
can do it ! Of course, nothing related to the game logic must appear in any of your
dynamic libraries.

## The game rules
• The unit of measure is the square. The size of a square is up to you, but it must
  be reasonable and can vary from one graphic library to another.
  
• The game area is a finite plane of squares. The edges of the plane can’t be passed
  through.
  
• The snake starts with a size of 4 squares in the middle of the game area. The
  direction does not matter.
  
• The snake progresses forward automatically at a constant speed. That speed is up
  to you. Each section of its tail follows the exact same path than the head.
  
• The snake can’t move backwards.

• The snake must be able to turn left or right using the keyboard.

• The goal of this game is to feed your snake to help it grow. The game area must
  never have less that one element of food. The food position can be random or
  pseudo-random if you want some control on where it spawns.
  
• One food element fills one and only one square of the area.

• When the head of the snake is over a square occupied by food, the food disappears,
  and one section is added to the tail of the snake on the next move on the same
  square as the previous last section.
  
• If the snake hits a wall or one of its own sections, the game is over.

## Bonus part
Once you are done with your project and the 3 dynamic libraries, you can look for some
bonus by extending the game rules. These are some examples:

• A scoring system

• A bonus of food appears for a short period of time

• The head section looks different from the others sections

• The snake speed increases during the game

• The game area has some obstacles

• Sounds ! Please note that this bonus will be accepted if and only if the sound
  library is used the same way as your graphic libraries: through a dynamic library
  that you must create, load and use yourself at runtime. You don’t need to create 3
  though, but that would be badass.

• Multiplayer ! Two snakes fighting for the same food ! Wicked ! Please note that a
  single player mode must remain available.

• Multiplayer through network. Same as above. The project could hardly be more
  badass if you acheive that.
