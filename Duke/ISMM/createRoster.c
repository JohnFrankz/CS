#include <stdio.h>
#include <stdlib.h>
#include "roster.h"


/*
    Check that the argc == 2 (fail if not)
    Read the input from the file named by argv[1] (call this the_roster)
    Check that r != NULL (fail if not)
    Create the list of all of the class names (call this result unique_class_list)
    Write all the class roster files from unique_class_list and the_roster
    Free memory held by unique_class_list
    Free memory held by the_roster
    return EXIT_SUCCESS
*/
int mai(int argc, char ** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: roster inputname\n");
        return EXIT_FAILURE;
    }
    roster_t roster = readInput(argv[1]);
    if (roster == NULL) {
        fprintf(stderr,"Could not read the roster information\n");
        return EXIT_FAILURE;
    }
    printClassRoster(roster);
    // classes_t unique_class_list = getClassList(roster);
    // writeAllFiles(unique_class_list, roster);
    // freeClasses(unique_class_list);
    // freeRoster(roster);
    return EXIT_SUCCESS;
}