/******************************************************************************
  Title          : hash_table.h
  Author         : Yu Tong Chen
  Created on     : 4/7/2019
  Description    : The interface of concrete class derived from abstract class _hash_table.h
  Purpose        : Interface of hash table.
  Usage          :
  Build with     :
  Modifications  :

******************************************************************************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "_hash_table.h"
#include "_hash_item.h"
#include <vector>

class HashTable:public __HashTable {
    public:

        /**
         * Default Constructor
         */
        HashTable();

        /**
        * Constructor
        */
        HashTable(int n);

        /**
         * Destructor
        */
        ~HashTable();

        /** find() searches in table for given item
        *  @precondition: item's key value is initialized
        *  @postcondition: if matching item is found, it is filled with value from
        *                  table.
        *  @param  ItemType [in,out] item : item to search for
        *  @return int 0 if item is not in table, and 1 if it is
        */
        int find   ( __ItemType & item ) const override ;

        /** insert() inserts the given item into the table
        *  @precondition: item is initialized
        *  @postcondition: if item is not in table already, it is inserted
        *  @param  ItemType [in] item : item to insert
        *  @return int 0 if item is not inserted in table, and 1 if it is
        */
        int insert ( __ItemType item   ) override;


        /** remove() removes the specified  item from the table, if it is there
        *  @precondition: item's key is initialized
        *  @postcondition: if item was in table already, it is removed and copied
        *                  into the parameter, item
        *  @param  ItemType [in] item : item to remove
        *  @return int 0 if item is not removed from the table, and 1 if it is
        */
        int remove ( __ItemType  item ) override;

        /** size() returns the number of items in the table
        *  @precondition: none
        *  @postcondition: none
        *  @return int the number of items in the table
        */
        int size() const override;

        /** listall() lists all items currently in the table
        *  @note   This function writes each item in the tabel onto the given stream.
        *          Items should be written one per line, in whatever format the
        *          underlying _ItemType output operator formats them.
        *  @param  ostream [in,out] the stream onto which items are written
        *  @return int the number of items written to the stream
        */
        int listall ( ostream & os ) const override;

    private:
        int table_size; // size of hash table
        int num_item = 0;  // number of items
        __ItemType **hash_table;
        __ItemType dummy;  // dummy marker

};


#endif //HASH_TABLE_H
