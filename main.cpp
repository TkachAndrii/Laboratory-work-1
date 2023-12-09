    int sizeIntList, sizeCharList, sizeStringList = 0;
    double sizeDoubleList = 0.0;
    char symbol;
    string words;
    cout << "Enter the size of IntList: " << endl;
    cin >> sizeIntList;
    cout << "Enter the size of DoubleList: " << endl;
    cin >> sizeDoubleList;
    cout << "Enter the size of CharList: " << endl;
    cin >> sizeCharList;
    cout << "Enter the size of StringList: " << endl;
    cin >> sizeStringList;

    Nodelist<int> intList;
    Nodelist<double> doubleList;
    Nodelist<char> charList;
    Nodelist<string> stringList;


    for (int i = 0; i < sizeIntList; i++) {
        intList.AddLastNode(rand() % 100);
    }
    for (int i = 0; i < sizeDoubleList; i++) {
        doubleList.AddLastNode(dist(mt));
    }

    for (int i = 0; i < sizeCharList; i++) {
        cout << "Char symbols you want to be in each node: ";
        cin >> symbol;
        charList.AddLastNode(symbol);
        cout << "Char list" << endl;
    }

    for (int i = 0; i < sizeStringList; i++) {
        cout << "String Words you want to be in each node: ";
        cin >> words;
        stringList.AddLastNode(words);
        cout << "String list" << endl;
    }

    intList.showList();
    doubleList.showList();
    charList.showList();
    stringList.showList();

    intList.bubbleSort();
    intList.selectionSort();
    intList.quickSort();
    intList.insertionSort();
    intList.mergeSort();

    doubleList.bubbleSort();
    doubleList.selectionSort();
    doubleList.quickSort();
    doubleList.insertionSort();
    doubleList.mergeSort();

    charList.bubbleSort();
    charList.selectionSort();
    charList.quickSort();
    charList.insertionSort();
    charList.mergeSort();

    stringList.bubbleSort();
    stringList.selectionSort();
    stringList.quickSort();
    stringList.insertionSort();
    stringList.mergeSort();

    cout << "Sorted list: " << endl;
    intList.showList();
    doubleList.showList();
    charList.showList();
    stringList.showList();




    int sizeIntListVector;
    cout << "Enter the size of IntListArray: ";
    cin >> sizeIntListVector;
    arrList<int> myArrList;
    for (int i = 0; i < sizeIntListVector; i++) {
        myArrList.add(rand() % 100);
    }

    myArrList.quickSort();
    myArrList.showList();

    int sizeIntListVector;
    cout << "Enter the size of IntListVector: ";
    cin >> sizeIntListVector;
    Vectorlist<int> myVectorlist;
    for (int i = 0; i < sizeIntListVector; i++) {
        myVectorList.add(rand() % 100);
    }

    myVectorlist.showList();
    myVectorlist.quickSort();
    myVectorlist.mergeSortPrivate();
    myVectorlist.insertionSort();
    myVectorlist.showList();
