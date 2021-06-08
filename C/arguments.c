    char* args[127];
    //127 because i found it on google and sysconf(_SC_ARG_MAX) didn't work
    //Splitting the input after every " " or " \t"
  	char* part = strtok(cmd, " \t");
    args[0] = part;
    int i = 0;

    while(part != NULL)
    {
  	   part = strtok(NULL, " \t");
  	   args[++i] = part;
    }
