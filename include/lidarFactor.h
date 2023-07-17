#pragma once
// c++
#include <iostream>

// eigen 
#include <Eigen/Core>

// ceres
#include <ceres/ceres.h>

// utility
#include "utility.h"
#include "imuProcessing.h"

class LidarPlaneNormFactor : public ceres::SizedCostFunction<1, 3, 4>
{
public:
    LidarPlaneNormFactor(const Eigen::Vector3d &point_body_, const Eigen::Vector3d &norm_vector_, const double norm_offset_, double weight_ = 1.0);

    virtual bool Evaluate(double const *const *parameters, double *residuals, double **jacobians) const;

    void check(double **parameters);

    Eigen::Vector3d point_body;
    Eigen::Vector3d norm_vector;

    double norm_offset;
    double weight;

    static Eigen::Vector3d t_il;
    static Eigen::Quaterniond q_il;
    static double sqrt_info;
};

class CTLidarPlaneNormFactor : public ceres::SizedCostFunction<1, 3, 4, 3, 4>
{
public:
    CTLidarPlaneNormFactor(const Eigen::Vector3d &raw_keypoint_, const Eigen::Vector3d &norm_vector_, const double norm_offset_, double alpha_time_, double weight_ = 1.0);

    virtual bool Evaluate(double const *const *parameters, double *residuals, double **jacobians) const;

    void check(double **parameters);

    Eigen::Vector3d raw_keypoint;
    Eigen::Vector3d norm_vector;

    double norm_offset;
    double alpha_time;
    double weight;

    static Eigen::Vector3d t_il;
    static Eigen::Quaterniond q_il;
    static double sqrt_info;
};

class LocationConsistencyFactor : public ceres::SizedCostFunction<3, 3>
{

public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    
    LocationConsistencyFactor(const Eigen::Vector3d &previous_location_, double beta_);

    virtual ~LocationConsistencyFactor() {}

    virtual bool Evaluate(double const* const* parameters, double* residuals, double** jacobians) const;

    Eigen::Vector3d previous_location;
    double beta = 1.0;
};

class RotationConsistencyFactor : public ceres::SizedCostFunction<3, 4>
{

public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    
    RotationConsistencyFactor(const Eigen::Quaterniond &previous_rotation_, double beta_);

    virtual ~RotationConsistencyFactor() {}

    virtual bool Evaluate(double const* const* parameters, double* residuals, double** jacobians) const;

    Eigen::Quaterniond previous_rotation;
    double beta = 1.0;
};

class SmallVelocityFactor : public ceres::SizedCostFunction<3, 3, 3>
{

public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    SmallVelocityFactor(double beta_);

    virtual ~SmallVelocityFactor() {}

    virtual bool Evaluate(double const* const* parameters, double* residuals, double** jacobians) const;

    double beta;
};

class VelocityConsistencyFactor : public ceres::SizedCostFunction<9, 9>
{

public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    
    VelocityConsistencyFactor(state* previous_state_, double beta_);

    virtual ~VelocityConsistencyFactor() {}

    virtual bool Evaluate(double const* const* parameters, double* residuals, double** jacobians) const;

    Eigen::Vector3d previous_velocity;
    Eigen::Vector3d previous_ba;
    Eigen::Vector3d previous_bg;
    double beta = 1.0;
};

class TruncatedLoss : public ceres::LossFunction {
public:
    explicit TruncatedLoss(double sigma) : sigma2_(sigma * sigma) {}

    void Evaluate(double, double *) const override;

private:
    const double sigma2_;
};
