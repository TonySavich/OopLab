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
        virtual void setPosition(Point m)=0 {
          
        }
        virtual Point getPosition() = 0 {
           
        }
protected:
    Point m_m;
};



class Form: public Control {
public:
    Form() :Control() {
        std::cout << "Form" << std::endl;
    }
    ~Form() {

    }
   void setPosition(Point m) override {
       m_m = m;
    }
  Point getPosition() override {
      return m_m;
    }
    void addControl() {
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
    void setPosition(Point m) override {
        m_m = m;
    }
    Point getPosition() override {
        return m_m;
    }
    void setText(std::string t) {
        std::cout << "setText" << std::endl;
        m_t = t;
    }
    std::string getText() {
        return m_t;
    }
protected:
    std::string m_t;
};


class TextBox :public Control {
public:
    TextBox():Control() {
        std::cout << "Textbox" << std::endl;
   }
    ~TextBox()  {

    }

    void setPosition(Point m) override {
        m_m = m;
    }
    Point getPosition() override {
        return m_m;
    }
    void setText(std::string t) {
        m_t = t;
   }
    std::string getText() {
        return m_t;
    }
    void OnValueChanged() {
        std::cout << "OnValueChanged" << std::endl;
    }
protected:
    std::string m_t;
};


class Factory {
public:
    Factory() {

    }
    ~Factory() {

    }
    virtual Label* createLabel() = 0;
    virtual TextBox* createTextbox() = 0;
    virtual Form* createForm() = 0;
};




class WindowsConrolFactory : public Factory {
public:
    WindowsConrolFactory() :Factory() {
        std::cout << "WindowsControlFactory" << std::endl;
    }
    ~WindowsConrolFactory() {

    }
    Label *createLabel() override {
        return new Label;
    }
    TextBox * createTextbox() override {
        return new TextBox;
    }
    Form *createForm() override {
        return new Form;
    }
};


class LinuxConrolFactory : public Factory {
public:
    LinuxConrolFactory() :Factory() {
        std::cout << "WindowsControlFactory" << std::endl;
    }
    ~LinuxConrolFactory() {

    }
    Label* createLabel() override {
        return new Label;
    }
    TextBox* createTextbox() override {
        return new TextBox;
    }
    Form* createForm() override {
        return new Form;
    }
};

int main()
{

    Factory* factory = new WindowsConrolFactory;
    TextBox* t = factory->createTextbox();
    t->OnValueChanged();
    Factory* lFactory = new LinuxConrolFactory();
    Form* f = lFactory->createForm();
    f->addControl();
    
}
