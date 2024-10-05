#!/bin/bash

# Function to display usage information
usage() {
  echo "Usage: $0 [--clean]"
  echo "  --clean  Clean the build directory"
  exit 1
}

# Check for the --clean option
if [[ $# -gt 1 ]]; then
  usage
fi

CLEAN=0
if [[ $# -eq 1 ]]; then
  if [[ "$1" == "--clean" ]]; then
    CLEAN=1
  else
    usage
  fi
fi

# Create a build directory if it doesn't exist
BUILD_DIR="build"
mkdir -p "$BUILD_DIR"

# Clean the build directory if requested
if [[ $CLEAN -eq 1 ]]; then
  echo "Cleaning build directory..."
  rm -rf "$BUILD_DIR"/*
  echo "Build directory cleaned."
fi

# Change to the build directory
cd "$BUILD_DIR"

# Run CMake to generate the build system
cmake ..

# Build the project
cmake --build .

# Run the executable
./PVSS