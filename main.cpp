#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "\t SLAR is:" << std::endl;
    cout << "3.01x1-0.14x2-0.15x3=1.00\n"
            "1.11x1+0.13x2-0.75x3=0.13\n"
            "0.17x1-2.11x2+0.71x3=0.17" << std::endl;
    double Matrix[3][4] = {{3.01, -0.14, -0.15, 1.00},
                           {1.11, 0.13,  -0.75, 0.13},
                           {0.17, -2.11, 0.71,  0.17}};
    int riad = 0;
    cout<<"\t METOD GAUSA"<<endl;
    while (riad != 2) { // зведення до трикутної матриці
        double max = 0;
        int nMaxPos = 0;
        for (int i = riad; i <= 2; i++) { // знаходження головного елемента
            if (fabs(Matrix[i][riad]) > max) {
                max = fabs(Matrix[i][riad]);
                nMaxPos = i;
            }
        }
        printf("\n");
        while (nMaxPos != riad) { // переставлення головного елемента на початок
            double temp[4];
            for(int i=0;i<=3;i++){
                temp[i]=Matrix[nMaxPos - 1][i];
                Matrix[nMaxPos-1][i]=Matrix[nMaxPos][i];
                Matrix[nMaxPos][i]=temp[i];
            }
            --nMaxPos;
        }

        int koef=riad;
        while(koef!=2){ // множення рядків на коефіцієнт та додавання до наступних рядків
            double ThisKoef=-Matrix[koef+1][riad]/Matrix[riad][riad];
            for(int i=1;i<=3-riad;i++){
                double dodati=Matrix[riad][riad+i]*ThisKoef;
                Matrix[koef+1][riad+i]=Matrix[koef+1][riad+i]+dodati;
            }
            ++koef;
        }
        for(int i=riad+1;i<=2;i++){ // занулення рядка
            Matrix[i][riad]=0;
        }

        for(int i=0;i<3;i++){ // вивід матриці
            for(int j=0;j<4;j++){
                printf("%lf ",Matrix[i][j]);
            }
            printf("\n");
        }
        riad++;
    }
    for(int i=riad+1;i<=2;i++){// занулення рядка
        Matrix[i][riad]=0;
    }
    printf("\n");
    double x3=Matrix[2][3]/Matrix[2][2];
    double x2=(Matrix[1][3]-x3*Matrix[1][2])/Matrix[1][1];
    double x1=(Matrix[0][3]-Matrix[0][2]*x3-Matrix[0][1]*x2)/Matrix[0][0];
    printf("\nx3=%lf, x2=%lf, x1=%lf", x3,x2,x1);

    double nMatrix[3][4] = {{3.01, -0.14, -0.15, 1.00},
                           {1.11, 0.13,  -0.75, 0.13},
                           {0.17, -2.11, 0.71,  0.17}};

    cout<<"\n \t METOD LU"<<endl;

    double LMatrix[3][3] = {0,0,0,0,0,0,0,0,0};
    double UMatrix[3][3] = {0,0,0,0,0,0,0,0,0};

    for(int i=0;i<3;i++){
        LMatrix[i][0]=Matrix[i][0];
    }
    for(int i=1;i<3;i++){
        UMatrix[0][i]=Matrix[0][i]/Matrix[0][0];
    }
    for(int i=0;i<3;i++){
        UMatrix[i][i]=1;
    }
    int i=0;
    while(i!=3){
        i++
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%lf ",UMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%lf ",LMatrix[i][j]);
        }
        printf("\n");
    }
}

