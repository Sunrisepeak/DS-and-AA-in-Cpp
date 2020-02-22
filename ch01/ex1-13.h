#ifndef COLLECTION_H
#define COLLECTION_H

/* Introduce:
 *      Variale template of Collection by resize-Array.
 *      havan't implements iterator
 **/
template <typename Object>
class Collection {
    private:
        Object *arr;
        int size;       // current array size
        int countElement { 0 }; // quantity of current Element

        void resize(const int _size);
    public:
        explicit Collection();

        Collection(int _size);

        /*  Big-Five:
         *      1.Destructor;
         *      2.Copy Constructor;
         *      3.Move Constructor; 
         *      4.Copy Assignment Operator=;
         *      5.Move Assignment operator=;
         **/

        ~Collection();   //destuctor

        Collection(const Collection<Object> &c);   //cpy constructor
     
        Collection(Collection<Object> &&c);  //move constructor

        Collection & operator=(const Collection &c);  //copy assigment
           
        Collection & operator=(Collection &&c);    //move assigment

        bool isEmpty() const;

        void makeEmpty();

        void remove(const Object &o);

        void insert(const Object &o);

        void insert(const int &index, const Object &o);

        bool contains(const Object &o) const;

        int getSize() const;

        const Object & operator[](const int &index) const;

        Object & operator[](const int &index);
};

//-----------------private func-member-----------------

template <typename Object>
void Collection<Object>::resize(const int _size) {
    Object *oldArr = arr;
    arr = new Object[_size];
    for (int i = 0; i < countElement; i++) {
        arr[i] = oldArr[i];
    }
    size = _size;
    delete [] oldArr;
}

// ------------------public func-member---------------

template <typename Object>
Collection<Object>::Collection() : Collection(1) {

}

template <typename Object>
Collection<Object>::Collection(int _size) : size{ _size } {
    arr = new Object[size];
}

template <typename Object>
Collection<Object>::~Collection() {
    delete [] arr;
}

template <typename Object>
Collection<Object>::Collection(const Collection<Object> &c) {   //cpy constructor
    arr = new Object[c.size];   //? why is ok to access size? Becase of 'this'?
    for (int i = 0; i < c.countElement; i++) {
        arr[i] = c.arr[i];
    }
    size = c.size;
    countElement = c.countElement;
}

template <typename Object>
Collection<Object>::Collection(Collection<Object> &&c) : arr { c.arr }, size{ c.size }, 
    countElement{ c.countElement }  {   //move constructor                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        {  //move constructor
    c.arr = nullptr;
}

template <typename Object>
Collection<Object> & Collection<Object>::operator=(const Collection &c) {   //copy assigment
    if (this != &c) {
        delete [] arr;
        arr = new Object[c.size];
        for (int i = 0; i < c.size; i++) {
            arr[i] = c.arr[i];
        }
        size = c.size;
        countElement = c.countElement;
    }
    return *this;
}

template <typename Object>
Collection<Object> & Collection<Object>::operator=(Collection &&c) {    //move assigment
    delete [] arr;
    arr = new Object[c.size];
    for (int i = 0; i < c.size; i++) {
        std::swap(arr[i], c.arr[i]);
    }
    size = c.size;
    countElement = c.countElement;
    return *this;
}

template <typename Object>
bool Collection<Object>::isEmpty() const {
    return countElement == 0;
}

template <typename Object>
void Collection<Object>::makeEmpty() {
    countElement = 0;
    size = 1;
    delete [] arr;
    arr = new Object[size];
}

template <typename Object>
void Collection<Object>::remove(const Object &o) {
    int pos = 0;
    while (pos < countElement && arr[pos] != o) {
        pos++;
    }
    if (pos < countElement) {
        for (int i = pos + 1; i < countElement; i++) {
            arr[i - 1] = arr[i];
        }
        countElement--;
        if (countElement == size / 4) {
            resize(2 * countElement);
        }
    } else {
        throw std::invalid_argument(std::to_string(o) + "isn't exist.");
    }
}

template <typename Object>
void Collection<Object>::insert(const Object &o) {
    if (countElement + 1 > size) {
        resize(2 * size);
    } 
    arr[countElement] = o;
    countElement++;
}

template <typename Object>
void Collection<Object>::insert(const int &index, const Object &o) {
    if (index > size) {
        throw std::invalid_argument(std::to_string(index) + "(index) isn't between 0 and " + std::to_string(size));
    }
    if (countElement + 1 > size) {
        resize(2 * size);
    } 
    for (int i = countElement - 1; i >= index; i--) {
        arr[i + 1] = arr[i]; 
    }
    arr[index] = o;
    countElement++;
}

template <typename Object>
bool Collection<Object>::contains(const Object &o) const {
    for (int i = 0; i < countElement; i++) {
        if (arr[i] == o) {
            return true;
        }
    }
    return false;
}

template<typename Object>
int Collection<Object>::getSize() const {
    return countElement;
}

template <typename Object>
const Object & Collection<Object>::operator[](const int &index) const  {
    if (index < 0 || index >= countElement) {
        throw std::invalid_argument(std::to_string(index) + " is over border of array");
    }
    return arr[index];
}

template <typename Object>
Object & Collection<Object>::operator[](const int &index) {
    if (index < 0 || index >= countElement) {
        throw std::invalid_argument(std::to_string(index) + " is over border of array");
    }
    return arr[index];
}
#endif

