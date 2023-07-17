# Semi-Elastic-LIO

**Semi-Elastic-LIO** (Semi-Elastic LiDAR-Inertial Odometry) is an accurate and robust optimization based LiDAR-inertial odometry (LIO). Compared with the previous work which treats the state at the beginning of current sweep as equal to the state at the end of previous sweep, the **Semi-Elastic-LIO** provides the state sufficient flexibility to be optimized to the correct value, thus preferably ensuring improved accuracy, consistency, and robustness of state estimation.

## Related Work

[Semi-Elastic LiDAR-Inertial Odometry]

Authors: [*Zikang Yuan*](https://scholar.google.com/citations?hl=zh-CN&user=acxdM9gAAAAJ), [*Fengtian Lang*](https://scholar.google.com/citations?hl=zh-CN&user=zwgGSkEAAAAJ&view_op=list_works&gmla=ABEO0Yrl4-YPuowyntSYyCW760yxM5-IWkF8FGV4t9bs9qz1oWrqnlHmPdbt7LMcMDc04kl2puqRR4FaZvaCUONsX7MQhuAC6a--VS2pTsuwj-CyKgWp3iWDP2TS0I__Zui5da4), *Tianle Xu*, [*Chengwei Zhao*](https://github.com/chengwei0427) and [*Xin Yang*](https://scholar.google.com/citations?user=lsz8OOYAAAAJ&hl=zh-CN)

## Demo Video (2023-07-17 Update)

The comparison result between our estimated trajectoriy and ground truth on sequence *nclt_2012-04-29* (left), the local point cloud map of *nclt_2012-04-29* (center), and the **x40 Real-Time Performance** on sequence captured by a 16-line Robosense LiDAR and a IMU coming with [*StarNeto*](http://www.starneto.com/) RTK (right). On our currently hardware platform (**Intel Core i7-12700 and 32 GB RAM**), and the **Semi-Elastic-LIO** need **60~70ms** to handle a sweep under this environment.

<div align="left">
<img src="doc/nclt_result.png" width=56.6% />
<img src="doc/demo_gif.gif" width=34.85% />
</div>

**Pipeline:**
<div align="center">
<img src="doc/framework.png" width=90% />
</div>

**New Features:**
The proposed **Semi-Elastic LiDAR-Inertial State Estimation** method utilizes the point-to-plane constraint to ensure the state at the end of current sweep, and utilizes the logical constraint to ensure the state at the beginning of current sweep. The IMU pre-integration constraints both begin state and end state to make them satisfy kinematic constraints within elastic range. The comparision between our method with the **traditional LiDAR-Inertial State Estimation** and the **Elastic LiDAR-Inertial State Estimation** is illustrated by the figure as follow:
<div align="center">
<img src="doc/method_comparison.png" width=90% />
</div>

## Installation

### 1. Requirements

> GCC >= 5.4.0
>
> Cmake >= 3.0.2
> 
> [Eigen3](http://eigen.tuxfamily.org/index.php?title=Main_Page) >= 3.2.8
>
> [PCL](https://pointclouds.org/downloads/) == 1.7 for Ubuntu 16.04, and == 1.8 for Ubuntu 18.04
>
> [Ceres](http://ceres-solver.org/installation.html) >= 1.14
>
> [ROS](http://wiki.ros.org/ROS/Installation)

##### Have Tested On:

| OS    | GCC  | Cmake | Eigen3 | PCL | Ceres |
|:-:|:-:|:-:|:-:|:-:|:-:|
| Ubuntu 16.04 | 5.4.0  | 3.16.0 | 3.2.8 | 1.7 | 1.14 |
| Ubuntu 18.04 | 7.5.0  | 3.11.2 | 3.3.4 | 1.8 | 1.14 |

### 2. Create ROS workspace

```bash
mkdir -p ~/Semi-Elastic-LIO/src
cd Semi-Elastic/src
```

### 3. Clone the directory and build

```bash
git clone https://github.com/ZikangYuan/semi_elastic_lio.git
cd ..
catkin_make
```
