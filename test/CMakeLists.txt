add_executable( RandomImageSource RandomImageSource.cxx )
target_link_libraries( RandomImageSource ${ITK_LIBRARIES} )

add_test( NAME CreateRandomImages
  COMMAND RandomImageSource random1.png random2.png )

add_test( NAME ImageCompareTest1
  COMMAND ImageCompare random1.png random1.png )
add_test( NAME ImageCompareTest2
  COMMAND ImageCompare random1.png random2.png )

set_tests_properties( ImageCompareTest1 ImageCompareTest2
  PROPERTIES DEPENDS CreateRandomImages )
set_tests_properties( ImageCompareTest2
  PROPERTIES WILL_FAIL TRUE )
