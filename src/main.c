#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "shell.h"

int main(void) {
	//char line[MAX_LINE]; // buffer for typing
	// readlinecode
	char *argv[MAX_ARGS + 1]; // array of word pointers
	
	// persistent history
	read_history(".shell_history");

	for (;;) {
		//readline
		char *line = readline("shellzinha> " );

		if (line == NULL) {
			putchar('\n');
			break;
		}

		if (*line != '\0') {
			add_history(line);
		}
		//legacy line reading:
		//
		//fputs("shellzinha> ", stdout); // print prompt
		//fflush(stdout);

		//if (!fgets(line, sizeof line, stdin)) {
		//	putchar('\n');		// user pressed Ctrl-D
		//	break;
		//}
		//

		//line[strcspn(line, "\n")] = '\0'; // finds \n and replaces with \0
													 
		int argc = tokenize(line, argv);
		if (argc == 0) { free(line); continue; };

		// built-in commands:
		if(strcmp(argv[0], "exit") == 0) { free(line); break; } // if user types "exit", quit
		if(strcmp(argv[0], "pwd") == 0) {
			char buf[1024];

			if(getcwd(buf, sizeof buf) == NULL) {
				perror("pwd");
				free(line);
				continue;
			}
			printf("%s\n", buf);
			free(line);
			continue;
		}

		if(strcmp(argv[0], "cd") == 0) {
			if(argc == 1) {
				char *env_value = getenv("HOME");
				if (env_value == NULL) { // bug fix incase home is not set
					fprintf(stderr, "cd: HOME not set\n");
					free(line);
					continue;
				}
				if (chdir(env_value) == 0) {
					printf("Changed directory to %s\n", env_value);	
					free(line);
					continue;
				} else {
					perror("cd failed");
					free(line);
					continue;
				}
			} else {
				if (chdir(argv[1]) == 0) {
					free(line);
					continue;
				} else { 
					perror("cd failed");
					free(line);
					continue;
				}
			}
		}
		
		// for debug:
		//	for(int i = 0; i < argc; i++) {
		//		printf(" arg[%d] = \"%s\"\n", i, argv[i]);
		//	}
		run_command(argv);

		free(line);
	}
	// persistent loop
	write_history(".shell_history");

	return 0;
}
