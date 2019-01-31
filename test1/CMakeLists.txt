


set(TEST_LIBS
	${table_lib_name}
)


add_executable(test1 test1.cpp)
target_link_libraries(test1 ${TEST_LIBS})
