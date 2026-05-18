add_executable(AConsoleTests
    Main.cpp
)

target_include_directories(AConsoleTests
	PRIVATE ${PROJECT_SOURCE_DIR}/Source
)

target_link_libraries(AConsoleTests
	PRIVATE GTest::gtest
	GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(AConsoleTests)
