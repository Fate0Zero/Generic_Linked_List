/**
 *   DO NOT MODIFY THIS FILE IN ANY WAY!!
 * 
 *   You will not be submitting this file for grading, so any changes you
 *   make to it will not be in effect when we evaluate your submission.
 */
 #ifndef DLISTTESTHARNESS_H
#define DLISTTESTHARNESS_H
#include <stdio.h>
#include <stdbool.h>

struct _Scores {
    // points awarded, per category
    unsigned int Initialization;
    unsigned int Insertion;
    unsigned int Deletion;
    unsigned int Reporters;
    
    // points deducted, per category
    unsigned int dInitialization;
    unsigned int dInsertion;
    unsigned int dDeletion;
    unsigned int dReporters;
};
typedef struct _Scores Scores;

bool testDList(FILE* Log);
Scores getScores();

#endif

