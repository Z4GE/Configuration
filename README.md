#   Z4GE.Configuration

##  Table of Contents
1.  [Introduction](#introduction)
2.  [Building](#building)
3.  [Contribution & Support](#contribution--support)
4.  [License](#license)

##  Introduction
Z4GE.Configuration provides prerequisite configuration, CMake modules and other support for Z4GE.

This package, _Z4GE.Configuration_, includes but not limited to:
  - CMake Modules
  - CXX Macros
  - CXX Standard Identification
  - CXX Compiler Identification
  - CXX Platform Identification
  - CXX Compiler Feature Identification
  - Implementation of CXX Features as macros based on platform, compiler and available CXX standard.
##  Building
1.  Clone the git repository
```sh
    git clone https://github.com/z4ge/configuration.git z4ge/configuration
    cd z4ge/configuration
```

2.  Create a dedicated build directory and configure using CMake
```sh
    mkdir Build
    cd Build
    cmake -S ../ -G <YOUR_FAVOURITE_GENERATOR>
```

The follwing are the list of configuration options provided by Z4GE.Configuration for custimizing the build

|                  Build Option                      |                                 Remark                                  |
| -------------------------------------------------- | ----------------------------------------------------------------------- |
| Z4GE_CONFIGURATION_DISABLE_PEDANTIC_ERRORS         | Disable pedantic errors by compiler for Z4GE.Configuration              |
| Z4GE_CONFIGURATION_DISABLE_WARNING_AS_ERROR        | Disable treating warning as errors by compiler for Z4GE.Configuration   |
| Z4GE_CONFIGURATION_BUILD_DOCUMENTATION             | Build documentation for Z4GE.Configuration (Requires Doxygen)           |
| Z4GE_CONFIGURATION_ENABLE_DEVELOPER_DOCUMENTATION  | Build documentation that includes developer sections                    |

##  Contribution & Support
### Issues
![GitHub issues](https://img.shields.io/github/issues/zerozero4/catalyst?label=Issues&style=flat-square)

All bugs, feature requests can be reported through the [Github Issue Tracker](https://github.com/z4ge/configuration/issues).

### Contribution
![GitHub pull requests](https://img.shields.io/github/issues-pr/zerozero4/catalyst?label=Pull%20Requests&style=flat-square)

If you are willing to contribute to this project (Z4GE.Configuration), grab any issue from the issue tracker (
[Github Issue Tracker](https://github.com/z4ge/configuration/issues)), fix it, submit your changes through a
[Pullrequest](https://github.com/z4ge/configuration/pulls). The pull request will be reviewed shortly and changes will be merged
on the desired branch

##  License
This project (Z4GE.Configuration) is licensed under [BSD 3-Clause License](LICENSE).