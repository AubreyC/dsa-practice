add_library(dsa_practice_lib STATIC)

target_sources(dsa_practice_lib PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/dsa_practice.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/dsa_tree.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/dsa_lru_cache.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/dsa_search_sort.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/dsa_linked_list.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/dsa_heap.cpp
)

target_include_directories(dsa_practice_lib PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)

add_executable(main)

target_sources(main PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(main PUBLIC
  dsa_practice_lib
)

install(TARGETS main DESTINATION bin)
