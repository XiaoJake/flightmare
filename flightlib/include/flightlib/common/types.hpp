#pragma once

#include <eigen3/Eigen/Eigen>

namespace flightlib {

// ------------ General Stuff-------------

// Define the scalar type used.
using Scalar = double;

// Define frame id for unity
using FrameID = uint64_t;

// Define frame id for unity
using SceneID = size_t;

const Scalar Gz = -9.81;

// ------------ Eigen Stuff-------------

// Define `Dynamic` matrix size.
static constexpr int Dynamic = Eigen::Dynamic;

// Using shorthand for `Matrix<ros, cols>` with scalar type.
template<int rows = Dynamic, int cols = rows>
using Matrix = Eigen::Matrix<Scalar, rows, cols>;

// Using shorthand for `Matrix<ros, cols>` with scalar type.
template<int rows = Dynamic, int cols = rows>
using MatrixRowMajor = Eigen::Matrix<Scalar, rows, cols, Eigen::RowMajor>;

// Using shorthand for `Vector<ros>` with scalar type.
template<int rows = Dynamic>
using Vector = Matrix<rows, 1>;

// Vector bool
template<int rows = Dynamic>
using BoolVector = Eigen::Matrix<bool, -1, 1>;

// Using shorthand for `Array<rows, cols>` with scalar type.
template<int rows = Dynamic, int cols = rows>
using Array = Eigen::Array<Scalar, rows, cols>;

// Using `SparseMatrix` with type.
using SparseMatrix = Eigen::SparseMatrix<Scalar>;

// Using SparseTriplet with type.
using SparseTriplet = Eigen::Triplet<Scalar>;

// Using `Quaternion` with type.
using Quaternion = Eigen::Quaternion<Scalar>;

// Using `Ref` for modifier references.
template<class Derived>
using Ref = Eigen::Ref<Derived>;

// // Using `ConstRef` for constant references.
// template<class Derived>
// using ConstRef = const Eigen::Ref<const Derived>;

// Using `Map`.
template<class Derived>
using Map = Eigen::Map<Derived>;

}  // namespace flightlib