from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps
from conan.tools.files import copy, rmdir
from conan.tools.layout import basic_layout
import os

class CppMiddleCourseConanFile(ConanFile):
    name = "cpp_middle"
    version = "0.0.1"
    settings = "os", "compiler", "build_type", "arch"
    
    def requirements(self):
        self.tool_requires("cmake/3.30.0")

        #
        # We are including all the dependencies, which will be used during the cpp-middle course
        #
        self.requires("benchmark/1.9.1")
        self.requires("gtest/1.13.0")
        self.requires("abseil/20250127.0")
        self.requires("boost/1.88.0")
        self.requires("openssl/3.1.1")
        self.requires("sqlite3/3.49.1")
        self.requires("range-v3/0.12.0")
    
    def layout(self):
        basic_layout(self, src_folder=".", build_folder="build")
    
    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        
        tc = CMakeToolchain(self)
        tc.generate()
    
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
