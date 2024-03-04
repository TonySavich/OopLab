#include <iostream>
#include <vector>

class User {
public:
    int id;
    std::string name;
    std::string login;
    std::string password;
};

class IUserManger {
public:
    IUserManger();
    void SignIn(User user) {
        if (m_authorized == 0) {

            m_user = user;
            m_authorized = 1;

        }
        else if (user.login == m_user.login) {
           // std::cout << "ok";
        }
        else {
           // std::cout << "exit?(1.Yes  2.No)";
           // int tmpt;
            //std::cin >> tmpt;
           // if (tmpt == 1) {
                this->SignOut();
                
           // }
        }

    }
    void SignOut() {
        m_authorized = 0;
    }
    bool IsAuthorized() {
        return m_authorized;
    }
protected:
    User m_user;
    bool m_authorized = 0;
};


template<typename T>
class IDataRepsoity {
public:


    std::vector<T> Get() {
        return m_data;
    }



    void Add(T item) {
        m_data.push_back(item);

    }



    void Remove(T item) {
        for (int i = 0; i < m_data.size(); i++) {
            if (item == m_data[i]) {

                m_data.erase(i);
            }
        }
    }

    void Update(T item) {
        m_data.clear();
    }
private:

    std::vector<T>  m_data;

};
IDataRepsoity<User> dataBase;



class FileManager {
public:
    FileManager() {

    }
    void Create(std::string name, std::string login, std::string password) {
      
        t++;
        User user;
        user.id = t;
        user.login = login;
        user.name = name;
        user.password = password;
        dataBase.Add(user);
    }
    void SignIn(User user) {
        std::vector<User> data = dataBase.Get();
        for (int i = 0; i < data.size(); i++) {
            if (user.login == data[i].login && user.name == data[i].name && user.password == data[i].password) {
                ium.SignIn(user);
                break;
            }
        }
    }

    void SignOut() {
        ium.SignOut();
    }


    User GetById(int id) {
       
        std::vector<User>  data = dataBase.Get();
        for (int i = 0; i < data.size(); i++) {
            if (data[i].id == id)
                return data[i];
        }
    }
    User GetByName(std::string name) {
     
        std::vector<User>data = dataBase.Get();
        for (int i = 0; i < data.size(); i++) {
            if (data[i].name == name)
                return data[i];
        }
    }


private:

    IUserManger ium;
    int t = 0;
};

int main()
{
    FileManager file;
    std::string a, b, c;
    User us;
    std::cin >> a >> b >> c;
    file.Create(a, b, c);
    us = file.GetByName(a);
    std::cin >> a >> b >> c;
    file.Create(a, b, c);
    file.SignOut();
    file.SignIn(us);

}
