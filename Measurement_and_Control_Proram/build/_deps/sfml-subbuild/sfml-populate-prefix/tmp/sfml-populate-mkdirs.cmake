# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/guo/Desktop/code/School_project/Measurement_and_Control_Proram/build/_deps/sfml-src"
  "/home/guo/Desktop/code/School_project/Measurement_and_Control_Proram/build/_deps/sfml-build"
  "/home/guo/Desktop/code/School_project/Measurement_and_Control_Proram/build/_deps/sfml-subbuild/sfml-populate-prefix"
  "/home/guo/Desktop/code/School_project/Measurement_and_Control_Proram/build/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "/home/guo/Desktop/code/School_project/Measurement_and_Control_Proram/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "/home/guo/Desktop/code/School_project/Measurement_and_Control_Proram/build/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "/home/guo/Desktop/code/School_project/Measurement_and_Control_Proram/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/guo/Desktop/code/School_project/Measurement_and_Control_Proram/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/guo/Desktop/code/School_project/Measurement_and_Control_Proram/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
