#include <kernel.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

// Define the two unique usernames
char USERNAME1[] = "user1";
char PASSWORD1[] = "pass1";
char USERNAME2[] = "user2";
char PASSWORD2[] = "pass2";

// Declare local function definitions
local chat  (ushort, ushort, char *name);

// The following function logs a user in, and begins the chat program
command xsh_chat (ushort stdin, ushort stdout, ushort stderr, ushort nargs, char *args[]) {

	// Define variables
	char username[20];
	char password[20];
	int logged_in_status = 0;
	
	// Continue prompting until the user has logged in
	do {
	// Retrieve username and password from user
	fprintf (stdout, "\nUsername: ");
	read    (stdin,  username, 20);
	
	fprintf (stdout, "Password: ");
	read    (stdin,  password, 20);

	// Check to see if the login was successfull
	if ( (strncmp(username, USERNAME1, 5) == 0   &&
	strncmp(password, PASSWORD1, 5) == 0 ) ||
	(strncmp(username, USERNAME2, 5) == 0   &&
	strncmp(password, PASSWORD2, 5) == 0 ) ) 
	
	{
		// Greet the user and proceed to the chat room
		username[5] = '\0';
		fprintf (stdout, "\nWelcome back %s \n\n", username);
		logged_in_status = 1;
	}
	else
	{
	// Continue prompting for a login if unsuccessful login
	fprintf (stdout, "\nIncorrect username/password. ");
	fprintf (stdout, "Please try again!\n");
	}
	} while (logged_in_status == 0);
	
	// Begin the chat room
	if (stdin == TTY0)
	chat (TTY0, TTY1, username);
	else if (stdin == TTY1)
	chat (TTY1, TTY0, username);

	return OK;
	}

	// Chat room function
	local chat (ushort in, ushort out, char *name) {
	
	// Define local variables
	char message[50];
	int i;
	int exit = 0;

	// Continue chat room until the user exits
	while (exit == 0) {

	// Clear the message buffer
	for (i=0; i<50; i++) {	
	message[i] = '\0';
	}
	
	// Take in the user message to send
	read(in, message, 50);

	// If the user typed 'exit' then quit
	if ( strncmp(message, "exit", 4) == 0) {
	exit = 1;
	strcpy(message, "** HAS LEFT THE CHAT **");
	}

	// Send out the chat message
	fprintf(out, "\x1B[31m" "%s: " "\033[0m", name);
	write(out, message, strlen(message));
	}
	return OK;
}
