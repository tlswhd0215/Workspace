#include <stdio.h>
#include <string.h>
#include <signal.h>

int f_chmod(int argc, char **argv)
{
	int i, mode;

	if (argc < 3) {
		printf("Usage: chmod mode file ...\n");
		return -1;
	}

	sscanf(argv[1], "%o", &mode);

	for (i = 2; i < argc; i++)
		if (chmod(argv[i], mode) == -1) {
			perror("chmod failed\n");
			return -1;
		}
	return 0;
}

int f_kill(int argc, char **argv)
{
	int i;
	int signo = 15;

	if (argc < 2) {
		printf("Usage: kill [-signo] pid ...\n");
		return -1;
	}

	if (argv[1][0] = '-') {
		signo = (-1) * atoi(argv[1]);
		i = 2;
	}

	else i = 1;

	for (; i < argc; i++) {
		kill(atoi(argv[i]), signo);
	}

	return 0;
}

void f_cd(int argc, char **argv) {
	char *path;
	if (argc > 1) path = argv[1];
	else if ((path = (char*)getenv("HOME")) == NULL) path = ".";
	if (chdir(path) < 0) {
		printf("error\n");
	}
}

void f_pwd() {
	system("pwd");
}

void main()
{
	char str[200];
	char *argv[100];
	int argc;

	while (1) {
		printf("prompt$ ");
		gets(str);

		if (!strcmp(str, "exit"))
			break;
		else if (!strlen(str))
			continue;
		else {
			argc = 1;
			argv[0] = strtok(str, " ");

			while (argv[argc] = strtok(NULL, " "))
				argc++;

			if (!strcmp(argv[0], "chmod")) {
				f_chmod(argc, argv);
			}

			else if (!strcmp(argv[0], "kill")) {
				f_kill(argc, argv);
			}

			else if (!strcmp(argv[0], "cd")) {
				f_cd(argc, argv);
			}

			else if (!strcmp(argv[0], "pwd")) {
				f_pwd();
			}

			else
				printf("error!!\n");
		}
	}
}