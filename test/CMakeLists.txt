enable_testing()

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

include_directories(../include)

# Add test files
add_executable(test_BatteryModule test_BatteryModule.cpp ../src/BatteryModule.cpp)
target_link_libraries(test_BatteryModule GTest::gtest_main)

add_executable(test_Grid test_Grid.cpp ../src/Grid.cpp)
target_link_libraries(test_Grid GTest::gtest_main)

add_executable(test_Inverter test_Inverter.cpp ../src/Inverter.cpp)
target_link_libraries(test_Inverter GTest::gtest_main)

add_executable(test_StorageSystem test_StorageSystem.cpp ../src/StorageSystem.cpp ../src/Inverter.cpp ../src/BatteryModule.cpp) 
target_link_libraries(test_StorageSystem GTest::gtest_main)

file(GLOB SOURCES "../src/*.cpp")
add_executable(test_EMController test_EMController.cpp ${SOURCES}) 
target_link_libraries(test_EMController GTest::gtest_main)


# Add tests
add_test(NAME test_BatteryModule COMMAND test_BatteryModule)
add_test(NAME test_Grid COMMAND test_Grid)
add_test(NAME test_Inverter COMMAND test_Inverter)
add_test(NAME test_StorageSystem COMMAND test_StorageSystem)
add_test(NAME test_EMController COMMAND test_EMController)

