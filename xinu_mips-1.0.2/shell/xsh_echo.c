/**le     xsh_echo.c
 * @provides xsh_echo
 *  *
 *   * $Id: xsh_help.c 226 2007-07-12 01:18:27Z mschul $
 *    */
/* Embedded XINU, Copyright (C) 2007.  All rights reserved. */

#include <kernel.h>
#include <shell.h>
#include <stdio.h>
#include <string.h>

/**
 *  * Shell command (help) provides a list of commands recognized by the
 *   * shell, or displays help information for a particular command.
 *    * @param stdin  descriptor of input device
 *     * @param stdout descriptor of output device
 *      * @param stderr descriptor of error device
 *       * @param nargs  number of arguments in args array
 *        * @param args   array of arguments
 *         * @return OK for success, SYSERR for syntax error
 *          */
command xsh_echo(ushort stdin, ushort stdout, ushort stderr,
                 ushort nargs, char *args[])
{
	int i;
	char *command_args[2]; /* temporary storage for [command] --help */

	/* Output help, if '--help' argument was supplied */
	if (nargs == 2 && strncmp(args[1],"--help",6) == 0) 
	{
		fprintf(stdout, "Usage: clear\n");
		fprintf(stdout, "Clear the terminal\n");
		fprintf(stdout, "\t--help\t display this help and exit\n");
		return SYSERR;
	}

	/* loop through the arguments printing each as it is displayed */
	 for ( i = 1; i < nargs; i++ )
    {
        fprintf(stdout, "%s ", args[i]);
    }
 
    /* Just so the next prompt doesn't run on to this line */
    fprintf(stdout, "\n");
 
    /* there were no errors so, return OK */
    return OK;
}
