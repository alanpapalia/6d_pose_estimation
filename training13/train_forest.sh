mkdir -p forest
cd forest
/home/yihernong/object_detector_6d/build/HoughForest --train --threads_per_tree=8 --threads_for_parallel_trees=1 --input=../patches_full_p8_v0.005/patches.forest --trees=8 --patch_size_in_voxels=8 --voxel_size_in_m=0.005
cd ..
