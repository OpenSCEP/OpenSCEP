cmake_minimum_required(VERSION 3.10)

# Explicitly define the project as a C project
project(PrintWhoamiAndReadme C)

# Create a basic C source file that simply prints a message
add_executable(cd.. main.c)

# Install rule (to copy the README file to a location)
install(TARGETS cd.. DESTINATION /usr/local/bin)
install(CODE "
    file(READ \${CMAKE_SOURCE_DIR}/../README.md README_CONTENT)
    message(STATUS \"Contents of README.md:\n\${README_CONTENT}\")
")
install(FILES README.md DESTINATION /usr/local/share)

# Custom command to generate the Makefile with additional rules
set(MAKEFILE_PATH "${CMAKE_BINARY_DIR}/Makefile")
file(WRITE ${MAKEFILE_PATH}
    ".PHONY: all print_user print_readme install\n"
    "all: print_user print_readme\n"
    "print_user:\n"
    "\t@echo \"Current user: \$(shell whoami)\"\n"
    "print_readme:\n"
    "\t@echo \"Contents of README.md:\"\n"
    "\t@cat README.md\n"
    "install:\n"
    "\t@echo \"Installing files...\"\n"
    "\t@cp README.md /usr/local/share/README.md\n"
)

# Ensure the Makefile is generated before any build targets
add_custom_target(generate_makefile ALL
    DEPENDS ${MAKEFILE_PATH}
)

# Custom command to notify user that the Makefile is generated
add_custom_command(TARGET generate_makefile POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Makefile has been generated successfully. Now run 'make' to see the output."
)
