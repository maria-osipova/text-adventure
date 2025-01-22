# text-adventure
this is a project i built for the [codecademy c++ course](https://www.codecademy.com/enrolled/courses/learn-c-plus-plus).  
it is a story i made up myself, hope you'd enjoy it!

https://maria-osipova.github.io/text-adventure/

to make the program run from the terminal use*

`c++ -std=c++17 -I/Users/maria/Downloads/text-adventure-starting/vcpkg/installed/arm64-osx/include \
-L/Users/maria/Downloads/text-adventure-starting/vcpkg/installed/arm64-osx/lib \
-ljsoncpp /Users/maria/Downloads/text-adventure-starting/src/text-adventure.cpp -o text-adventure`

* `-I/Users/maria/.../include`: Adds the path to the include directory where the header files for the jsoncpp library are located. Replace this path with your own if it differs.  
  `-L/Users/maria/.../lib`: Adds the path to the lib directory where the compiled libraries (e.g., jsoncpp) are stored.  
  `-ljsoncpp`: Links the compiled code with the jsoncpp library.  
  `/Users/maria/.../text-adventure.cpp`: Specifies the path to the main source file of the project.  

then:  

`./text-adventure`                                                                                      

this project uses [vcpkg](https://github.com/microsoft/vcpkg) to manage dependencies.
ensure you have vcpkg installed and set up.

thank you! :3