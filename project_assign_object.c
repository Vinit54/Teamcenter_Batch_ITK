#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {

    int i = 0;
    int j = 0;
    int ifail = ITK_ok;
    int iEntryCount = 0;
    int iItemFound = 0;
    int iNumOfUser = 0;

    char** cEntries = NULL;
    char** cValues = NULL;
    char* cItemName = NULL;

    tag_t tQuery = NULLTAG;
    tag_t* tResults = NULLTAG;

    tag_t tItem = NULL;
    tag_t tProject = NULLTAG;
    tag_t tUser = NULLTAG;
    tag_t tGroup = NULLTAG;
    tag_t* tUserTags = NULLTAG;

    char* cProjectId = ITK_ask_cli_argument("-proj_id=");

    // Initialize module
    reportError(ITK_init_module("infodba", "infodba", "dba"));
    printf("\n\n Login success");

    if (cProjectId != NULL) {
        reportError(PROJ_find(cProjectId, &tProject));

        if (tProject != NULL) {
            printf("\n\n Project find success");
            reportError(SA_find_user2("AdminV", &tUser));
            if (tUser != NULL) {
                printf("\n\n User found success");
                reportError(PROJ_add_members(tProject, 1, &tUser));
                printf("\n\n add member success");
            }
        }
    }
    else {
        printf("\n\n Enter value of -proj_id = ?");
    }
  
    // Logout from the module
    reportError(ITK_exit_module(TRUE));
    printf("\n\n Logout Success");

    return 0;
}
