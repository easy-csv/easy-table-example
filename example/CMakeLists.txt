


set(TEST_LIBS
	${table_lib_name}
)


add_executable(example example.cpp)
target_link_libraries(example ${TEST_LIBS})
