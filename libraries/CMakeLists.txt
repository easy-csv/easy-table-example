

set(table_src_path "easy-table")

set(table_include_path "easy-table")

set(TABLE_H_FILES)
set(TABLE_S_FILES)


list_lib("${table_src_path}" "${table_core_name}" TABLE_H_FILES TABLE_S_FILES "${TABLE_H_FILES}" "${TABLE_S_FILES}")
list_lib("${table_src_path}" "${table_ser_lib_name}" TABLE_H_FILES TABLE_S_FILES "${TABLE_H_FILES}" "${TABLE_S_FILES}")

#MESSAGE(STATUS "TABLE_H_FILES: ${TABLE_H_FILES}")
#MESSAGE(STATUS "TABLE_S_FILES: ${TABLE_S_FILES}")


add_library( ${table_lib_name} ${TABLE_S_FILES} ${TABLE_H_FILES} )

target_link_libraries( ${table_lib_name} 
)

target_include_directories( ${table_lib_name} PUBLIC "${table_include_path}" )

set_target_properties( ${table_lib_name} PROPERTIES PUBLIC_HEADER "${TABLE_H_FILES}" FOLDER "table")
