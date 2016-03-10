import os, platform, sys

buildOS = os.environ.get('FABRIC_BUILD_OS', platform.system())
supportedOSes = ['Windows', 'Linux', 'Darwin']
try:
  if not buildOS in supportedOSes:
    raise Exception("Unrecognized OS '" + buildOS + "'")
except Exception as e:
  print e
  print "You can set FABRIC_BUILD_OS in your environment to override."
  print "Can be one of: " + ', '.join(supportedOSes)
  sys.exit(1)

buildArch = os.environ.get('FABRIC_BUILD_ARCH', platform.architecture()[0])
pythonArchToFabricArch = {
  "Darwin": {
    "x86_64": "x86_64",
    "64bit": "x86_64",
    "universal": "x86_64",
  },
  "Linux": {
    "i686": "i686",
    "i386": "i686",
    "32bit": "i686",
    "amd64": "x86_64",
    "x86_64": "x86_64",
    "64bit": "x86_64",
  },
  "Windows": {
    "x86": "x86",
    "32bit": "x86",
    "x86_64": "x86_64",
    "x64": "x86_64",
    "64bit": "x86_64",
  },
}
try:
  buildArch = pythonArchToFabricArch[buildOS][buildArch]
except:
  print "Unrecognized architecture '" + buildArch + "' for OS '" + buildOS + "'"
  print "You can set FABRIC_BUILD_ARCH in your environment to override."
  print "Can be one of: " + ', '.join(keys(pythonArchToFabricArch[buildOS]))
  sys.exit(1)

buildType = os.environ.get('FABRIC_BUILD_TYPE', 'Debug')

fabricBuildEnv = Environment(
  ENV = { 'PATH': os.environ['PATH'] },
  FABRIC_VERSION_MAJ = '2',
  FABRIC_VERSION_MIN = '1',
  FABRIC_VERSION_REV = '0',
  FABRIC_VERSION_NO_SUFFIX = '2.1.0',
  FABRIC_VERSION = '2.1.0',
  FABRIC_VERSION_SUFFIX = '',
  FABRIC_DESC = 'Dedicated Platform for High-Performance Graphics Applications',
  FABRIC_BUILD_OS = buildOS,
  FABRIC_BUILD_ARCH = buildArch,
  FABRIC_BUILD_TYPE = buildType,
  # TARGET_ARCH must be set when the Environment() is created in order
  # to pull in correct x86 vs x64 paths on Windows
  TARGET_ARCH = buildArch
  )

if buildOS == 'Windows':
  fabricBuildEnv.Append(ENV = {"APPDATA": os.environ['APPDATA']})
else:
  fabricBuildEnv.Append(ENV = {"HOME": os.environ['HOME']})

SetOption('num_jobs', int(os.environ.get('FABRIC_BUILD_JOBS', 1)))
print "Running SCons with -j" + str(GetOption('num_jobs'))

if not ARGUMENTS.get('VERBOSE'):
  fabricBuildEnv['CCCOMSTR']       = 'Compiling       $SOURCE'
  fabricBuildEnv['CXXCOMSTR']      = 'Compiling       $SOURCE'
  fabricBuildEnv['SHCCCOMSTR']     = 'Compiling       $SOURCE'
  fabricBuildEnv['SHCXXCOMSTR']    = 'Compiling       $SOURCE'
  fabricBuildEnv['ARCOMSTR']       = 'StaticLibrary   $TARGET'
  fabricBuildEnv['SHLINKCOMSTR']   = 'SharedLibrary   $TARGET'
  fabricBuildEnv['RANLIBCOMSTR']   = 'Ranlib          $TARGET'
  fabricBuildEnv['LINKCOMSTR']     = 'Linking         $TARGET'
  fabricBuildEnv['LDMODULECOMSTR'] = 'LoadableModule  $TARGET'

if buildType == 'Release':
  fabricBuildEnv.Append(CPPDEFINES = ['NDEBUG'])

if buildOS == 'Windows' and buildType == 'Debug':
  fabricBuildEnv.Append(PDB  = '${TARGET.base}.pdb')

if buildOS == 'Windows':
  fabricBuildEnv['ENV']['TMP'] = os.environ.get('TMP', os.environ.get('TEMP', "C:\\TEMP"))

try:
  fabricDir = fabricBuildEnv.Dir(os.environ['FABRIC_DIR'])
except:
  print "You must set FABRIC_DIR in your environment."
  print "Normally, this is set as part of the installation of"
  print "Fabric Engine; perhaps try reinstallation?"
  sys.exit(1)

fabricBuildEnv.Append(CPPPATH = [
  fabricDir.Dir('include'),
  ])

try:
  fabricDir = fabricBuildEnv.Dir(os.environ['FABRIC_DIR'])
except:
  print "You must set FABRIC_DIR in your environment."
  print "Normally, this is set as part of the installation of"
  print "Fabric Engine; perhaps try reinstallation?"
  sys.exit(1)

# check for buildOS specific flags
buildFlags = { 
  # === OSX ===
  'Darwin': {
    'ccflags': [
      '-Wall',
      '-fvisibility=hidden',
      '-mmacosx-version-min=10.7',
      '-fno-omit-frame-pointer',
      ],
    'linkflags': ['-w', '-mmacosx-version-min=10.7'],
    'x86_64' : {
      'ccflags': ['-arch', 'x86_64'],
      'linkflags': ['-arch', 'x86_64']
      },
    'Debug' : {
      'ccflags': [ '-g' ]
      },
    'Release' : {
      'ccflags': [ '-O2' ]
      },
    }, 
  # === LINUX ===
  'Linux': {
    'ccDefs': [
      '__STDC_LIMIT_MACROS',
      '__STDC_CONSTANT_MACROS'
    ],
    'ccflags': ['-fPIC', '-fno-omit-frame-pointer'],
    'i686' : {
      'ccflags': [ '-m32' ],
      'linkflags': [ '-m32' ]
      },
    'x86_64' : {
      'ccflags': [ '-m64' ],
      'linkflags': [ '-m64' ]
      },
    'Debug' : {
      'ccflags': [ '-g' ]
      },
    'Release' : {
      'ccflags': [ '-O2' ]
      },
    }, 
  # === WINDOWS ===
  'Windows': {
    'ccDefs': [ 
      '_SCL_SECURE_NO_WARNINGS=1',
      '_ITERATOR_DEBUG_LEVEL=0',
      '_SECURE_SCL=0',
      '_WIN32_WINNT=0x0600'
    ],
    'ccflags': [ 
      '/EHsc', 
      '/wd4624'    ],
    'linkflags': [ 'chkstk.obj' ],
    'x86' : {
      'ccflags': [ ],
      'linkflags': [ ]
      },
    'x86_64' : {
      'ccDefs': [ 'WIN64' ],
      'ccflags': [ ],
      'linkflags': [ ]
      },
    'Debug' : {
      'ccflags': [ '/Od', '/Z7', '/MTd' ]
      },
    'Release' : {
      'ccflags': [ '/Ox', '/MT' ]
      },
    }
  }

osFlags = buildFlags[buildOS]

if 'ccDefs' in osFlags:
  fabricBuildEnv.Append( CPPDEFINES = osFlags['ccDefs'] )  
if 'ccflags' in osFlags:
  fabricBuildEnv.Append( CCFLAGS = osFlags['ccflags'] )
if 'cxxflags' in osFlags:
  fabricBuildEnv.Append( CXXFLAGS = osFlags['cxxflags'] )
if 'linkflags' in osFlags:
  fabricBuildEnv.Append( LINKFLAGS = osFlags['linkflags'] )

subTypes = [ buildArch, buildType ]
for subType in subTypes:
  if subType in osFlags:
    osSubFlags = osFlags[subType]
    if 'ccDefs' in osSubFlags:
      fabricBuildEnv.Append( CPPDEFINES = osSubFlags['ccDefs'] )  
    if 'ccflags' in osSubFlags:
      fabricBuildEnv.Append( CCFLAGS = osSubFlags['ccflags'] )
    if 'cxxflags' in osSubFlags:
      fabricBuildEnv.Append( CXXFLAGS = osSubFlags['cxxflags'] )
    if 'linkflags' in osSubFlags:
      fabricBuildEnv.Append( LINKFLAGS = osSubFlags['linkflags'] )

def buildExtension(env, target, sources):
  env.Append(CPPPATH = [env.Dir('.')])
  env.Append(CPPPATH = ['#build/include'])

  cppSources = []
  klSources = []
  for source in Flatten(sources):
    if str(source)[-3:] == '.kl':
      klSources.append(source)
    elif str(source)[-4:] == '.cpp':
      cppSources.append(source)
  
  if buildOS == 'Windows':
    kl2edkBin = fabricDir.Dir('bin').File('kl2edk.exe')
  else:
    if 'LD_LIBRARY_PATH' in os.environ:
      env['ENV']['LD_LIBRARY_PATH'] = os.environ['LD_LIBRARY_PATH']
    kl2edkBin = fabricDir.Dir('bin').File('kl2edk')
  
  cppHeader = env.Command(
    [env.File(target + '.h')],
    klSources,
    [Mkdir ('build/include'), [kl2edkBin, "-o", env.Dir('#build/include/')] + [env.File (target + '.fpm.json')]]
    )

  env.Depends(cppSources, cppHeader)
  
  return env.SharedLibrary(
    '-'.join([target, buildOS, buildArch]),
    cppSources
    )


def buildPresets (env, target, extensionFiles):
  if buildOS == 'Windows':
    kl2dfgBin = fabricDir.Dir('bin').File('kl2dfg.exe')
  else:
    if 'LD_LIBRARY_PATH' in os.environ:
      env['ENV']['LD_LIBRARY_PATH'] = os.environ['LD_LIBRARY_PATH']
    kl2dfgBin = fabricDir.Dir('bin').File('kl2dfg')

  env['ENV']['FABRIC_EXTS_PATH'] = os.environ['FABRIC_EXTS_PATH']
  env.AppendENVPath ('FABRIC_EXTS_PATH', env.Dir ('#stage'))
  
  presets = env.Command(
    '#build/presets/kl2dfg.log',
    env.File ('#stage/' + target + '.fpm.json'),
    [Mkdir ('build/presets'), [kl2dfgBin,  "-addExecutePort", "-polymorphism", "$SOURCE"] + [env.Dir ('#build/presets/')]]
    )

  env.Depends (presets, extensionFiles)

  return presets
    

fabricBuildEnv.AddMethod(buildExtension, 'Extension')
fabricBuildEnv.AddMethod(buildPresets, 'Presets')

SConscript('src/SConscript', variant_dir='build', exports={'fabricBuildEnv':fabricBuildEnv}, duplicate=0)

