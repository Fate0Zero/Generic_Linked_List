/**  Test/grading driver for C01 Generic List in CS 2506 Fall 2016.
 * 
 *   Execution:  driver [-rand]
 *   Output:
 *        InitLog.txt       results of testing initialization logic
 *        InsertLog.txt     results of testing insertion logic
 *        DeleteLog.txt     results of testing deletion logic
 *        ReportersLog.txt  results of testing reporter functions
 *        Summary.txt       summary of scores for all tests
 *        Seed.txt          randomization seed used in testing
 * 
 *   If the switch -rand is used, the seed value will be taken from the
 *   current system clock, and a new sequence of test data will be used;
 *   otherwise the seed value will be taken from the existing Seed.txt
 *   file, so the most recent test data will be regenerated.
 */
 
/**
 *   BE WARNED:
 * 
 *   You will not be submitting this file for grading, so any changes you
 *   make to it will not be in effect when we evaluate your submission.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

#include "DListTestHarness.h"
static void reportScores(FILE* Log);

//  The following are file-scoped in order to make them accessible to the
//  signal handler.
static FILE* Log  = NULL;
static unsigned int Seed = 0;

/**  Custom handler invoked if a segmentation fault occurs during execution of
 *   the program.  It merely logs some information to the summary log file and
 *   exits the process.
 */
void handler(int sig) {
    
    fprintf(stdout, "OOPS!!\nCaught a SIGSEGV!!\nRandomization seed was %d.\n\n", Seed);
    
    fflush(Log);
    fprintf(Log, "Note that testing was interrupted by a SIGSEGV.\n");
    fprintf(Log, "As a result, the various test logs may be incomplete.\n");
    fprintf(Log, "You should rerun your test under gdb, using the same seed.\n");
    fprintf(Log, "Randomization seed was %d.\n\n", Seed);
    
    reportScores(Log);
    fclose(Log);
    exit(-1);
}

int main(int argc, char** argv) {
    
   // Register the segfault handler:
   signal(SIGSEGV, handler);

   // Create summary log file:
   Log = fopen("Summary.txt", "w");
   
   // Select randomized or repeated testing logic:
   if ( argc == 2 && strcmp(argv[1], "-rand") == 0 ) {
      Seed = time(NULL);
      FILE* fp = fopen("Seed.txt", "w");
      fprintf(fp, "%d\n", Seed);
      fclose(fp);
	}
	else {
		FILE* fp = fopen("Seed.txt", "r");
		if ( fp == NULL ) {
			printf("Error invoking driver; see specification.\n");
			return 1;
		}
		fscanf(fp, "%d", &Seed);
		fclose(fp);
	}
	fprintf(Log, "Seed value: %d\n", Seed);
   srand( Seed );

   bool succeeded = true;
   if ( ! (succeeded = testDList(Log)) ) {
      fprintf(Log, "Errors found testing DList implementation.\n");
      fprintf(Log, "See the log files for more information.\n\n");
   }
   
   fprintf(Log, "\n");
   reportScores(Log);
   fclose(Log);
   
   if ( succeeded )
      return 0;
   else
      return -1;
}

/**  Writes a summary of the individual test scores.
 * 
 *   Pre:  Log is open on the file to hold the summary report.
 */
static void reportScores(FILE* Log) {
    
    unsigned int total = 0;
    Scores results = getScores();
    
    fprintf(Log, "Initialization:  %4u", results.Initialization);
    if (results.dInitialization != 0 ) {
        fprintf(Log, "   (deducted:  %3u)", results.dInitialization);
    }
    fprintf(Log, "\n");
    total += results.Initialization;
    
    fprintf(Log, "Insertion:       %4u", results.Insertion);
    if (results.dInsertion != 0 ) {
        fprintf(Log, "   (deducted:  %3u)", results.dInsertion);
    }
    fprintf(Log, "\n");
    total += results.Insertion;
    
    fprintf(Log, "Deletion:        %4u", results.Deletion);
    if (results.dDeletion != 0 ) {
        fprintf(Log, "   (deducted:  %3u)", results.dDeletion);
    }
    fprintf(Log, "\n");
    total += results.Deletion;
    
    fprintf(Log, "Reporters:       %4u", results.Reporters);
    if (results.dReporters != 0 ) {
        fprintf(Log, "   (deducted:  %3u)", results.dReporters);
    }
    fprintf(Log, "\n");
    total += results.Reporters;
    
    fprintf(Log, "Total score:     %4u\n", total);
    
    // Write tab-separated scores for easy import to spreadsheet:
    fprintf(Log, "\nScores:\t%3u\t%3u\t%3u\t%3u\n", 
            results.Initialization, results.Insertion, results.Deletion, results.Reporters);
}
