
A simple macro processor, implemented as a program expand that takes input either from stdin (if called with no arguments) or from one or more files whose names are provided on the command line (if called with one or more arguments).

A macro consists of the pipe symbol '|', followed by the name of a readable file, followed by another pipe symbol '|'. Each occurrence of a macro in stdin or within a single file is replaced by the contents of the named file, expanded according to the same rules. The result of these replacements are then sent to stdout. The pipe symbols are referred to as the delimiters of the macro.

