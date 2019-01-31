

function(list_lib code_path scope_name ref_hpps ref_cpps hpps cpps)


	if( WIN32 )
		set(hscope "${scope_name}\\include")
		set(sscope "${scope_name}\\src")
	else()
		set(hscope "${scope_name}/include")
		set(sscope "${scope_name}/src")
	endif()

	set(search_path "${code_path}/${scope_name}")

	#MESSAGE(STATUS "search_path: ${search_path}")

	file(GLOB hfiles "${search_path}/*.h")
	file(GLOB sfiles "${search_path}/*.cpp")

	source_group( 
		${hscope}
		FILES 
		${hfiles}
	)
	
	source_group( 
		${sscope}
		FILES 
		${sfiles}
	)
	set(newhpp "${hpps};${hfiles}")
	set(${ref_hpps} ${newhpp} PARENT_SCOPE)

	set(newcpp "${cpps};${sfiles}")
	set(${ref_cpps} ${newcpp} PARENT_SCOPE)

endfunction(list_lib)

