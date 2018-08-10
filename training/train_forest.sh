mkdir -p forest
cd forest
/home/yihernong/pose_estimation_pipeline/6d_pose_estimation/build/HoughForest --train --threads_per_tree=8 --threads_for_parallel_trees=1 --input=../patches_full_p8_v0.01/patches.forest --trees=8 --patch_size_in_voxels=8 --voxel_size_in_m=0.01
cd ..
