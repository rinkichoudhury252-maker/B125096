
#include <iostream>
using namespace std;

class Camera {
private:
    string brand;
    string model;
    int megapixels;
    int storageCapacity;

public:
    // Constructor
    Camera(string b, string m, int mp, int storage) {
        brand = b;
        model = m;
        megapixels = mp;
        storageCapacity = storage;
    }

    // Friend function declaration
    friend void compareCamera(Camera c1, Camera c2);
};

void compareCamera(Camera c1, Camera c2) {
    Camera better = c1;

    // Compare megapixels first
    if (c2.megapixels > c1.megapixels) {
        better = c2;
    }
    // If megapixels are same, compare storage
    else if (c2.megapixels == c1.megapixels &&
             c2.storageCapacity > c1.storageCapacity) {
        better = c2;
    }

    cout << "----- Better Camera -----" << endl;
    cout << "Brand: " << better.brand << endl;
    cout << "Model: " << better.model << endl;
    cout << "Megapixels: " << better.megapixels << " MP" << endl;
    cout << "Storage: " << better.storageCapacity << " GB" << endl;
}

int main() {
    Camera c1("Canon", "EOS 200D", 24, 128);
    Camera c2("Sony", "Alpha A7", 33, 64);

    compareCamera(c1, c2);

    return 0;
}
