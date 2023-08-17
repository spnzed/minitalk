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
