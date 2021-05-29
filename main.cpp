

#include <iostream>
#include "Sequance.h"
#include "LinkedList.h"
#include "DynamicArray.h"
#include "Tests.h"


void menu() {
    int choice = 0;
    while (choice != 5) {
        std::cout << "1.Sum\n" << "2.MultOnScal\n" << "3.Norm\n" << "4.ScalMult\n" << "5.exit\n" <<"Make your choice: ";
        std::cin >> choice;
        std::cout << std::endl;
        if (choice < 1 || choice > 5) {
            std::cout << "Wrong choice! Try again.\n";
            continue;
        }
        int type;
        int n;
       
        switch (choice) {
        case 1: {
            std::cout << "1.Array\n2.List\nInput type of sequance: ";
            std::cin >> type;
            if (type != 1 && type != 2) {
                std::cout << "Wrong choice of type! Try again.\n";
                continue;
            }
            switch (type) {
            case 1: {
                ArrayVector<float> vec1 ;
                ArrayVector<float> vec2 ;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec1.Append(data);
                }
                std::cout << "Input vector2: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec2.Append(data);
                }
                vec1.Sum(&vec2);
                std::cout << "Sum= ";
                vec1.Output();
            }
                  break;

            case 2: {
                ListVector<float> vec3;
                ListVector<float> vec4;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec3.Append(data);
                }
                std::cout << "Input vector2: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec4.Append(data);
                }
                vec3.Sum(&vec4);
                std::cout << "Sum= ";
                vec3.Output();
            }
                  break;
            }
        }
              break;
        case 2: {
            std::cout << "1.Array\n2.List\nInput type of sequance: ";
            std::cin >> type;
            if (type != 1 && type != 2) {
                std::cout << "Wrong choice of type! Try again.\n";
                continue;
            }
            switch (type) {
            case 1: {
                ArrayVector<float> vec1;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec1.Append(data);
                }
                int scal;
                std::cout << "Input Scalar: ";
                std::cin >> scal;

                vec1.MultOnScal(scal);
                std::cout << "Mult on scal= ";
                vec1.Output();
            }
                  break;
            case 2: {
                ListVector<float> vec3;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec3.Append(data);
                }
                int scal2;
                std::cout << "Input Scalar: ";
                std::cin >> scal2;

                vec3.MultOnScal(scal2);
                std::cout << "Mult on scal= ";
                vec3.Output();
            }
                  break;
            }
        }
              break;
        case 3: {
            std::cout << "1.Array\n2.List\nInput type of sequance: ";
            std::cin >> type;
            if (type != 1 && type != 2) {
                std::cout << "Wrong choice of type! Try again.\n";
                continue;
            }
            switch (type) {
            case 1: {
                ArrayVector<float> vec1;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec1.Append(data);
                }

                float norm = vec1.Norm();
                std::cout << "Norm= " << norm << std::endl;
            }
                  break;
            case 2: {
                ListVector<float> vec3;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec3.Append(data);
                }
                float norm2 = vec3.Norm();
                std::cout << "Norm= " << norm2 << std::endl;
            }
                  break;
            }
        }
              break;
        case 4: {
            std::cout << "1.Array\n2.List\nInput type of sequance: ";
            std::cin >> type;
            if (type != 1 && type != 2) {
                std::cout << "Wrong choice of type! Try again.\n";
                continue;
            }
            switch (type) {
            case 1: {
                ArrayVector<float> vec1;
                ArrayVector<float> vec2;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec1.Append(data);
                }
                std::cout << "Input vector2: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec2.Append(data);
                }
                float scalMult = vec1.ScalMult(&vec2);
                std::cout << "ScalMult= " << scalMult << std::endl;
                
            }
                  break;
            case 2: {
                ListVector<float> vec3;
                ListVector<float> vec4;
                std::cout << "Input size: ";
                std::cin >> n;
                std::cout << "Input vector1: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec3.Append(data);
                }
                std::cout << "Input vector2: ";
                for (int i = 0; i < n; i++) {
                    float data;
                    std::cin >> data;
                    vec4.Append(data);
                }
                vec3.ScalMult(&vec4);
                std::cout << "ScalMult= " << vec3.ScalMult(&vec4) << std::endl;
            }
                  break;
            }
        }
              break;
        case 5: {
            std::cout << "Exit the program...\n";
            return;
        }
              break;
        default: {
            std::cout << "Wrong choice! Try again.\n";
        }
               break;
        }
        
    }
}

int main()
{
    menu();
   
    Test_Sum_Arr();
    Test_MultOnScal_Arr();
    Test_Norm_Arr();
    Test_ScalMult_Arr();
    Test_Concat_Arr();
    Test_GetSubVec_Arr();
    Test_Pop_Arr();

    Test_Sum_List();
    Test_MultOnScal_List();
    Test_Norm_List();
    Test_ScalMult_List();
    Test_Concat_List();
    Test_GetSubVec_List();
    Test_Pop_List();

}

