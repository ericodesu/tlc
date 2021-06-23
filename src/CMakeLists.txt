#### START INTERNAL LIBRARIES ####

set(SERVICES_HEADER_LIST "${PROJECT_SOURCE_DIR}/include/services/ui_handler.h"
                         "${PROJECT_SOURCE_DIR}/include/services/prompt_handler.h"
                         "${PROJECT_SOURCE_DIR}/include/services/random_generator.h"
                         "${PROJECT_SOURCE_DIR}/include/services/vector_handler.h"
                         "${PROJECT_SOURCE_DIR}/include/services/math_handler.h"
                         "${PROJECT_SOURCE_DIR}/include/services/image_handler.h"
)

set(SERVICES_SOURCE_LIST "${PROJECT_SOURCE_DIR}/src/services/ui_handler.cpp"
                         "${PROJECT_SOURCE_DIR}/src/services/prompt_handler.cpp"
                         "${PROJECT_SOURCE_DIR}/src/services/math_handler.cpp"
                         "${PROJECT_SOURCE_DIR}/src/services/image_handler.cpp"
)

set(EXERCISES_HEADER_LIST "${PROJECT_SOURCE_DIR}/include/exercises/list/fifth.h"
                          "${PROJECT_SOURCE_DIR}/include/exercises/list/eighth.h"
                          "${PROJECT_SOURCE_DIR}/include/exercises/list/ninth.h"
                          "${PROJECT_SOURCE_DIR}/include/exercises/list/tenth.h"
                          "${PROJECT_SOURCE_DIR}/include/exercises/list/thirteenth.h"
                          "${PROJECT_SOURCE_DIR}/include/exercises/interfaces/exercise_interface.h"
                          "${PROJECT_SOURCE_DIR}/include/exercises/interfaces/question_interface.h"
                          "${PROJECT_SOURCE_DIR}/include/exercises/exercise.h"
                          "${PROJECT_SOURCE_DIR}/include/exercises/exercises.h"
                          "${PROJECT_SOURCE_DIR}/include/exercises/question.h"
)

set(EXERCISES_SOURCE_LIST "${PROJECT_SOURCE_DIR}/src/exercises/list/fifth.cpp"
                          "${PROJECT_SOURCE_DIR}/src/exercises/list/eighth.cpp"
                          "${PROJECT_SOURCE_DIR}/src/exercises/list/ninth.cpp"
                          "${PROJECT_SOURCE_DIR}/src/exercises/list/tenth.cpp"
                          "${PROJECT_SOURCE_DIR}/src/exercises/list/thirteenth.cpp"
                          "${PROJECT_SOURCE_DIR}/src/exercises/exercise.cpp"
                          "${PROJECT_SOURCE_DIR}/src/exercises/exercises.cpp"
                          "${PROJECT_SOURCE_DIR}/src/exercises/question.cpp"
)

add_library(my_library ${SERVICES_HEADER_LIST}
                       ${SERVICES_SOURCE_LIST}
                       ${EXERCISES_HEADER_LIST}
                       ${EXERCISES_SOURCE_LIST}
)

target_include_directories(my_library PUBLIC "${PROJECT_SOURCE_DIR}/include")

#### END INTERNAL LIBRARIES ####

#### START EXTERNAL LIBRARIES ####

IF(WIN32)
    set(OpenCV_DIR "C:/OpenCV/build/")
ELSE()
    set(OpenCV_DIR "/usr/local/")
ENDIF()

find_package(OpenCV REQUIRED PATHS "${PROJECT_SOURCE_DIR}/cmake")

target_include_directories(my_library PUBLIC ${OpenCV_INCLUDE_DIRS})

target_link_libraries(my_library ${OpenCV_LIBS})

#### END EXTERNAL LIBRARIES ####

target_compile_features(my_library PUBLIC cxx_std_17)

set_target_properties(my_library PROPERTIES LINKER_LANGUAGE CXX)