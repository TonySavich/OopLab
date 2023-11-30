#include <iostream>

const int N = 1000;


template <typename T>
class Array3d {
public:

    Array3d(int i, int j, int k) {
        m_t = i * j * k;
        m_i = i;
        m_j = j;
        m_k = k;

    }
    void SetAll() {
        for (int i = 0; i < m_t; i++) {
            std::cin >> mas[i];
        }
    }



    void Fill(int tmp) {
        for (int i = 0; i < m_t; i++) {
            mas[i] = tmp;
        }
    }

    int Element(int i, int j, int k) {
        return mas[i + j * m_i + k * m_i * m_j];
}
    

    void GetValues0(int i) {

        for (int j = 0; j < m_j; j++) {
            for (int k = 0; k < m_k; k++) {
                std::cout << mas[i + j * m_i + k * m_i * m_j] << " ";
    
            }
            std::cout << std::endl;;
        }
    }

    void GetValues1(int j) {

        for (int i = 0; i < m_i; i++) {
            for (int k = 0; k < m_k; k++) {
                std::cout << mas[i + j * m_i + k * m_i * m_j] << " ";
   
            }
            std::cout << std::endl;;
        }
    }


    void GetValues2(int k) {
  
        for (int i = 0; i < m_i; i++) {
            for (int j = 0; j < m_j; j++) {
                std::cout << mas[i + j * m_i + k * m_i * m_j] << " ";
               
            }
            std::cout << std::endl;;
        }
    }


    void GetValues01(int i, int j) {
 
            for (int k = 0; k < m_k; k++) {
                std::cout << mas[i + j*m_i + k*m_i*m_j] << " ";
         
            }
     
    }

    void GetValues02(int i, int k) {

        for (int j = 0; j < m_j; j++) {
            std::cout << mas[i + j * m_i + k * m_i * m_j] << " ";
        
        }

    }

    void GetValues12(int j, int k) {
      
        for (int i = 0; i < m_i; i++) {
            std::cout << mas[i + j * m_i + k * m_i * m_j] << " ";

        }

    }





    void SetValues0(int i) {
        for (int j = 0; j < m_j; j++) {
            for (int k = 0; k < m_k; k++) {
                std::cin>> mas[i + j * m_i + k * m_i * m_j];
            }
        }
    }

    void SetValues1(int j) {
        for (int i = 0; i < m_i; i++) {
            for (int k = 0; k < m_k; k++) {
                std::cin >> mas[i + j * m_i + k * m_i * m_j];
            }
        }
    }


    void SetValues2(int k) {
        for (int i = 0; i < m_i; i++) {
            for (int j = 0; j < m_j; j++) {
                std::cin >> mas[i + j * m_i + k * m_i * m_j];
            }
        }
    }


    void SetValues01(int i, int j) {

        for (int k = 0; k < m_k; k++) {
            std::cin >> mas[i + j * m_i + k * m_i * m_j];

        }

    }


    void SetValues02(int i, int k) {

        for (int j = 0; j < m_j; j++) {
            std::cin >> mas[i + j * m_i + k * m_i * m_j];

        }

    }

    void SetValues12(int j, int k) {

        for (int i = 0; i < m_i; i++) {
            std::cin >> mas[i + j * m_i + k * m_i * m_j];

        }

    }

private:
    int m_i, m_j, m_k, m_t;
    T mas[N];
    };


    int main()
    {
        Array3d<int> mas(2, 2, 2);
        mas.SetAll();// 1 2 3 4 5 6 7 8
        mas.GetValues12(1, 0);
        std::cout << std::endl;
        std::cout << mas.Element(1, 1, 1);
    }

