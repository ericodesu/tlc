file(GLOB MY_CVS_FILES
  "${PROJECT_SOURCE_DIR}/tools/csv/*.csv"
)

file(COPY ${MY_CVS_FILES} DESTINATION "${PROJECT_BINARY_DIR}/apps/Resources/csv/")

file(GLOB MY_IMAGE_FILES
  "${PROJECT_SOURCE_DIR}/tools/images/*.png"
  "${PROJECT_SOURCE_DIR}/tools/images/*.jpeg"
)

file(COPY ${MY_IMAGE_FILES} DESTINATION "${PROJECT_BINARY_DIR}/apps/Resources/images/")