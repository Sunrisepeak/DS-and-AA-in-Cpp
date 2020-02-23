#include <iostream>
#include <vector>
#include <functional>   //using defaul ordering for cmp -- less<Object> {}

using namespace std;

class Rectangle {
    private:
        int lenght;
        int width;
    
    public:

        explicit Rectangle(int len = 2, int wid = 1) : lenght{ len }, width{ wid }{

        }

        ~Rectangle() = default;

        Rectangle(const Rectangle &rec) = default;

        Rectangle(Rectangle &&rec) : lenght{ rec.lenght }, width{ rec.width } { }

        Rectangle & operator=(const Rectangle &rec) = default;

        Rectangle & operator=(Rectangle &&rec) = default;

        int getLength() const {
            return lenght;
        }

        int getWidth() const {
            return width;
        }

        // GCC requires friend functions to be declared in name space
        // while much arguments.                os << rec
        friend std::ostream & operator<<(std::ostream &os, const Rectangle &rec) {
            //<< is left associative
            os << "Rectangle:\n" << "\tLength: " << rec.lenght << "\tWidth: " << rec.width;
            return os;
        }

        // this < rec
        bool operator<(const Rectangle &rec) const {
            return (width * lenght) < (rec.width * rec.lenght);
        }
};

template<typename Object, typename Comparator>
const Object & findMax(const vector<Object> &arr, Comparator isLessThan) {
    int maxIndex = 0;
    for (unsigned int i = 0; i < arr.size(); i++) {
        if (isLessThan(arr[maxIndex], arr[i])) {
            maxIndex = i;
        }
    }
    return arr[maxIndex];
}

class RecPerimeterCompare {
    public:
        bool operator()(const Rectangle &lrec, const Rectangle &rrec) {
            //const rec only access const member(-function).
            return lrec < rrec;
        }
};

template <typename Object>
const Object & findMax(const vector<Object> &arr) {
    return findMax(arr, less<Object> { });  //call above findMax 
}

int main() {
    vector<Rectangle> arr {Rectangle(2, 3), Rectangle(), Rectangle(4, 5)};

    cout << findMax(arr,RecPerimeterCompare { }) << endl;
    //cout << findMax(arr) << endl; //defualt less<> only <
    return 0;
}