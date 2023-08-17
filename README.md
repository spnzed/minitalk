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

<b>Create a communication program in the form of a client and a server:</b>
> <i> The server must be started first. After its launch, it has to print its PID. The client takes two parameters: The server PID, the string to send. The client must send the string passed as a parameter to the server.</i>

<b>Once the string has been received, the server must print it:</b>
> <i> The server has to display the string pretty quickly. Quickly means that if you think
it takes too long, then it is probably too long.</i>

<b>1 second for displaying 100 characters is way too much:</b>
> <i> Your server should be able to receive strings from several clients in a row without
needing to restart. The communication between your client and your server has to be done only using
UNIX signals. You can only use these two signals: SIGUSR1 and SIGUSR2.</i>

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
#	Then server will give us it's PID
$ server> PID is: 912354
```
**2. Make it run (or talk!)**
```bash
# Client needs the PID of server, and then text. Example you can see below.
$ ./client 912354 "Hello world"
#	Then server will give us the message!
$ server>Hello world
```
 
</p>
