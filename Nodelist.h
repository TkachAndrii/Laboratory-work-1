#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class node {
private:
    T value{};
    node<T> *next;
public:
    node() {
        next = nullptr;
    }

    void setValue(T setV) {
        value = setV;
    }

    T getValue() {
        return value;
    }

    node *getNext() {
        return next;
    }

    void setNext(node<T> *nextNode) {
        next = nextNode;
    }

};

template<typename T>
class nodeList {
private:
    node<T> *head;
    node<T> *sorted;

    node<T> *getTail(node<T> *cur) {
        while (cur != nullptr && cur->getNext() != nullptr)
            cur = cur->getNext();
        return cur;
    }

    node<T> *partition(node<T> *head, node<T> *end, node<T> **newHead, node<T> **newEnd) {
	    
        node<T> *pivot = end;
        node<T> *prev = nullptr;
        node<T> *cur = head;
        node<T> *tail = pivot;

        while (cur != pivot) {
            if (cur->getValue() < pivot->getValue()) {
                if ((*newHead) == nullptr) {
                    (*newHead) = cur;
                }
                prev = cur;
                cur = cur->getNext();
            } else {
                if (prev)
                    prev->setNext(cur->getNext());

                node<T> *tmp = cur->getNext();
                cur->setNext(nullptr);
                tail->setNext(cur);
                tail = cur;
                cur = tmp;
            }
        }

        if ((*newHead) == nullptr)
            (*newHead) = pivot;
        (*newEnd) = tail;
        return pivot;
    }

    node<T> *quickSortRecur(node<T> *head, node<T> *end) {
        if (!head || head == end)
            return head;

        node<T> *newHead = nullptr;
        node<T> *newEnd = nullptr;

        node<T> *pivot = partition(head, end, &newHead, &newEnd);

        if (newHead != pivot) {
            node<T> *tmp = newHead;
            while (tmp->getNext() != pivot)
                tmp = tmp->getNext();
            tmp->setNext(nullptr);

            newHead = quickSortRecur(newHead, tmp);

            tmp = getTail(newHead);
            tmp->setNext(pivot);
        }

        pivot->setNext(quickSortRecur(pivot->getNext(), newEnd));

        return newHead;
    }

    void mergeSortPrivate(node<T> **headRef) {
        node<T> *head = *headRef;
        node<T> *a;
        node<T> *b;

        if (head == nullptr || head->getNext() == nullptr) {
            return;
        }

        frontBackSplit(head, &a, &b);

        mergeSortPrivate(&a);
        mergeSortPrivate(&b);

        *headRef = sortedMerge(a, b);
    }

    node<T> *sortedMerge(node<T> *a, node<T> *b) {
        node<T> *result = nullptr;

        if (a == nullptr)
            return b;
        else if (b == nullptr)
            return a;

        if (a->getValue() <= b->getValue()) {
            result = a;
            result->setNext(sortedMerge(a->getNext(), b));
        } else {
            result = b;
            result->setNext(sortedMerge(a, b->getNext()));
        }
        return result;
    }

    void frontBackSplit(node<T> *source, node<T> **frontRef, node<T> **backRef) {
        node<T> *fast;
        node<T> *slow;
        slow = source;
        fast = source->getNext();

        while (fast != nullptr) {
            fast = fast->getNext();
            if (fast != nullptr) {
                slow = slow->getNext();
                fast = fast->getNext();
            }
        }

        *frontRef = source;
        *backRef = slow->getNext();
        slow->setNext(nullptr);
    }

    void insertion() {
        sorted = NULL;
        node<T> *current = head;

        while (current != NULL) {
            node<T> *next = current->getNext();

            sortedInsert(current);

            current = next;
        }

        head = sorted;
    }

    void sortedInsert(node<T> *newNode) {
 
        if (sorted == NULL || sorted->getValue() >= newNode->getValue()) {
            newNode->setNext(sorted);
            sorted = newNode;
        } else {
            node<T> *current = sorted;

            while (current->getNext() != NULL && current->getNext()->getValue() < newNode->getValue()) {
                current = current->getNext();
            }
            newNode->setNext(current->getNext());
            current->setNext(newNode);
        }
    }

    node<T> *find(node<T> *const pbeg, T d) {
        node<T> *pv = pbeg;
        while (pv) {
            if (pv->data == d)
                break;
            pv = pv->next;
        }
        return pv;
    }

public:
    nodeList() {
        head = nullptr;
    }

    void add(T data) {
        auto *temp = new node<T>;
        temp->setValue(data);
        temp->setNext(nullptr);
        if (head == nullptr) {
            head = temp;
        } else {
            node<T> *curr = head;
            while (curr->getNext() != nullptr)
                curr = curr->getNext();
            curr->setNext(temp);
        }
    }

    vector<T> getNodeList() {
        vector<T> nodeList;
        node<T> *temp = head;
        while (temp != nullptr) {
            nodeList.push_back(temp->getValue());
            temp = temp->getNext();
        }
        return nodeList;
    }

    bool insert(T key, T data) {
        if (node<T> *pkey = find(begin, key)) {

            auto *pv = new node<T>(data, pkey, pkey->next);
            pkey->next = pv;
            if (pkey != end)
                (pv->next)->prev = pv;
            else
                end = pv;
            return true;
        }
        return false;
    }

    bool remove(T key) {
        node<T> *current = head;
        node<T> *prev = nullptr;

        while (current != nullptr) {
            if (current->getValue() == key) {

                if (current == head) {
                    head = current->getNext();
                } else {
                    prev->setNext(current->getNext());
                }

                delete current;
                return true;
            }

            prev = current;
            current = current->getNext();
        }
        return false;
    }

    void showList() {
        node<T> *temp = head;
        if (temp == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        int i = 1;
        while (temp != nullptr) {
            cout << temp->getValue() << endl;
            temp = temp->getNext();
            i++;
        }
    }

    void bubbleSort() {
        bool change = true;
        node<T> *temp;
        node<T> *lastSorted = nullptr; 

        while (change) {
            temp = head;
            change = false;
            while (temp->getNext() != lastSorted) {
                if (temp->getValue() > temp->getNext()->getValue()) {
                    T temporary = temp->getValue();
                    temp->setValue(temp->getNext()->getValue());
                    temp->getNext()->setValue(temporary);
                    change = true;
                }
                temp = temp->getNext();
            }
            lastSorted = temp; 
        }
    }

    void selectionSort() {
        node<T> *temp = head;

        while (temp->getNext() != nullptr) {
            node<T> *min = temp;
            node<T> *r = temp->getNext();

            while (r != nullptr) {
                if (min->getValue() > r->getValue())
                    min = r;

                r = r->getNext();
            }

            T temporary = temp->getValue();
            temp->setValue(min->getValue());
            min->setValue(temporary);
            temp = temp->getNext();
        }
    }

    // taken algorithm and code from: https://www.geeksforgeeks.org/cpp-program-for-quicksort-on-singly-linked-list/
    void quickSort() {
        quickSortRecur(head, getTail(head));
    }

    // taken algorithm and code from: https://www.geeksforgeeks.org/cpp-program-for-insertion-sort-in-a-singly-linked-list/
    void insertionSort() {
        void insertion();
    }

    // taken algorithm and code from: https://www.geeksforgeeks.org/cpp-program-for-merge-sort-of-linked-lists/
    void mergeSort() {
        mergeSortPrivate(&head);
    }

    friend ostream &operator<<(ostream &out, vector<T> &vectorOut);

    ~nodeList() {
        while (head != nullptr) {
            node<T> *temp = head;
            head = head->getNext();
            delete (temp);
        }
    }
};
