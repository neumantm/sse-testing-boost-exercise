#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;

struct MatrixIoFixture {
  MatrixIoFixture()
  {
    filename       = "testmatrix.csv";
    matrixSize     = 3;
    expectedMatrix = MatrixXd(3, 3);
    expectedMatrix << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;
  }

  std::string filename;
  int         matrixSize;
  MatrixXd    expectedMatrix;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIoTests, MatrixIoFixture)

using namespace matrixIO;

BOOST_AUTO_TEST_CASE(OpenData)
{
  const MatrixXd resultMatrix = openData(filename, matrixSize);

  for (int i = 0; i < matrixSize; i++) {
    BOOST_TEST_CONTEXT("I:" + std::to_string(i))
    for (int j = 0; j < matrixSize; j++) {
      BOOST_TEST_CONTEXT("J:" + std::to_string(j))
      BOOST_TEST(expectedMatrix(i, j) == resultMatrix(i, j));
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()
