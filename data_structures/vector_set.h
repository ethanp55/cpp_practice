#pragma once
#include <vector>


/** 
 * A vector set class that uses a vector of type T to store items.
 * **/
template<class T>
class VectorSet {
private:
    vector<T> _vec;

public:
    /** 
     * Checks to see if the given item is already in the set.
     * 
     * Output:
     * - true, if the item is in the set
     * - false, otherwise
     * **/
    bool contains(T item) const {
        for (const auto& element: _vec) {
            if (element == item) {
                return true;
            }
        }

        return false;
    }

    /** 
     * Attempts to insert a new item to the set.  If the item is already 
     * in the set, it is not added.
     * 
     * Output:
     * - true, if the item is not in the set and is added
     * - false, otherwise
     * **/
    bool insert(T item) {
        for (const auto& element: _vec) {
            if (element == item) {
                return false;
            }
        }

        _vec.push_back(item);
        return true;
    }

    /** 
     * Attempts to remove an item from the set.  If the item is not 
     * in the set, it is not removed.
     * 
     * Output:
     * - true, if the item is in the set and is removed
     * - false, otherwise
     * **/
    bool remove(T item) {
        for (auto iter = _vec.begin(); iter != _vec.end(); iter++) {
            if (*iter == item) {
                _vec.erase(iter);
                return true;
            }
        }

        return false;
    }

    /** 
     * Returns the number of items in the set (i.e., the set's size).
     * 
     * Output:
     * - the set's size
     * **/
    int size() const {
        return _vec.size();
    }

    /** 
     * Checks if the set is empty (i.e., contains no items).
     * 
     * Output:
     * - true, if the set is empty
     * - false, otherwise
     * **/
    bool empty() const {
        return _vec.empty();
    }

    /** 
     * Clears the set (i.e., removes every item from the set).
     * 
     * Output:
     * - N.A.
     * **/
    void clear() {
        _vec.clear();
    }

};
