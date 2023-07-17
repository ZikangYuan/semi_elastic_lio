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
