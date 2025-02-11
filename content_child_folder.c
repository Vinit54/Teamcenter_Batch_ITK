#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {
    int iCount = 0;
    int iObjCount = 0;
    char* cFolderName = NULL;
    char* cValue = NULL;
    tag_t* tSearchList = NULLTAG;
    tag_t* tObjects = NULLTAG;
    tag_t tUser = NULLTAG;
    WSO_search_criteria_t tCriteria;

    // Initialize module
    reportError(ITK_init_module("infodba", "infodba", "dba"));
    printf("\n\n Login success");

    // Clear search criteria before applying
    reportError(WSOM_clear_search_criteria(&tCriteria));
    printf("\n\n clear search criteria");

    // Find user
    reportError(SA_find_user2("infodba", &tUser));
    printf("\n\n Find user success");

    // Set criteria for searching "Folder" objects of class "TATA"
    tc_strcpy(tCriteria.class_name, "Folder");  // Set the class name criteria
    tc_strcpy(tCriteria.name, "TATA");  // Set the folder name criteria
    tCriteria.owner = tUser;

    // Perform the search
    reportError(WSOM_search(tCriteria, &iCount, &tSearchList));
    printf("\n\n Search success");

    // Iterate over all search results (found folders)
    for (int i = 0; i < iCount; i++) {
        reportError(WSOM_ask_name2(tSearchList[i], &cFolderName));
        printf("\n\n Folder name: %s", cFolderName);

        // Retrieve references (children) of the folder
        reportError(FL_ask_references(tSearchList[i], FL_fsc_by_name, &iObjCount, &tObjects));
        printf("\n\n Found %d children:", iObjCount);

        // Iterate over the children (objects) and print their names
        for (int j = 0; j < iObjCount; j++) {
            reportError(WSOM_ask_name2(tObjects[j], &cValue));
            printf("\n\n %d. Child name: %s", j + 1, cValue);
        }

        // Handle case when there are no children
        if (iObjCount == 0) {
            printf("\n\n No children found for folder: %s", cFolderName);
        }
    }

    // Free memory allocated for the search results and objects
    if (tSearchList) {
        MEM_free(tSearchList);
    }
    if (tObjects) {
        MEM_free(tObjects);
    }

    // Logout from the module
    reportError(ITK_exit_module(TRUE));
    printf("\n\n Logout Success");

    return 0;
}
