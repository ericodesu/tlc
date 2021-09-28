file(GLOB MY_CVS_FILES
  "${CMAKE_CURRENT_LIST_DIR}/csv/*.csv"
)

file(COPY ${MY_CVS_FILES} DESTINATION "${PROJECT_BINARY_DIR}/resources/csv/")

file(GLOB MY_IMAGE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/images/*.png"
  "${CMAKE_CURRENT_LIST_DIR}/images/*.jpeg"
)

file(COPY ${MY_IMAGE_FILES} DESTINATION "${PROJECT_BINARY_DIR}/resources/images/")

target_compile_definitions(my_library PUBLIC RESOURCE_FILE_DIR="${PROJECT_BINARY_DIR}/resources")