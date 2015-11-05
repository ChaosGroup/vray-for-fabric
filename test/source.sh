
stagepath=$( cd "$(dirname "$0")/../stage" ; pwd -P )

export FABRIC_EXTS_PATH=${FABRIC_EXTS_PATH}:$stagepath
export FABRIC_DFG_PATH=${FABRIC_DFG_PATH}:$stagepath/presets

export FABRIC_ENABLE_CRASH_HANDLER=1
export FABRIC_DEBUG=2

