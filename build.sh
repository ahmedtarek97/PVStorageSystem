#!/bin/bash

# Function to display usage information
usage() {
  echo "Usage: $0 [--clean] [--doc]"
  echo "  --clean  Clean the build directory"
  echo "  --doc  generate doxgen documintation in /doc directory"
  exit 1
}

DOC=0
CLEAN=0

for arg in "$@"; do
  case $arg in
    --clean)
        CLEAN=1
      ;;
    --doc)
        DOC=1
      ;;
    *)
        usage
        exit 1
      ;;
  esac
done


# Create a build and doc directories if doesn't exist
BUILD_DIR="build"
mkdir -p "$BUILD_DIR"

DOC_DIR="doc"
mkdir -p "$DOC_DIR"

# Clean the build and doc directories if requested
if [[ $CLEAN -eq 1 ]]; then
  echo "Cleaning build and doc directories..."
  rm -rf "$BUILD_DIR"/* "$DOC_DIR"/*
  echo "Build directory cleaned."
fi

if [[ $DOC -eq 1 ]]; then
    # Check if Doxygen is installed
    if command -v doxygen &> /dev/null; then
        echo "Doxygen is installed. Generating documentation..."
        # Generate Doxygen documentation (assuming Doxyfile is in the same directory)
        doxygen Doxyfile
        echo "Documentation generated successfully!"
    else
        echo "Doxygen is not installed. Please install it before generating documentation."
    fi
fi

# Change to the build directory
cd "$BUILD_DIR"

# Run CMake to generate the build system
cmake ..

# Build the project
cmake --build .
