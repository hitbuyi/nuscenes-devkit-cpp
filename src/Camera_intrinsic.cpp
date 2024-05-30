#include "Camera_intrinsic.hpp"


const std::any &Camera_intrinsic::get_intrinsic() const{return intrinsic;}
Camera_intrinsic::Camera_intrinsic(const json &j) {
     if (j.empty()) {
            intrinsic = std::vector<std::vector<double>>(); // Empty array
        } else if (j.is_array() && j.size() == 3 && j[0].is_array() && j[0].size() == 3) {
            std::vector<std::vector<double>> matrix(3, std::vector<double>(3));
            for (size_t i = 0; i < 3; ++i) {
                for (size_t k = 0; k < 3; ++k) {
                    matrix[i][k] = j[i][k].get<double>();
                }
            }
            intrinsic = matrix; // 3x3 array
        } else {
            throw std::invalid_argument("Invalid JSON format for CameraIntrinsic");
      }
}

// Method to print the intrinsic data for debugging purposes
void Camera_intrinsic::print() const {
std::cout << " camera instrinsics:" << std::endl;
  if (intrinsic.type() == typeid(std::vector<std::vector<double>>)) {
    const auto& matrix = std::any_cast<const std::vector<std::vector<double>>&>(intrinsic);
    if (matrix.empty()) {
        std::cout << "Intrinsic is an empty array." << std::endl;
    } else {
        for (const auto& row : matrix) {
            for (double val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
  } else {
    std::cout << "Intrinsic is of an unknown type." << std::endl;
  }
}

void Camera_intrinsic::accept(const RecordVisitor &visitor) const {
  visitor.visit(*this);
}
