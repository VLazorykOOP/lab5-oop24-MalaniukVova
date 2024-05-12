//5.1
#include <iostream>
#include <string>

using namespace std;

class Window {
protected:
    int topLeftX, topLeftY, bottomRightX, bottomRightY;
    string bgColor;

public:
    Window(int tlX, int tlY, int brX, int brY, const string& color)
        : topLeftX(tlX), topLeftY(tlY), bottomRightX(brX), bottomRightY(brY), bgColor(color) {}

    ~Window() {}

    void print() {
        cout << "Window Coordinates: (" << topLeftX << ", " << topLeftY << ") to ("
            << bottomRightX << ", " << bottomRightY << ")" << endl;
        cout << "Background Color: " << bgColor << endl;
    }
};

class MenuWindow : public Window {
private:
    string menuString;

public:
    MenuWindow(int tlX, int tlY, int brX, int brY, const string& color, const string& menu)
        : Window(tlX, tlY, brX, brY, color), menuString(menu) {}

    MenuWindow(int tlX, int tlY, int brX, int brY, const string& menu)
        : Window(tlX, tlY, brX, brY, "White"), menuString(menu) {}

    ~MenuWindow() {}

    void print() {
        Window::print();
        cout << "Menu String: " << menuString << endl;
    }

    void setBackgroundColor(const string& color) {
        bgColor = color;
    }

    void setMenuString(const string& menu) {
        menuString = menu;
    }
};

int main() {
    MenuWindow menuWindow(10, 10, 90, 40, "Green", "File Edit View");

    menuWindow.print();

    menuWindow.setBackgroundColor("Red");
    menuWindow.setMenuString("New File Edit View");

    menuWindow.print();

    return 0;
}

//5.2
#include <iostream>
#include <string>

using namespace std;

class HardDrive {
private:
    int volumeMB;

public:
    HardDrive(int volume) : volumeMB(volume) {}

    int getVolume() const {
        return volumeMB;
    }
};

class Computer {
private:
    string* brand;
    double price;
    HardDrive* hardDrive;

public:
    Computer(string* brandPtr, double cost, HardDrive* hd) : brand(brandPtr), price(cost), hardDrive(hd) {}

    ~Computer() {
        delete brand;
        delete hardDrive;
    }

    void printInfo() const {
        cout << "Brand: " << *brand << ", Price: $" << price << ", Hard Drive Volume: " << hardDrive->getVolume() << "MB" << endl;
    }
};

class Monitor {
private:
    int size;

public:
    Monitor(int monitorSize) : size(monitorSize) {}

    int getSize() const {
        return size;
    }
};

class DesktopComputer : public Computer {
private:
    Monitor* monitor;

public:
    DesktopComputer(string* brandPtr, double cost, HardDrive* hd, int monitorSize) : Computer(brandPtr, cost, hd), monitor(new Monitor(monitorSize)) {}

    ~DesktopComputer() {
        delete monitor;
    }

    void printInfo() const {
        Computer::printInfo();
        cout << "Monitor Size: " << monitor->getSize() << " inches" << endl;
    }
};

int main() {
    string brandName = "Example Brand";
    string* brandPtr = &brandName;
    HardDrive* hd = new HardDrive(500); // 500MB hard drive
    DesktopComputer desktop(brandPtr, 999.99, hd, 27); // 27-inch monitor

    desktop.printInfo();

    return 0;
}
