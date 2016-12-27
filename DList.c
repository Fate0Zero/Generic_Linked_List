#include "DList.h"

//On my honor:
//
//-I have not discussed the C language code in my program with
// anyone other than my instructor or the teaching assistants 
// assigned to this course.
//
//-I have not used C language code obtained from another student, 
//or any other unauthorized source, either modified or unmodified.  
//
//-If any C language code or documentation used in my program 
//was obtained from an allowed source, such as a text book or course
//notes, that has been clearly noted with a proper citation in
//the comments of my program.
//
//Yuhui Lyu
//
void DNode_Init(DNode* const pN) {
	pN->prev = NULL;
	pN->next = NULL;
}
void DList_Init(DList* const pL) {
	pL->fGuard.prev = NULL;
	pL->fGuard.next = &pL->rGuard;
	pL->rGuard.next = NULL;
	pL->rGuard.prev = &pL->fGuard;
}
bool DList_Empty(const DList* const pL){
	return (pL->fGuard.next == &pL->rGuard);
}
void DList_PushBefore(DNode* const pBefore, DNode* const pNode){
	DNode* temp = pBefore->prev;
	temp->next = pNode;
	pBefore->prev = pNode;
	pNode->prev = temp;
	pNode->next = pBefore;
}
void DList_PushFront(DList* const pL, DNode* const pNode){
	pNode->prev = &pL->fGuard;
	pNode->next = pL->fGuard.next;
	pL->fGuard.next->prev = pNode;
	pL->fGuard.next = pNode;
}
void DList_PushRear(DList* const pL, DNode* const pNode) {
	pL->rGuard.prev->next = pNode;
	pNode->prev = pL->rGuard.prev;
	pNode->next = &pL->rGuard;
	pL->rGuard.prev = pNode;
}
DNode* DList_PopBefore(DNode* const pBefore) {
	DNode* temp = pBefore->prev;
	DNode* temp2 = temp->prev;
	pBefore->prev = temp2;
	temp2->next = pBefore;
	return temp;
}
DNode* DList_PopFront(DList* const pL) {
	if (DList_Empty(pL)) {
		return NULL;
	}
	else {
		DNode* temp = pL->fGuard.next;
		DNode* temp2 = temp->next;
		temp2->prev = &pL->fGuard;
		pL->fGuard.next = temp2;
		return temp;
	}
}
DNode* DList_PopRear(DList* const pL) {
	if (DList_Empty(pL)) {
		return NULL;
	}
	else {
		DNode* temp = pL->rGuard.prev;
		DNode* temp2 = temp->prev;
		temp2->next = &pL->rGuard;
		pL->rGuard.prev = temp2;
		return temp;
	}
}
const DNode* DList_Front(const DList* const pL) {
	if (DList_Empty(pL)) {
		return NULL;
	}
	else {
		DNode* f = pL->fGuard.next;
		return f;
	}
}
const DNode* DList_Back(const DList* const pL) {
	if (DList_Empty(pL)) {
		return NULL;
	}
	else {
		DNode* r = pL->rGuard.prev;
		return r;
	}
}