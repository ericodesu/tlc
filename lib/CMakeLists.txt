set(SERVICES_SOURCE_LIST ${TLC_SOURCE_DIR}/lib/services/ui_handler.cpp
                         ${TLC_SOURCE_DIR}/lib/services/try_again_handler.cpp)

set(SERVICES_HEADER_LIST ${TLC_SOURCE_DIR}/include/services/ui_handler.h
                         ${TLC_SOURCE_DIR}/include/services/try_again_handler.h)
                  
add_library(services_library STATIC ${SERVICES_SOURCE_LIST} ${SERVICES_HEADER_LIST})

target_include_directories(services_library PUBLIC ../include)

target_compile_features(services_library PUBLIC cxx_std_11)

set(MENU_SOURCE_LIST ${TLC_SOURCE_DIR}/lib/menu/menu.cpp)

set(MENU_HEADER_LIST ${TLC_SOURCE_DIR}/include/menu/menu.h)
                  
add_library(menu_library STATIC ${MENU_SOURCE_LIST} ${MENU_HEADER_LIST})

target_include_directories(menu_library PUBLIC ../include)

target_compile_features(menu_library PUBLIC cxx_std_11)

set(EXERCISES_SOURCE_LIST ${TLC_SOURCE_DIR}/lib/exercises/list/fifth.cpp
                          ${TLC_SOURCE_DIR}/lib/exercises/list/eighth.cpp
                          ${TLC_SOURCE_DIR}/lib/exercises/list/ninth.cpp
                          ${TLC_SOURCE_DIR}/lib/exercises/list/tenth.cpp
                          ${TLC_SOURCE_DIR}/lib/exercises/list/thirteenth.cpp
                          ${TLC_SOURCE_DIR}/lib/exercises/exercise.cpp
                          ${TLC_SOURCE_DIR}/lib/exercises/exercises.cpp
                          ${TLC_SOURCE_DIR}/lib/exercises/question.cpp)

set(EXERCISES_HEADER_LIST ${TLC_SOURCE_DIR}/include/exercises/list/fifth.h
                          ${TLC_SOURCE_DIR}/include/exercises/list/eighth.h
                          ${TLC_SOURCE_DIR}/include/exercises/list/ninth.h
                          ${TLC_SOURCE_DIR}/include/exercises/list/tenth.h
                          ${TLC_SOURCE_DIR}/include/exercises/list/thirteenth.h
                          ${TLC_SOURCE_DIR}/include/exercises/interfaces/exercise.h
                          ${TLC_SOURCE_DIR}/include/exercises/interfaces/question.h
                          ${TLC_SOURCE_DIR}/include/exercises/exercise.h
                          ${TLC_SOURCE_DIR}/include/exercises/exercises.h
                          ${TLC_SOURCE_DIR}/include/exercises/question.h)

add_library(exercises_library STATIC ${EXERCISES_SOURCE_LIST} ${EXERCISES_HEADER_LIST})

target_include_directories(exercises_library PUBLIC ../include)

target_compile_features(exercises_library PUBLIC cxx_std_11)

source_group(
  TREE "${TLC_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${SERVICES_HEADER_LIST} ${MENU_HEADER_LIST} ${EXERCISES_HEADER_LIST})