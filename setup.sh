export VRAY_PATH=/opt/chaosgroup/vrayappsdk/20160308/bin
export VRAY_SDK=/opt/chaosgroup/vrayappsdk/20160308
export PATH=${PATH}:/opt/chaosgroup/vrayappsdk/20160308/bin
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/opt/chaosgroup/vrayappsdk/20160308/bin
export PYTHONPATH=${PYTHONPATH}:/opt/chaosgroup/vrayappsdk/20160308/python27/bin

export FABRIC_DIR=/opt/fabricsoftware/fabric-engine/FabricEngine-2.1.0-Linux-x86_64
export FABRIC_EDK_DIR=/opt/fabricsoftware/fabric-engine/FabricEngine-2.1.0-Linux-x86_64
export FABRIC_EXTS_PATH=/opt/fabricsoftware/fabric-engine/FabricEngine-2.1.0-Linux-x86_64/Exts
export FABRIC_DFG_PATH=/opt/fabricsoftware/fabric-engine/FabricEngine-2.1.0-Linux-x86_64/Presets/DFG
export PATH=${PATH}:/opt/fabricsoftware/fabric-engine/FabricEngine-2.1.0-Linux-x86_64/bin
export PYTHONPATH=${PYTHONPATH}:/opt/fabricsoftware/fabric-engine/FabricEngine-2.1.0-Linux-x86_64/Python/2.7

stagepath=$( cd "$(dirname "$0")/stage" ; pwd -P )
export FABRIC_EXTS_PATH=${FABRIC_EXTS_PATH}:$stagepath
export FABRIC_DFG_PATH=${FABRIC_DFG_PATH}:$stagepath/presets
export FABRIC_ENABLE_CRASH_HANDLER=1
export FABRIC_DEBUG=2
