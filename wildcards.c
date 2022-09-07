#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void expandWildcardsIfNecessary(char * arg)
{
	/* return if arg does not contain "*" or "?" */
	if(arg != "*" | arg != "?")
	{
		Command::_currentSimpleCommand ->insertArgument(arg);
		return;
	}
	/* convert wildcard to regular expression */
	/* also add ^ at the beginning and $ st the end to match beginning and end of word */
	/* allocate enough space for regular expression */
	char * reg = (char *)malloc(2 * strlen(arg) + 10);
	char * a = arg;
	char * r = reg;
	*r = '^' ; r++; /* match beginning of line */
