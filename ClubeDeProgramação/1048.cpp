#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  float sal,salaj,vlraj;
  cin >> sal;

  cout << fixed << setprecision(2);
  if(sal>=0 & sal<=400){
    vlraj=sal*0.15;
    salaj=sal+vlraj;
    cout << "Novo salario: " << salaj << endl;
    cout << "Reajuste ganho: " << vlraj << endl;
    cout << "Em percentual: 15 %" << endl;
  }else if(sal>=400.01 & sal<=800){
    vlraj=sal*0.12;
    salaj=sal+vlraj;
    cout << "Novo salario: " << salaj << endl;
    cout << "Reajuste ganho: " << vlraj << endl;
    cout << "Em percentual: 12 %" << endl;
  }else if(sal>=800.01 & sal<=1200){
    vlraj=sal*0.10;
    salaj=sal+vlraj;
    cout << "Novo salario: " << salaj << endl;
    cout << "Reajuste ganho: " << vlraj << endl;
    cout << "Em percentual: 10 %" << endl;    
  }else if(sal>=1200.01 & sal<=2000){
    vlraj=sal*0.07;
    salaj=sal+vlraj;
    cout << "Novo salario: " << salaj << endl;
    cout << "Reajuste ganho: " << vlraj << endl;
    cout << "Em percentual: 7 %" << endl;
  }else if(sal>=2000.01){
    vlraj=sal*0.04;
    salaj=sal+vlraj;
    cout << "Novo salario: " << salaj << endl;
    cout << "Reajuste ganho: " << vlraj << endl;
    cout << "Em percentual: 4 %" << endl;
  }
  return 0;
}