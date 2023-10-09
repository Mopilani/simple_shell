#include "main.h"


/**
 * execmd -
 * @argv:
 *
 */
void execmd(_dou_p local_argv, _dou_p env, char **argv)
{

    int _exev_Rv, _status;
    pid_t _child_PID_Rv;
    string cmmd, atl_cmmd;

    (void)env;

    if (local_argv)
    {
        cmmd = local_argv[0];
        atl_cmmd = NULL;

        atl_cmmd = get_PATH(cmmd);
        if (atl_cmmd == NULL)
        {
            perror(argv[0]);
            return;
        }

        _child_PID_Rv = fork();
        
	if (_child_PID_Rv < 0)
        {
            perror(argv[0]);
            if (local_argv != NULL)
            {
                free(local_argv);
                exit(EXIT_FAILURE);
            }
        }
        else if (_child_PID_Rv == 0)
        {
            _exev_Rv = execve(atl_cmmd, local_argv, env);
            if (_exev_Rv == ERROR)
            {
                perror(argv[0]);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&_status);
        }
    }
}
