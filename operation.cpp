#include "list.h"
#include "operation.h"
#include "my_data.h"


void insertAndSort(List &L, infotype x) {
    /**
    * IS : List may be empty
    * PR : insert a new element into an already sorted-by-ID List L
    *      so that the elements inside List L is still sorted by ID.
    *      procedure must also check if such ID is already exists (No Duplicate ID).
    *      If new data has duplicate ID, new data is rejected.
    * FS : elements in List L sorted by ID, P is inside List L
    */

    //-------------your code here-------------
    address P, Prec;
    P = allocate(x);
    if (first(L)==NULL){
        insertFirst(L,P);
    } else {
        Prec = findElm(L,info(P));
        if (Prec ==NULL){
            address last = first(L);
            while (next(last)!=NULL){
                last = next(last);
            }
            if (info(P).ID <= info(first(L)).ID){
                insertFirst(L,P);
            } else if (info(P).ID >= info(first(L)).ID) {
                insertLast(L,P);
            } else {
                Prec = first(L);
                while (info(next(Prec)).ID < info(P).ID){
                    Prec = next(Prec);
                }
                insertAfter(L,Prec,P);
            }
        } else {
            cout<<"Duplikat ID"<<endl;
        }
    }
    //----------------------------------------
}


void deletebyID(List &L, int id_x) {
    /**
    * IS : List L may be empty
    * FS : an element with ID info = id_x is deleted from List L (deallocate)
    */

    address Prec, P;
    //-------------your code here-------------
    infotype x;
    x.ID = id_x;
    P = findElm(L,x);
    if (first(L)!=NULL){
        if (P==first(L)){
            deleteFirst(L,P);
            deallocate(P);
        } else if (next(P)==NULL){
            deleteLast(L,P);
            deallocate(P);
        } else {
            Prec = first(L);
            while (next(Prec)!=P){
                Prec = next(Prec);
            }
            deleteAfter(L,Prec,P);
        }
    }
    //----------------------------------------
}


void savePassedMember(List &L, List &L2){
    /**
    * IS : List L and L2 may be empty
    * FS : any element with score greater than 80 is moved to L2
    */
    address P;
    //-------------your code here-------------
    List Ltmp;
    createList(Ltmp);
    while (first(L)!=NULL){
        deleteFirst(L,P);
        if (info(P).score > 80){
            insertAndSort(L2,info(P));
        } else {
            insertAndSort(Ltmp,info(P));
        }
    }
    L = Ltmp;

    //----------------------------------------
}
