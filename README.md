- Simple Shell -

Features :

- Can handle commands in both interactive and non interactive mode
- has some limited access to built-ins, such as exit, env, setenv, and unsetenv

Main Functions : 

- main.c : entry point
- prompter : provides prompt and reads in input
- prompt_tokenizer : splits words of arguments in command line into an array of pointers
- path_builder : use a singly linked list and the PATH environment variable to build a list of paths to executable directories
- interpreter : uses strcmp to determine if a cmd passed was to access a built-in - if not proceed as normal
- finder : if a path was passed, that file will be checked to make sure it exists at given path and executed if it does
- file_finder if a file was not passed, the singly list built with content from the PATH variable is used in order to search for the given command in the PATH
-  free : frees the PATH singly linked list and the array of user commands

Significant files:
- helper.c : contains various implementations for c standard functions (not really necessary)
- built-in : contains implementations of whatever built in command a user passes

Extra info:
This is my first big c-project, there may be some undesirable behaviour such as not returning an exit code on fail and will only do so when exit is explicitly passed to the program, and instead prompting the user again (with no further connected issues)
If you have any suggestions or want to fix any issues (or have spotted any issues that you're aware of how to fix) please let me know - especially it involves how error handling should be done as I'm still learning that,
I'll likely do another large project in c and focus on proper error ettiquette as compensation.
Also in retrospect and especially as I've looked into shell scripting in c since this project has been finished, there's better ways to ensure you don't allocate more memory than necessary by use of realloc in a loop to prevent segfaults,
because currently I'd expect one to happen past 1000 bytes (so file reading is not a practical feature)
