#include "Header.h"

int ITK_user_main(int argc, char* argv[]) {
  
    int i = 0;
    int j = 0;
    int iEntryCount = 0;
    int iItemFound = 0;

    char** cEntries = NULL;
    char** cValues = NULL;
    char* cItemName = NULL;

    tag_t tQuery = NULLTAG;
    tag_t* tResults = NULLTAG;

     // Initialize module
    reportError(ITK_init_module("infodba", "infodba", "dba"));
    printf("\n\n Login success");

    // finding query
    reportError(QRY_find2("Item Name", &tQuery));

    if (tQuery != NULL) {
        printf("\n\n Query find success");
        reportError(QRY_find_user_entries(tQuery, &iEntryCount, &cEntries, &cValues));
        if (cEntries != NULL) {
            printf("\n\n qyery entry find success");
            for (i = 0; i < iEntryCount; i++) {
                if (tc_strcmp(cEntries[i], "Item Name") == 0) {
                    tc_strcpy(cValues[i], "*");
                    reportError(QRY_execute(tQuery, iEntryCount, cEntries, cValues, &iItemFound, &tResults));
                    if (tResults != NULLTAG) {
                        printf("\n\n Numbers of item found : %d", iItemFound);
                        for (j = 0; j < iItemFound; j++) {
                            reportError(WSOM_ask_name2(tResults[j], &cItemName));
                            printf("\n\n Item Name is : %s", cItemName);
                        }
                    }
                }
            }
            if (cEntries) {
                MEM_free(cEntries);
            }
            if (cValues) {
                MEM_free(cValues);
            }
            if (tResults) {
                MEM_free(tResults);
            }
        }
    }

    // Logout from the module
    reportError(ITK_exit_module(TRUE));
    printf("\n\n Logout Success");

    return 0;
}
