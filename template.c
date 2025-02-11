#include "Header.h"


int ITK_user_main(int argc, char* argv[]) {

	// Login to the infodba module (assuming reportError handles errors)
	reportError(ITK_init_module("infodba", "infodba", "dba"));
	printf("\n\nLogin success");

	// Logout from the module
	reportError(ITK_exit_module(TRUE));
	printf("\n\nLogout Success\n");

	return 0;
}