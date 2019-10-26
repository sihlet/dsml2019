#include <stdio.h>
#include <stdlib.h>
#include "btree.h"


int main() {
    //testing the bulk loading for self created array of size 12
    int arr[12] = {23, 43, 2, 56, 7, 12, 23, 99, 0, 11, 9, 13};
    bulkload(arr);


    internal intN = createInternalNode();

    node n1 = createNode(4);
    node n2 = createNode(7);
    root rt = insertRootNode(6);
    rt.array[0] = n1;
    intN.array[0] = n2;
    printf("%d \n", rt.array[0].key);
    printf("%d \n", intN.array[0].key);
    printf("%d \n", n1.key);
    return 0;
}

/*
A function that creates a root node
Params: none
Return: root node
*/
root createRoot(){
    root r;
    return r;
}

/*
A function that creates an internal node
Params: none
Return: internal node
*/
internal createInternalNode(){
    internal n;
    return n;
}

/*
A function that creates a single node
Params: int key
Return: node
*/
node createNode(int k){
    node n;
    n.key = k;

    return n;
}

/*
A function that does a tuple-wise insert into the root
Params: int key
Return: root node
*/
root insertRootNode(int k){
    node n = createNode(k);
    root rootz = createRoot();
    for (int i = 0; i < fanout; i++){
        //insering when ith key is null or zero is empty
        if(rootz.array[i].key == 0){
            rootz.array[i] = n;
        }
    }
    
    return rootz;
}

/*
A function that bulk loads the btree instead of a tuple-wise insert
Params: int key[]
Return: internal node (as a root)
*/
void bulkload(int k[]){
    int countSize = size;
    int i = 0;  //ends when reaches i = (size - 1): for the do-while loop below
    int j = 0;  //a counter for keep each internal node after each block iteration
    
    //in step with larger sorted array
    for(;countSize >= 0 ;countSize = countSize - i){
        printf("I am chunk number: ");
        printf("%d \n", i);
        int countLoop = loop;
        internal IntN = createInternalNode();
        //in step with each quotient segment of the sorted array
        do
        {
            printf("Inserting at: ");
            printf("%d \n", i);
            node n = createNode(k[i]);
            IntN.array[i] = n;
            i++;
            countLoop--;
        } while(countLoop > 0);
        
        //keep the nodes somewhere before creating a new/overwriting the existing
        level2[j] = &IntN;
        printf("Just inserted into: ");
        printf("%d, \n", j);
        printf("of level2. Then incrementing j now \n");
        j++;
    }   
}