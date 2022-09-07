#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/** Command data structure that describes command and arguments
 */
struct simpleCommand
{
	/* existing space for arguments currently preallocated*/
	int _numberOfAvailableArguments;

	/* Number of arguments*/
	int _numberOfArguments;
	/* Array of arguments*/
	char **_arguments;

	simpleCommand();
	void insertArgument(char *argument);
};
/* describes a complete command with multiple pipes*/
/* or input output redirections if any*/
struct Command 
{
	int _numberOfAvailableSimpleCommands;
	int _numberOfSimpleCommands;
	simpleCommand **_simpleCommands;
	char *_outFile;
	char *_inputFile;
	char *_errFile;
	int _background;

	void prompt(void);
	void print(void);
	void execute(void);
	void clear(void);

	Command();
	void insertSimpleCommand(simpleCommand *SimpleCommand);

	static Command _currentCommand;
	static simpleCommand *_currentSimpleCommand;
};
