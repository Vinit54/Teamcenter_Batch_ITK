// Header.h

#include<stdio.h>
#include<tc/tc_startup.h>
#include<tcinit/tcinit.h>
#include<tc/emh.h>
#include<tccore/item.h>
#include<tc/folder.h>
#include<sa/user.h>
#include<tccore/aom.h>
#include<stdlib.h>
#include<ae/dataset.h>
#include<ae/datasettype.h>
#include<tccore/grm.h>
#include<tccore/workspaceobject.h>
#include<tccore/aom_prop.h>
#include<string.h>
#include<fclasses/tc_string.h>
#include<qry/qry.h>
#include<tccore/project.h>
#include<bom/bom.h>
#include<tccore/tctype.h>

//FILE* file;

int reportError(int ifail) {
	char* cError = NULL;
	if (ifail != ITK_ok) {
		EMH_ask_error_text(ifail, &cError);
		printf("\n\n Error is : %s", cError);
		MEM_free(cError);
		exit(0);
	}
	return 0;
}

typedef struct {
	char* cItemID;
	char* cItemName;
	char* cItemType;
}input_t;

//void displayUsage() {
//	printf("\n\n Teamcenter -- Utility to login");
//	printf("\n\n Usage -- To initialize teamcenter for customization");
//	printf("\n\n -u = \t Login User ID");
//	printf("\n\n -p = \t Login Password");
//	printf("\n\n -g = \t Group");
//	printf("\n\n -h \t To display detailed info of utility");
//	printf("\n\n -help \t To display detailed info of utilit");
//}
