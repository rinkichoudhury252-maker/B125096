#include <iostream>
using namespace std;

class Document {
public:
    virtual void exportFile() {
        cout << "Exporting document\n";
    }
};

class PDFDocument : public Document {
public:
    void exportFile() override {
        cout << "Exporting PDF file (.pdf)\n";
    }
};

class TextDocument : public Document {
public:
    void exportFile() override {
        cout << "Exporting Text file (.txt)\n";
    }
};

class CSVDocument : public Document {
public:
    void exportFile() override {
        cout << "Exporting CSV file (.csv)\n";
    }
};

int main() {
    PDFDocument p;
    TextDocument t;
    CSVDocument c;

    Document *ptr;

    ptr = &p;
    ptr->exportFile();

    ptr = &t;
    ptr->exportFile();

    ptr = &c;
    ptr->exportFile();

    return 0;
}