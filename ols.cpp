#include <iostream>
#include <random>
#include <Eigen/Dense>

int main()
{
  // number of observations
  const int n = 1000;

  std::default_random_engine generator;
  std::normal_distribution<double> z(0, 1);

  // predictor
  std::vector<double> x_vec(n);
  // residual error
  std::vector<double> e_vec(n);
  // dependent variable
  std::vector<double> y_vec(n);

  for(int i = 0; i < n; i++) {
    double draw = z(generator);
    x_vec[i] = draw;
  }

  for(int i = 0; i < n; i++) {
    double draw = z(generator);
    e_vec[i] = draw;
  }

  for(int i = 0; i < n; i++) {
     y_vec[i] = 5 * x_vec[i] + e_vec[i];
  }

  // we have generated data for:
  // y = x*b + e

  // move data from std::vector to Eigen data structures  

  // Design matrix
  Eigen::MatrixXd X(n, 2);
  X.col(0).setOnes();
  X.col(1) = Eigen::VectorXd::Map(x_vec.data(), x_vec.size());
  // dependent variable  
  Eigen::VectorXd y = Eigen::VectorXd::Map(y_vec.data(), y_vec.size());
  // residual error
  Eigen::VectorXd e = Eigen::VectorXd::Map(e_vec.data(), e_vec.size());

  Eigen::VectorXd betas = X.colPivHouseholderQr().solve(y); 
  
  std::cout << "Intercept: " << betas[0] << std::endl;
  std::cout << "Slope: " << betas[1] << std::endl;
  
  return 0;
}
