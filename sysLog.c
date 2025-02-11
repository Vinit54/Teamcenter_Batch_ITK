#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {

	int ifail = ITK_ok;

	FILE* fp = NULL;
	char* cError = NULL;

	char* cUserID = ITK_ask_cli_argument("-u=");
	char* cPassword = ITK_ask_cli_argument("-p=");
	char* cGroup = ITK_ask_cli_argument("-g=");

	fp = TC_fopen("V_ITK.syslog", "w");

	if (fp == NULL) {
		printf("\n\n File isn't created");
		exit(0);
	}

	TC_printf("---------------------------------------------------------------------------------------------------------");
	TC_printf("---------------------------------------Login Utility-----------------------------------------------------");
	TC_printf("---------------------------------------------------------------------------------------------------------");

	TC_write_syslog("---------------------------------------------------------------------------------------------------");
	TC_write_syslog("--------------------------------Login Utility------------------------------------------------------");
	TC_write_syslog("---------------------------------------------------------------------------------------------------");
	
	if (!cUserID || !cPassword || !cGroup) {
		printf("\n\n Enter value of -u=? -p=? -g=?");
		TC_write_syslog("\n\n Err: Enter value of -u=? -p=? -g=?");
		TC_fprintf(fp, "\n\n Err: Enter value of -u=? -p=? -g=?");
		exit(0);
	}
	else {
		ifail = ITK_init_module(cUserID, cPassword, cGroup);
		if (ifail == ITK_ok) {
			printf("\n\n Login success");
			TC_write_syslog("\n\n Login success");
			TC_fprintf(fp, "\n\n Login success");
		}
		else {
			EMH_ask_error_text(ifail, &cError);
			printf("\n\n error is : %s", cError);
		}
	}
	
	// Logout from the module
	reportError(ITK_exit_module(TRUE));
	//printf("\n\n Logout Success");

	return ifail;
}