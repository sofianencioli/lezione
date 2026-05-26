#include <iostream>
#include "gradiente_coniugato.hpp" 
#include <cstdlib> 
using namespace std;

int main(int argc, char **argv) 
{
  const double tolleranza = 1.0e-15;
  unsigned int n = 4; //costruisco una matrice 4*4

  Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
  //verifico se il determinante di B è quasi 0
  if (abs(B.determinant()) < tolleranza){
	  cout<< "test fallito"<<"\n";
	  return EXIT_FAILURE;
  }

  Eigen::MatrixXd A = B.transpose() * B; //A è per definizione simmetrica e definita positiva
  Eigen::VectorXd x_esatto = Eigen::VectorXd::Ones(n);
  Eigen::VectorXd b = A * x_esatto; //questa è quella che deve essere la soluzione
  Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);

  const unsigned int iter_max = 20000;
  const double residuo_tol = 1.0e-12;
  double residuo_frac = 0;
  
  cout.precision(2);
  cout << scientific << "Matrix Cond: " << condA(A) << endl;

  int iter = gradiente_coniugato(A, b, x0, residuo_tol, iter_max, residuo_frac);
  
  if (iter == -1){
	  cout<< "fallito perchè c'è una divisione per un valore nullo";
  return EXIT_FAILURE;}

  //questo operatore serve a evitare divisioni per 0 (per 0 fa una cosa, se no fa un'altra)
  double err_rel = (x_esatto.norm() == 0.0) ? (x0 - x_esatto).norm() : (x0 - x_esatto).norm() / x_esatto.norm();
  
  //stampe 
  cout.precision(4);
  cout << scientific << "iter/(iter massimo): " << iter << "/" << iter_max << endl;
  cout << scientific << "residuo/(residuo tolleranza): " << residuo_frac << "/" << residuo_tol << endl;
  cout << scientific << "errore relativo: " << err_rel << endl;
  cout << scientific << "soluzione:\n" << x0 << endl;


  if (err_rel <= residuo_tol && iter <= static_cast<int>(n)) {
    cout<< "successo"<<"\n";
	return EXIT_SUCCESS; 
	
  }
  else{
	cout<< "test fallito"<<"\n";
    return EXIT_FAILURE; 
  }
  return 0;
} 
