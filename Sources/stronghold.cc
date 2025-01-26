#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
#define pi 3.141592653589

#ifdef _WIN32
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define byte win_byte // avoid conflict with std::byte
#include <windows.h>
HANDLE hConsole;
#endif


// Colour functions:

void DefaultColors() {
#ifdef _WIN32
  SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
#else
  std::cout<<"\033[0m";
#endif
}

void RedForeground() {
#ifdef _WIN32
  SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
#else
  std::cout<<"\033[31m";
#endif
}

void BlueForeground() {
#ifdef _WIN32
  SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE); 
#else
  std::cout<<"\033[34m";
#endif
}


// Trigonometry functions:

float DegToRad(float alfa) {
  return alfa * (pi / 180);
}

float K(float alfa) {
  return tan(DegToRad(-alfa));
}

float B(float x,float z,float alfa) {
  return x - K(alfa) * z;
}

float Z(float x1,float z1,float alfa1,float x2,float z2,float alfa2) {
  return (B(x2,z2,alfa2)-B(x1,z1,alfa1))/(K(alfa1)-K(alfa2));
}

float X(float x1,float z1,float alfa1,float x2,float z2,float alfa2) {
  return K(alfa1)*Z(x1,z1,alfa1,x2,z2,alfa2)+B(x1,z1,alfa1);
}


// main:

int main(int argc, char *argv[]) {
#ifdef _WIN32
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
  int x1,z1,x2,z2;
  float alfa1,alfa2;
  if (argc > 6) {
    x1 = atoi(argv[1]);
    z1 = atoi(argv[2]);
    alfa1 = atof(argv[3]);
    x2 = atoi(argv[4]);
    z2 = atoi(argv[5]);
    alfa2 = atof(argv[6]);
  }
  else if (argc>1) return 0*printf("Arg amount error\n");
  else {
    cout << "First values:\nx: ";
    RedForeground();
    cin >> x1;
    DefaultColors();
    cout << "z: ";
    RedForeground();
    cin >> z1;
    DefaultColors();
    cout << "angle: "; 
    RedForeground();
    cin >> alfa1;
    DefaultColors();
    cout << "Second values:\nx: ";
    BlueForeground();
    cin >> x2;
    DefaultColors();
    cout << "z: ";
    BlueForeground();
    cin >> z2;
    DefaultColors();
    cout << "angle: "; 
    BlueForeground();
    cin >> alfa2;
    DefaultColors();
  }
  int shX = X(x1,z1,alfa1,x2,z2,alfa2);
  int shZ = Z(x1,z1,alfa1,x2,z2,alfa2);
  cout << "\nStronghold:\n\n Overworld:\n X: " << shX
    << " Z: " << shZ << "\n\n Nether:\n X: " 
    << (int)(shX/8) << " Z: " << (int)(shZ/8) << "\n\n";
  getchar();
  getchar();
  return 0;
}
