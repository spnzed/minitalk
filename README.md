<h1 align=center>
	<b>minitalk</b>
	 
  <i>42cursus' project #6</i>
</h2>
The purpose of this project is to code a small data exchange program using UNIX signals. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus.
  <h1 align=center>

![minitalke](https://github.com/spnzed/minitalk/assets/95354392/424f1b53-e3f8-4a36-afb2-b1621d5e197e)


---

<h3 align=center>
Mandatory
</h3>

<b>Game actions:</b>
> <i>The player can move in four directions but cannot move into walls. To exit the game, the player needs to collect something. The WASD keys are used to move the main character, and the game has a top-down 2D view. The movements are displayed in the shell, and pressing ESC must close the window and quit the program cleanly. </i>

<b>Graphics actions:</b>
> <i>The program should display the image within a window, and window management should be smooth, such as switching to another window or minimizing. Pressing the [ESC] key should close the window and quit the program cleanly. The usage of MiniLibX images is mandatory.</i>

<b>Map actions:</b>
> <i>The map must be rectangular/square in shape, surrounded by walls with a clear path to the exit. It should be able to parse any type of map as long as it follows the aforementioned rules and contains three components - the exit, player start position, and collectibles. Additionally, if there is a misconfiguration in the map, the program should return an error message to indicate the issue.</i>

<h3 align=center>


<h2>
The Project
</h2>

### 🗺️ Map Rules

<b>Map Requisites:</b>
- Only ``P`` *(Character)*, ``1`` *(wall)*, ``0`` *(empty)*, ``C`` *(collectible)*, and ``E`` *(exit)* will be accepted characters in our map (except if you add enemies as bonus)
- The map must be rectangular, i.e. all rows must have the same length
- There must be at least one exit, one player, and one collectible on the map
- The map must be closed, i.e. surrounded by walls

> <i>If any of these checks fail, the game must end with a error message.</i>

🏆 | The goal is for the player(s) to collect all the collectibles on the map before going to an exit in the least possible number of steps

<b>Map Creation:</b>
- Create a new text file with a .ber extension. This will be your map file.
- Open the text file in a text editor.
- Define the map dimensions using this 5 symbols to represent different elements on the map:
	- 0 for an empty space
	- 1 for a wall
	- C for a collectible
	- E for a map exit,
	- P for the player’s starting position.

- Create a rectangular or square map, knowing that the map must be surrounded by '1's (walls) and must contain only one 'P' (player's starting point), one 'E' (exit), and multiple 'C's (collectibles). To test all the game features and have a better gaming experience, create a good level design using other game objects such as '0' for empty spaces (where the player can move).
- After creating the map, you can run it by passing the path where the map was created:

### 📁 Structure

* ```libft/```  My own Libft library.
* ```maps/```  Some maps (for running and testing the game).
* ```mlx/```  Mlx library.
* ```src/```  The sauce!
* ```textures/```  All sprites used in the game in .xpm.


---
<h2>
Usage
</h2>

### How to build and run

client needs pid of server, and then text. In files test1.txt and test2.txt you can find sample texts to transfer. Example you can see below.
```
./server
server> PID is: 912354
./client 912354 "Hello world"
server>Hello world
```

### 🛠️ Instructions

**0. Download the archives**

```bash
# Clone the repository
$ git clone https://github.com/spnzed/minitalk.git

# Enter into the directory
$ cd minitalk/
```

**1. Compile the program**
```bash
# Run the command make root directory to run the mandatory part
$ make

# This command compiles the executable files of 'minitalk'
#	Now to execute it, first make the server run:
$ ./server
```
**2. How to play**
- Control the player using the arrow keys (up, down, left, and right) or the letter keys (w, a, s, and d).
- Press the 'R' key on your keyboard to reset the current level.
- Press the [ESC] key or Click in the 'X' window to exit the game.

<p align="center">
<img width="841" alt="Captura de pantalla 2023-08-17 a las 12 01 43" src="https://github.com/spnzed/so_long/assets/95354392/ea6a73d7-2560-4c9f-b3d8-5e7263044a35">

</p>
