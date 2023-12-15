#include "main.h"

/**
	* supress_err - void func
	* Description: supresses errors and exits on passed exit code
	* @exitcode: -1 if n/a, exitcode>0 when exit desired
	* @mode: where to send errors (null or to terminal)
	*/
void supress_err(int exitcode, int mode)
{
	if (exitcode == -1)
	{
		if (mode == 0)
			freopen("/dev/tty", "w", stderr);
		if (mode == 1)
			freopen("dev/null", "w", stderr);
	}
	freopen("dev/tty", "w", stderr);
	if (mode == 2)
		exit(exitcode);
}
