#pragma once
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
using namespace std;
double condA(const Eigen::MatrixXd& A)
{
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
  Eigen::VectorXd singularValuesA = svd.singularValues(); //estraggo i valori singolari(diagonali svd)
  return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

int gradiente_coniugato(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, Eigen::VectorXd& x0, double residuo_tol, unsigned int iter_max, double& residuo_frac) 
{
  Eigen::VectorXd residuo = b - A * x0;
  Eigen::VectorXd p = residuo;
  double residuo_norm_0 = residuo.norm();
  unsigned int iter = 0;
  //ciclo while che continua fino a che non supero il massimo numero di iterazioni(iter_max), il residuo non è abbastanza piccolo(=tolleranza*norma0)
  while (iter < iter_max && residuo.norm() > residuo_tol * residuo_norm_0){
    Eigen::VectorXd Ap = A * p;
    //faccio il prodotto scalatr (p^T)Ap
    double pAp = p.dot(Ap);
    if (pAp == 0.0){ 
      //gestisco il caso del denominatore=0
      cerr << "Errore: stai dividendo per un fattore nullo!" << endl;
      return -1; 
    }
    const double alpha_k = (p.dot(residuo)) / pAp;
    x0 = x0 + alpha_k * p;
    residuo = b - A * x0; //sto facendo r(k+1)=b-Ax(k+1)
      
    double beta_k = (Ap.dot(residuo)) / pAp;
    //aggiorno la direzione
    p = residuo - beta_k * p;
      
    iter = iter +1;
  }

  // passo indietro il rapporto del residuo 
  residuo_frac = residuo.norm() / residuo_norm_0;
  return iter;
}
