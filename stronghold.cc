#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
#define pi 3.141592653589

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

int main(int argc, char *argv[]) {
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
    cout << "First values:\nx: \033[31m";
    cin >> x1;
    cout << "\033[0mz: \033[31m";
    cin >> z1;
    cout << "\033[0mangle: \033[31m"; 
    cin >> alfa1;
    cout << "\033[0mSecond values:\nx: \033[34m";
    cin >> x2;
    cout << "\033[0mz: \033[34m";
    cin >> z2;
    cout << "\033[0mangle: \033[34m"; 
    cin >> alfa2;
    printf("\033[0m");
  }
  int shX = X(x1,z1,alfa1,x2,z2,alfa2);
  int shZ = Z(x1,z1,alfa1,x2,z2,alfa2);
  cout << "\nStronghold:\n\n Overworld:\n X: " << shX
    << " Z: " << shZ << "\n\n Nether:\n X: " 
    << (int)(shX/8) << " Z: " << (int)(shZ/8) << "\n\n";
  return 0;
}
