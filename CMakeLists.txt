set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указываем путь к vcpkg toolchain
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указываем пути к заголовкам и библиотеке jsoncpp
include_directories(/opt/homebrew/Cellar/jsoncpp/1.9.6/include)
link_directories(/opt/homebrew/Cellar/jsoncpp/1.9.6/lib)

# Указываем путь к заголовкам jsoncpp
include_directories(${CMAKE_SOURCE_DIR}/vcpkg/installed/arm64-osx/include)

# Указываем путь к jsoncppConfig.cmake
set(jsoncpp_DIR ${CMAKE_SOURCE_DIR}/vcpkg/installed/arm64-osx/share/jsoncpp)

# Находим библиотеку jsoncpp
find_package(jsoncpp CONFIG REQUIRED)

# Добавляем исполняемый файл
add_executable(text_adventure src/text-adventure.cpp)

# Линкуем библиотеку jsoncpp
target_link_libraries(text_adventure PRIVATE jsoncpp)
