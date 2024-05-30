# NuScenes Software Development Kit in Cpp

## Basic Information

This repository is based on [lolainta's work](https://github.com/lolainta/nuscenes-devkit-cpp), I used it for a C++ program, and some mistakes are found, this repository is created for correcting thoese bugs and some functions which exist in corresponding [python version](https://github.com/nutonomy/nuscenes-devkit) are added in it if necessary
## Change logs
 -- 2024/05/30  Add Camera_intrinsic.cpp and Camera_intrinsic.hpp to read camera intrinsic, tested<br>
 -- 2024/05/28  Rotation::Rotation() initialization order is wrong, change from x,y,w to w,x,y, z, in nuscenes dataset, a rotation is represented as a quaternoion of (w,x,y,z) in json file
## Reference
- [NuScenes Official Website](https://www.nuscenes.org)
- [NuScenes dev-kit in python](https://github.com/nutonomy/nuscenes-devkit)
