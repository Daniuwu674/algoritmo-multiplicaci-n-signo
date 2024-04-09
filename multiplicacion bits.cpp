#include <iostream>
#include <bitset>
#include <string>
#include <cmath>
using namespace std;

string cambio_Binario(int a, int num_bits) {
    string bi = "";
    bool Negativo = a < 0;
    if (Negativo)
        a = -a;

    for (int i = 0; i < num_bits; ++i) {  //bucle para convertir de decimal a binario
        bi = (a % 2 == 0 ? "0" : "1") + bi;
        a /= 2;
    }

    if (Negativo) {     //si el numero fuera negativo aplicamos un complemento a dos
        bool acarreo = true; //variable de control para el acarreo
        for (int i = bi.length() - 1; i >= 0; --i) {
            if (bi[i] == '1' && acarreo) {
                bi[i] = '0';
            }
            else if (bi[i] == '0' && acarreo) {
                bi[i] = '1';
                acarreo = false;
            }
        }
    }
    return bi;
}

string multiplicacion(int a, int b, int num_bits) {
    int producto = a * b;
    int resul_bits = 2 * num_bits;
    int maxVal = (1 << (resul_bits - 1)) - 1;
    int minVal = -(1 << (resul_bits - 1));

    if (producto > maxVal || producto < minVal) {
        producto %= (1 << resul_bits);
    }

    return cambio_Binario(producto, resul_bits);
}

string sumatoria(string a, string b) {
    string resultado = "";
    int acarreo = 0;

    int maxLength = std::max(a.length(), b.length());
    a = string(maxLength - a.length(), '0') + a;
    b = string(maxLength - b.length(), '0') + b;

    for (int i = maxLength - 1; i >= 0; --i) {
        int sum = (a[i] - '0') + (b[i] - '0') + acarreo;
        resultado = char(sum % 2 + '0') + resultado;
        acarreo = sum / 2;
    }

    if (acarreo != 0) { //en caso de que haya acarreo en la suma
        resultado = char(acarreo + '0') + resultado;
    }

    return resultado;
}

string resta_comple2(std::string a, std::string b) {
 
    for (int i = 0; i < b.length(); ++i) {
        b[i] = (b[i] == '0' ? '1' : '0');   
    }
    b = sumatoria(b, "1");

    return sumatoria(a, b);
}

int main() {
    int a;
    cout << "Que deseas hacer?" << endl;
    cout << "1) sumar" << endl;
    cout << "2) complemento 2" << endl;
    cout << "3) multiplicacion" << endl;
    cout << "4) resta" << endl;
    cin >> a;

    switch (a) {
    case 1:
    {
        system("cls");
        int x, y, cant_bits;
        cout << "Ingrese el primer numero: ";
        cin >> x;
        cout << "Ingrese el segundo numero: ";
        cin >> y;
        cout << "ingrese cantidad de bits: ";
        cin >> cant_bits;
        string pri_binario = cambio_Binario(x, cant_bits);
        string segu_binario = cambio_Binario(y, cant_bits);
        string suma = sumatoria(pri_binario, segu_binario);
        cout << "El resultado es: " << suma;
        break;
    }
    case 2:
    {
        system("cls");
        int x, y, cant_bits;
        std::cout << "Ingrese el primer numero: ";
        std::cin >> x;
        std::cout << "Ingrese la cantidad de bits: ";
        std::cin >> cant_bits;
        cambio_Binario(x, cant_bits);
        break;
    }
    case 3:
    {
        system("cls");
        int x, y, cant_bits;
        std::cout << "Ingrese el primer numero: ";
        std::cin >> x;
        std::cout << "Ingrese el segundo numero: ";
        std::cin >> y;
        std::cout << "Ingrese la cantidad de bits: ";
        std::cin >> cant_bits;
        string respuesta = multiplicacion(x, y, cant_bits);
        cout << "El resultado de la multiplicacion es: " << respuesta << endl;
        break;
    }

    case 4:
    {
        system("cls");
        int x, y, cant_bits;
        cout << "Ingrese el primer numero: ";
        cin >> x;
        cout << "Ingrese el segundo numero: ";
        cin >> y;
        cout << "ingrese cantidad de bits: ";
        cin >> cant_bits;
        string pri_binario = cambio_Binario(x, cant_bits);
        string segu_binario = cambio_Binario(y, cant_bits);
        string respuesta = resta_comple2(pri_binario, segu_binario);
        cout << "El resultado es: " << respuesta << endl;
    }
    default:
    return 0;
    }
    return 0;
}
