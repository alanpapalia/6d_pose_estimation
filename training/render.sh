# mustard_bottle
echo "Rendering object: mustard_bottle"
/home/yihernong/pose_estimation_pipeline/6d_pose_estimation/build/PatchGen --render \
--input=../meshes/mustard_bottle.ply \
--output=renderings/mustard_bottle \
--startHeight=0.875 \
--heightStep=0.2 \
--lightings=1 \
--numHeights=2 \
--inPlaceCamRot=36

