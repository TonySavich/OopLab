#include <iostream>

struct  Point
{
    int x;
    int y;
};

class Control {
public:
    Control() {
        std::cout << "Control" << std::endl;
    }
    virtual ~Control() {

    }
    virtual void setPosition(Point m) = 0 {

    }
    virtual Point getPosition() = 0 {

    }
protected:
    Point m_m;
};



class Form : public Control {
public:
     Form() :Control() {
        std::cout << "Form" << std::endl;
    }
    ~Form() {

    }
    virtual void setPosition(Point m) override {
        m_m = m;
    }
    virtual Point getPosition() override {
        return m_m;
    }
    virtual void addControl() {
        std::cout << "addContoll" << std::endl;
    }

};

class WindowsForm : public Form {
public:
    WindowsForm() :Form() {
        std::cout << "WindowsForm" << std::endl;
    }
    ~WindowsForm() {

    }
     void setPosition(Point m) override {
        m_m = m;
    }
    Point getPosition() override {
        return m_m;
    }
    void addControl() override {
        std::cout << "addContoll" << std::endl;
    }
};
class LinuxForm : public Form {
public:
    LinuxForm() :Form() {
        std::cout << "LinuxForm" << std::endl;
    }
    ~LinuxForm() {

    }
    void setPosition(Point m) override {
        m_m = m;
    }
    Point getPosition() override {
        return m_m;
    }
    void addControl() override {
        std::cout << "addContoll" << std::endl;
    }
};

class Label : public Control {
public:
    Label() :Control() {
        std::cout << "Label" << std::endl;
    }

    ~Label() {

    }
    virtual void setPosition(Point m) override {
        m_m = m;
    }
    virtual Point getPosition() override {
        return m_m;
    }
    virtual void setText(std::string t) {
        std::cout << "setText" << std::endl;
        m_t = t;
    }
    virtual std::string getText() {
        return m_t;
    }
protected:
    std::string m_t;
};


class WindowsLabel : public Label {
public:
    WindowsLabel() :Label() {
        std::cout << "WindowsLabel" << std::endl;
    }

    ~WindowsLabel() {

    }
    void setPosition(Point m) override {
        m_m = m;
    }
    Point getPosition() override {
        return m_m;
    }
    void setText(std::string t) override {
        std::cout << "setText" << std::endl;
        m_t = t;
    }
    std::string getText() {
        return m_t;
    }

};

class LinuxLabel : public Label {
public:
    LinuxLabel() :Label() {
        std::cout << "LinuxLabel" << std::endl;
    }

    ~LinuxLabel() {

    }
    void setPosition(Point m) override {
        m_m = m;
    }
    Point getPosition() override {
        return m_m;
    }
    void setText(std::string t) override {
        std::cout << "setText" << std::endl;
        m_t = t;
    }
    std::string getText() {
        return m_t;
    }

};


class Factory {
public:
    Factory() {

    }
    ~Factory() {

    }
    virtual Label* createLabel() = 0;
    virtual Form* createForm() = 0;
};




class WindowsConrolFactory : public Factory {
public:
    WindowsConrolFactory() :Factory() {
        std::cout << "WindowsControlFactory" << std::endl;
    }
    ~WindowsConrolFactory() {

    }
    Label* createLabel() override {
        return new WindowsLabel;
    }

    Form* createForm() override {
        return new WindowsForm;
    }
};


class LinuxConrolFactory : public Factory {
public:
    LinuxConrolFactory() :Factory() {
        std::cout << "LinuxControlFactory" << std::endl;
    }
    ~LinuxConrolFactory() {

    }
    Label* createLabel() override {
        return new LinuxLabel;
    }
 
    Form* createForm() override {
        return new LinuxForm;
    }
};

int main()
{

    Factory* factory = new WindowsConrolFactory;
    Factory* lFactory = new LinuxConrolFactory();
    Form* f = lFactory->createForm();
    f->addControl();

}
