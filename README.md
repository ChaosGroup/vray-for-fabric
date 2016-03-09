#                             V-Ray for Fabric Engine
![Canvas Screenshot](https://sjparker.github.io/images/screenshots/canvas.png)
This project wraps the V-Ray Application SDK and provides bindings to Fabric Engine's scripting language, KL. It also exposes those bindings in Fabric Engine's graphical programming application, Canvas.

The documentation and examples below assume a Linux environment.
## Requirements
- latest build of V-Ray Application SDK.
- [Fabric Engine](http://fabricengine.com/get-fabric/) 2.1.x
- Python 2.7.x
- [SCons](https://scons.org/) build system.

## Setup
### V-Ray Application SDK
V-Ray Application SDK requires the following environment variables to be set:
```
${VRAY_PATH}
${VRAY_SDK}
${PATH}
${LD_LIBRARY_PATH}
${PYTHONPATH}
```
Example (Linux/bash):
```
export VRAY_PATH=/opt/chaosgroup/vrayappsdk/20151029/bin
export VRAY_SDK=/opt/chaosgroup/vrayappsdk/20151029
export PATH=${PATH}:/opt/chaosgroup/vrayappsdk/20151029/bin
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/opt/chaosgroup/vrayappsdk/20151029/bin
export PYTHONPATH=${PYTHONPATH}:/opt/chaosgroup/vrayappsdk/20151029/python27/bin
```
### Fabric Engine
Fabric Engine requires the following environment variables to be set:
```
${FABRIC_DIR}
${FABRIC_EDK_DIR}
${FABRIC_EXTS_PATH}
${FABRIC_DFG_PATH}
${PATH}
${PYTHONPATH}
```
Example (Linux/bash):
```
export FABRIC_DIR=/opt/fabricsoftware/fabric-engine/FabricEngine-2.0.0-Linux-x86_64
export FABRIC_EDK_DIR=/opt/fabricsoftware/fabric-engine/FabricEngine-2.0.0-Linux-x86_64
export FABRIC_EXTS_PATH=/opt/fabricsoftware/fabric-engine/FabricEngine-2.0.0-Linux-x86_64/Exts
export FABRIC_DFG_PATH=/opt/fabricsoftware/fabric-engine/FabricEngine-2.0.0-Linux-x86_64/Presets/DFG
export PATH=${PATH}:/opt/fabricsoftware/fabric-engine/FabricEngine-2.0.0-Linux-x86_64/bin
export PYTHONPATH=${PYTHONPATH}:/opt/fabricsoftware/fabric-engine/FabricEngine-2.0.0-Linux-x86_64/Python/2.7
```
## Build
To build vray-for-fabric, simply run `scons` from the top-level project directory. This will generate the necessary headers, compile source, generate canvas dfg presets, and copy all relevant files to an extension directory `./stage`. All intermediate files are created in the `./build` directory. These directories will be (re)created each time `scons` is run.
```
cd <vray-for-fabric dir>
scons
```
To clean, run `scons -c`. This will remove everything in the `./build` and `./stage` directories, but not the directories themselves.
```
scons -c
```
## Test
In order to test vray-for-fabric, a few environment variables need to be appended and a couple new ones set. This can be accomplished by sourcing the shell script `source.sh` located in the `./test` directory.
```
cd ./test
source ./source.sh
```
### Commandline test using the `kl` tool:
This test will load the `test.vrscene` file and generate a `render.png` file and re-export the vrscene as `dump.vrscene`.
```
kl test.kl
```
### GUI test using the `canvas` application:
Launch canvas with the `test.canvas` file as an argument. Once you're in Canvas, connect the result plug of the SaveImage node to the 'expose' input on the right-side of the canvas to initiate graph execution. You should get an output png called `output_from_canvas.png` in the test directory.
```
canvas test.canvas
```
