#include <iostream>

const int N = 100;


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


    void GetValues0(int i, T dop[][N]) {

        for (int j = 0; j < m_j; j++) {
            for (int k = 0; k < m_k; k++) {
               dop[j][k] =mas[i + j * m_i + k * m_i * m_j] ;

            }
          //  std::cout << std::endl;;
        }
    }

    void GetValues1(int j, T dop[][N]) {

        for (int i = 0; i < m_i; i++) {
            for (int k = 0; k < m_k; k++) {
                dop[i][k] = mas[i + j * m_i + k * m_i * m_j];

            }
         //   std::cout << std::endl;;
        }
    }


    void GetValues2(int k, T dop[][N]) {

        for (int i = 0; i < m_i; i++) {
            for (int j = 0; j < m_j; j++) {
                dop[i][j]=mas[i + j * m_i + k * m_i * m_j] ;

            }
          //  std::cout << std::endl;;
        }
    }


    void GetValues01(int i, int j ,T dop[N]) {

        for (int k = 0; k < m_k; k++) {
           dop[k]= mas[i + j * m_i + k * m_i * m_j];

        }

    }

    void GetValues02(int i, int k, T dop[N]) {

        for (int j = 0; j < m_j; j++) {
            dop[j]= mas[i + j * m_i + k * m_i * m_j];

        }

    }

    void GetValues12(int j, int k, T dop[N]) {

        for (int i = 0; i < m_i; i++) {
            dop[i]=mas[i + j * m_i + k * m_i * m_j];

        }

    }





    void SetValues0(int i, T dop[][N]) {
        for (int j = 0; j < m_j; j++) {
            for (int k = 0; k < m_k; k++) {
               mas[i + j * m_i + k * m_i * m_j]= dop[j][k];
            }
        }
    }

    void SetValues1(int j, T dop[][N]) {
        for (int i = 0; i < m_i; i++) {
            for (int k = 0; k < m_k; k++) {
                mas[i + j * m_i + k * m_i * m_j] =dop[j][k];
            }
        }
    }


    void SetValues2(int k, T dop[][N]) {
        for (int i = 0; i < m_i; i++) {
            for (int j = 0; j < m_j; j++) {
                mas[i + j * m_i + k * m_i * m_j]= dop[j][j];
            }
        }
    }


    void SetValues01(int i, int j, T dop[N]) {

        for (int k = 0; k < m_k; k++) {
             mas[i + j * m_i + k * m_i * m_j]=dop[k] ;

        }

    }


    void SetValues02(int i, int k, T dop[N]) {

        for (int j = 0; j < m_j; j++) {
           mas[i + j * m_i + k * m_i * m_j] =dop[j];

        }

    }

    void SetValues12(int j, int k, T dop[N]) {

        for (int i = 0; i < m_i; i++) {
            mas[i + j * m_i + k * m_i * m_j]=dop[i];

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
    int maas[N][N];
    mas.GetValues1(1, maas);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << maas[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << mas.Element(1, 1, 1);
}

